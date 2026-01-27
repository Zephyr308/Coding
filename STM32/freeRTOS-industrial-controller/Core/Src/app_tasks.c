#include "app_tasks.h"
#include "app_queues.h"
#include "app_events.h"
#include "bsp.h"

#include "queue.h"
#include "event_groups.h"

/* ---------------- Task Handles ---------------- */
TaskHandle_t SensorTaskHandle = NULL;
static TaskHandle_t ControlTaskHandle;
static TaskHandle_t CommsTaskHandle;
static TaskHandle_t LoggerTaskHandle;

/* ---------------- Static Allocation ---------------- */
static StaticTask_t SensorTCB, ControlTCB, CommsTCB, LoggerTCB;
static StackType_t SensorStack[256];
static StackType_t ControlStack[256];
static StackType_t CommsStack[384];
static StackType_t LoggerStack[384];

/* ---------------- Task Prototypes ---------------- */
static void SensorTask(void *argument);
static void ControlTask(void *argument);
static void CommsTask(void *argument);
static void LoggerTask(void *argument);

void App_Tasks_Init(void)
{
    SensorTaskHandle = xTaskCreateStatic(
        SensorTask, "Sensor",
        256, NULL, 3,
        SensorStack, &SensorTCB);

    ControlTaskHandle = xTaskCreateStatic(
        ControlTask, "Control",
        256, NULL, 4,
        ControlStack, &ControlTCB);

    CommsTaskHandle = xTaskCreateStatic(
        CommsTask, "Comms",
        384, NULL, 2,
        CommsStack, &CommsTCB);

    LoggerTaskHandle = xTaskCreateStatic(
        LoggerTask, "Logger",
        384, NULL, 1,
        LoggerStack, &LoggerTCB);
}

/* ---------------- Sensor Task ----------------
 * Triggered by ADC ISR using task notification
 */
static void SensorTask(void *argument)
{
    for (;;)
    {
        /* Wait until ISR signals ADC conversion complete */
        ulTaskNotifyTake(pdTRUE, portMAX_DELAY);

        int sensorValue = BSP_ReadADC();

        xQueueSend(sensorQueue, &sensorValue, 0);
    }
}

/* ---------------- Control Task ---------------- */
static void ControlTask(void *argument)
{
    int sensorValue;

    for (;;)
    {
        if (xQueueReceive(sensorQueue, &sensorValue, portMAX_DELAY))
        {
            BSP_ControlOutput(sensorValue);
            xEventGroupSetBits(systemEvents, EVENT_CONTROL_OK);
        }
    }
}

/* ---------------- Communication Task ---------------- */
static void CommsTask(void *argument)
{
    char cmd[64];

    for (;;)
    {
        size_t len = xStreamBufferReceive(
            uartStreamBuffer,
            cmd,
            sizeof(cmd),
            portMAX_DELAY);

        BSP_ProcessCommand(cmd, len);
    }
}

/* ---------------- Logger Task ---------------- */
static void LoggerTask(void *argument)
{
    for (;;)
    {
        xEventGroupWaitBits(systemEvents,
                            EVENT_LOG_REQUEST,
                            pdTRUE,
                            pdFALSE,
                            portMAX_DELAY);

        xSemaphoreTake(storageMutex, portMAX_DELAY);
        BSP_WriteLog();
        xSemaphoreGive(storageMutex);
    }
}
