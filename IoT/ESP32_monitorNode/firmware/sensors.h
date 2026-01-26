#ifndef SENSORS_H
#define SENSORS_H

struct SensorData {
    float temperature;
    float current;
    float vibration;
    bool fault;
};

void sensorsInit();
SensorData sensorsRead();

#endif
