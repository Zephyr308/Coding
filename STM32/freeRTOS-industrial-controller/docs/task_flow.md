# Task Flow & Runtime Picture

## 1. SensorTask
- Wakes on ADC ISR notification.
- Reads ADC and forwards data to ControlTask via queue.

## 2. ControlTask
- Highest priority task.
- Receives sensor data.
- Updates motor/fan output deterministically.
- Sets event group for system status.

## 3. CommsTask
- Blocks on UART stream buffer.
- Parses supervisor commands safely.

## 4. LoggerTask
- Waits for log request event.
- Acquires mutex before writing to flash/SD.

## 5. Heartbeat Timer
- Software timer toggles LED every 1 second.

### System Flow Diagram

