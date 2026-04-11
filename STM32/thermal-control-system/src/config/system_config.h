#ifndef SYSTEM_CONFIG_H
#define SYSTEM_CONFIG_H

/* =========================
 * SYSTEM CONFIGURATION
 * ========================= */

#define TARGET_TEMP_C       60.0f
#define MAX_SAFE_TEMP       80.0f

#define CONTROL_LOOP_HZ     1000
#define DT                  (1.0f / CONTROL_LOOP_HZ)

/* PID gains */
#define KP 2.0f
#define KI 0.5f
#define KD 0.1f

#endif
