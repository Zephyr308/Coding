# Thermal Control System (Embedded Firmware Project)

A real-time embedded thermal control system simulating a consumer hair-styling appliance.

The system demonstrates:
- PID-based thermal regulation
- Hardware Abstraction Layer (HAL)
- FreeRTOS-based multitasking
- Safety-critical fault handling
- Sensor validation (redundancy + failure detection)
- Watchdog supervision
- Structured logging (circular buffer)

---

## 🧠 System Architecture

HAL → Control Layer → Safety Layer → Application Layer → RTOS

---

## ⚙️ Features

### Control
- PID controller with anti-windup
- Output ramp limiting

### Safety
- Over-temperature protection
- Sensor failure detection
- Redundant sensor validation
- Watchdog supervision per task

### System
- State machine-based control
- FreeRTOS task separation
- Timestamped logging system

---

## 🎯 Purpose

This project demonstrates embedded firmware design suitable for:
- Consumer electronics (thermal devices)
- Safety-critical embedded systems
- Real-time control applications

---
