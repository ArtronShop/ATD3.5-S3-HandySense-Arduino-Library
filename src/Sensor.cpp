#include <Arduino.h>
#include "Sensor.h"
#include "PinConfigs.h"
#include "UserConfigs.h"

static const char * TAG = "Sensor";

// include your sensor library
#include <Wire.h>

#include <ArtronShop_SHT45.h>
#include <ArtronShop_BH1750.h>

ArtronShop_SHT45 sht45(&Wire, 0x44); // SHT45-AD1B => 0x44
ArtronShop_BH1750 bh1750(BH1750_ADDR); // Non Jump ADDR: 0x23, Jump ADDR: 0x5C

__attribute__((weak)) void Sensor_init() { // Setup sensor (like void setup())
  Wire.begin();
  // Serial2.begin(9600, SERIAL_8N1, RS485_RX_PIN, RS485_TX_PIN);

  if (!sht45.begin()) {
    ESP_LOGE(TAG, "SHT45 not found !");
  }

  if (!bh1750.begin()) {
    ESP_LOGE(TAG, "BH1750 not found !");
  }
} 

__attribute__((weak)) bool Sensor_getTemp(float * value) { // Get Temperature from sensor in °C unit
  if (!sht45.measure()) {
    ESP_LOGE(TAG, "SHT45 read fail");
    return false;
  }
  *value = sht45.temperature();

  return true;
} 

__attribute__((weak)) bool Sensor_getHumi(float * value) { // Get Humidity from sensor in %RH unit
  *value = sht45.humidity();

  return true;
} 

__attribute__((weak)) bool Sensor_getSoil(float * value) { // Get Soil moisture from sensor in % unit
  int raw = analogRead(SOIL_PIN);
  ESP_LOGV(TAG, "A1 analog value : %d", raw);
  *value = map(raw, SOIL_ANALOG_MIN, SOIL_ANALOG_MAX, 0, 100);
  *value = constrain(*value, 0, 100);

  return true;
} 

__attribute__((weak)) bool Sensor_getLight(float * value) { // Get Light from sensor in lux uint
  *value = bh1750.light();
  if (*value < 0) {
    ESP_LOGE(TAG, "BH1750 read fail");
    return false;
  }

  return true;
}