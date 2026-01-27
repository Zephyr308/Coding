#ifndef BSP_H
#define BSP_H

#include <stddef.h>

void BSP_Init(void);
int  BSP_ReadADC(void);
void BSP_ControlOutput(int value);
void BSP_ProcessCommand(char *cmd, size_t len);
void BSP_WriteLog(void);
void BSP_ToggleLED(void);
void BSP_ErrorHandler(void);

#endif
