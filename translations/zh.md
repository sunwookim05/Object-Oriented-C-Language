# Object-Oriented C Language

> 这是一个使用纯 C 语言实现面向对象编程范式的示例项目。

---

以下链接可点击，以您喜欢的语言查看翻译内容：

🌍 [English](../README.md) | [한국어](ko.md) | [中文](zh.md) | [日本語](ja.md) | [Русский](ru.md) | [Français](fr.md) | [Español](es.md) | [Italiano](it.md) | [Português](pt.md) | [हिन्दी](hi.md) | [العربية](ar.md)

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
  <img src="https://img.shields.io/github/commit-activity/t/sunwookim05/Object-Oriented-C-Language?style=flat" alt="Commits" />
  <img src="https://img.shields.io/github/last-commit/sunwookim05/Object-Oriented-C-Language?style=flat" alt="Last Commit" />
  <img src="https://img.shields.io/github/stars/sunwookim05/Object-Oriented-C-Language?style=flat" alt="Stars" />
  <img src="https://img.shields.io/github/forks/sunwookim05/Object-Oriented-C-Language?style=flat" alt="Forks" />
  <img src="https://img.shields.io/github/issues/sunwookim05/Object-Oriented-C-Language?style=flat" alt="Issues" />
  <img src="https://img.shields.io/github/repo-size/sunwookim05/Object-Oriented-C-Language?style=flat" alt="Repo Size" />
  <img src="https://img.shields.io/github/license/sunwookim05/Object-Oriented-C-Language?style=flat" alt="License" />
  <img src="https://img.shields.io/github/v/release/sunwookim05/Object-Oriented-C-Language?style=flat" alt="Version" />
</div>

## 📖 概要

本项目仅使用纯 C 语言（C99 标准）以模块化结构实现面向对象编程的核心概念（抽象、封装、继承、多态）。各系统组件如 `System`、`Thread`、`Console`、`Scanner`、`Algorithm` 等，均使用 struct 和函数指针表示对象。

## ⚙️ 主要功能

* **System**：基本输入输出、文件读写、定时器、平台抽象
* **Thread**：轻量级线程的创建与管理
* **Console**：控制台输入输出的格式化与控制
* **Scanner**：输入流工具
* **Algorithm**：Stack、Queue、Deque、List 等集合

## 🧰 技术栈

| 徽章                                                                                                                   | 描述                                                                      |
| -------------------------------------------------------------------------------------------------------------------- | ----------------------------------------------------------------------- |
| ![C](https://img.shields.io/badge/C-00599C?style=flat\&logo=c\&logoColor=white)                                      | **C 语言**：C99 标准，使用 struct 与函数指针实现面向对象编程                                 |
| ![GCC](https://img.shields.io/badge/GCC-333333?style=flat\&logo=gnu\&logoColor=white)                                | **GCC**：GNU 编译器集合，用于构建 C 程序                                             |
| ![Make](https://img.shields.io/badge/Make-064F8C?style=flat\&logo=cmake\&logoColor=white)                            | **Make**：用于自动化编译与链接源文件的工具                                               |
| ![Makefile](https://img.shields.io/badge/Makefile-000000?style=flat)                                                 | **Makefile**：编写 Make 命令的构建指令文件                                          |
| ![Windows](https://img.shields.io/badge/Windows-0078D4?style=flat\&logo=windows\&logoColor=white)                    | **Windows API**：Windows 系统函数与多线程支持（`windows.h`, `conio.h`, `process.h`） |
| ![Linux](https://img.shields.io/badge/Linux-000000?style=flat\&logo=linux\&logoColor=white)                          | **Linux**：广泛使用的开源操作系统                                                   |
| ![MACOS](https://img.shields.io/badge/MACOS-000000?style=flat\&logo=apple\&logoColor=white)                          | **macOS**：支持 Unix 命令的 Mac 硬件操作系统                                        |
| ![POSIX](https://img.shields.io/badge/POSIX%20Threads-000000?style=flat)                                             | **POSIX 线程**：Unix 系统的多线程支持（`pthread.h`）                                 |
| ![Standard Lib](https://img.shields.io/badge/C%20Standard%20Library-000000?style=flat)                               | **C 标准库**：核心库如 `stdio.h`, `stdlib.h`, `string.h`, `time.h`              |
| ![OOP](https://img.shields.io/badge/Object--Oriented%20Programming-000000?style=flat)                                | **C 中的 OOP**：通过 struct 和函数指针实现封装、抽象、多态                                  |
| ![Algorithms](https://img.shields.io/badge/Algorithms%20%28Stack%2C%20Queue%2C%20List%29-000000?style=flat)          | **算法**：实现 Stack、Queue、Deque、List 等数据结构                                  |
| ![Git](https://img.shields.io/badge/Git-F05032?style=flat\&logo=git\&logoColor=white)                                | **Git**：版本控制系统                                                          |
| ![GitHub](https://img.shields.io/badge/GitHub-181717?style=flat\&logo=github\&logoColor=white)                       | **GitHub**：代码共享与审查平台                                                    |
| ![Vim](https://img.shields.io/badge/Vim-019733?style=flat\&logo=vim\&logoColor=white)                                | **Vim**：高效可定制的文本编辑器                                                     |
| ![Visual Studio](https://img.shields.io/badge/Visual%20Studio-5C2D91?style=flat\&logo=visualstudio\&logoColor=white) | **Visual Studio**：集成调试、代码分析与测试工具的 C/C++ IDE                             |
| ![VS Code](https://img.shields.io/badge/VSCode-007ACC?style=flat\&logo=visualstudiocode\&logoColor=white)            | **Visual Studio Code**：代码编辑与调试源代码编辑器                                    |
| ![CLion](https://img.shields.io/badge/CLion-000000?style=flat\&logo=jetbrains\&logoColor=white)                      | **CLion**：支持代码分析、重构与 CMake 的 JetBrains C/C++ IDE                        |

## 🖥️ 平台兼容性

本项目已在以下平台测试与运行：

* 🪟 **Windows 10 / 11**
* 🐧 **Linux**
* 🍎 **macOS**

## 🛣️ 路线图

* [x] 在 C 中实现面向对象编程
* [x] 线程与互斥锁抽象
* [x] 控制台 I/O 工具
* [x] 基本类型 Scanner
* [x] 数据结构：Stack、Queue、List
* [ ] 高级文件工具
* [ ] 使用 SDL 或 ncurses 的 GUI 层（计划中）

## 🏗️ 各操作系统构建步骤

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

> **注意**：多线程支持需要 `-lpthread`。

## 📂 目录结构

```
Object-Oriented-C-Language/
├── inc/                      # 头文件
│   ├── algorithm.h
│   ├── console.h
│   ├── main.h
│   ├── Scanner.h
│   ├── System.h
│   └── thread.h
├── src/                      # 源文件
│   ├── algorithm.c
│   ├── console.c
│   ├── main.c
│   ├── Scanner.c
│   ├── System.c
│   └── thread.c
├── translations/             # 翻译文件
│   ├── ar.md                 # 阿拉伯语
│   ├── es.md                 # 西班牙语
│   ├── fr.md                 # 法语
│   ├── hi.md                 # 印地语
│   ├── it.md                 # 意大利语
│   ├── ja.md                 # 日语
│   ├── ko.md                 # 韩语
│   ├── pt.md                 # 葡萄牙语
│   ├── ru.md                 # 俄语
│   └── zh.md                 # 中文 （本文件）
├── LICENSE                   # 许可证信息
└── README.md                 # 项目说明
```

## 🔧 开发与构建

### 要求

* GCC (版本 ≥ 4.8)
* Make (可选)

### 手动编译

```bash
# 在项目根目录执行
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

## 🚀 运行

```bash
# 构建后
./main
```

示例将创建对象、调用方法并测试线程。

## 📑 API 结构

### 1. System 与基本类型

* **SYSTEM out**

  * `out.printf(const string format, ...)`：格式化输出
  * `out.println(const string format, ...)`：带换行的格式化输出

* **SYSTEM in**

  * `in.read() -> int32_t`：从 stdin 读取字符并返回整型

* **File**

  * 构造函数：`File new_File(const string path, const string mode)`
  * 方法：

    * `f.scanf(const string format, ...)`：从文件读取格式化输入
    * `f.printf(const string format, ...)`：向文件写入格式化输出
    * `f.println(const string format, ...)`：带换行输出
    * `f.open(const string path, const string mode)`：打开文件
    * `f.close()`：关闭文件
    * `f.readLine() -> string`：从文件读取一行

* **Time**

  * 构造函数：`Time new_Time(void)`
  * 方法：

    * `t.getSystemTime(Time* t)`：获取当前系统时间
    * `t.getTime(Time* t)`：获取内部时间值
    * `t.setTime(...)`：设置时间（年、月、日、时、分、秒）
    * `t.start()` / `t.stop()`：计时器线程控制

* **基本类型包装构造函数**

  * `new_String(string s)`

    * 方法：`s.length()`, `s.charAt(index)`, `s.substring(start, end)`, `s.equals(...)`, `s.toCharArray()`
    * 静态方法：`String.valueOf(...)`, `String.format(...)`

  * `new_Character(char c)`

    * 方法：`c.charValue()`, `c.equals(...)`, `Character.isDigit(char)`, `Character.isLetter(char)`

  * `new_Byte(...)`, `new_Short(...)`, `new_Integer(...)`, `new_Long(...)`, `new_Float(...)`, `new_Double(...)`, `new_Boolean(...)`

    * 通用方法：`x.getValue()`, `x.toString()`, `x.equals(...)`, `x.compareTo(...)`
    * 静态方法：`Wrapper.parse<Type>(...)`, `Wrapper.valueOf(...)`
    * Byte 特有：`b.byteValue()`, `b.toUnsigned()`, `Byte.parseByte(string, base)`
    * Boolean 特有：`b.booleanValue()`, `b.isTrue()`, `b.isFalse()`, `Boolean.parseBoolean(...)`

### 2. Thread 与 Mutex

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

    （默认使用空白作为分隔符，也支持逐行读取。）

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

1. **Fork** 本仓库
2. **创建功能分支**：`git checkout -b feature/YourFeature`
3. **实现功能**
4. **编写测试并更新文档**
5. **创建 Pull Request**

如需讨论想法，请先创建 issue。

## 📄 许可证

本项目根据 [MIT License](../LICENSE) 许可。
