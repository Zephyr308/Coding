#include "bsp.h"
#include "app_tasks.h"   /* For SensorTaskHandle */
#include "FreeRTOS.h"
#include "task.h

/* Stubbed BSP for portability */

void BSP_Init(void) {}

int BSP_ReadADC(void)
{
    return 123; /* dummy value */
}

void BSP_ControlOutput(int value)
{
    (void)value;
}

void BSP_ProcessCommand(char *cmd, size_t len)
{
    (void)cmd;
    (void)len;
}

void BSP_WriteLog(void) {}

void BSP_ToggleLED(void) {}

void BSP_ErrorHandler(void)
{
    while (1) {}
}

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc)
{
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    /* Notify SensorTask that ADC conversion is complete */
    vTaskNotifyGiveFromISR(SensorTaskHandle,
                           &xHigherPriorityTaskWoken);

    /* Perform context switch if SensorTask has higher priority */
    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}

