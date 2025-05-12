<!--
README.md for Object-Oriented C Language
Translated to English
-->

# Object-Oriented C Language

> An example project implementing object-oriented programming paradigms using pure C.

---

<!-- 🧰 Tech Stack & 🔧 Dynamic Status (2줄 구성) -->
<div align="center" style="font-size: 0.85rem;">

  <!-- Line 1: 기술 스택 13개 -->
  <img src="https://img.shields.io/badge/C-00599C?style=flat&logo=c&logoColor=white" alt="C" />
  <img src="https://img.shields.io/badge/GCC-333333?style=flat&logo=gnu&logoColor=white" alt="GCC" />
  <img src="https://img.shields.io/badge/Make-064F8C?style=flat&logo=cmake&logoColor=white" alt="Make" />
  <img src="https://img.shields.io/badge/Makefile-000000?style=flat" alt="Makefile" />
  <img src="https://img.shields.io/badge/Windows-0078D4?style=flat&logo=windows&logoColor=white" alt="Windows" />
  <img src="https://img.shields.io/badge/Linux-FCC624?style=flat&logo=linux&logoColor=black" alt="Linux" />
  <img src="https://img.shields.io/badge/MACOS-000000?style=flat&logo=apple&logoColor=white" alt="MACOS" />
  <img src="https://img.shields.io/badge/Git-F05032?style=flat&logo=git&logoColor=white" alt="Git" />
  <img src="https://img.shields.io/badge/GitHub-181717?style=flat&logo=github&logoColor=white" alt="GitHub" />
  <img src="https://img.shields.io/badge/Vim-019733?style=flat&logo=vim&logoColor=white" alt="Vim" />
  <img src="https://img.shields.io/badge/Visual%20Studio-5C2D91?style=flat&logo=visualstudio&logoColor=white" alt="VS" />
  <img src="https://img.shields.io/badge/VSCode-007ACC?style=flat&logo=visualstudiocode&logoColor=white" alt="VSCode" />
  <img src="https://img.shields.io/badge/CLion-000000?style=flat&logo=jetbrains&logoColor=white" alt="CLion" />

  <br />

  <!-- Line 2: 다이나믹 상태 3개 -->
  <img src="https://img.shields.io/badge/Commits-1234-blue?style=flat" alt="Commits" />
  <img src="https://img.shields.io/badge/License-MIT-green?style=flat" alt="License" />
  <img src="https://img.shields.io/badge/Version-1.0.0-orange?style=flat" alt="Version" />

</div>

## 📖 Overview

This project is an example that implements key concepts of object-oriented programming (abstraction, encapsulation, inheritance, polymorphism) in a modular structure using only the C language (C99 standard). Various system components (`System`), threading (`Thread`), console I/O (`Console`), input scanning (`Scanner`), and algorithms (`Algorithm`) are expressed as objects using structs and function pointers.

## ⚙️ Key Features

* **System**: Basic I/O, file I/O, timer, platform abstraction
* **Thread**: Lightweight thread creation and management
* **Console**: Console I/O formatting and control
* **Scanner**: Input stream utilities
* **Algorithm**: Stack, Queue, Deque, List collections

## 🧰 Tech Stack

| Badge                                                                                                              | Description                                                                                                  |
| ------------------------------------------------------------------------------------------------------------------ | ------------------------------------------------------------------------------------------------------------ |
| ![C](https://img.shields.io/badge/C-00599C?style=flat&logo=c&logoColor=white)                                     | **C Language**: C99 standard, Object-Oriented Programming implementation using structs and function pointers |
| ![GCC](https://img.shields.io/badge/GCC-333333?style=flat&logo=gnu&logoColor=white)                               | **GCC**: GNU Compiler Collection, used for building C programs                                               |
| ![Make](https://img.shields.io/badge/Make-064F8C?style=flat&logo=cmake&logoColor=white)                           | **Make**: Build automation tool used for compiling and linking source files                                  |
| ![Makefile](https://img.shields.io/badge/Makefile-000000?style=flat)                                              | **Makefile**: Configuration file used by Make for specifying build instructions                              |
| ![Windows](https://img.shields.io/badge/Windows-0078D4?style=flat&logo=windows&logoColor=white)                   | **Windows API**: Windows system functions and multithreading support (`windows.h`, `conio.h`, `process.h`)   |
| ![Linux](https://img.shields.io/badge/Linux-000000?style=flat&logo=linux&logoColor=white)                          | **Linux**: Open-source operating system widely used in programming and development                           |
| ![MACOS](https://img.shields.io/badge/MACOS-000000?style=flat&logo=apple&logoColor=white)                          | **macOS**: Operating system used for Mac hardware with Unix-like commands                                    |
| ![POSIX](https://img.shields.io/badge/POSIX%20Threads-000000?style=flat)                                          | **POSIX Threads**: `pthread.h`, used for multithreading in Unix-based systems                                |
| ![Standard Lib](https://img.shields.io/badge/C%20Standard%20Library-000000?style=flat)                            | **C Standard Library**: Core libraries including `stdio.h`, `stdlib.h`, `string.h`, `time.h`                 |
| ![OOP](https://img.shields.io/badge/Object--Oriented%20Programming-000000?style=flat)                             | **OOP in C**: Encapsulation, abstraction, and polymorphism via structs and function pointers                 |
| ![Algorithms](https://img.shields.io/badge/Algorithms%20\(Stack,%20Queue,%20List\)-000000?style=flat)             | **Algorithms**: Implementations of data structures like stack, queue, deque, and list                        |
| ![Git](https://img.shields.io/badge/Git-F05032?style=flat&logo=git&logoColor=white)                               | **Git**: Version control system for managing code changes                                                    |
| ![GitHub](https://img.shields.io/badge/GitHub-181717?style=flat&logo=github&logoColor=white)                      | **GitHub**: Platform for version control and collaboration, enabling sharing and review of code              |
| ![Vim](https://img.shields.io/badge/Vim-019733?style=flat&logo=vim&logoColor=white)                               | **Vim**: Highly configurable text editor for efficient text editing                                          |
| ![Visual Studio](https://img.shields.io/badge/Visual%20Studio-5C2D91?style=flat&logo=visualstudio&logoColor=white) | **Visual Studio**: IDE for C/C++ development with powerful debugging, code analysis, and testing tools       |
| ![VS Code](https://img.shields.io/badge/VSCode-007ACC?style=flat&logo=visualstudiocode&logoColor=white)          | **Visual Studio Code**: Source code editor used for writing and debugging                                    |
| ![CLion](https://img.shields.io/badge/CLion-000000?style=flat&logo=jetbrains&logoColor=white)                     | **CLion**: JetBrains' C/C++ IDE, with powerful code analysis, refactoring, and CMake integration             |

## 🖥️ Platform Compatibility

This project has been tested and runs on the following platforms:

* 🪟 **Windows** 10 / 11
* 🐧 **Linux**
* 🍎 **macOS**

## 🛣️ Roadmap

* [x] Object-Oriented Programming in C
* [x] Thread and Mutex abstraction
* [x] Console I/O utilities
* [x] Input Scanner for primitive types
* [x] Data Structures: Stack, Queue, List
* [ ] Advanced File utilities
* [ ] GUI Layer using SDL or ncurses (Planned)

## 🏗️ OS-Specific Build Instructions

### 🪟 Windows (GCC MinGW)

```bash
gcc -std=c99 -Wall -I inc -o main.exe src/*.c
main.exe
```

### 🪟 Windows (MSVC Command Prompt)

```cmd
cl /I inc /Fe:main.exe src\*.c
main.exe
```

### 🐧 Linux / 🍎 macOS

```bash
gcc -std=c99 -Wall -I inc -o main src/*.c -lpthread
./main
```

> **Note**: `-lpthread` is required for multithreading support.

## 📂 Directory Structure

```
Object-Oriented-C-Language/
├── LICENSE                # License information
├── README.md              # Project description (this file)
├── inc/                   # Header files
│   ├── algorithm.h
│   ├── console.h
│   ├── main.h
│   ├── Scanner.h
│   ├── System.h
│   └── thread.h
└── src/                   # Source files
    ├── algorithm.c
    ├── console.c
    ├── main.c
    ├── Scanner.c
    ├── System.c
    └── thread.c
```

## 🔧 Development & Build

### Requirements

* GCC (version ≥ 4.8)
* Make (optional)

### Manual Compilation

```bash
# From the project root directory
gcc -std=c99 -Wall -I inc/ -o main src/*.c
```

### Sample Makefile

```Makefile
CC = gcc
CFLAGS = -std=c99 -Wall -I inc
SRCS = $(wildcard src/*.c)
OBJS = $(SRCS:.c=.o)
TARGET = main

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f src/*.o $(TARGET)
```

## 🚀 How to Run

```bash
# After build
./main
```

The sample will automatically create objects, invoke methods, and test threads.

## 📑 API Structure

### 1. System & Basic Types

* **SYSTEM out**

  * `out.printf(const string format, ...)` : Formatted output
  * `out.println(const string format, ...)` : Formatted output with newline

* **SYSTEM in**

  * `in.read() -> int32_t` : Read a character as integer from stdin

* **File**

  * Constructor: `File new_File(const string path, const string mode)`
  * Methods:

    * `f.scanf(const string format, ...)` : Formatted input from file
    * `f.printf(const string format, ...)` : Formatted output to file
    * `f.println(const string format, ...)` : Output with newline
    * `f.open(const string path, const string mode)` : Open file
    * `f.close()` : Close file
    * `f.readLine() -> string` : Read one line from file

* **Time**

  * Constructor: `Time new_Time(void)`
  * Methods:

    * `t.getSystemTime(Time* t)` : Get current system time
    * `t.getTime(Time* t)` : Get internal time value
    * `t.setTime(...)` : Set time (year, month, day, hour, minute, second)
    * `t.start()` / `t.stop()` : Timer thread control

* **Primitive Wrapper Constructors**

  * `new_String(string s)`

    * Methods: `s.length()`, `s.charAt(index)`, `s.substring(start, end)`, `s.equals(...)`, `s.toCharArray()`
    * Static: `String.valueOf(...)`, `String.format(...)`

  * `new_Character(char c)`

    * Methods: `c.charValue()`, `c.equals(...)`, `Character.isDigit(char)`, `Character.isLetter(char)`

  * `new_Byte(...)`, `new_Short(...)`, `new_Integer(...)`, `new_Long(...)`, `new_Float(...)`, `new_Double(...)`, `new_Boolean(...)`

    * Common methods: `x.getValue()`, `x.toString()`, `x.equals(...)`, `x.compareTo(...)`
    * Static: `Wrapper.parse<Type>(...)`, `Wrapper.valueOf(...)`
    * Byte-specific: `b.byteValue()`, `b.toUnsigned()`, `Byte.parseByte(string, base)`
    * Boolean-specific: `b.booleanValue()`, `b.isTrue()`, `b.isFalse()`, `Boolean.parseBoolean(...)`

### 2. Thread & Mutex

* **Thread**

  * Constructor: `Thread new_Thread(void* (*function)(void*))`
  * Methods:

    * `start(...)`, `join()`, `detach()`, `cancel()`, `exit()`, `delete()`

* **Mutex**

  * Constructor: `Mutex new_Mutex()`
  * Methods:

    * `lock()`, `unlock()`, `delete()`

### 3. Console

* **Console**

  * Constructor: `Console new_console(void)`
  * Methods:

    * `print(...)`, `println(...)`, `readLine()`, `clear()`
    * `setColor(ColorType color)`, `resetColor()`, `kbhit() -> int`

### 4. Scanner

* **Scanner**

  * Constructor: `Scanner new_Scanner(struct __stdin_t in)`
  * Methods:

    * `nextChar()`, `nextByte()`, `nextShort()`, `nextInt()`, `nextLong()`
    * `nextUByte()`, `nextUShort()`, `nextUInt()`, `nextULong()`
    * `nextBoolean()`, `nextFloat()`, `nextDouble()`, `nextLDouble()`
    * `next() -> string`, `nextLine() -> string`

    (By default, uses whitespace as delimiter and supports line reading.)

### 5. Collections (Algorithm)

* **Stack**

  * Constructor: `Stack new_stack(size_t elementSize)`
  * Methods: `push(...)`, `pop() -> void*`, `clear()`, `delete()`

* **Queue**

  * Constructor: `Queue new_queue(size_t elementSize)`
  * Methods: `push(...)`, `pop() -> void*`, `clear()`, `delete()`

* **Deque**

  * Constructor: `Deque new_deque(size_t elementSize)`
  * Methods: `pushFront(...)`, `pushBack(...)`, `popFront()`, `popBack()`, `clear()`, `delete()`

* **List**

  * Constructor: `List new_list(size_t elementSize)`
  * Methods: `add(...)`, `get(index)`, `remove(index)`, `size()`, `clear()`, `delete()`

## 🛠️ Contribution Guide

1. **Fork** this project
2. **Create a feature branch**: `git checkout -b feature/YourFeature`
3. **Implement the feature**
4. **Write tests and update docs**
5. **Create a Pull Request**

Please open an issue first to discuss your ideas before contributing.

## 📄 License

This project is licensed under the [MIT License](LICENSE).
