#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

typedef enum {
    STATE_INIT,
    STATE_IDLE,
    STATE_HEATING,
    STATE_STABLE,
    STATE_FAULT
} system_mode_t;

extern system_mode_t current_state;

void state_machine_update(float temp);

#endif
