#include <Arduino.h>

#include "State.h"

String bayStatus = "FREE";

float voltage = 0.0, current = 0.0, power = 0.0, energyWh = 0.0, temperature = 0.0;

unsigned long sessionStartMs = 0;

// Edge AI variables

float predictedArrivalProb = 0.0;

int predictedDurationMin = 0;

int lastHourOfDay = 12;

int peakTariffStartHr = 1;
bool manualOverrideActive = false;
int peakTariffEndHr = 21;

float predictionThreshold = 0.5f;

float overloadCurrentA = 32.0f;


float maxStationLoadW = 16.0f;

unsigned long DUTY_CYCLE_WINDOW_MS = 2000UL;

// Tracks whether this bay is currently in an overload condition.

bool overloadActive = false;

int throttleLevel = 100;

// Shared optimization decision maintained by the application state.

String loadDecision = "ALLOW";