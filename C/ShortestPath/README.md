# Shortest Path (Dijkstra’s Algorithm in C)

## 📌 Overview
This program computes the shortest path from the **first node** to the **last node** in a directed, unweighted graph using **Dijkstra’s algorithm**.  
It demonstrates graph representation with an adjacency matrix, string parsing for edges, and path reconstruction.

---

## ⚙️ Features
- Implements **Dijkstra’s algorithm** on an unweighted directed graph  
- Handles multiple test cases  
- Detects unreachable nodes and reports clearly  
- Prints the path in `A-B-C-...` format  

---

## 📂 Files
- `shortest_path.c` → Source code  
- `README.md` → This file  
- `Makefile` *(optional)* → For easy compilation  
- `test_cases.txt` *(optional)* → Example inputs/outputs  

---

## ▶️ How to Compile & Run
```bash
gcc shortest_path.c -o shortest_path
./shortest_path
```

---

## 🧪 Example Test Cases
Input (hardcoded in main)
```matlab
1. {"4", "A", "B", "C", "D", "A-B", "B-C", "C-D"}
2. {"5", "A", "B", "C", "D", "E", "A-B", "B-C", "C-D", "D-E", "A-E"}
3. {"3", "A", "B", "C", "A-B", "B-C", "C-A"}
4. {"6", "A", "B", "C", "D", "E", "F", "A-B", "B-C", "C-D", "D-E", "E-F", "A-F"}
```

---

## Output
```code
A-B-C-D
A-E
A-B-C
A-F
```
---

## 🎯 Learning Points
- Practice with graph algorithms in C
- Use of adjacency matrices for graph representation
- String parsing with strtok and strdup
- Path reconstruction using a prev[] array

---
## 📌 Notes

- The graph is directed and unweighted (all edges have weight = 1).
- For unweighted graphs, BFS could also be used, but Dijkstra’s algorithm works correctly here.
- The program is designed for practice and reference, not large-scale optimization.
