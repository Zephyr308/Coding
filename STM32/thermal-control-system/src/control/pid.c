#include "pid.h"
#include "../config/system_config.h"

/* =========================
 * ROBUST PID CONTROLLER
 * ========================= */

static float integral = 0;
static float prev_error = 0;
static float prev_output = 0;

#define INTEGRAL_LIMIT 100.0f
#define OUTPUT_RATE_LIMIT 5.0f

float pid_compute(float target, float measured)
{
    float error = target - measured;

    /* Integral with anti-windup */
    integral += error * DT;

    if(integral > INTEGRAL_LIMIT) integral = INTEGRAL_LIMIT;
    if(integral < -INTEGRAL_LIMIT) integral = -INTEGRAL_LIMIT;

    /* Derivative */
    float derivative = (error - prev_error) / DT;

    float output = KP*error + KI*integral + KD*derivative;

    /* Clamp output */
    if(output > 100) output = 100;
    if(output < 0) output = 0;

    /* Output ramp limiting */
    float delta = output - prev_output;

    if(delta > OUTPUT_RATE_LIMIT) output = prev_output + OUTPUT_RATE_LIMIT;
    if(delta < -OUTPUT_RATE_LIMIT) output = prev_output - OUTPUT_RATE_LIMIT;

    prev_error = error;
    prev_output = output;

    return output;
}
