# Task Design Rationale

## ControlTask
- Highest priority
- Event-driven
- No blocking delays

## SensorTask
- Periodic execution
- Triggered by ADC ISR via task notification

## LoggerTask
- Lowest priority
- Deferred I/O
- Mutex-protected shared resource
