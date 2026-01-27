#ifndef APP_QUEUES_H
#define APP_QUEUES_H

#include "queue.h"
#include "stream_buffer.h"
#include "semphr.h"

/* Global RTOS objects */
extern QueueHandle_t sensorQueue;
extern StreamBufferHandle_t uartStreamBuffer;
extern SemaphoreHandle_t storageMutex;

void App_Queues_Init(void);

#endif
