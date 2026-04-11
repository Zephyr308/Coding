#ifndef SAFETY_H
#define SAFETY_H

typedef enum {
    SYSTEM_OK,
    FAULT_OVERTEMP,
    FAULT_SENSOR
} system_state_t;

extern system_state_t system_state;

void safety_check(float temp);
void sensor_check(float temp);

#endif
