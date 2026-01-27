#include "bsp.h"

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
