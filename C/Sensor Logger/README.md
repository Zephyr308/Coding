# 📦 Embedded Sensor Logger (Microcontroller Simulation in C)

## 📌 Overview
This program simulates a **microcontroller-based sensor logger**.  
It generates random temperature readings, logs them into a circular buffer, and uses a simulated **control register** with bitfields to manage logging and error states.  
It demonstrates embedded systems concepts such as `volatile`, `const`, `static`, and register simulation.

---

## ⚙️ Features
- **Sensor Simulation**: Generates pseudo-random temperature readings (`rand()`).
- **Circular Buffer**: Stores the last 10 readings with automatic overwrite.
- **Control Register (bitfields)**:
  - `LOG_ENABLE`: controls if logging is active
  - `ERROR`: flags out-of-range readings
- **Embedded Concepts**:
  - `volatile` → for simulated hardware register
  - `const` → ROM-like thresholds
  - `static` → persistent state across calls
- **System Output**: Prints readings, register state, and buffer contents.

---

## 📂 Files
- `sensor_logger.c` → Source code  
- `README.md` → This file  
- `Makefile` *(optional)* → For easy compilation  
- `test_cases.txt` *(optional)* → Example runs  

---

## ▶️ How to Compile & Run
```bash
gcc sensor_logger.c -o sensor_logger
./sensor_logger
```

---
## 🧪 Example Run
Output (sample)
```
=== Embedded Sensor Logger (Simulation) ===
[Sensor] Reading #1 = 23°C
[Sensor] Reading #2 = 41°C
⚠️  ERROR: Temperature out of range!
[Sensor] Reading #3 = 15°C
...

[Control Register] LOG: 1, ERROR: 0, BUFFER COUNT: 10
[Sensor Log] Latest = 15°C | Min = 5°C | Max = 39°C
[Buffer Contents]: 23 15 39 12 8 5 30 28 35 15
```
--- 
## 🎯 Learning Points
- How to simulate **hardware registers** with bitfields
- Implementing a **circular buffer** for sensor data
- Using `volatile`, `const`, and `static` in embedded-style C
- Simulating **logging control** and **error detection**

---
## 📌 Notes
- The buffer size is fixed at **10 readings**.
- Temperature thresholds are defined as constants:
  - Low = `0°C`
  - High = `40°C`
- Out-of-range readings set the `ERROR` flag but are not logged.
- This is a **simulation for practice/reference**, not production firmware.

