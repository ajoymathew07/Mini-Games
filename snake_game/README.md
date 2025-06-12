# 🐍 Console Snake Game

A simple console-based **Snake game** implemented in **C++**, developed as part of learning linked lists, basic game loops, and object-oriented programming concepts.

---

## 🎮 Features

- Console-based gameplay
- Snake grows upon eating food (`$`)
- Collision detection (with walls and itself)
- Snake path is tracked using a linked list (`Node` class)
- Configurable board size
- Object-oriented design (`Snake` and `Node` classes)

---

## 🧠 Concepts Used

- Object-Oriented Programming in C++ (Classes, Friend Classes)
- Dynamic Memory Allocation (`new`, `delete`)
- Pointers and Linked Lists
- Console I/O (`getch()`, `kbhit()`)
- Basic game loop and logic
- Platform-specific input handling

---
## 📚 Libraries Used

| Library          | Purpose                                           |
|------------------|---------------------------------------------------|
| `<iostream>`     | Input/output operations in console                |
| `<conio.h>`      | Non-blocking input (`getch()`, `kbhit()`) — *Windows only* |
| `<windows.h>`    | Sleep function (`Sleep(ms)`) and console handling — *Windows only* |
| `<chrono>`       | Time manipulation (optional) — for cross-platform sleep |
| `<thread>`       | Used with `<chrono>` for portable delays (`std::this_thread::sleep_for`) |

> ✅ You can optionally replace `<windows.h>` and `<conio.h>` with POSIX or cross-platform alternatives for compatibility with Linux/macOS.

## 🛠️ How to Run

### 🔧 Compile

#### On Windows (Using g++)
```bash
g++ -o snake.exe main.cpp snake.cpp -std=c++17
```
### 🐧 On Linux / macOS
⚠️ Requires replacing conio.h and windows.h with portable alternatives.

🔧 Compile using g++
``` bash
g++ -o snake main.cpp snake.cpp -std=c++17

```
🔧 Or Compile and Run using Make

``` bash
make
./snake
```
To clean the build:
``` bash
make clean
```
