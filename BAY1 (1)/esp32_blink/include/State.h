#ifndef STATE_H
#define STATE_H

#include <Arduino.h>
// ---------------------------------------------------------------------
// Live bay state
// ---------------------------------------------------------------------
extern String bayStatus;
extern float voltage, current, power, energyWh, temperature;

extern unsigned long sessionStartMs;
// ---------------------------------------------------------------------
// Timing / debounce bookkeeping
// ---------------------------------------------------------------------
//edge ai variables 
extern float predictedArrivalProb;
extern int predictedDurationMin;
extern int lastHourOfDay;

extern int peakTariffStartHr;
extern bool manualOverrideActive;
extern int peakTariffEndHr;
extern float predictionThreshold;
extern float overloadCurrentA;
extern float maxStationLoadW;
extern unsigned long DUTY_CYCLE_WINDOW_MS;

// Tracks whether this bay is currently in an overload condition.
extern bool overloadActive;
extern int throttleLevel;

// Shared optimization decision maintained by the application state.
extern String loadDecision;


#endif