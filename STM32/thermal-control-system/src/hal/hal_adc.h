#ifndef HAL_ADC_H
#define HAL_ADC_H

/* =========================
 * ADC HARDWARE ABSTRACTION
 * ========================= */

void hal_adc_init(void);

/* Returns temperature in Celsius */
float hal_adc_read_temp(void);

#endif
