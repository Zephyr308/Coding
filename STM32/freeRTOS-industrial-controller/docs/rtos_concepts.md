# RTOS Concepts Applied

| Concept | Where Used | Reason |
|---------|------------|--------|
| Task notifications | SensorTask ← ADC ISR | Fastest ISR → task signaling |
| Queues | SensorTask → ControlTask | Decouples producer/consumer |
| Stream buffers | UART RX → CommsTask | Byte stream communication |
| Mutex | LoggerTask | Protect shared flash/SD |
| Event groups | System status, log requests | Multi-task signaling |
| Software timers | Heartbeat LED | Non-blocking periodic tasks |
| Static allocation | All tasks, queues, timers | Safety-critical environments |
