# STM32 FreeRTOS – Smart Industrial Controller

## Overview
This project demonstrates a **clean, industry-style FreeRTOS firmware architecture**
implemented on **STM32**.

The goal is not feature complexity, but **correct RTOS usage**, modularity,
deterministic behavior, and production-ready design patterns.

## Key Objectives
- Apply FreeRTOS concepts correctly
- Use static allocation (industry & safety friendly)
- Demonstrate ISR → task synchronization
- Maintain clean separation of concerns
- Provide clear documentation for design decisions

## RTOS Features Used
- Tasks & priorities
- Queues
- Event groups
- Stream buffers
- Mutexes (priority inheritance)
- Software timers
- Task notifications (ISR → task)
- Static allocation
- Runtime hooks & assertions

## Firmware Architecture
```yaml
main()
├── BSP_Init()
├── RTOS Objects Init
├── Task Creation
└── vTaskStartScheduler()
```

See `/docs/architecture.md` for details.

## Task Overview

| Task | Priority | Purpose |
|----|----|----|
| ControlTask | High | Deterministic control logic |
| SensorTask | Medium | Periodic sensor sampling |
| CommsTask | Medium | UART command handling |
| LoggerTask | Low | Deferred logging |

## Hardware
- MCU: STM32 (generic – CubeIDE compatible)
- HAL-based BSP layer

## Build
- STM32CubeIDE
- FreeRTOS (CMSIS-FreeRTOS optional)

## Safety & Reliability
- Static allocation only
- Stack overflow & malloc failure hooks
- Correct interrupt priority configuration
- Assertions enabled

## Status
✅ Stable skeleton  
🚧 Extendable for CAN / MODBUS / Ethernet

## License
MIT

