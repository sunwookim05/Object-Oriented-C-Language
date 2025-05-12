# Object-Oriented C Language

> Пример проекта, реализующего парадигмы объектно-ориентированного программирования с использованием чистого C.

---

Вы можете просмотреть перевод на предпочитаемом языке, щелкнув по соответствей ссылке.

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
  <img src="https://img.shields.io/badge/Visual%20Studio-5C2D91?style=flat&logo=visualstudio&logoColor=white" alt="Visual Studio" />
  <img src="https://img.shields.io/badge/VSCode-007ACC?style=flat&logo=visualstudiocode&logoColor=white" alt="VSCode" />
  <img src="https://img.shields.io/badge/CLion-000000?style=flat&logo=jetbrains&logoColor=white" alt="CLion" />

  <br />
  <img src="https://img.shields.io/badge/Commits-1234-blue?style=flat" alt="Commits" />
  <img src="https://img.shields.io/badge/License-MIT-green?style=flat" alt="License" />
  <img src="https://img.shields.io/badge/Version-1.0.0-orange?style=flat" alt="Version" />
</div>

## 📖 Обзор

Этот проект демонстрирует реализацию ключевых концепций объектно-ориентированного программирования (абстракция, инкапсуляция, наследование, полиморфизм) в модульной структуре, используя только язык C (стандарт C99). Различные системные компоненты (`System`), многопоточность (`Thread`), консольный ввод-вывод (`Console`), сканер ввода (`Scanner`) и алгоритмы (`Algorithm`) представлены как объекты с помощью структур и указателей на функции.

## ⚙️ Основные возможности

* **System**: базовый ввод-вывод, работа с файлами, таймер, абстракция платформы
* **Thread**: создание и управление легковесными потоками
* **Console**: форматирование и управление консольным вводом-выводом
* **Scanner**: утилиты для потоков ввода
* **Algorithm**: коллекции Stack, Queue, Deque, List

## 🧰 Технологический стек

| Значок                                                                                                               | Описание                                                                                             |
| -------------------------------------------------------------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------- |
| ![C](https://img.shields.io/badge/C-00599C?style=flat\&logo=c\&logoColor=white)                                      | **C**: стандарт C99, реализация ООП с помощью структур и указателей на функции                       |
| ![GCC](https://img.shields.io/badge/GCC-333333?style=flat\&logo=gnu\&logoColor=white)                                | **GCC**: GNU Compiler Collection, используется для сборки программ на C                              |
| ![Make](https://img.shields.io/badge/Make-064F8C?style=flat\&logo=cmake\&logoColor=white)                            | **Make**: инструмент автоматизации сборки                                                            |
| ![Makefile](https://img.shields.io/badge/Makefile-000000?style=flat)                                                 | **Makefile**: файл конфигурации для Make                                                             |
| ![Windows](https://img.shields.io/badge/Windows-0078D4?style=flat\&logo=windows\&logoColor=white)                    | **Windows API**: системные функции и поддержка многопоточности (`windows.h`, `conio.h`, `process.h`) |
| ![Linux](https://img.shields.io/badge/Linux-000000?style=flat\&logo=linux\&logoColor=white)                          | **Linux**: открытая операционная система                                                             |
| ![MACOS](https://img.shields.io/badge/MACOS-000000?style=flat\&logo=apple\&logoColor=white)                          | **macOS**: Unix-подобная операционная система Apple                                                  |
| ![POSIX](https://img.shields.io/badge/POSIX%20Threads-000000?style=flat)                                             | **POSIX Threads**: многопоточность на Unix-системах (`pthread.h`)                                    |
| ![Standard Lib](https://img.shields.io/badge/C%20Standard%20Library-000000?style=flat)                               | **Стандартная библиотека C**: `stdio.h`, `stdlib.h`, `string.h`, `time.h` и др.                      |
| ![OOP](https://img.shields.io/badge/Object--Oriented%20Programming-000000?style=flat)                                | **ООП в C**: инкапсуляция, абстракция и полиморфизм с помощью структур и указателей на функции       |
| ![Algorithms](https://img.shields.io/badge/Algorithms%20\(Stack,%20Queue,%20List\)-000000?style=flat)                | **Алгоритмы**: реализации структур данных stack, queue, deque, list                                  |
| ![Git](https://img.shields.io/badge/Git-F05032?style=flat\&logo=git\&logoColor=white)                                | **Git**: система контроля версий                                                                     |
| ![GitHub](https://img.shields.io/badge/GitHub-181717?style=flat\&logo=github\&logoColor=white)                       | **GitHub**: платформа для совместной работы и ревью кода                                             |
| ![Vim](https://img.shields.io/badge/Vim-019733?style=flat\&logo=vim\&logoColor=white)                                | **Vim**: настраиваемый редактор для эффективного редактирования текста                               |
| ![Visual Studio](https://img.shields.io/badge/Visual%20Studio-5C2D91?style=flat\&logo=visualstudio\&logoColor=white) | **Visual Studio**: IDE с инструментами отладки, анализа кода и тестирования                          |
| ![VSCode](https://img.shields.io/badge/VSCode-007ACC?style=flat\&logo=visualstudiocode\&logoColor=white)             | **Visual Studio Code**: редактор исходного кода                                                      |
| ![CLion](https://img.shields.io/badge/CLion-000000?style=flat\&logo=jetbrains\&logoColor=white)                      | **CLion**: IDE от JetBrains для разработки на C/C++                                                  |

## 🖥️ Совместимость с платформами

Проект протестирован и работает на следующих платформах:

* 🪟 **Windows** 10 / 11
* 🐧 **Linux**
* 🍎 **macOS**

## 🛣️ Дорожная карта

* [x] ООП на языке C
* [x] Абстракция потоков и мьютексов
* [x] Консольные утилиты ввода-вывода
* [x] Вводной сканер
* [x] Структуры данных: стек, очередь, список
* [ ] Расширенные файловые утилиты
* [ ] GUI-слой с использованием SDL или ncurses (планируется)

## 🏗️ Инструкции по сборке для ОС

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

> **Примечание**: для поддержки многопоточности необходим флаг `-lpthread`.

## 📂 Структура каталогов

````
Object-Oriented-C-Language/
├── inc/                   # Заголовочные файлы
│   ├── algorithm.h
│   ├── console.h
│   ├── main.h
│   ├── Scanner.h
│   ├── System.h
│   └── thread.h
├── src/                   # Исходные файлы
│   ├── algorithm.c
│   ├── console.c
│   ├── main.c
│   ├── Scanner.c
│   ├── System.c
│   └── thread.c
├── translations/          # Папка переводов
│   ├── ja.md              # Японский
│   ├── ko.md              # Корейский
│   ├── ru.md              # Русский (этот файл)
│   └── zh.md              # Китайский
├── LICENSE                # Информация о лицензии
└── README.md              # Описание проекта 
````

## 🔧 Разработка и сборка

### Требования

* GCC (версия ≥ 4.8)
* Make (по желанию)

### Ручная компиляция

```bash
# Из корневой директории проекта
gcc -std=c99 -Wall -I inc/ -o main src/*.c
````

### Пример Makefile

```makefile
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

## 🚀 Запуск

```bash
# После сборки
./main
```

Пример автоматически создаёт объекты, вызывает методы и тестирует потоки.

## 📑 Структура API

### 1. System и базовые типы

* **SYSTEM out**

  * `out.printf(const string format, ...)` : форматированный вывод
  * `out.println(const string format, ...)` : вывод с переводом строки

* **SYSTEM in**

  * `in.read() -> int32_t` : чтение одного символа из stdin в виде целого числа

* **File**

  * Конструктор: `File new_File(const string path, const string mode)`
  * Методы:

    * `f.scanf(const string format, ...)` : форматированный ввод из файла
    * `f.printf(const string format, ...)` : форматированный вывод в файл
    * `f.println(const string format, ...)` : вывод с переводом строки
    * `f.open(const string path, const string mode)` : открытие файла
    * `f.close()` : закрытие файла
    * `f.readLine() -> string` : чтение одной строки из файла

### 2. Thread и Mutex

* **Thread**

  * Конструктор: `Thread new_Thread(void* (*function)(void*))`
  * Методы: `start(...)`, `join()`, `detach()`, `cancel()`, `exit()`, `delete()`

* **Mutex**

  * Конструктор: `Mutex new_Mutex()`
  * Методы: `lock()`, `unlock()`, `delete()`

### 3. Console

* **Console**

  * Конструктор: `Console new_console(void)`
  * Методы:

    * `print(...)`, `println(...)`, `readLine()`, `clear()`
    * `setColor(ColorType color)`, `resetColor()`, `kbhit() -> int`

### 4. Scanner

* **Scanner**

  * Конструктор: `Scanner new_Scanner(struct __stdin_t in)`
  * Методы:

    * `nextChar()`, `nextByte()`, `nextShort()`, `nextInt()`, `nextLong()`
    * `nextUByte()`, `nextUShort()`, `nextUInt()`, `nextULong()`
    * `nextBoolean()`, `nextFloat()`, `nextDouble()`, `nextLDouble()`
    * `next() -> string`, `nextLine() -> string` (использует пробелы в качестве разделителей по умолчанию)

### 5. Коллекции (Algorithm)

* **Stack**

  * Конструктор: `Stack new_stack(size_t elementSize)`
  * Методы: `push(...)`, `pop() -> void*`, `clear()`, `delete()`

* **Queue**

  * Конструктор: `Queue new_queue(size_t elementSize)`
  * Методы: `push(...)`, `pop() -> void*`, `clear()`, `delete()`

* **Deque**

  * Конструктор: `Deque new_deque(size_t elementSize)`
  * Методы: `pushFront(...)`, `pushBack(...)`, `popFront()`, `popBack()`, `clear()`, `delete()`

* **List**

  * Конструктор: `List new_list(size_t elementSize)`
  * Методы: `add(...)`, `get(index)`, `remove(index)`, `size()`, `clear()`, `delete()`

## 🛠️ Руководство по внесению изменений

1. Форкните проект.
2. Создайте ветку функции: `git checkout -b feature/YourFeature`
3. Реализуйте функцию.
4. Напишите тесты и обновите документацию.
5. Создайте Pull Request для обсуждения изменений.

Открывайте issue перед внесением изменений для обсуждения идей.

## 📄 Лицензия

Этот проект лицензируется под лицензией [MIT](../LICENSE).
