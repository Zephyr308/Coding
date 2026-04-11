#include "safety.h"
#include <math.h>
#include "../config/system_config.h"

system_state_t system_state = SYSTEM_OK;

/* Previous sensor value */
static float prev_temp = 0;
static int stuck_counter = 0;

/* =========================
 * OVER-TEMPERATURE CHECK
 * ========================= */
void safety_check(float temp)
{
    if(temp > MAX_SAFE_TEMP)
    {
        system_state = FAULT_OVERTEMP;
    }
}

/* =========================
 * SENSOR VALIDATION
 * ========================= */
void sensor_check(float temp)
{
    /* Range validation */
    if(temp < -20 || temp > 150)
    {
        system_state = FAULT_SENSOR;
    }

    /* Stuck sensor detection */
    if(fabs(temp - prev_temp) < 0.01f)
    {
        stuck_counter++;
    }
    else
    {
        stuck_counter = 0;
    }

    if(stuck_counter > 100)
    {
        system_state = FAULT_SENSOR;
    }

    prev_temp = temp;
}
