#include "hal_adc.h"

/* Simulated ADC register (hardware abstraction) */
#define ADC_REG (*((volatile unsigned int*)0x40012400))

#define ADC_MAX 4095.0f
#define VREF    3.3f

/* Convert raw ADC → temperature */
float hal_adc_read_temp(void)
{
    unsigned int raw = ADC_REG;

    float voltage = (raw / ADC_MAX) * VREF;

    /* TMP36 conversion model */
    return (voltage - 0.5f) * 100.0f;
}
