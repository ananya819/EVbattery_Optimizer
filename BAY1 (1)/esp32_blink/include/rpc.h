#ifndef RPC_H
#define RPC_H

#include <Arduino.h>

// Handles incoming MQTT RPC requests
void handleRpc(String requestId, char* payload);
extern bool manualOverrideActive;
#endif // RPC_H