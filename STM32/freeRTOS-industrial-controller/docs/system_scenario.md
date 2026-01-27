# Industrial Scenario – Temperature & Motor Controller

## Overview
The system simulates a **factory-floor controller** that monitors temperature, controls a fan/motor, communicates with a supervisor system, and logs operating data safely.

---

## Requirements
1. Read temperature sensor via ADC on conversion complete.
2. Control motor/fan speed based on temperature.
3. Accept supervisor commands over UART.
4. Log system events & faults.
5. Blink heartbeat LED every second.
6. Guarantee real-time deterministic control.
7. Fail safely in case of errors.

---

## Firmware Mapping

| Requirement | Implementation |
|-------------|----------------|
| ADC read | ADC ISR → Task Notification → SensorTask |
| Control motor | ControlTask receives sensor data via queue → BSP_ControlOutput() |
| UART commands | UART RX ISR → StreamBuffer → CommsTask parses commands |
| Logging | Event group triggers LoggerTask → mutex protects flash/SD |
| Heartbeat | Software timer toggles LED every 1 second |
| Safety | Stack overflow / malloc failure hooks, assertions |
