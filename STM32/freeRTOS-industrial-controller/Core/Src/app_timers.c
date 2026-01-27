#include "app_timers.h"
#include "FreeRTOS.h"
#include "timers.h"
#include "bsp.h"

static StaticTimer_t heartbeatTimerStruct;
static TimerHandle_t heartbeatTimer;

static void HeartbeatCallback(TimerHandle_t xTimer)
{
    BSP_ToggleLED();
}

void App_Timers_Init(void)
{
    heartbeatTimer = xTimerCreateStatic(
        "Heartbeat",
        pdMS_TO_TICKS(1000),
        pdTRUE,
        NULL,
        HeartbeatCallback,
        &heartbeatTimerStruct);

    xTimerStart(heartbeatTimer, 0);
}
