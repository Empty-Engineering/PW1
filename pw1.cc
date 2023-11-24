//Arduino program to Measure temperature input from 18B20, TSIC301, and PT1000 temperature sensors on an ESP32 and send the data over serial
#define plat_in 33
#define TSIC301_in 32
#define T18B20_in 35

#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <WiFi.h>
#include <PubSubClient.h>
#include <Wire.h>

void setup(){
    pinMode(plat_in, INPUT);
    pinMode(TSIC_in, INPUT);
    pinMode(T18B20_in, INPUT);
    Serial.begin(9600);
}
void loop(){
    float plat_temp = analogRead(plat_in);
    float T01C_temp = analogRead(T01C_in);
    float T18B20_temp = analogRead(T18B20_in);
    //PT1000 split by 330 ohm resistor, 5v input, the sensor is 100 ohm at 0C.
    float plat_temp_C = (plat_temp/4095)*5*100 - 273.15;
    //TSIC 301 unsplit, 5v input
    float T01C_temp_C = (T01C_temp/4095)*5*100 - 273.15;
    //18B20 unplit, 5v input
    float T18B20_temp_C = (T18B20_temp/4095)*5*100 - 273.15;
    Serial.print("Platinum: ");
    Serial.print(plat_temp_C);
    Serial.print(" TSIC301: ");
    Serial.print(T01C_temp_C);
    Serial.print(" 18B20: ");
    Serial.println(T18B20_temp_C);
    delay(1000);
}


