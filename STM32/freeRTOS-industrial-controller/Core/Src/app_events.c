#include "app_events.h"

static StaticEventGroup_t systemEventsStruct;
EventGroupHandle_t systemEvents;

void App_Events_Init(void)
{
    systemEvents = xEventGroupCreateStatic(&systemEventsStruct);
}
