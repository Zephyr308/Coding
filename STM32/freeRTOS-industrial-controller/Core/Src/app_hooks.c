#include "app_hooks.h"
#include "bsp.h"

void vApplicationStackOverflowHook(TaskHandle_t xTask, char *pcTaskName)
{
    BSP_ErrorHandler();
}

void vApplicationMallocFailedHook(void)
{
    BSP_ErrorHandler();
}
