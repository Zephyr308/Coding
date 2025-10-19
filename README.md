# My Coding Reference 📚

A personal collection of coding exercises, algorithms, and practice programs.  
Each program lives in its own folder with a consistent structure for easy navigation and reuse.

---

## 📂 Repository Structure
```graphql
/MyCodingReference
├── README.md # This file (overview of the repo)
├── C/ # C language programs
│   ├── ShortestPath/
│   │  ├── README.md
│   │  ├── shortest_path.c
│   │  ├── Makefile (optional)
│   │  └── test_cases.txt (optional)
│   └── ... (other C programs)
├── Python/ # Python programs (future expansion)
├── Java/ # Java programs (future expansion)
└── ... # Other languages or categories
```



---

## 🛠 Folder Structure for Each Program
Every program folder follows the same format:
- **README.md** → Short description of the program  
- **Source file(s)** → The actual code  
- **Makefile** *(optional)* → For easy compilation (C/C++ projects)  
- **test_cases.txt** *(optional)* → Example inputs/outputs  
- **notes.md** *(optional)* → Personal notes, observations, or improvements  

---

## ✅ Completed Programs
### C
- **ShortestPath** → Implements Dijkstra’s algorithm on a directed, unweighted graph.  
  - Handles multiple test cases  
  - Detects unreachable nodes  
  - Prints path in `A-B-C` format  

*(Add more as you go…)*

---

## 🚀 How to Use
1. Clone the repository:
   ```bash
   git clone https://github.com/<your-username>/MyCodingReference.git
   ```
2. Navigate to the program folder:
   ```bash
   cd MyCodingReference/C/ShortestPath
   ```
2. Compile and run (for C programs):
   ```bash
   gcc shortest_path.c -o shortest_path
    ./shortest_path
   ```
   
---
## 🎯 Purpose

This repository is not a tutorial collection — it’s my personal coding reference. It helps me:

- Keep track of solved problems and algorithms
- Maintain a consistent structure across projects
- Revisit and reuse code snippets quickly
- Build a growing library of coding knowledge
---

## 📌 Notes

- Each folder is self-contained.
- Code is written for clarity and practice, not production optimization.
- Over time, this repo will expand to include multiple languages and categories.
