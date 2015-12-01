# -*- coding: utf-8 -*- {{{
# vim: set fenc=utf-8 ft=python sw=4 ts=4 sts=4 et:
#
# Copyright (c) 2015, Battelle Memorial Institute
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
#
# 1. Redistributions of source code must retain the above copyright notice, this
#    list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright notice,
#    this list of conditions and the following disclaimer in the documentation
#    and/or other materials provided with the distribution.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
# ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
# DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
# ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
# (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
# LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
# ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
# SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#
# The views and conclusions contained in the software and documentation are those
# of the authors and should not be interpreted as representing official policies,
# either expressed or implied, of the FreeBSD Project.
#

# This material was prepared as an account of work sponsored by an
# agency of the United States Government.  Neither the United States
# Government nor the United States Department of Energy, nor Battelle,
# nor any of their employees, nor any jurisdiction or organization
# that has cooperated in the development of these materials, makes
# any warranty, express or implied, or assumes any legal liability
# or responsibility for the accuracy, completeness, or usefulness or
# any information, apparatus, product, software, or process disclosed,
# or represents that its use would not infringe privately owned rights.
#
# Reference herein to any specific commercial product, process, or
# service by trade name, trademark, manufacturer, or otherwise does
# not necessarily constitute or imply its endorsement, recommendation,
# r favoring by the United States Government or any agency thereof,
# or Battelle Memorial Institute. The views and opinions of authors
# expressed herein do not necessarily state or reflect those of the
# United States Government or any agency thereof.
#
# PACIFIC NORTHWEST NATIONAL LABORATORY
# operated by BATTELLE for the UNITED STATES DEPARTMENT OF ENERGY
# under Contract DE-AC05-76RL01830

#}}}

import logging
import sys
import os
import gevent
from volttron.platform.vip.agent import Agent, Core, RPC
from volttron.platform.agent import utils
from driver import DriverAgent
import resource

from driver_locks import configure_socket_lock, configure_publish_lock

utils.setup_logging()
_log = logging.getLogger(__name__)

def master_driver_agent(config_path, **kwargs):

    config = utils.load_config(config_path)

    def get_config(name, default=None):
        try:
            return kwargs.pop(name)
        except KeyError:
            return config.get(name, default)
        
    max_open_sockets = get_config('max_open_sockets', None)
    # Increase open files resource limit to max or 8192 if unlimited
    limit = None
    
    try:
        soft, hard = resource.getrlimit(resource.RLIMIT_NOFILE)
    except OSError:
        _log.exception('error getting open file limits')
    else:
        if soft != hard and soft != resource.RLIM_INFINITY:
            try:
                limit = 8192 if hard == resource.RLIM_INFINITY else hard
                resource.setrlimit(resource.RLIMIT_NOFILE, (limit, hard))
            except OSError:
                _log.exception('error setting open file limits')
            else:
                _log.debug('open file resource limit increased from %d to %d',
                           soft, limit)
        if soft == hard:
            limit = soft
                
    if max_open_sockets is not None:
        configure_socket_lock(max_open_sockets)
        _log.info("maximum concurrently open sockets limited to " + str(max_open_sockets))
    elif limit is not None:
        max_open_sockets = int(limit*0.8)
        _log.info("maximum concurrently open sockets limited to " + str(max_open_sockets) + 
                  " (derived from system limits)")
        configure_socket_lock(max_open_sockets)
    else:
        configure_socket_lock()
        _log.warn("No limit set on the maximum number of concurrently open sockets. "
                  "Consider setting max_open_sockets if you plan to work with 800+ modbus devices.")
        
    
    #TODO: update the default after scalability testing.
    max_concurrent_publishes = get_config('max_concurrent_publishes', 10000)
    if max_concurrent_publishes < 1:
        _log.warn("No limit set on the maximum number of concurrent driver publishes. "
                  "Consider setting max_concurrent_publishes if you plan to work with many devices.")
    else:
        _log.info("maximum concurrent driver publishes limited to " + str(max_concurrent_publishes))
    configure_publish_lock(max_concurrent_publishes)

    vip_identity = get_config('vip_identity', 'platform.driver')
    #pop the uuid based id
    kwargs.pop('identity', None)
    driver_config_list = get_config('driver_config_list')

    class MasterDriverAgent(Agent):
        def __init__(self, **kwargs):
            super(MasterDriverAgent, self).__init__(**kwargs)
            self.instances = {}
            
        @Core.receiver('onstart')
        def starting(self, sender, **kwargs):
            env = os.environ.copy()
            env.pop('AGENT_UUID', None)
            for config_name in driver_config_list:
                _log.debug("Launching driver for config "+config_name)
                driver = DriverAgent(self, config_name)
                gevent.spawn(driver.core.run)   
                #driver.core.stop to kill an agent. 
                   
        
        def device_startup_callback(self, topic, driver):
            _log.debug("Driver hooked up for "+topic)
            topic = topic.strip('/')
            self.instances[topic] = driver
            
        @RPC.export
        def get_point(self, path, point_name):
            return self.instances[path].get_point(point_name)
        
        @RPC.export
        def set_point(self, path, point_name, value):
            return self.instances[path].set_point(point_name, value)
        
        @RPC.export
        def heart_beat(self):
            _log.debug("sending heartbeat")
            for device in self.instances.values():
                device.heart_beat()
                
            
    return MasterDriverAgent(identity=vip_identity, **kwargs)




def main(argv=sys.argv):
    '''Main method called to start the agent.'''
    #try:
    utils.vip_main(master_driver_agent)
    #except Exception:
    #    _log.exception('unhandled exception')


if __name__ == '__main__':
    # Entry point for script
    try:
        sys.exit(main())
    except KeyboardInterrupt:
        pass
