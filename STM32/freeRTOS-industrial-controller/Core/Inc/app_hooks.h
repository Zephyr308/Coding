#ifndef APP_HOOKS_H
#define APP_HOOKS_H

void vApplicationStackOverflowHook(TaskHandle_t xTask, char *pcTaskName);
void vApplicationMallocFailedHook(void);

#endif
