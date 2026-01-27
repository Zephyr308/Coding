# Safety & Fault Handling

## Hooks Enabled
- `vApplicationStackOverflowHook()` → Detects task stack overflow.
- `vApplicationMallocFailedHook()` → Detects memory allocation failure.
- `configASSERT()` → Catches critical misconfigurations early.

## Runtime Behavior
- Any hook triggers `BSP_ErrorHandler()` → Halts system safely.
- Ensures deterministic and predictable failure.
- No silent corruption.

## Interrupt Priority Rules
- All ISRs calling FreeRTOS APIs must have priority ≥ `configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY`.
- Ensures RTOS kernel stability and deterministic behavior.
