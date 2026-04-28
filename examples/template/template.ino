#include <Arduino.h>
#include <HandySense.h>
#include <UI.h>

void setup() {
  Serial.begin(115200);
  
  HandySense_init(); // Init HandySense, MQTT, WiFi Manager
  UI_init(); // Init LVGL and UI
}

void loop() {
  HandySense_loop();
  UI_loop();
  delay(5);
}

void Sensor_init() { // Setup sensor (like void setup())
  Serial.println("Call Sensor_init in main.cpp");
} 

bool Sensor_getTemp(float * value) { // Get Temperature from sensor in °C unit
  Serial.println("Call Sensor_getTemp in main.cpp");

  return false;
} 

bool Sensor_getHumi(float * value) { // Get Humidity from sensor in %RH unit
  Serial.println("Call Sensor_getHumi in main.cpp");

  return false;
} 

bool Sensor_getSoil(float * value) { // Get Soil moisture from sensor in % unit
  Serial.println("Call Sensor_getSoil in main.cpp");

  return false;
} 

bool Sensor_getLight(float * value) { // Get Light from sensor in lux uint
  Serial.println("Call Sensor_getLight in main.cpp");

  return false;
}
