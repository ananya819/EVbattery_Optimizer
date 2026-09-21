#include <Arduino.h>
#include "State.h"
#include "config.h"
#include "Peripherals.h"
#include <Wifi.h>
#include "Network.h"

#include"Telemetry.h"
 
#include "model.h"
#include "edge_ai.h"
#include "optimization.h"
#include <rpc.h>


void setup()
{

    Serial.begin(115200);
    dht.begin();  // initialise sesnor
    configTime(0,0,"pool.ntp.org","time.nist.gov");
    pinMode(BTN_PLUGIN,INPUT_PULLUP);
    pinMode(BTN_PLUGOUT,INPUT_PULLUP);
    pinMode(RELAY_PIN,OUTPUT);
    pinMode(LED_GREEN,OUTPUT);
    pinMode(LED_YELLOW,OUTPUT);
    pinMode(LED_RED,OUTPUT);

    connectWiFi();

//cofig mqtt server then oard to the cloud
 // Configure MQTT server
    mqtt.setServer(MQTT_SERVER, MQTT_PORT);
    connectMQTT();
}

unsigned long now;
unsigned long last_print;
static bool lastMqttState=false;

void loop()
{

    mqtt.loop();
    //print vals every 2 sec
    now = millis();
    if((now - last_print) > 5000)
    {
        last_print = now;
         //READ DTA FROM SENSORS
         sample_sensor();
        runEdgeAIInference();
        if(manualOverrideActive==0){
        runOptimization();
    }
         publishTelemetry();
         //run ai to get prediction
         


    }
    plug_status();
    updateLeds();

    
}

