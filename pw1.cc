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
    pinMode(TSIC301_in, INPUT);
    pinMode(T18B20_in, INPUT);
    Serial.begin(9600);

void loop(){
    float plat = analogRead(plat_in);
    float TSIC301 = analogRead(TSIC301_in);
    float T18B20 = analogRead(T18B20_in);
    Serial.print("Platinum: ");
    Serial.print(plat);
    Serial.print("TSIC301: ");
    Serial.print(TSIC301);
    Serial.print("T18B20: ");
    Serial.print(T18B20);
    delay(1000);
}
