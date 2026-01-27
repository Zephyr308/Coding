#ifndef APP_EVENTS_H
#define APP_EVENTS_H

#include "event_groups.h"

/* Event bits */
#define EVENT_CONTROL_OK   (1 << 0)
#define EVENT_LOG_REQUEST  (1 << 1)

extern EventGroupHandle_t systemEvents;

void App_Events_Init(void);

#endif
