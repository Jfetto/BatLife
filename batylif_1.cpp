#include <Arduino.h>

unsigned long clock_start = 0;
unsigned long clock_end = 0;
int sensor = A0;
int sensor_value = 0;
int light_thresh_start = 50;
int light_thresh_end = 1;
bool timing = false;

void setup() {
  Serial.begin(9600);
  Serial.println("Welcome to BatLif Tester");
}

void loop() {
  sensor_value = analogRead(sensor);
  //Serial.println(sensor_value);

  if (sensor_value > light_thresh_start && timing != true) {
    clock_start = millis();
    Serial.println("Timer as started");
    timing = true;
  }

  if (sensor_value < light_thresh_end && timing == true) {
    Serial.println("Timer has ended");
    clock_end = millis();
    timing = false;

    unsigned long clock = clock_end - clock_start;
    unsigned long seconds = clock / 1000;
    unsigned long true_seconds = seconds % 60;
    unsigned long minutes = seconds / 60;
    unsigned long true_minutes = minutes % 60;
    unsigned long hours = minutes / 60;

    Serial.print("Battery has lasted for: ");
    Serial.print(hours);
    Serial.print(" Hours ");
    Serial.print(true_minutes);
    Serial.print(" Minutes ");
    Serial.print(true_seconds);
    Serial.print(" Seconds ");
    Serial.println("");
  }

  delay(100);
}
