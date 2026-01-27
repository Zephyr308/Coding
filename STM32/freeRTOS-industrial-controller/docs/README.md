# STM32 FreeRTOS – Smart Industrial Controller

## Overview
This repository demonstrates a **production-grade FreeRTOS firmware** for STM32 microcontrollers.
The firmware implements a **Smart Industrial Controller**, using real-time principles and industry best practices.

Key highlights:
- ISR → Task Notification for fast hardware signaling
- Fully static allocation for safety-critical environments
- Clear task separation: Control, Sensor, Communication, Logger
- Event groups, queues, and mutexes for synchronization
- Software timers for heartbeat monitoring
- Fault detection and safe handling

---

## Documentation Contents

| File | Purpose |
|------|---------|
| system_scenario.md | Concrete industrial scenario mapping to RTOS |
| task_flow.md       | Task-by-task runtime explanation |
| rtos_concepts.md   | Detailed mapping of FreeRTOS concepts |
| safety_and_faults.md | Safety hooks and error handling |

---
