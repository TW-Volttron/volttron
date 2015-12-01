#ifndef __omc_FourZoneBuilding_h_
#define __omc_FourZoneBuilding_h_
#include "adevs.h"
#include "adevs_public_modelica_runtime.h"

/**
 * Define the input and output type of the adevs models.
 */
#ifndef OMC_ADEVS_IO_TYPE
#define OMC_ADEVS_IO_TYPE double
#endif

/**
 * Simulation code for FourZoneBuilding
 * generated by the OpenModelica Compiler.
 */
class FourZoneBuilding:
    public adevs::ode_system<OMC_ADEVS_IO_TYPE>
{
    public:
       /**
        * Constructor. New state events can be added to the model by
        * passing the number of new event conditions to the constructor
        * and then extending the state_event_func method. Your state
        * events will begin at the index returned by numStateEvents().
        * You can also set the hysteresis value for the event surfaces
        * by passing a value for eventHys.
        */
       FourZoneBuilding(int extra_state_events = 0, double eventHys = 1E-4);
       /// Destructor
       ~FourZoneBuilding();
       /// Index of the first extra state event
       int numStateEvents() const { return numZeroCrossings(); }
       /**
        * These methods are generated by the OpenModelica compiler.
        */
       void init(double* q);
       void der_func(const double* q, double* dq);
       void postStep(double* q);
       void state_event_func(const double* q, double* z);
       /**
        * These methods may be overridden by any derived class.
        */
       virtual void extra_state_event_funcs(double* z){}
       double time_event_func(const double* q);
       void internal_event(double* q, const bool* state_event);
       void external_event(double* q, double e,
           const adevs::Bag<OMC_ADEVS_IO_TYPE>& xb){}
       void confluent_event(double *q, const bool* state_event,
           const adevs::Bag<OMC_ADEVS_IO_TYPE>& xb)
       {
           internal_event(q,state_event);
       }
       void output_func(const double *q, const bool* state_event,
           adevs::Bag<OMC_ADEVS_IO_TYPE>& yb){}
       void gc_output(adevs::Bag<OMC_ADEVS_IO_TYPE>& gb){}
       /**
        * These methods are used to access variables and
        * parameters in the modelica model by name.
        */
       double getEventEpsilon() const { return epsilon; }
       double get_time() const { return timeValue; }
       double get_z1_energyUsed() const { return _z1_energyUsed; }
       double get_z2_energyUsed() const { return _z2_energyUsed; }
       double get_z3_energyUsed() const { return _z3_energyUsed; }
       double get_z4_energyUsed() const { return _z4_energyUsed; }
       double get_znoise_energyUsed() const { return _znoise_energyUsed; }
       double get_znoise_t3() const { return _znoise_t3; }
       double get_znoise_t2() const { return _znoise_t2; }
       double get_znoise_t1() const { return _znoise_t1; }
       double get_z4_t3() const { return _z4_t3; }
       double get_z4_t2() const { return _z4_t2; }
       double get_z4_t1() const { return _z4_t1; }
       double get_z3_t3() const { return _z3_t3; }
       double get_z3_t2() const { return _z3_t2; }
       double get_z3_t1() const { return _z3_t1; }
       double get_z2_t3() const { return _z2_t3; }
       double get_z2_t2() const { return _z2_t2; }
       double get_z2_t1() const { return _z2_t1; }
       double get_z1_t3() const { return _z1_t3; }
       double get_z1_t2() const { return _z1_t2; }
       double get_z1_t1() const { return _z1_t1; }
       double get_DER_z1_energyUsed() const { return _DER_z1_energyUsed; }
       double get_DER_z2_energyUsed() const { return _DER_z2_energyUsed; }
       double get_DER_z3_energyUsed() const { return _DER_z3_energyUsed; }
       double get_DER_z4_energyUsed() const { return _DER_z4_energyUsed; }
       double get_DER_znoise_energyUsed() const { return _DER_znoise_energyUsed; }
       double get_DER_znoise_t3() const { return _DER_znoise_t3; }
       double get_DER_znoise_t2() const { return _DER_znoise_t2; }
       double get_DER_znoise_t1() const { return _DER_znoise_t1; }
       double get_DER_z4_t3() const { return _DER_z4_t3; }
       double get_DER_z4_t2() const { return _DER_z4_t2; }
       double get_DER_z4_t1() const { return _DER_z4_t1; }
       double get_DER_z3_t3() const { return _DER_z3_t3; }
       double get_DER_z3_t2() const { return _DER_z3_t2; }
       double get_DER_z3_t1() const { return _DER_z3_t1; }
       double get_DER_z2_t3() const { return _DER_z2_t3; }
       double get_DER_z2_t2() const { return _DER_z2_t2; }
       double get_DER_z2_t1() const { return _DER_z2_t1; }
       double get_DER_z1_t3() const { return _DER_z1_t3; }
       double get_DER_z1_t2() const { return _DER_z1_t2; }
       double get_DER_z1_t1() const { return _DER_z1_t1; }
       #ifndef ____link_Q_get_adevs_modelica
       #define ____link_Q_get_adevs_modelica
       double get_link_Q(int i0) const { return _link_Q[i0]; }
       #endif
       

       #ifndef ____link_T_get_adevs_modelica
       #define ____link_T_get_adevs_modelica
       double get_link_T(int i0) const { return _link_T[i0]; }
       #endif
       

       double get_outdoor_d2() const { return _outdoor_d2; }
       double get_outdoor_d1() const { return _outdoor_d1; }
       double get_outdoor_dayHour() const { return _outdoor_dayHour; }
       double get_outdoor_dayCycle() const { return _outdoor_dayCycle; }
       double get_outdoor_day() const { return _outdoor_day; }
       double get_z4_pin_Q() const { return _z4_pin_Q; }
       double get_z3_pin_Q() const { return _z3_pin_Q; }
       double get_z2_pin_Q() const { return _z2_pin_Q; }
       double get_z1_pin_Q() const { return _z1_pin_Q; }
       double get_z1_d3() const { return _z1_d3; }
       double get_z2_d3() const { return _z2_d3; }
       double get_z3_d3() const { return _z3_d3; }
       double get_z4_d3() const { return _z4_d3; }
       double get_znoise_d3() const { return _znoise_d3; }
       #ifndef ____link_KInterZone_get_adevs_modelica
       #define ____link_KInterZone_get_adevs_modelica
       double get_link_KInterZone(int i0) const { return _link_KInterZone[i0]; }
       #endif
       

       double get_z1_C1() const { return _z1_C1; }
       double get_z1_C2() const { return _z1_C2; }
       double get_z1_C3() const { return _z1_C3; }
       double get_z1_K1() const { return _z1_K1; }
       double get_z1_K2() const { return _z1_K2; }
       double get_z1_K3() const { return _z1_K3; }
       double get_z1_K4() const { return _z1_K4; }
       double get_z1_K5() const { return _z1_K5; }
       double get_z1_heatHvac() const { return _z1_heatHvac; }
       double get_z1_coolHvac() const { return _z1_coolHvac; }
       double get_z2_C1() const { return _z2_C1; }
       double get_z2_C2() const { return _z2_C2; }
       double get_z2_C3() const { return _z2_C3; }
       double get_z2_K1() const { return _z2_K1; }
       double get_z2_K2() const { return _z2_K2; }
       double get_z2_K3() const { return _z2_K3; }
       double get_z2_K4() const { return _z2_K4; }
       double get_z2_K5() const { return _z2_K5; }
       double get_z2_heatHvac() const { return _z2_heatHvac; }
       double get_z2_coolHvac() const { return _z2_coolHvac; }
       double get_z3_C1() const { return _z3_C1; }
       double get_z3_C2() const { return _z3_C2; }
       double get_z3_C3() const { return _z3_C3; }
       double get_z3_K1() const { return _z3_K1; }
       double get_z3_K2() const { return _z3_K2; }
       double get_z3_K3() const { return _z3_K3; }
       double get_z3_K4() const { return _z3_K4; }
       double get_z3_K5() const { return _z3_K5; }
       double get_z3_heatHvac() const { return _z3_heatHvac; }
       double get_z3_coolHvac() const { return _z3_coolHvac; }
       double get_z4_C1() const { return _z4_C1; }
       double get_z4_C2() const { return _z4_C2; }
       double get_z4_C3() const { return _z4_C3; }
       double get_z4_K1() const { return _z4_K1; }
       double get_z4_K2() const { return _z4_K2; }
       double get_z4_K3() const { return _z4_K3; }
       double get_z4_K4() const { return _z4_K4; }
       double get_z4_K5() const { return _z4_K5; }
       double get_z4_heatHvac() const { return _z4_heatHvac; }
       double get_z4_coolHvac() const { return _z4_coolHvac; }
       double get_znoise_C1() const { return _znoise_C1; }
       double get_znoise_C2() const { return _znoise_C2; }
       double get_znoise_C3() const { return _znoise_C3; }
       double get_znoise_K1() const { return _znoise_K1; }
       double get_znoise_K2() const { return _znoise_K2; }
       double get_znoise_K3() const { return _znoise_K3; }
       double get_znoise_K4() const { return _znoise_K4; }
       double get_znoise_K5() const { return _znoise_K5; }
       double get_znoise_heatHvac() const { return _znoise_heatHvac; }
       double get_znoise_coolHvac() const { return _znoise_coolHvac; }
       int get_z1_heatStage() const { return _z1_heatStage; }
       int get_z1_coolStage() const { return _z1_coolStage; }
       int get_z2_heatStage() const { return _z2_heatStage; }
       int get_z2_coolStage() const { return _z2_coolStage; }
       int get_z3_heatStage() const { return _z3_heatStage; }
       int get_z3_coolStage() const { return _z3_coolStage; }
       int get_z4_heatStage() const { return _z4_heatStage; }
       int get_z4_coolStage() const { return _z4_coolStage; }
       int get_znoise_heatStage() const { return _znoise_heatStage; }
       int get_znoise_coolStage() const { return _znoise_coolStage; }
       #ifndef ____link_pb_T_get_adevs_modelica
       #define ____link_pb_T_get_adevs_modelica
       double get_link_pb_T(int i0) const { return _link_pb_T[i0]; }
       #endif
       

       #ifndef ____link_pa_T_get_adevs_modelica
       #define ____link_pa_T_get_adevs_modelica
       double get_link_pa_T(int i0) const { return _link_pa_T[i0]; }
       #endif
       

       #ifndef ____link_pa_Q_get_adevs_modelica
       #define ____link_pa_Q_get_adevs_modelica
       double get_link_pa_Q(int i0) const { return _link_pa_Q[i0]; }
       #endif
       

       #ifndef ____link_pb_Q_get_adevs_modelica
       #define ____link_pb_Q_get_adevs_modelica
       double get_link_pb_Q(int i0) const { return _link_pb_Q[i0]; }
       #endif
       

       double get_znoise_pin_T() const { return _znoise_pin_T; }
       double get_z4_pin_T() const { return _z4_pin_T; }
       double get_z3_pin_T() const { return _z3_pin_T; }
       double get_z2_pin_T() const { return _z2_pin_T; }
       double get_z1_pin_T() const { return _z1_pin_T; }
       double get_znoise_d2() const { return _znoise_d2; }
       double get_z4_d2() const { return _z4_d2; }
       double get_z3_d2() const { return _z3_d2; }
       double get_z2_d2() const { return _z2_d2; }
       double get_z1_d2() const { return _z1_d2; }
       double get_znoise_d1() const { return _znoise_d1; }
       double get_z4_d1() const { return _z4_d1; }
       double get_z3_d1() const { return _z3_d1; }
       double get_z2_d1() const { return _z2_d1; }
       double get_z1_d1() const { return _z1_d1; }
       double get_znoise_dayHour() const { return _znoise_dayHour; }
       double get_z4_dayHour() const { return _z4_dayHour; }
       double get_z3_dayHour() const { return _z3_dayHour; }
       double get_z2_dayHour() const { return _z2_dayHour; }
       double get_z1_dayHour() const { return _z1_dayHour; }
       double get_znoise_pin_Q() const { return _znoise_pin_Q; }
       
       /// These methods are for solving non-linear algebraic eqns
       // Calculate the minimization function for initializing reals
       void initial_objective_func(double* w, double* f, double lambda);
       
    private:
       // State variables
       double _z1_energyUsed; double _PRE_z1_energyUsed;
       double _z2_energyUsed; double _PRE_z2_energyUsed;
       double _z3_energyUsed; double _PRE_z3_energyUsed;
       double _z4_energyUsed; double _PRE_z4_energyUsed;
       double _znoise_energyUsed; double _PRE_znoise_energyUsed;
       double _znoise_t3; double _PRE_znoise_t3;
       double _znoise_t2; double _PRE_znoise_t2;
       double _znoise_t1; double _PRE_znoise_t1;
       double _z4_t3; double _PRE_z4_t3;
       double _z4_t2; double _PRE_z4_t2;
       double _z4_t1; double _PRE_z4_t1;
       double _z3_t3; double _PRE_z3_t3;
       double _z3_t2; double _PRE_z3_t2;
       double _z3_t1; double _PRE_z3_t1;
       double _z2_t3; double _PRE_z2_t3;
       double _z2_t2; double _PRE_z2_t2;
       double _z2_t1; double _PRE_z2_t1;
       double _z1_t3; double _PRE_z1_t3;
       double _z1_t2; double _PRE_z1_t2;
       double _z1_t1; double _PRE_z1_t1;
       // Derivative variables
       double _DER_z1_energyUsed; double _PRE_DER_z1_energyUsed;
       double _DER_z2_energyUsed; double _PRE_DER_z2_energyUsed;
       double _DER_z3_energyUsed; double _PRE_DER_z3_energyUsed;
       double _DER_z4_energyUsed; double _PRE_DER_z4_energyUsed;
       double _DER_znoise_energyUsed; double _PRE_DER_znoise_energyUsed;
       double _DER_znoise_t3; double _PRE_DER_znoise_t3;
       double _DER_znoise_t2; double _PRE_DER_znoise_t2;
       double _DER_znoise_t1; double _PRE_DER_znoise_t1;
       double _DER_z4_t3; double _PRE_DER_z4_t3;
       double _DER_z4_t2; double _PRE_DER_z4_t2;
       double _DER_z4_t1; double _PRE_DER_z4_t1;
       double _DER_z3_t3; double _PRE_DER_z3_t3;
       double _DER_z3_t2; double _PRE_DER_z3_t2;
       double _DER_z3_t1; double _PRE_DER_z3_t1;
       double _DER_z2_t3; double _PRE_DER_z2_t3;
       double _DER_z2_t2; double _PRE_DER_z2_t2;
       double _DER_z2_t1; double _PRE_DER_z2_t1;
       double _DER_z1_t3; double _PRE_DER_z1_t3;
       double _DER_z1_t2; double _PRE_DER_z1_t2;
       double _DER_z1_t1; double _PRE_DER_z1_t1;
       // Inline variables
       // Algebraic variables
        
        
        
        
        
        
        
        
       #ifndef ____link_Q_declared_adevs_modelica
       #define ____link_Q_declared_adevs_modelica
       double _link_Q[5];
       #endif
       
        #ifndef ____PRE_link_Q_declared_adevs_modelica
       #define ____PRE_link_Q_declared_adevs_modelica
       double _PRE_link_Q[5];
       #endif
       

       #ifndef ____link_T_declared_adevs_modelica
       #define ____link_T_declared_adevs_modelica
       double _link_T[5];
       #endif
       
        #ifndef ____PRE_link_T_declared_adevs_modelica
       #define ____PRE_link_T_declared_adevs_modelica
       double _PRE_link_T[5];
       #endif
       

       double _outdoor_d2; double _PRE_outdoor_d2;
       double _outdoor_d1; double _PRE_outdoor_d1;
       double _outdoor_dayHour; double _PRE_outdoor_dayHour;
       double _outdoor_dayCycle; double _PRE_outdoor_dayCycle;
       double _outdoor_day; double _PRE_outdoor_day;
       double _z4_pin_Q; double _PRE_z4_pin_Q;
       double _z3_pin_Q; double _PRE_z3_pin_Q;
       double _z2_pin_Q; double _PRE_z2_pin_Q;
       double _z1_pin_Q; double _PRE_z1_pin_Q;
       double _z1_d3; double _PRE_z1_d3;
       double _z2_d3; double _PRE_z2_d3;
       double _z3_d3; double _PRE_z3_d3;
       double _z4_d3; double _PRE_z4_d3;
       double _znoise_d3; double _PRE_znoise_d3;
       // Integer algebraic variables
       // Boolean algebraic variables
       // Alias variables
        
        
        
        
        
       #ifndef ____link_pb_T_declared_adevs_modelica
       #define ____link_pb_T_declared_adevs_modelica
       double _link_pb_T[5];
       #endif
       
        #ifndef ____PRE_link_pb_T_declared_adevs_modelica
       #define ____PRE_link_pb_T_declared_adevs_modelica
       double _PRE_link_pb_T[5];
       #endif
       

        
       #ifndef ____link_pa_T_declared_adevs_modelica
       #define ____link_pa_T_declared_adevs_modelica
       double _link_pa_T[5];
       #endif
       
        #ifndef ____PRE_link_pa_T_declared_adevs_modelica
       #define ____PRE_link_pa_T_declared_adevs_modelica
       double _PRE_link_pa_T[5];
       #endif
       

        
        
        
        
        
        
        
        
        
        
       #ifndef ____link_pa_Q_declared_adevs_modelica
       #define ____link_pa_Q_declared_adevs_modelica
       double _link_pa_Q[5];
       #endif
       
        #ifndef ____PRE_link_pa_Q_declared_adevs_modelica
       #define ____PRE_link_pa_Q_declared_adevs_modelica
       double _PRE_link_pa_Q[5];
       #endif
       

       #ifndef ____link_pb_Q_declared_adevs_modelica
       #define ____link_pb_Q_declared_adevs_modelica
       double _link_pb_Q[5];
       #endif
       
        #ifndef ____PRE_link_pb_Q_declared_adevs_modelica
       #define ____PRE_link_pb_Q_declared_adevs_modelica
       double _PRE_link_pb_Q[5];
       #endif
       

       double _znoise_pin_T; double _PRE_znoise_pin_T;
       double _z4_pin_T; double _PRE_z4_pin_T;
       double _z3_pin_T; double _PRE_z3_pin_T;
       double _z2_pin_T; double _PRE_z2_pin_T;
       double _z1_pin_T; double _PRE_z1_pin_T;
       double _znoise_d2; double _PRE_znoise_d2;
       double _z4_d2; double _PRE_z4_d2;
       double _z3_d2; double _PRE_z3_d2;
       double _z2_d2; double _PRE_z2_d2;
       double _z1_d2; double _PRE_z1_d2;
       double _znoise_d1; double _PRE_znoise_d1;
       double _z4_d1; double _PRE_z4_d1;
       double _z3_d1; double _PRE_z3_d1;
       double _z2_d1; double _PRE_z2_d1;
       double _z1_d1; double _PRE_z1_d1;
       double _znoise_dayHour; double _PRE_znoise_dayHour;
       double _z4_dayHour; double _PRE_z4_dayHour;
       double _z3_dayHour; double _PRE_z3_dayHour;
       double _z2_dayHour; double _PRE_z2_dayHour;
       double _z1_dayHour; double _PRE_z1_dayHour;
       double _znoise_pin_Q; double _PRE_znoise_pin_Q;
       // Integer alias variables
       // Boolean alias variables
       // Parameter variables
       #ifndef ____link_KInterZone_declared_adevs_modelica
       #define ____link_KInterZone_declared_adevs_modelica
       double _link_KInterZone[5];
       #endif
       
        #ifndef ____PRE_link_KInterZone_declared_adevs_modelica
       #define ____PRE_link_KInterZone_declared_adevs_modelica
       double _PRE_link_KInterZone[5];
       #endif
       

        
        
        
        
       double _z1_C1; double _PRE_z1_C1;
       double _z1_C2; double _PRE_z1_C2;
       double _z1_C3; double _PRE_z1_C3;
       double _z1_K1; double _PRE_z1_K1;
       double _z1_K2; double _PRE_z1_K2;
       double _z1_K3; double _PRE_z1_K3;
       double _z1_K4; double _PRE_z1_K4;
       double _z1_K5; double _PRE_z1_K5;
       double _z1_heatHvac; double _PRE_z1_heatHvac;
       double _z1_coolHvac; double _PRE_z1_coolHvac;
       double _z2_C1; double _PRE_z2_C1;
       double _z2_C2; double _PRE_z2_C2;
       double _z2_C3; double _PRE_z2_C3;
       double _z2_K1; double _PRE_z2_K1;
       double _z2_K2; double _PRE_z2_K2;
       double _z2_K3; double _PRE_z2_K3;
       double _z2_K4; double _PRE_z2_K4;
       double _z2_K5; double _PRE_z2_K5;
       double _z2_heatHvac; double _PRE_z2_heatHvac;
       double _z2_coolHvac; double _PRE_z2_coolHvac;
       double _z3_C1; double _PRE_z3_C1;
       double _z3_C2; double _PRE_z3_C2;
       double _z3_C3; double _PRE_z3_C3;
       double _z3_K1; double _PRE_z3_K1;
       double _z3_K2; double _PRE_z3_K2;
       double _z3_K3; double _PRE_z3_K3;
       double _z3_K4; double _PRE_z3_K4;
       double _z3_K5; double _PRE_z3_K5;
       double _z3_heatHvac; double _PRE_z3_heatHvac;
       double _z3_coolHvac; double _PRE_z3_coolHvac;
       double _z4_C1; double _PRE_z4_C1;
       double _z4_C2; double _PRE_z4_C2;
       double _z4_C3; double _PRE_z4_C3;
       double _z4_K1; double _PRE_z4_K1;
       double _z4_K2; double _PRE_z4_K2;
       double _z4_K3; double _PRE_z4_K3;
       double _z4_K4; double _PRE_z4_K4;
       double _z4_K5; double _PRE_z4_K5;
       double _z4_heatHvac; double _PRE_z4_heatHvac;
       double _z4_coolHvac; double _PRE_z4_coolHvac;
       double _znoise_C1; double _PRE_znoise_C1;
       double _znoise_C2; double _PRE_znoise_C2;
       double _znoise_C3; double _PRE_znoise_C3;
       double _znoise_K1; double _PRE_znoise_K1;
       double _znoise_K2; double _PRE_znoise_K2;
       double _znoise_K3; double _PRE_znoise_K3;
       double _znoise_K4; double _PRE_znoise_K4;
       double _znoise_K5; double _PRE_znoise_K5;
       double _znoise_heatHvac; double _PRE_znoise_heatHvac;
       double _znoise_coolHvac; double _PRE_znoise_coolHvac;
       // Integer parameter variables
       int _z1_heatStage; int _PRE_z1_heatStage;
       int _z1_coolStage; int _PRE_z1_coolStage;
       int _z2_heatStage; int _PRE_z2_heatStage;
       int _z2_coolStage; int _PRE_z2_coolStage;
       int _z3_heatStage; int _PRE_z3_heatStage;
       int _z3_coolStage; int _PRE_z3_coolStage;
       int _z4_heatStage; int _PRE_z4_heatStage;
       int _z4_coolStage; int _PRE_z4_coolStage;
       int _znoise_heatStage; int _PRE_znoise_heatStage;
       int _znoise_coolStage; int _PRE_znoise_coolStage;
       // Boolean parameter variables
       // String variables
       // String parameters
       // External object variables
       // Constants
       // Integer constants
       // Boolean constants
       // String constants

       
       double epsilon;
       // These must be accessed via a pointer to localVal
       double timeValue, _PRE_timeValue;
       // Are we at an event?
       bool atEvent;
       // Are we initializing the model?
       bool atInit;
       
       // Zero crossing variables
       int *zc;
       int numZeroCrossings() const {
            return numRelations()+2*numMathEvents();
       }
       int numRelations() const { return 0; }
       int numMathEvents() const { return 1; }
       
       // Initial unknowns via solution to least squares
       void solve_for_initial_unknowns();
       std::vector<double*> init_unknown_vars;
       void bound_params();
       void save_vars();
       void restore_vars();
       void clear_event_flags();
       bool check_for_new_events();
       bool initial() const { return atInit; }
       
       void calc_vars(const double* q = NULL, bool doReinit = false);
       
       AdevsSampleData** samples;
       int numTimeEvents() const { return 0; }
       bool sample(int index, double tStart, double tInterval);
       
       AdevsDelayData** delays;
       int numDelays() const { return 0; }
       double calcDelay(int index, double expr, double t, double delay);
       void saveDelay(int index, double expr, double t, double maxdelay);
       
       AdevsMathEventFunc** eventFuncs;
       double floor(double expr, int index);
       double div(double x, double y, int index);
       int integer(double expr, int index);
       double ceil(double expr, int index);
       
       bool selectStateVars();
       
    protected:
       /**
        * Calculate the values of the state and algebraic variables.
        * State variables will be initialized to q if provided,
        * or left unchanged if not. This should be called after your
        * event handler modifies any state variables that
        * appear in the Modelica equations.
        */
       void update_vars(const double* q = NULL, bool doReinit = false)
       {
           calc_vars(q,doReinit);
           for (int i = 0; i < numMathEvents(); i++)
              if (eventFuncs[i] != NULL)
                 eventFuncs[i]->setInit(false);
           save_vars();
       }
       /**
         * These methods may be used to change paramters
         * and state variables at events. Remember to call
         * update_vars(q,true) if you change anything.
         */
       void set_z1_energyUsed(double val) { _z1_energyUsed = val; }
       void set_z2_energyUsed(double val) { _z2_energyUsed = val; }
       void set_z3_energyUsed(double val) { _z3_energyUsed = val; }
       void set_z4_energyUsed(double val) { _z4_energyUsed = val; }
       void set_znoise_energyUsed(double val) { _znoise_energyUsed = val; }
       void set_znoise_t3(double val) { _znoise_t3 = val; }
       void set_znoise_t2(double val) { _znoise_t2 = val; }
       void set_znoise_t1(double val) { _znoise_t1 = val; }
       void set_z4_t3(double val) { _z4_t3 = val; }
       void set_z4_t2(double val) { _z4_t2 = val; }
       void set_z4_t1(double val) { _z4_t1 = val; }
       void set_z3_t3(double val) { _z3_t3 = val; }
       void set_z3_t2(double val) { _z3_t2 = val; }
       void set_z3_t1(double val) { _z3_t1 = val; }
       void set_z2_t3(double val) { _z2_t3 = val; }
       void set_z2_t2(double val) { _z2_t2 = val; }
       void set_z2_t1(double val) { _z2_t1 = val; }
       void set_z1_t3(double val) { _z1_t3 = val; }
       void set_z1_t2(double val) { _z1_t2 = val; }
       void set_z1_t1(double val) { _z1_t1 = val; }
       #ifndef ____link_KInterZone_set_adevs_modelica
       #define ____link_KInterZone_set_adevs_modelica
       void set_link_KInterZone(double val, int i0) { _link_KInterZone[i0] = val; }
       #endif
       

       void set_z1_C1(double val) { _z1_C1 = val; }
       void set_z1_C2(double val) { _z1_C2 = val; }
       void set_z1_C3(double val) { _z1_C3 = val; }
       void set_z1_K1(double val) { _z1_K1 = val; }
       void set_z1_K2(double val) { _z1_K2 = val; }
       void set_z1_K3(double val) { _z1_K3 = val; }
       void set_z1_K4(double val) { _z1_K4 = val; }
       void set_z1_K5(double val) { _z1_K5 = val; }
       void set_z1_heatHvac(double val) { _z1_heatHvac = val; }
       void set_z1_coolHvac(double val) { _z1_coolHvac = val; }
       void set_z2_C1(double val) { _z2_C1 = val; }
       void set_z2_C2(double val) { _z2_C2 = val; }
       void set_z2_C3(double val) { _z2_C3 = val; }
       void set_z2_K1(double val) { _z2_K1 = val; }
       void set_z2_K2(double val) { _z2_K2 = val; }
       void set_z2_K3(double val) { _z2_K3 = val; }
       void set_z2_K4(double val) { _z2_K4 = val; }
       void set_z2_K5(double val) { _z2_K5 = val; }
       void set_z2_heatHvac(double val) { _z2_heatHvac = val; }
       void set_z2_coolHvac(double val) { _z2_coolHvac = val; }
       void set_z3_C1(double val) { _z3_C1 = val; }
       void set_z3_C2(double val) { _z3_C2 = val; }
       void set_z3_C3(double val) { _z3_C3 = val; }
       void set_z3_K1(double val) { _z3_K1 = val; }
       void set_z3_K2(double val) { _z3_K2 = val; }
       void set_z3_K3(double val) { _z3_K3 = val; }
       void set_z3_K4(double val) { _z3_K4 = val; }
       void set_z3_K5(double val) { _z3_K5 = val; }
       void set_z3_heatHvac(double val) { _z3_heatHvac = val; }
       void set_z3_coolHvac(double val) { _z3_coolHvac = val; }
       void set_z4_C1(double val) { _z4_C1 = val; }
       void set_z4_C2(double val) { _z4_C2 = val; }
       void set_z4_C3(double val) { _z4_C3 = val; }
       void set_z4_K1(double val) { _z4_K1 = val; }
       void set_z4_K2(double val) { _z4_K2 = val; }
       void set_z4_K3(double val) { _z4_K3 = val; }
       void set_z4_K4(double val) { _z4_K4 = val; }
       void set_z4_K5(double val) { _z4_K5 = val; }
       void set_z4_heatHvac(double val) { _z4_heatHvac = val; }
       void set_z4_coolHvac(double val) { _z4_coolHvac = val; }
       void set_znoise_C1(double val) { _znoise_C1 = val; }
       void set_znoise_C2(double val) { _znoise_C2 = val; }
       void set_znoise_C3(double val) { _znoise_C3 = val; }
       void set_znoise_K1(double val) { _znoise_K1 = val; }
       void set_znoise_K2(double val) { _znoise_K2 = val; }
       void set_znoise_K3(double val) { _znoise_K3 = val; }
       void set_znoise_K4(double val) { _znoise_K4 = val; }
       void set_znoise_K5(double val) { _znoise_K5 = val; }
       void set_znoise_heatHvac(double val) { _znoise_heatHvac = val; }
       void set_znoise_coolHvac(double val) { _znoise_coolHvac = val; }
       void set_z1_heatStage(int val) { _z1_heatStage = val; }
       void set_z1_coolStage(int val) { _z1_coolStage = val; }
       void set_z2_heatStage(int val) { _z2_heatStage = val; }
       void set_z2_coolStage(int val) { _z2_coolStage = val; }
       void set_z3_heatStage(int val) { _z3_heatStage = val; }
       void set_z3_coolStage(int val) { _z3_coolStage = val; }
       void set_z4_heatStage(int val) { _z4_heatStage = val; }
       void set_z4_coolStage(int val) { _z4_coolStage = val; }
       void set_znoise_heatStage(int val) { _znoise_heatStage = val; }
       void set_znoise_coolStage(int val) { _znoise_coolStage = val; }
 };

 #endif

