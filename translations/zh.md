# Object-Oriented C Language

> 使用纯 C 语言实现面向对象编程范式的示例项目。

---

您可以点击以下链接，以您偏好的语言查看翻译版本.

🌍 [English](../README.md) | [한국어](ko.md) | [中文](zh.md) | [日本語](ja.md) | [Русский](ru.md)

---

<div align="center" style="font-size: 0.85rem;">
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
  <img src="https://img.shields.io/badge/Commits-1234-blue?style=flat" alt="Commits" />
  <img src="https://img.shields.io/badge/License-MIT-green?style=flat" alt="License" />
  <img src="https://img.shields.io/badge/Version-1.0.0-orange?style=flat" alt="Version" />
</div>

## 📖 概览

此项目是一个示例，使用纯 C 语言（C99 标准）以模块化结构实现面向对象编程的关键概念（抽象、封装、继承、多态）。各种系统组件（`System`）、线程（`Thread`）、控制台 I/O（`Console`）、输入扫描（`Scanner`）和算法（`Algorithm`）均通过结构体和函数指针来表达为对象。

## ⚙️ 主要特性

* **System**：基本 I/O、文件 I/O、定时器、平台抽象
* **Thread**：轻量级线程创建和管理
* **Console**：控制台 I/O 格式化和控制
* **Scanner**：输入流实用工具
* **Algorithm**：栈、队列、双端队列、链表集合

## 🧰 技术栈

| 徽章                                                                                                                   | 描述                                                                      |
| -------------------------------------------------------------------------------------------------------------------- | ----------------------------------------------------------------------- |
| ![C](https://img.shields.io/badge/C-00599C?style=flat\&logo=c\&logoColor=white)                                      | **C 语言**：C99 标准，使用结构体和函数指针实现面向对象编程                                      |
| ![GCC](https://img.shields.io/badge/GCC-333333?style=flat\&logo=gnu\&logoColor=white)                                | **GCC**：GNU 编译器集合，用于构建 C 程序                                             |
| ![Make](https://img.shields.io/badge/Make-064F8C?style=flat\&logo=cmake\&logoColor=white)                            | **Make**：用于编译和链接源文件的构建自动化工具                                             |
| ![Makefile](https://img.shields.io/badge/Makefile-000000?style=flat)                                                 | **Makefile**：Make 用于指定构建指令的配置文件                                         |
| ![Windows](https://img.shields.io/badge/Windows-0078D4?style=flat\&logo=windows\&logoColor=white)                    | **Windows API**：Windows 系统函数和多线程支持（`windows.h`, `conio.h`, `process.h`） |
| ![Linux](https://img.shields.io/badge/Linux-000000?style=flat\&logo=linux\&logoColor=white)                          | **Linux**：用于编程和开发的开源操作系统                                                |
| ![MACOS](https://img.shields.io/badge/MACOS-000000?style=flat\&logo=apple\&logoColor=white)                          | **macOS**：用于 Mac 硬件的类 Unix 操作系统                                         |
| ![POSIX](https://img.shields.io/badge/POSIX%20Threads-000000?style=flat)                                             | **POSIX 线程**：`pthread.h`，用于基于 Unix 的系统中的多线程                             |
| ![Standard Lib](https://img.shields.io/badge/C%20Standard%20Library-000000?style=flat)                               | **C 标准库**：核心库，包括 `stdio.h`, `stdlib.h`, `string.h`, `time.h`            |
| ![OOP](https://img.shields.io/badge/Object--Oriented%20Programming-000000?style=flat)                                | **C 中的面向对象编程**：通过结构体和函数指针实现封装、抽象和多态                                     |
| ![Algorithms](https://img.shields.io/badge/Algorithms%20\(Stack,%20Queue,%20List\)-000000?style=flat)                | **算法**：栈、队列、双端队列和链表等数据结构的实现                                             |
| ![Git](https://img.shields.io/badge/Git-F05032?style=flat\&logo=git\&logoColor=white)                                | **Git**：用于管理代码变更的版本控制系统                                                 |
| ![GitHub](https://img.shields.io/badge/GitHub-181717?style=flat\&logo=github\&logoColor=white)                       | **GitHub**：用于版本控制和协作的平台，支持代码共享和审查                                       |
| ![Vim](https://img.shields.io/badge/Vim-019733?style=flat\&logo=vim\&logoColor=white)                                | **Vim**：高度可配置的文本编辑器，用于高效的文本编辑                                           |
| ![Visual Studio](https://img.shields.io/badge/Visual%20Studio-5C2D91?style=flat\&logo=visualstudio\&logoColor=white) | **Visual Studio**：具有强大调试、代码分析和测试工具的 C/C++ 集成开发环境                        |
| ![VS Code](https://img.shields.io/badge/VSCode-007ACC?style=flat\&logo=visualstudiocode\&logoColor=white)            | **Visual Studio Code**：用于编写和调试的源代码编辑器                                   |
| ![CLion](https://img.shields.io/badge/CLion-000000?style=flat\&logo=jetbrains\&logoColor=white)                      | **CLion**：JetBrains 的 C/C++ 集成开发环境，具有强大的代码分析、重构和 CMake 集成               |

## 🖥️ 平台兼容性

此项目已在以下平台测试并运行：

* 🪟 **Windows** 10 / 11
* 🐧 **Linux**
* 🍎 **macOS**

## 🛣️ 路线图

* [x] 在 C 中实现面向对象编程
* [x] 线程和互斥体抽象
* [x] 控制台 I/O 实用工具
* [x] 原始类型输入扫描器
* [x] 数据结构：栈、队列、链表
* [ ] 高级文件实用工具
* [ ] 使用 SDL 或 ncurses 的 GUI 层（计划中）

## 🏗️ 操作系统特定的构建说明

### 🪟 Windows (GCC MinGW)

```bash
gcc -std=c99 -Wall -I inc -o main.exe src/*.c
main.exe
```

### 🪟 Windows (MSVC 命令提示符)

```cmd
cl /I inc /Fe:main.exe src\*.c
main.exe
```

### 🐧 Linux / 🍎 macOS

```bash
gcc -std=c99 -Wall -I inc -o main src/*.c -lpthread
./main
```

> **注意**：需要加入 `-lpthread` 以支持多线程。

## 📂 目录结构

```
Object-Oriented-C-Language/
├── inc/                   # 头文件
│   ├── algorithm.h
│   ├── console.h
│   ├── main.h
│   ├── Scanner.h
│   ├── System.h
│   └── thread.h
├── src/                   # 源文件
│   ├── algorithm.c
│   ├── console.c
│   ├── main.c
│   ├── Scanner.c
│   ├── System.c
│   └── thread.c
├── translations/          # 翻译文件夹
│   ├── ja.md              # 日语
│   ├── ko.md              # 韩语
│   ├── ru.md              # 俄语
│   └── zh.md              # 中文 （本文件）
├── LICENSE                # 许可证信息
└── README.md              # 项目描述
```

## 🔧 开发与构建

### 要求

* GCC（版本 ≥ 4.8）
* Make（可选）

### 手动编译

```bash
# 在项目根目录下
gcc -std=c99 -Wall -I inc/ -o main src/*.c
```

### 示例 Makefile

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

## 🚀 如何运行

```bash
# 构建完成后
./main
```

该示例将自动创建对象，调用方法并测试线程。

## 📑 API 结构

### 1. System & 基本类型

* **SYSTEM out**

  * `out.printf(const string format, ...)` ：格式化输出
  * `out.println(const string format, ...)` ：格式化输出并换行

* **SYSTEM in**

  * `in.read() -> int32_t` ：从 stdin 读取一个字符并以整数形式返回

* **File**

  * 构造函数：`File new_File(const string path, const string mode)`
  * 方法：

    * `f.scanf(const string format, ...)` ：从文件格式化读取
    * `f.printf(const string format, ...)` ：格式化输出到文件
    * `f.println(const string format, ...)` ：输出并换行到文件
    * `f.open(const string path, const string mode)` ：打开文件
    * `f.close()` ：关闭文件
    * `f.readLine() -> string` ：从文件读取一行

* **Time**

  * 构造函数：`Time new_Time(void)`
  * 方法：

    * `t.getSystemTime(Time* t)` ：获取当前系统时间
    * `t.getTime(Time* t)` ：获取内部时间值
    * `t.setTime(...)` ：设置时间（年、月、日、时、分、秒）
    * `t.start()` / `t.stop()` ：定时器线程控制

* **原始类型包装构造函数**

  * `new_String(string s)`

    * 方法：`s.length()`, `s.charAt(index)`, `s.substring(start, end)`, `s.equals(...)`, `s.toCharArray()`
    * 静态：`String.valueOf(...)`, `String.format(...)`

  * `new_Character(char c)`

    * 方法：`c.charValue()`, `c.equals(...)`, `Character.isDigit(char)`, `Character.isLetter(char)`

  * `new_Byte(...)`, `new_Short(...)`, `new_Integer(...)`, `new_Long(...)`, `new_Float(...)`, `new_Double(...)`, `new_Boolean(...)`

    * 常用方法：`x.getValue()`, `x.toString()`, `x.equals(...)`, `x.compareTo(...)`
    * 静态：`Wrapper.parse<Type>(...)`, `Wrapper.valueOf(...)`
    * Byte 特有：`b.byteValue()`, `b.toUnsigned()`, `Byte.parseByte(string, base)`
    * Boolean 特有：`b.booleanValue()`, `b.isTrue()`, `b.isFalse()`, `Boolean.parseBoolean(...)`

### 2. Thread & 互斥体

* **Thread**

  * 构造函数：`Thread new_Thread(void* (*function)(void*))`
  * 方法：

    * `start(...)`, `join()`, `detach()`, `cancel()`, `exit()`, `delete()`

* **Mutex**

  * 构造函数：`Mutex new_Mutex()`
  * 方法：

    * `lock()`, `unlock()`, `delete()`

### 3. Console

* **Console**

  * 构造函数：`Console new_console(void)`
  * 方法：

    * `print(...)`, `println(...)`, `readLine()`, `clear()`
    * `setColor(ColorType color)`, `resetColor()`, `kbhit() -> int`

### 4. Scanner

* **Scanner**

  * 构造函数：`Scanner new_Scanner(struct __stdin_t in)`
  * 方法：

    * `nextChar()`, `nextByte()`, `nextShort()`, `nextInt()`, `nextLong()`
    * `nextUByte()`, `nextUShort()`, `nextUInt()`, `nextULong()`
    * `nextBoolean()`, `nextFloat()`, `nextDouble()`, `nextLDouble()`
    * `next() -> string`, `nextLine() -> string`

    (默认使用空白字符作为分隔符，并支持行读取。)

### 5. 集合 (Algorithm)

* **Stack**

  * 构造函数：`Stack new_stack(size_t elementSize)`
  * 方法：`push(...)`, `pop() -> void*`, `clear()`, `delete()`

* **Queue**

  * 构造函数：`Queue new_queue(size_t elementSize)`
  * 方法：`push(...)`, `pop() -> void*`, `clear()`, `delete()`

* **Deque**

  * 构造函数：`Deque new_deque(size_t elementSize)`
  * 方法：`pushFront(...)`, `pushBack(...)`, `popFront()`, `popBack()`, `clear()`, `delete()`

* **List**

  * 构造函数：`List new_list(size_t elementSize)`
  * 方法：`add(...)`, `get(index)`, `remove(index)`, `size()`, `clear()`, `delete()`

## 🛠️ 贡献指南

1. **Fork** 本项目
2. **创建功能分支**：`git checkout -b feature/YourFeature`
3. **实现功能**
4. **编写测试并更新文档**
5. **创建 Pull Request**

在贡献之前请先打开 issue 讨论您的想法。

## 📄 许可证

本项目采用 [MIT 许可证](../LICENSE) 许可。
