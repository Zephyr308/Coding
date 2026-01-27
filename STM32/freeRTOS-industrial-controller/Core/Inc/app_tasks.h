#ifndef APP_TASKS_H
#define APP_TASKS_H

#include "FreeRTOS.h"
#include "task.h"

/* Exposed task handle for ISR notification */
extern TaskHandle_t SensorTaskHandle;

void App_Tasks_Init(void);

#endif
