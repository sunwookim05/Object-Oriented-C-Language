# Object-Oriented C Language

> Un proyecto de ejemplo que implementa el paradigma de programación orientada a objetos utilizando únicamente el lenguaje C puro.

---

A continuación, haz clic en el enlace para ver el contenido traducido al idioma que prefieras.

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
  <img src="https://img.shields.io/github/issues-pr/sunwookim05/Object-Oriented-C-Language?style=flat" alt="Open Pull Requests" />
  <img src="https://img.shields.io/github/issues-pr-closed/sunwookim05/Object-Oriented-C-Language?style=flat" alt="Closed Pull Requests" />
  <img src="https://img.shields.io/github/repo-size/sunwookim05/Object-Oriented-C-Language?style=flat" alt="Repo Size" />
  <img src="https://img.shields.io/github/license/sunwookim05/Object-Oriented-C-Language?style=flat" alt="License" />
  <img src="https://img.shields.io/github/v/release/sunwookim05/Object-Oriented-C-Language?style=flat" alt="Version" />
  <img src="https://img.shields.io/github/stars/sunwookim05/Object-Oriented-C-Language?style=flat" alt="Stars" />
  <img src="https://img.shields.io/github/forks/sunwookim05/Object-Oriented-C-Language?style=flat" alt="Forks" />
  <img src="https://img.shields.io/github/watchers/sunwookim05/Object-Oriented-C-Language?style=flat" alt="Watchers" />
</div>

## 📖 Descripción general

Este proyecto es un ejemplo que implementa los conceptos clave de la programación orientada a objetos (abstracción, encapsulación, herencia, polimorfismo) utilizando únicamente C puro (estándar C99) en una estructura modular. Diferentes componentes del sistema (`System`), hilos (`Thread`), entrada/salida de consola (`Console`), escaneo de entrada (`Scanner`) y algoritmos (`Algorithm`) se representan como objetos mediante `struct` y punteros a funciones.

## ⚙️ Funcionalidades principales

* **System**: entrada/salida básica, entrada/salida de archivos, temporizador, abstracción de plataforma
* **Thread**: creación y gestión de hilos ligeros
* **Console**: formateo y control de entrada/salida de consola
* **Scanner**: utilidades para flujos de entrada
* **Algorithm**: colecciones Stack, Queue, Deque, List

## 🧰 Stack tecnológico

| Insignia                                                                                                             | Descripción                                                                             |
| -------------------------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------- |
| ![C](https://img.shields.io/badge/C-00599C?style=flat\&logo=c\&logoColor=white)                                      | **Lenguaje C**: estándar C99, implementación de POO con `struct` y punteros a funciones |
| ![GCC](https://img.shields.io/badge/GCC-333333?style=flat\&logo=gnu\&logoColor=white)                                | **GCC**: GNU Compiler Collection para compilar programas en C                           |
| ![Make](https://img.shields.io/badge/Make-064F8C?style=flat\&logo=cmake\&logoColor=white)                            | **Make**: herramienta de automatización de compilación                                  |
| ![Makefile](https://img.shields.io/badge/Makefile-000000?style=flat)                                                 | **Makefile**: archivo de instrucciones de compilación                                   |
| ![Windows](https://img.shields.io/badge/Windows-0078D4?style=flat\&logo=windows\&logoColor=white)                    | **Windows API**: funciones del sistema y soporte multihilo                              |
| ![Linux](https://img.shields.io/badge/Linux-FCC624?style=flat\&logo=linux\&logoColor=black)                          | **Linux**: sistema operativo de código abierto                                          |
| ![MACOS](https://img.shields.io/badge/MACOS-000000?style=flat\&logo=apple\&logoColor=white)                          | **macOS**: sistema operativo Unix compatible                                            |
| ![POSIX](https://img.shields.io/badge/POSIX%20Threads-000000?style=flat)                                             | **Hilos POSIX**: soporte de multihilo en sistemas Unix                                  |
| ![Standard Lib](https://img.shields.io/badge/C%20Standard%20Library-000000?style=flat)                               | **Biblioteca estándar de C**: `stdio.h`, `stdlib.h`, `string.h`, `time.h`, etc.         |
| ![OOP](https://img.shields.io/badge/Object--Oriented%20Programming-000000?style=flat)                                | **POO en C**: encapsulación, abstracción y polimorfismo mediante `struct`               |
| ![Algorithms](https://img.shields.io/badge/Algorithms%20\(Stack,%20Queue,%20List\)-000000?style=flat)                | **Algoritmos**: implementación de Stack, Queue, Deque, List                             |
| ![Git](https://img.shields.io/badge/Git-F05032?style=flat\&logo=git\&logoColor=white)                                | **Git**: control de versiones                                                           |
| ![GitHub](https://img.shields.io/badge/GitHub-181717?style=flat\&logo=github\&logoColor=white)                       | **GitHub**: plataforma de colaboración y revisión de código                             |
| ![Vim](https://img.shields.io/badge/Vim-019733?style=flat\&logo=vim\&logoColor=white)                                | **Vim**: editor de texto configurable                                                   |
| ![Visual Studio](https://img.shields.io/badge/Visual%20Studio-5C2D91?style=flat\&logo=visualstudio\&logoColor=white) | **Visual Studio**: IDE para desarrollo y depuración en C/C++                            |
| ![VS Code](https://img.shields.io/badge/VSCode-007ACC?style=flat\&logo=visualstudiocode\&logoColor=white)            | **Visual Studio Code**: editor de código y depuración                                   |
| ![CLion](https://img.shields.io/badge/CLion-000000?style=flat\&logo=jetbrains\&logoColor=white)                      | **CLion**: IDE de JetBrains con análisis de código y soporte de CMake                   |

## 🖥️ Compatibilidad de plataformas

Este proyecto ha sido probado y funciona en:

* 🪟 **Windows** 10 / 11
* 🐧 **Linux**
* 🍎 **macOS**

## 🛣️ Hoja de ruta

* [x] POO en C
* [x] Abstracción de hilos y mutex
* [x] Utilidades de entrada/salida de consola
* [x] Escáner de tipos primitivos
* [x] Estructuras de datos: Stack, Queue, List
* [ ] Utilidades avanzadas de archivos
* [ ] Capa GUI con SDL o ncurses (planificado)

## 🏗️ Instrucciones de compilación por SO

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

> **Nota**: Se requiere `-lpthread` para soporte de multihilo.

## 📂 Estructura de directorios

```
Object-Oriented-C-Language/
├── inc/                      # Archivos de encabezado
│   ├── algorithm.h
│   ├── console.h
│   ├── main.h
│   ├── Scanner.h
│   ├── System.h
│   └── thread.h
├── src/                      # Archivos fuente
│   ├── algorithm.c
│   ├── console.c
│   ├── main.c
│   ├── Scanner.c
│   ├── System.c
│   └── thread.c
├── translations/             # Archivos de traducción
│   ├── ar.md                 # Árabe
│   ├── es.md                 # Español (este archivo)
│   ├── fr.md                 # Francés
│   ├── hi.md                 # Hindi
│   ├── it.md                 # Italiano
│   ├── ja.md                 # Japonés
│   ├── ko.md                 # Coreano
│   ├── pt.md                 # Portugués
│   ├── ru.md                 # Ruso
│   └── zh.md                 # Chino
├── LICENSE                   # Información de licencia
└── README.md                 # Descripción del proyecto
```

## 🔧 Desarrollo y compilación

### Requisitos

* GCC (versión ≥ 4.8)
* Make (opcional)

### Compilación manual

```bash
# Desde el directorio raíz del proyecto
gcc -std=c99 -Wall -I inc/ -o main src/*.c
```

### Ejemplo de Makefile

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

## 🚀 Cómo ejecutar

```bash
# Tras compilar
./main
```

El ejemplo crea objetos, invoca métodos y prueba los hilos.

## 📑 Estructura de la API

### 1. System y tipos primitivos

* **SYSTEM out**

  * `out.printf(const string format, ...)` : salida formateada
  * `out.println(const string format, ...)` : salida formateada con salto de línea

* **SYSTEM in**

  * `in.read() -> int32_t` : lee un carácter desde stdin como entero

* **File**

  * Constructor: `File new_File(const string path, const string mode)`
  * Métodos:

    * `f.scanf(const string format, ...)` : lectura formateada desde archivo
    * `f.printf(const string format, ...)` : salida formateada a archivo
    * `f.println(const string format, ...)` : salida con salto de línea a archivo
    * `f.open(const string path, const string mode)` : abre archivo
    * `f.close()` : cierra archivo
    * `f.readLine() -> string` : lee una línea del archivo

* **Time**

  * Constructor: `Time new_Time(void)`
  * Métodos:

    * `t.getSystemTime(Time* t)` : obtiene hora del sistema
    * `t.getTime(Time* t)` : obtiene valor de tiempo interno
    * `t.setTime(...)` : establece tiempo (año, mes, día, hora, minuto, segundo)
    * `t.start()` / `t.stop()` : controla hilo de temporizador

* **Wrappers de tipos primitivos**

  * `new_String(string s)`

    * Métodos: `s.length()`, `s.charAt(index)`, `s.substring(start, end)`, `s.equals(...)`, `s.toCharArray()`
    * Métodos estáticos: `String.valueOf(...)`, `String.format(...)`

  * `new_Character(char c)`

    * Métodos: `c.charValue()`, `c.equals(...)`, `Character.isDigit(char)`, `Character.isLetter(char)`

  * `new_Byte(...)`, `new_Short(...)`, `new_Integer(...)`, `new_Long(...)`, `new_Float(...)`, `new_Double(...)`, `new_Boolean(...)`

    * Métodos comunes: `x.getValue()`, `x.toString()`, `x.equals(...)`, `x.compareTo(...)`
    * Métodos estáticos: `Wrapper.parse<Type>(...)`, `Wrapper.valueOf(...)`
    * Byte exclusivo: `b.byteValue()`, `b.toUnsigned()`, `Byte.parseByte(string, base)`
    * Boolean exclusivo: `b.booleanValue()`, `b.isTrue()`, `b.isFalse()`, `Boolean.parseBoolean(...)`

### 2. Thread y Mutex

* **Thread**

  * Constructor: `Thread new_Thread(void* (*function)(void*))`
  * Métodos:

    * `start(...)`, `join()`, `detach()`, `cancel()`, `exit()`, `delete()`

* **Mutex**

  * Constructor: `Mutex new_Mutex()`
  * Métodos:

    * `lock()`, `unlock()`, `delete()`

### 3. Console

* **Console**

  * Constructor: `Console new_console(void)`
  * Métodos:

    * `print(...)`, `println(...)`, `readLine()`, `clear()`
    * `setColor(ColorType color)`, `resetColor()`, `kbhit() -> int`

### 4. Scanner

* **Scanner**

  * Constructor: `Scanner new_Scanner(struct __stdin_t in)`
  * Métodos:

    * `nextChar()`, `nextByte()`, `nextShort()`, `nextInt()`, `nextLong()`
    * `nextUByte()`, `nextUShort()`, `nextUInt()`, `nextULong()`
    * `nextBoolean()`, `nextFloat()`, `nextDouble()`, `nextLDouble()`
    * `next() -> string`, `nextLine() -> string`

    (Por defecto usa espacios como delimitadores y también soporta lectura por línea.)

### 5. Colecciones (Algorithm)

* **Stack**

  * Constructor: `Stack new_stack(size_t elementSize)`
  * Métodos: `push(...)`, `pop() -> void*`, `clear()`, `delete()`

* **Queue**

  * Constructor: `Queue new_queue(size_t elementSize)`
  * Métodos: `push(...)`, `pop() -> void*`, `clear()`, `delete()`

* **Deque**

  * Constructor: `Deque new_deque(size_t elementSize)`
  * Métodos: `pushFront(...)`, `pushBack(...)`, `popFront()`, `popBack()`, `clear()`, `delete()`

* **List**

  * Constructor: `List new_list(size_t elementSize)`
  * Métodos: `add(...)`, `get(index)`, `remove(index)`, `size()`, `clear()`, `delete()`

## 🛠️ Guía de contribución

1. **Haz un fork** de este proyecto
2. **Crea una rama de función**: `git checkout -b feature/TuCaracterística`
3. **Implementa la función**
4. **Escribe pruebas y actualiza la documentación**
5. **Abre un Pull Request**

Abre un issue para discutir ideas antes de implementarlas.

## 📄 Licencia

Este proyecto está licenciado bajo la [MIT License](../LICENSE).
