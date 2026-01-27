#include "main.h"
#include "FreeRTOS.h"
#include "task.h"

#include "app_tasks.h"
#include "app_queues.h"
#include "app_events.h"
#include "app_timers.h"
#include "bsp.h"

int main(void)
{
    HAL_Init();
    SystemClock_Config();

    BSP_Init();

    App_Queues_Init();
    App_Events_Init();
    App_Timers_Init();
    App_Tasks_Init();

    vTaskStartScheduler();

    while (1) {}
}
