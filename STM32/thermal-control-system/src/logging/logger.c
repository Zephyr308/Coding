#include "logger.h"

/* =========================
 * CIRCULAR LOG BUFFER
 * ========================= */

#define LOG_SIZE 256

typedef struct {
    float temp;
    float pwm;
    unsigned int timestamp;
} log_entry_t;

static log_entry_t buffer[LOG_SIZE];
static unsigned int head = 0;

/* Fake timestamp */
unsigned int get_time_ms(void)
{
    return head * 10;
}

/* Log system data */
void log_data(float temp, float pwm)
{
    buffer[head].temp = temp;
    buffer[head].pwm = pwm;
    buffer[head].timestamp = get_time_ms();

    head = (head + 1) % LOG_SIZE;
}
