#include "hal_pwm.h"

/* Simulated PWM register */
#define PWM_REG (*((volatile unsigned int*)0x40010000))

void hal_pwm_set_duty(float duty_percent)
{
    if(duty_percent > 100) duty_percent = 100;
    if(duty_percent < 0) duty_percent = 0;

    PWM_REG = (unsigned int)duty_percent;
}
