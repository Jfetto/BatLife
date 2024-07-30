// Use this code to test for your thresholds 


#include <Arduino.h>

int sensor = A0;
int sensor_value = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("Uno has started");
  Serial.println("");
}

void loop() {
  sensor_value = analogRead(sensor);
  Serial.println(sensor_value);
  delay(2000);
}

