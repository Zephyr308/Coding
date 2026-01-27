#include "app_queues.h"

/* ---------------- Static Storage ---------------- */
static uint8_t sensorQueueStorage[8 * sizeof(int)];
static StaticQueue_t sensorQueueStruct;

static uint8_t uartStreamStorage[128];
static StaticStreamBuffer_t uartStreamStruct;

static StaticSemaphore_t storageMutexStruct;

/* ---------------- Handles ---------------- */
QueueHandle_t sensorQueue;
StreamBufferHandle_t uartStreamBuffer;
SemaphoreHandle_t storageMutex;

void App_Queues_Init(void)
{
    sensorQueue = xQueueCreateStatic(
        8, sizeof(int),
        sensorQueueStorage,
        &sensorQueueStruct);

    uartStreamBuffer = xStreamBufferCreateStatic(
        sizeof(uartStreamStorage),
        1,
        uartStreamStorage,
        &uartStreamStruct);

    storageMutex = xSemaphoreCreateMutexStatic(&storageMutexStruct);
}
