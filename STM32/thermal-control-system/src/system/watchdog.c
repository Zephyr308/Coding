#include "watchdog.h"

/* =========================
 * WATCHDOG TIMER
 * ========================= */

void watchdog_init(void)
{
    IWDG_KR = 0x5555;
    IWDG_PR = 0x06;
    IWDG_RLR = 1000;
    IWDG_KR = 0xCCCC;
}

void watchdog_kick(void)
{
    IWDG_KR = 0xAAAA;
}
