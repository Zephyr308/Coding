#include "state_machine.h"
#include "../config/system_config.h"
#include "../safety/safety.h"

/* Current system state */
system_mode_t current_state = STATE_INIT;

/* User input simulation */
int user_start_pressed(void)
{
    return 1; /* simulate always ON for demo */
}

/* =========================
 * STATE MACHINE LOGIC
 * ========================= */
void state_machine_update(float temp)
{
    switch(current_state)
    {
        case STATE_INIT:
            current_state = STATE_IDLE;
            break;

        case STATE_IDLE:
            if(user_start_pressed())
                current_state = STATE_HEATING;
            break;

        case STATE_HEATING:
            if(system_state != SYSTEM_OK)
                current_state = STATE_FAULT;

            if(temp >= TARGET_TEMP_C - 2)
                current_state = STATE_STABLE;
            break;

        case STATE_STABLE:
            if(system_state != SYSTEM_OK)
                current_state = STATE_FAULT;
            break;

        case STATE_FAULT:
            /* locked state */
            break;
    }
}
