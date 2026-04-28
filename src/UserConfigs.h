#pragma once
#include "SensorSupport.h"

// Configs use Sensor
#define SOIL_PIN        A1_PIN
#define SOIL_ANALOG_MIN (2900)
#define SOIL_ANALOG_MAX (1500)

#define BH1750_ADDR (0x23) // ADDR pin jump to GND => 0x23, ADDR pin jump to VCC => 0x5C