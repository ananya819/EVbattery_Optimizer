#include <Arduino.h>
#include <DHT.h>
#include "State.h"
#include "Peripherals.h"
#include "config.h"

DHT dht(DHT_PIN, DHT_TYPE);

static float mapFloat(float value, float fromLow, float fromHigh,
                      float toLow, float toHigh)
{
    return (value - fromLow) * (toHigh - toLow) /
           (fromHigh - fromLow) + toLow;
}

void sample_sensor(void)
{
    int raw_current = analogRead(CURRENT_PIN); // 0 to 4095 0 32A
    int raw_voltage = analogRead(VOLTAGE_PIN); // 0 to 4095 0 to 250 v

    //map oltage 0 to 250
     voltage=mapFloat(raw_voltage,0,4095,0,250);
     if(bayStatus=="CHARGING"){

     
     current=mapFloat(raw_current,0,4095,0,250);}
     
     //read current and 5 values array to find out the avg



     //calulte power
     power=voltage*current;

    // To read temperature
   float  t = dht.readTemperature();
    //valid it
    if(!(isnan(t))) temperature=t;



    Serial.print("current POT value: ");
    Serial.println(current);

    Serial.print("Voltage POT value: ");
    Serial.println(voltage);

    if (isnan(temperature))
    {
        Serial.println("ERROR in reading the Temperature");
    }
    else
    {
        Serial.print("Temperature reading is: ");
        Serial.print(temperature, 1);
        Serial.println(" C");
    }
}

float recentAvgCurrent(void){
float sum=0;
for(int i=0;i<5;i++){
    sum=sum+current;
    


}
return sum/5;


}






bool plugin_flag = 1;
bool plugout_flag = 1;

void plug_status(void)
{

    // ---------------- PLUG IN ----------------
    bool pluginReading = digitalRead(BTN_PLUGIN);

    if (pluginReading == LOW && plugin_flag)
    {
        //session time 
        sessionStartMs= millis();
        // Switch is pressed
        plugin_flag = 0;

        // Change bay_status FREE to CHARGING
        if (bayStatus == "FREE")
        {
            bayStatus = "CHARGING";
            Serial.println("Bay1 PLUGIN DETECTED, BAY IS CHARGING");
        }
    }

    if (pluginReading == HIGH)
    {
        plugin_flag = 1;
    }

    // ---------------- PLUG OUT ----------------
    bool plugoutReading = digitalRead(BTN_PLUGOUT);

    if (plugoutReading == LOW && plugout_flag)
    {
        // Switch is pressed
        plugout_flag = 0;

        // Change bay_status CHARGING to FREE
        if (bayStatus == "CHARGING")
        {
            bayStatus = "FREE";
            Serial.println("Bay1 PLUGOUT DETECTED, BAY IS FREE");
            digitalWrite(RELAY_PIN,HIGH);//TURN ON THE RELAY
         }
    }

    if (plugoutReading == HIGH)
    {
        plugout_flag = 1;
    }
}
void update_led_status(void){
   //turn on green if chargin else red AND YELLOW
   if(bayStatus=="FREE"){
      digitalWrite(LED_GREEN,HIGH);
      digitalWrite(LED_YELLOW,LOW);
   }
   else{
       digitalWrite(LED_GREEN,LOW);
       digitalWrite(LED_YELLOW,HIGH);

   }

}