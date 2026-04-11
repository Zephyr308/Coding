#ifndef LOGGER_H
#define LOGGER_H

/* =========================
 * LOGGER MODULE
 * =========================
 * Stores system telemetry in a circular buffer
 * for debugging and production analysis.
 */

/**
 * @brief Log temperature and PWM values
 * @param temp Current temperature (°C)
 * @param pwm  PWM duty cycle (%)
 */
void log_data(float temp, float pwm);

/**
 * @brief Get system timestamp (ms)
 * @note Currently simulated in software
 */
unsigned int get_time_ms(void);

#endif
