#ifndef MQTT_CLIENT_H
#define MQTT_CLIENT_H

#include "sensors.h"

void mqttInit();
void mqttLoop();
void mqttPublish(const SensorData& data);
bool mqttIsConnected();

#endif
