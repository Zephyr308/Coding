# 🚀 Installation Guide — Advanced IoT Vehicle Tracking System

This guide walks through the complete setup of the GPS vehicle tracking platform using:

- Raspberry Pi Zero W
- GPS Module
- GPSD
- MQTT
- FastAPI
- Docker
- Live Dashboard

---

# 📋 Prerequisites

Before starting, make sure you have:

✅ Raspberry Pi Zero W  
✅ GPS Module with antenna  
✅ PL2303 USB to UART converter  
✅ OTG cable  
✅ Portable WiFi hotspot or dongle  
✅ Power bank (Recommended 10,000mAh+)  
✅ MicroSD card (16GB+)  

---

# 🖥️ Step 1 — Flash Raspberry Pi OS

Download:

👉 https://www.raspberrypi.com/software/

Use:

- Raspberry Pi Imager
- Raspberry Pi OS Lite (Recommended)

---

# ⚙️ Configure Headless Setup

Inside Raspberry Pi Imager:

Enable:

- SSH
- WiFi
- Username/password

Recommended:

```text
Username: pi
Hostname: gps-tracker
```

---

# 🔌 Step 2 — Hardware Wiring

## GPS Module → PL2303

| GPS Module | PL2303 |
|---|---|
| TX | RX |
| RX | TX |
| GND | GND |
| VCC | 5V |

---

## Connect Hardware

```text
GPS Module
   ↓
PL2303 USB UART
   ↓
OTG Cable
   ↓
Raspberry Pi Zero W
```

---

# 🌐 Step 3 — Find Raspberry Pi IP Address

---

## Windows

Use:

- Advanced IP Scanner

OR check your router dashboard.

---

## Linux

```bash
nmap -sn 192.168.1.0/24
```

---

# 🔑 Step 4 — SSH Into Raspberry Pi

```bash
ssh pi@YOUR_PI_IP
```

Example:

```bash
ssh pi@192.168.1.20
```

---

# 📥 Step 5 — Clone Repository

```bash
git clone https://github.com/YOUR_USERNAME/vehicle-tracking-system.git
```

---

## Enter Project Directory

```bash
cd vehicle-tracking-system
```

---

# 📦 Step 6 — Install Dependencies

---

## Move to Edge Device Folder

```bash
cd edge-device
```

---

## Make Installer Executable

```bash
chmod +x install.sh
```

---

## Run Installer

```bash
./install.sh
```

This installs:

- GPSD
- GPSD clients
- Python dependencies
- SQLite
- MQTT packages

---

# 🛰️ Step 7 — Configure GPSD

Edit GPSD config:

```bash
sudo nano /etc/default/gpsd
```

Replace contents with:

```bash
START_DAEMON="true"
USBAUTO="true"
DEVICES="/dev/ttyUSB0"
GPSD_OPTIONS="-n"
```

---

# 🔄 Restart GPSD

```bash
sudo systemctl restart gpsd
```

---

# 🧪 Step 8 — Verify GPS Detection

---

## Check USB Devices

```bash
lsusb
```

Expected:

```text
Prolific Technology, Inc. PL2303 Serial Port
```

---

## Check Serial Port

```bash
dmesg | grep tty
```

Expected:

```text
ttyUSB0
```

---

# 📍 View Live GPS Data

---

## GPS Console UI

```bash
cgps
```

---

## Advanced GPS Monitor

```bash
gpsmon
```

---

## Raw GPS Data

```bash
cat /dev/ttyUSB0
```

Expected:

```text
$GPGGA,...
$GPRMC,...
```

---

# ⚡ Step 9 — Enable Auto Start Service

---

## Copy Service File

```bash
sudo cp gpstracker.service /etc/systemd/system/
```

---

## Reload Services

```bash
sudo systemctl daemon-reload
```

---

## Enable Auto Start

```bash
sudo systemctl enable gpstracker
```

---

## Start Service

```bash
sudo systemctl start gpstracker
```

---

## Check Status

```bash
sudo systemctl status gpstracker
```

---

# 🌍 Step 10 — Setup Backend Server

---

## Move to Backend Folder

```bash
cd ../backend
```

---

## Install Requirements

```bash
pip install -r requirements.txt
```

---

## Run Backend

```bash
uvicorn main:app --reload
```

Backend will run on:

```text
http://localhost:8000
```

---

# 🐳 Step 11 — Docker Deployment

---

## Start Docker Services

```bash
docker-compose up --build
```

---

# 📡 Step 12 — MQTT Monitoring

---

## Subscribe to GPS Topic

```bash
mosquitto_sub -h broker.hivemq.com -t vehicle/livegps
```

You should receive:

```json
{
  "device_id": "vehicle_001",
  "lat": 26.4207,
  "lon": 50.0888,
  "speed": 45
}
```

---

# 🗺️ Step 13 — Open Dashboard

Open in browser:

```text
http://localhost:8000
```

---

# 🔒 Security Recommendations

For production deployment:

✅ Use TLS MQTT  
✅ Use private brokers  
✅ Enable firewalls  
✅ Add JWT authentication  
✅ Use VPN access  

---

# ⚡ Performance Optimizations

Recommended for Raspberry Pi Zero W:

- Use Raspberry Pi OS Lite
- Disable HDMI
- Disable Bluetooth (if unused)
- Use heatsinks
- Use large power bank

---

# 🔋 Power Recommendations

| Power Bank | Estimated Runtime |
|---|---|
| 10,000mAh | 12–16 Hours |
| 20,000mAh | 24+ Hours |

Avoid:
- 1000mAh power banks

---

# 🧪 Debugging & Troubleshooting

---

# GPS Status

```bash
cgps
```

---

# Advanced GPS Monitor

```bash
gpsmon
```

---

# Raw GPS Data

```bash
cat /dev/ttyUSB0
```

---

# Detect USB Device

```bash
lsusb
```

---

# Detect Serial Port

```bash
dmesg | grep tty
```

---

# MQTT Live Stream

```bash
mosquitto_sub -h broker.hivemq.com -t vehicle/livegps
```

---

# View Service Logs

```bash
journalctl -u gpstracker.service -f
```

---

# Restart GPSD

```bash
sudo systemctl restart gpsd
```

---

# Restart Tracker Service

```bash
sudo systemctl restart gpstracker
```

---

# Check Running Services

```bash
systemctl status gpsd
```

```bash
systemctl status gpstracker
```

---

# 🛠️ Common Problems

---

## ❌ No GPS Fix

### Solutions

- Move outdoors
- Wait 5–15 minutes
- Check antenna placement
- Avoid USB interference

---

## ❌ No `/dev/ttyUSB0`

### Solutions

Check:

```bash
lsusb
```

Reconnect:
- OTG cable
- PL2303 module

---

## ❌ MQTT Not Publishing

### Solutions

Check internet:

```bash
ping google.com
```

Restart service:

```bash
sudo systemctl restart gpstracker
```

---

## ❌ Dashboard Not Updating

### Solutions

Verify:
- Backend running
- MQTT subscriber active
- Browser console logs

---

# 🎯 Deployment Tips

For production deployments:

✅ Use VPS cloud server  
✅ Use Docker containers  
✅ Add HTTPS reverse proxy  
✅ Use InfluxDB + Grafana  
✅ Enable monitoring  

---

# ☁️ Recommended Production Stack

| Layer | Technology |
|---|---|
| Edge Device | Raspberry Pi Zero W |
| GPS Layer | GPSD |
| Streaming | MQTT |
| Backend | FastAPI |
| Database | PostgreSQL / InfluxDB |
| Dashboard | React + Leaflet |
| Analytics | Grafana |
| Deployment | Docker |

---

# 🎉 Installation Complete

Your GPS vehicle tracking platform is now ready for:

✅ Live vehicle tracking  
✅ Fleet monitoring  
✅ GPS telemetry streaming  
✅ Dashboard visualization  
✅ Cloud deployment  
✅ Real-time analytics  

---
