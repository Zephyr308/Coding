#include "sensors.h"
#include "config.h"
#include <Arduino.h>

void sensorsInit() {
    // Initialize ADCs / I2C / OneWire here
    analogReadResolution(12);
}

SensorData sensorsRead() {
    SensorData data;

    // ---- Simulated values (replace with real sensors) ----
    data.temperature = 55.0 + random(-5, 5) * 0.1;
    data.current     = 2.5 + random(-5, 5) * 0.1;
    data.vibration   = 0.6 + random(-5, 5) * 0.05;

    // ---- Edge Fault Detection ----
    data.fault = (data.temperature > TEMP_LIMIT_C ||
                  data.current > CURRENT_LIMIT_A ||
                  data.vibration > VIB_LIMIT);

    return data;
}
