# Object-Oriented C Language

> Это пример проекта, реализующего парадигму объектно-ориентированного программирования на чистом языке C.

---

Нажмите на ссылку ниже, чтобы просмотреть перевод на предпочитаемом языке:

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
  <img src="https://img.shields.io/github/languages/top/sunwookim05/Object-Oriented-C-Language?style=flat" alt="Top Language" />
  <img src="https://img.shields.io/github/commit-activity/t/sunwookim05/Object-Oriented-C-Language?style=flat" alt="Commits" />
  <img src="https://img.shields.io/github/last-commit/sunwookim05/Object-Oriented-C-Language?style=flat" alt="Last Commit" />
  <img src="https://img.shields.io/github/issues/sunwookim05/Object-Oriented-C-Language?style=flat" alt="Issues" />
  <img src="https://img.shields.io/github/issues-pr-closed/sunwookim05/Object-Oriented-C-Language?style=flat" alt="Closed Pull Requests" />
  <img src="https://img.shields.io/github/repo-size/sunwookim05/Object-Oriented-C-Language?style=flat" alt="Repo Size" />
  <img src="https://img.shields.io/github/license/sunwookim05/Object-Oriented-C-Language?style=flat" alt="License" />
  <img src="https://img.shields.io/github/v/release/sunwookim05/Object-Oriented-C-Language?style=flat" alt="Version" />
  <img src="https://img.shields.io/github/stars/sunwookim05/Object-Oriented-C-Language?style=flat" alt="Stars" />
  <img src="https://img.shields.io/github/forks/sunwookim05/Object-Oriented-C-Language?style=flat" alt="Forks" />
  <img src="https://img.shields.io/github/watchers/sunwookim05/Object-Oriented-C-Language?style=flat" alt="Watchers" />
</div>

## 📖 Обзор

Этот проект демонстрирует реализацию основных концепций ООП (абстракция, инкапсуляция, наследование, полиморфизм) с использованием только чистого языка C (стандарт C99) в модульной структуре. Различные системные компоненты, такие как `System`, `Thread`, `Console`, `Scanner`, `Algorithm`, представлены как объекты с помощью struct и указателей на функции.

## ⚙️ Основные возможности

* **System**: базовый ввод/вывод, файловый ввод/вывод, таймер, абстракция платформы
* **Thread**: создание и управление легковесными потоками
* **Console**: форматирование и управление консольным вводом/выводом
* **Scanner**: утилиты для работы с входным потоком
* **Algorithm**: коллекции Stack, Queue, Deque, List

## 🧰 Технологический стек

| Бейдж                                                                                                                | Описание                                                                                                     |
| -------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------ |
| ![C](https://img.shields.io/badge/C-00599C?style=flat\&logo=c\&logoColor=white)                                      | **C**: стандарт C99, реализация ООП с использованием struct и указателей на функции                          |
| ![GCC](https://img.shields.io/badge/GCC-333333?style=flat\&logo=gnu\&logoColor=white)                                | **GCC**: GNU Compiler Collection для сборки C-программ                                                       |
| ![Make](https://img.shields.io/badge/Make-064F8C?style=flat\&logo=cmake\&logoColor=white)                            | **Make**: инструмент автоматизации сборки файлов                                                             |
| ![Makefile](https://img.shields.io/badge/Makefile-000000?style=flat)                                                 | **Makefile**: файл конфигурации для Make                                                                     |
| ![Windows](https://img.shields.io/badge/Windows-0078D4?style=flat\&logo=windows\&logoColor=white)                    | **Windows API**: системные функции Windows и поддержка многопоточности (`windows.h`, `conio.h`, `process.h`) |
| ![Linux](https://img.shields.io/badge/Linux-000000?style=flat\&logo=linux\&logoColor=white)                          | **Linux**: широко используемая открытая ОС                                                                   |
| ![MACOS](https://img.shields.io/badge/MACOS-000000?style=flat\&logo=apple\&logoColor=white)                          | **macOS**: Unix-подобная ОС для оборудования Apple                                                           |
| ![POSIX](https://img.shields.io/badge/POSIX%20Threads-000000?style=flat)                                             | **POSIX Threads**: поддержка многопоточности в Unix-системах (`pthread.h`)                                   |
| ![Standard Lib](https://img.shields.io/badge/C%20Standard%20Library-000000?style=flat)                               | **Стандартная библиотека C**: `stdio.h`, `stdlib.h`, `string.h`, `time.h` и др.                              |
| ![OOP](https://img.shields.io/badge/Object--Oriented%20Programming-000000?style=flat)                                | **ООП в C**: инкапсуляция, абстракция, полиморфизм через struct и указатели на функции                       |
| ![Algorithms](https://img.shields.io/badge/Algorithms%20%28Stack%2C%20Queue%2C%20List%29-000000?style=flat)          | **Алгоритмы**: реализация Stack, Queue, Deque, List                                                          |
| ![Git](https://img.shields.io/badge/Git-F05032?style=flat\&logo=git\&logoColor=white)                                | **Git**: система контроля версий                                                                             |
| ![GitHub](https://img.shields.io/badge/GitHub-181717?style=flat\&logo=github\&logoColor=white)                       | **GitHub**: платформа для обмена и рецензирования кода                                                       |
| ![Vim](https://img.shields.io/badge/Vim-019733?style=flat\&logo=vim\&logoColor=white)                                | **Vim**: настраиваемый текстовый редактор                                                                    |
| ![Visual Studio](https://img.shields.io/badge/Visual%20Studio-5C2D91?style=flat\&logo=visualstudio\&logoColor=white) | **Visual Studio**: IDE для C/C++ с мощными инструментами отладки и анализа кода                              |
| ![VS Code](https://img.shields.io/badge/VSCode-007ACC?style=flat\&logo=visualstudiocode\&logoColor=white)            | **VS Code**: редактор кода и отладки                                                                         |
| ![CLion](https://img.shields.io/badge/CLion-000000?style=flat\&logo=jetbrains\&logoColor=white)                      | **CLion**: IDE от JetBrains с поддержкой CMake, анализа и рефакторинга                                       |

## 🖥️ Поддерживаемые платформы

Проект протестирован и работает на следующих платформах:

* 🪟 **Windows 10 / 11**
* 🐧 **Linux**
* 🍎 **macOS**

## 🛣️ Дорожная карта

* [x] Реализация ООП в C
* [x] Абстракция потоков и мьютексов
* [x] Утилиты консольного ввода/вывода
* [x] Базовый Scanner
* [x] Структуры данных: Stack, Queue, List
* [ ] Расширенные файловые утилиты
* [ ] GUI-слой с использованием SDL или ncurses (в планах)

## 🏗️ Инструкции по сборке для ОС

### 🪟 Windows (GCC MinGW)

```bash
gcc -std=c99 -Wall -I inc -o main.exe src/*.c
main.exe
```

### 🪟 Windows (командная строка MSVC)

```cmd
cl /I inc /Fe:main.exe src\*.c
main.exe
```

### 🐧 Linux / 🍎 macOS

```bash
gcc -std=c99 -Wall -I inc -o main src/*.c -lpthread
./main
```

> **Примечание**: для поддержки многопоточности требуется `-lpthread`.

## 📂 Структура каталогов

```
Object-Oriented-C-Language/
├── inc/                      # заголовочные файлы
│   ├── algorithm.h
│   ├── console.h
│   ├── main.h
│   ├── Scanner.h
│   ├── System.h
│   └── thread.h
├── src/                      # исходники
│   ├── algorithm.c
│   ├── console.c
│   ├── main.c
│   ├── Scanner.c
│   ├── System.c
│   └── thread.c
├── translations/             # файлы переводов
│   ├── ar.md                 # арабский
│   ├── es.md                 # испанский
│   ├── fr.md                 # французский
│   ├── hi.md                 # хинди
│   ├── it.md                 # итальянский
│   ├── ja.md                 # японский
│   ├── ko.md                 # корейский
│   ├── pt.md                 # португальский
│   ├── ru.md                 # русский  (этот файл)
│   └── zh.md                 # китайский
├── LICENSE                   # лицензия
└── README.md                 # описание проекта
```

## 🔧 Разработка и сборка

### Требования

* GCC (версия ≥ 4.8)
* Make (опционально)

### Ручная компиляция

```bash
# Выполнить в корне проекта
gcc -std=c99 -Wall -I inc/ -o main src/*.c
```

### Пример Makefile

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

## 🚀 Запуск

```bash
# После сборки
./main
```

Пример создаёт объекты, вызывает методы и тестирует потоки.

## 📑 Структура API

### 1. System и базовые типы

* **SYSTEM out**

  * `out.printf(const string format, ...)`: форматированный вывод
  * `out.println(const string format, ...)`: форматированный вывод с новой строкой

* **SYSTEM in**

  * `in.read() -> int32_t`: чтение символа из stdin и возврат как int32\_t

* **File**

  * Конструктор: `File new_File(const string path, const string mode)`
  * Методы:

    * `f.scanf(const string format, ...)`: чтение форматированного ввода из файла
    * `f.printf(const string format, ...)`: форматированный вывод в файл
    * `f.println(const string format, ...)`: вывод с новой строкой
    * `f.open(const string path, const string mode)`: открыть файл
    * `f.close()`: закрыть файл
    * `f.readLine() -> string`: чтение одной строки из файла

* **Time**

  * Конструктор: `Time new_Time(void)`
  * Методы:

    * `t.getSystemTime(Time* t)`: получить текущее системное время
    * `t.getTime(Time* t)`: получить внутреннее время
    * `t.setTime(...)`: установить время (год, месяц, день, час, минута, секунда)
    * `t.start()` / `t.stop()`: управление потоковым таймером

* **Конструкторы обёрток примитивных типов**

  * `new_String(string s)`

    * Методы: `s.length()`, `s.charAt(index)`, `s.substring(start, end)`, `s.equals(...)`, `s.toCharArray()`
    * Статические методы: `String.valueOf(...)`, `String.format(...)`

  * `new_Character(char c)`

    * Методы: `c.charValue()`, `c.equals(...)`, `Character.isDigit(char)`, `Character.isLetter(char)`

  * `new_Byte(...)`, `new_Short(...)`, `new_Integer(...)`, `new_Long(...)`, `new_Float(...)`, `new_Double(...)`, `new_Boolean(...)`

    * Общие методы: `x.getValue()`, `x.toString()`, `x.equals(...)`, `x.compareTo(...)`
    * Статические методы: `Wrapper.parse<Type>(...)`, `Wrapper.valueOf(...)`
    * Специфичные для Byte: `b.byteValue()`, `b.toUnsigned()`, `Byte.parseByte(string, base)`
    * Специфичные для Boolean: `b.booleanValue()`, `b.isTrue()`, `b.isFalse()`, `Boolean.parseBoolean(...)`

### 2. Thread и Mutex

* **Thread**

  * Конструктор: `Thread new_Thread(void* (*function)(void*))`
  * Методы:

    * `start(...)`, `join()`, `detach()`, `cancel()`, `exit()`, `delete()`

* **Mutex**

  * Конструктор: `Mutex new_Mutex()`
  * Методы: 
  
    * `lock()`, `unlock()`, `delete()`

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
    * `next() -> string`, `nextLine() -> string`

    (По умолчанию используеются пробелы в качестве разделителей, также поддерживается чтение по строкам.)

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

## 🛠️ Руководство по внесению вклада

1. **Fork** репозиторий
2. **Создайте ветку**: `git checkout -b feature/YourFeature`
3. **Реализуйте функциональность**
4. **Напишите тесты и обновите документацию**
5. **Создайте Pull Request**

Для обсуждения идей создайте issue.

## 📄 Лицензия

Этот проект лицензирован под [MIT License](../LICENSE).
