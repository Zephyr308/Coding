# 🔥 Thermal Control Embedded System

A real-time embedded firmware system simulating a consumer thermal device (hair-styling appliance).

This project demonstrates **industrial embedded system design patterns**, including:
- Hardware Abstraction Layer (HAL)
- PID control with anti-windup
- Safety-critical fault handling
- State machine architecture
- Watchdog supervision
- Circular buffer logging
- Real-time control loop (RTOS-ready)

---

# 🧠 System Architecture

## High-Level Design

```mermaid
flowchart TD
    A[Application Layer<br>State Machine + Main Loop]
    B[Control Layer<br>PID Controller + Filtering]
    C[Safety Layer<br>Fault Detection + Sensor Validation]
    D[HAL Layer<br>ADC / PWM / Time]
    E[Hardware<br>MCU + Sensors + Heater + Fan]
    F[Logger<br>Circular Buffer Telemetry]

    A --> B
    B --> D
    A --> C
    C --> D
    B --> D
    D --> E
    A --> F
    C --> F
    B --> F
```
