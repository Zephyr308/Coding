#ifndef WATCHDOG_H
#define WATCHDOG_H

/* =========================
 * WATCHDOG TIMER INTERFACE
 * =========================
 * Provides system-level fault recovery.
 * Resets MCU if not periodically refreshed.
 */

/**
 * @brief Initialize independent watchdog timer
 */
void watchdog_init(void);

/**
 * @brief Refresh (kick) watchdog timer
 * Must be called periodically when system is healthy
 */
void watchdog_kick(void);

#endif
