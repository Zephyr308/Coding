# 🚗 Advanced IoT Vehicle Tracking System

<div align="center">

![Python](https://img.shields.io/badge/Python-3.11-blue)
![RaspberryPi](https://img.shields.io/badge/Raspberry%20Pi-Zero%20W-red)
![MQTT](https://img.shields.io/badge/MQTT-Streaming-green)
![GPS](https://img.shields.io/badge/GPS-RealTime-orange)
![Docker](https://img.shields.io/badge/Docker-Enabled-blue)

A Production-Ready GPS Vehicle Tracking & Visualization Platform  
Built using Raspberry Pi Zero W, GPSD, MQTT, FastAPI, SQLite, Docker, and Leaflet.js

</div>

---

# 📌 Project Overview

This project is an advanced IoT-based GPS vehicle tracking platform designed for:

- 🚗 Vehicle Monitoring
- 🚚 Fleet Management
- 📍 Real-Time GPS Tracking
- 🛰️ Telemetry Streaming
- 📊 Live Dashboard Visualization
- 🌍 Geo-location Monitoring
- 📡 Mobile Edge Computing

The system collects GPS coordinates from a moving vehicle using a Raspberry Pi Zero W connected to a GPS module and streams the data to a live web dashboard over MQTT.

---

# 🧠 Real-World Use Cases

## 🚕 Taxi Fleet Tracking

Track all taxi vehicles live on a map.

### Features:
- Live location
- Speed monitoring
- Route history
- Driver analytics

---

## 🚚 Logistics & Delivery Tracking

Monitor delivery vehicles in real-time.

### Features:
- ETA prediction
- Geo-fencing alerts
- Route optimization
- Driver performance

---

## 🚑 Ambulance Tracking

Track emergency response vehicles.

### Features:
- Fastest route selection
- Real-time dispatch visibility
- Live movement analytics

---

## 🚓 Security & Patrol Systems

Deploy in patrol vehicles for:

- Perimeter monitoring
- Route logging
- Incident tracking

---

## 🛥️ Boat / Marine Monitoring

Track boats and marine assets using GPS.

---

# 🏗️ System Architecture

```text
                  ┌────────────────────┐
                  │    GPS Satellite    │
                  └─────────┬──────────┘
                            │
                            ▼
                  ┌────────────────────┐
                  │     GPS Module      │
                  └─────────┬──────────┘
                            │ UART
                            ▼
                  ┌────────────────────┐
                  │   PL2303 UART USB   │
                  └─────────┬──────────┘
                            │ USB OTG
                            ▼
                  ┌────────────────────┐
                  │ Raspberry Pi Zero W │
                  │  Python + GPSD      │
                  └─────────┬──────────┘
                            │ MQTT
                            ▼
                  ┌────────────────────┐
                  │    MQTT Broker      │
                  └─────────┬──────────┘
                            │
                            ▼
                  ┌────────────────────┐
                  │ FastAPI Backend     │
                  └─────────┬──────────┘
                            │
                            ▼
                  ┌────────────────────┐
                  │ Live Web Dashboard  │
                  └────────────────────┘
```

# 🧰 Hardware Requirements

| Hardware                            | Quantity |
| ----------------------------------- | -------- |
| Raspberry Pi Zero Wireless          | 1        |
| GPS Module with Long Antenna        | 1        |
| PL2303 USB to UART Converter        | 1        |
| OTG Cable                           | 1        |
| Power Bank (Recommended 10,000mAh+) | 1        |
| Portable WiFi Dongle / Hotspot      | 1        |
| Jumper Wires                        | 4        |

# 🔌 Hardware Wiring
| GPS Module | PL2303 |
| ---------- | ------ |
| TX         | RX     |
| RX         | TX     |
| GND        | GND    |
| VCC        | 5V     |

# 📁 Project Structure

```
vehicle-tracking-system/
│
├── edge-device/
│   ├── gps_tracker.py
│   ├── mqtt_publisher.py
│   ├── local_buffer.py
│   ├── config.py
│   ├── requirements.txt
│   ├── install.sh
│   └── gpstracker.service
│
├── backend/
│   ├── main.py
│   ├── mqtt_subscriber.py
│   ├── database.py
│   ├── models.py
│   ├── requirements.txt
│   └── Dockerfile
│
├── dashboard/
│   ├── index.html
│   ├── app.js
│   ├── style.css
│   └── leaflet.js
│
├── docker-compose.yml
├── README.md
└── .gitignore
```
# ⚙️ Software Stack
| Technology    | Purpose              |
| ------------- | -------------------- |
| Python        | GPS Processing       |
| GPSD          | GPS Communication    |
| MQTT          | Real-Time Streaming  |
| SQLite        | Local Offline Buffer |
| FastAPI       | Backend API          |
| Docker        | Deployment           |
| Leaflet.js    | Live Map Dashboard   |
| OpenStreetMap | Maps                 |

# 📊 Features

✅ Real-Time GPS Tracking
- Live coordinates
- Vehicle marker updates

✅ Offline Data Buffering
If internet disconnects:
- GPS data stored locally
- Auto upload later

✅ MQTT Streaming
- Lightweight
- Real-time
- IoT optimized

✅ Docker Deployment
- Easy cloud/server deployment.

✅ Production Ready
Includes:
- Auto restart
- GPS reconnect handling
- Modular architecture
- Scalable backend

# 🔒 Security Recommendations

For production:
- Use TLS MQTT
- VPN access
- JWT authentication
- Firewall rules

# 🔥 Future Improvements

Planned Features
- 📱 Mobile App
- 🤖 AI Route Prediction
- 🚨 Accident Detection
- 🗺️ Route Replay
- 📈 Driver Analytics
- ☁️ AWS IoT Integration
- 🛰️ Multi-Vehicle Dashboard

# 🧪 Debugging Commands

GPS Status
`cgps`
GPS Raw Data
`cat /dev/ttyUSB0`
MQTT Monitor
`mosquitto_sub -h broker.hivemq.com -t vehicle/livegps`
Service Logs
`journalctl -u gpstracker.service -f`

# 🧠 Performance Optimizations

Recommended for Raspberry Pi Zero W:
- Use Raspberry Pi OS Lite
- Disable HDMI
- Disable Bluetooth (if unused)
- Use heatsinks
- Use large power bank

# ⚠️ Power Recommendation

| Power Bank | Runtime     |
| ---------- | ----------- |
| 10,000mAh  | 12–16 Hours |
| 20,000mAh  | 24+ Hours   |

Avoid:
- 1000mAh power banks

# 👨‍💻 Author

Built for:
- IoT Developers
- Embedded Engineers
- Fleet Tracking Systems
- Smart Transportation
- GPS Telemetry Platforms

# ⭐ Contributing

Contributions are welcome.
Fork the repository and create a pull request.

# ❤️ Acknowledgements
- Raspberry Pi Foundation
- OpenStreetMap
- FastAPI
- MQTT Community
- GPSD Project
