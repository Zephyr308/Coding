# STM32 Interrupt Priority Rules

Any ISR calling FreeRTOS APIs must have priority:

Numerically >= configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY

Violation can cause:
- HardFault
- Random lockups
- Corrupted scheduler state
