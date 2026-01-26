# Industrial IoT Equipment Monitoring System (ESP32)

## Overview
This project implements an **industry-grade IoT edge device** for monitoring industrial equipment health parameters and transmitting data securely to a cloud platform using **MQTT**.  
The system is designed with **industrial reliability, scalability, and maintainability** in mind and reflects real-world **Industry 4.0** and **predictive maintenance** use cases.

---

## Key Objectives
- Continuous monitoring of critical equipment parameters
- Edge-based fault detection to reduce cloud dependency
- Reliable and scalable data transmission
- Clear separation between hardware abstraction, communication, and application logic

---

## System Architecture
```yaml
Sensors → ESP32 Edge Node → MQTT Broker → Cloud Dashboard / Alerts
```

**Design philosophy:**  
> *Process data at the edge, transmit only meaningful information, and ensure system resilience.*

---

## Features
- Modular ESP32 firmware architecture
- Sensor abstraction layer (HAL)
- Edge-level threshold monitoring and fault detection
- MQTT-based data publishing
- Automatic reconnection handling
- JSON-formatted telemetry payloads
- Configurable sampling intervals and limits

---

## Hardware Components
| Component | Description |
|--------|------------|
ESP32 | IoT edge controller with Wi-Fi |
Temperature Sensor | Equipment thermal monitoring |
Current Sensor | Load and power consumption tracking |
Vibration Sensor | Mechanical health monitoring |
Power Supply | 5V / 12V (industrial recommended) |

---

## Firmware Architecture
```yaml
firmware/
├── main.cpp // Application entry point
├── config.h // System configuration & thresholds
├── sensors.h/.cpp // Sensor abstraction & validation
├── mqtt_client.h/.cpp // MQTT communication handling
└── security.h // TLS certificates (optional)
```

**Architecture principles used:**
- Separation of concerns
- Non-blocking execution
- Edge-first data processing
- Scalable design for future expansion

---

## Data Flow
1. Sensors are sampled at fixed intervals
2. Raw values are validated and filtered at the edge
3. Thresholds are evaluated locally
4. Structured JSON payload is published via MQTT
5. Cloud platform processes, visualizes, and triggers alerts

---

## MQTT Telemetry Payload Example

```json
{
  "device_id": "motor_node_01",
  "temperature": 62.4,
  "current": 3.1,
  "vibration": 0.42,
  "fault": false
}
```
## Communication Protocol
- **Protocol:** MQTT  
- **QoS:** 1 (at least once delivery)  
- **Payload Format:** JSON  
- **Security:** TLS supported (configurable)

---

## Reliability & Industrial Considerations
- Deterministic sensor sampling  
- MQTT reconnection logic  
- Edge fault detection to reduce latency  
- Configurable thresholds and timing  
- Designed to scale to hundreds of devices  

---

## Performance Targets
- **Sensor sampling interval:** 2 seconds  
- **Telemetry latency:** < 1 second (local network)  
- **Fault detection:** Real-time (edge-based)  
- **System uptime:** Continuous operation  

---

## How to Run
1. Configure Wi-Fi and MQTT settings in `config.h`
2. Connect sensors to the ESP32
3. Flash firmware using Arduino IDE or PlatformIO
4. Start MQTT broker (Mosquitto or cloud service)
5. Monitor data via Node-RED or cloud dashboard

---

## Use Cases
- Industrial motor health monitoring  
- Predictive maintenance systems  
- Smart factory equipment tracking  
- Energy consumption analysis  
- Condition-based monitoring  

---

## Future Enhancements
- MQTT over TLS (port 8883)  
- OTA firmware updates  
- Device provisioning and authentication  
- Time-series database integration  
- Dashboard alarms and notifications  
- Migration to AWS IoT or Azure IoT Hub  

---

## What This Project Demonstrates
- Embedded systems engineering  
- Industrial IoT architecture  
- Edge computing principles  
- Secure and scalable communication  
- Clean, maintainable firmware design  

---

## License
MIT License

---

## Author
Portfolio project demonstrating industry-ready IoT and embedded systems competence.



