# Firmware Architecture

The firmware follows a **layered design**:

- BSP Layer: Hardware access (GPIO, ADC, UART)
- RTOS Layer: Tasks, queues, events
- Application Layer: Control logic

No hardware access is done directly from application tasks.
