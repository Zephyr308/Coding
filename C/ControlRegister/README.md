# 🔧 Embedded Control Register Simulator (C)

## 📌 Overview
This program simulates a simple **8-bit hardware control register** using C bitfields.  
It accepts text-based commands (e.g., `POWER=ON,MODE=3`) from the user, updates the register accordingly, and displays its state in both **decimal** and **binary**.  
It also maintains a circular event log to track recent register changes.

---

## ⚙️ Features
- **Bitfield struct** to represent an 8-bit control register  
- **Command parsing** with `strtok`, `sscanf`, and `strcasecmp`  
- **Enum + dispatch pattern** for scalable command handling  
- **Circular buffer** for event logging (last 10 changes)  
- **CLI loop** with commands:
  - `POWER=ON/OFF`
  - `ALARM=ON/OFF`
  - `MODE=0–7`
  - `RESERVED=0–7`
  - `RESET` → clears the register
  - `LOG` → shows last 10 changes
  - `EXIT` → quits the program

---

## 📂 Files
- `control_register.c` → Source code  
- `README.md` → This file  
- `Makefile` *(optional)* → For easy compilation  
- `test_cases.txt` *(optional)* → Example commands and outputs  

---

## ▶️ How to Compile & Run
```bash
gcc control_register.c -o control_register
./control_register
```

---

## 🧪 Example Run
Input
```
POWER=ON,MODE=3
ALARM=ON
RESERVED=5
LOG
RESET
EXIT
```

Output (sample)
```
🧾 Current Register State:
  POWER    = 1
  ALARM    = 0
  MODE     = 3
  RESERVED = 0
  Binary   = 00011001 (0x19)

🧾 Current Register State:
  POWER    = 1
  ALARM    = 1
  MODE     = 3
  RESERVED = 0
  Binary   = 01011001 (0x59)

🔍 Event Log:
  [0] POWER set to ON
  [1] MODE set to 3
  [2] ALARM set to ON
  [3] RESERVED bits set to 5
```
---

## 🎯 Learning Points
- Using bitfields to model hardware registers
- Implementing a command parser in C
- Designing a circular buffer for logs
- Building a simple CLI loop for interactive testing

---
## 📌 Notes
- This is a practice/reference project, not production code.
- The register is 8-bit wide with the following layout:
  - `Bits 0–2 → RESERVED`
  - `Bits 3–5 → MODE (0–7)`
  - `Bit 6 → ALARM`
  - `Bit 7 → POWER`
 
