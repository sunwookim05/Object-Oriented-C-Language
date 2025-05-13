# Object-Oriented C Language

> Un progetto di esempio che implementa il paradigma di programmazione orientata agli oggetti utilizzando puro linguaggio C.

---

Clicca sui link sottostanti per visualizzare il contenuto tradotto nella lingua desiderata.

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

## 📖 Panoramica

Questo progetto è un esempio modulare che implementa i concetti chiave della programmazione orientata agli oggetti (astrazione, incapsulamento, ereditarietà, polimorfismo) utilizzando esclusivamente il linguaggio C (standard C99). Diversi componenti di sistema (`System`), threading (`Thread`), input/output console (`Console`), scanner di input (`Scanner`), algoritmi (`Algorithm`) sono rappresentati come "oggetti" tramite struct e puntatori a funzione.

## ⚙️ Funzionalità principali

* **System**: input/output di base, I/O su file, timer, astrazione di piattaforma
* **Thread**: creazione e gestione di thread leggeri
* **Console**: formattazione e controllo I/O console
* **Scanner**: utility per stream di input
* **Algorithm**: implementazioni di collezioni Stack, Queue, Deque, List

## 🧰 Stack tecnologico

| Badge                                                                                                                | Description                                                                                                  |
| -------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------ |
| ![C](https://img.shields.io/badge/C-00599C?style=flat\&logo=c\&logoColor=white)                                      | **Linguaggio C**: standard C99, implementazione OOP con struct e puntatori a funzione                        |
| ![GCC](https://img.shields.io/badge/GCC-333333?style=flat\&logo=gnu\&logoColor=white)                                | **GCC**: GNU Compiler Collection, utilizzato per compilare il programma C                                    |
| ![Make](https://img.shields.io/badge/Make-064F8C?style=flat\&logo=cmake\&logoColor=white)                            | **Make**: strumento di automazione per compilazione e linking                                                |
| ![Makefile](https://img.shields.io/badge/Makefile-000000?style=flat)                                                 | **Makefile**: file di istruzioni per il comando Make                                                         |
| ![Windows](https://img.shields.io/badge/Windows-0078D4?style=flat\&logo=windows\&logoColor=white)                    | **Windows API**: funzioni di sistema Windows e supporto multithreading (`windows.h`, `conio.h`, `process.h`) |
| ![Linux](https://img.shields.io/badge/Linux-000000?style=flat\&logo=linux\&logoColor=white)                          | **Linux**: sistema operativo open source comunemente utilizzato per sviluppo                                 |
| ![MACOS](https://img.shields.io/badge/MACOS-000000?style=flat\&logo=apple\&logoColor=white)                          | **macOS**: sistema operativo Unix-based supportato da hardware Apple                                         |
| ![POSIX](https://img.shields.io/badge/POSIX%20Threads-000000?style=flat)                                             | **Thread POSIX**: supporto multithreading per sistemi Unix (`pthread.h`)                                     |
| ![Standard Lib](https://img.shields.io/badge/C%20Standard%20Library-000000?style=flat)                               | **Libreria standard C**: `stdio.h`, `stdlib.h`, `string.h`, `time.h` e altre librerie di base                |
| ![OOP](https://img.shields.io/badge/Object--Oriented%20Programming-000000?style=flat)                                | **OOP in C**: incapsulamento, astrazione, polimorfismo tramite struct e puntatori a funzione                 |
| ![Algorithms](https://img.shields.io/badge/Algorithms%20\(Stack,%20Queue,%20List\)-000000?style=flat)                | **Algoritmi**: implementazioni di Stack, Queue, Deque, List                                                  |
| ![Git](https://img.shields.io/badge/Git-F05032?style=flat\&logo=git\&logoColor=white)                                | **Git**: sistema di controllo versione per la gestione del codice                                            |
| ![GitHub](https://img.shields.io/badge/GitHub-181717?style=flat\&logo=github\&logoColor=white)                       | **GitHub**: piattaforma per condivisione e revisione del codice                                              |
| ![Vim](https://img.shields.io/badge/Vim-019733?style=flat\&logo=vim\&logoColor=white)                                | **Vim**: editor di testo altamente configurabile per sviluppo                                                |
| ![Visual Studio](https://img.shields.io/badge/Visual%20Studio-5C2D91?style=flat\&logo=visualstudio\&logoColor=white) | **Visual Studio**: IDE C/C++ con potenti strumenti di debug, analisi e test                                  |
| ![VS Code](https://img.shields.io/badge/VSCode-007ACC?style=flat\&logo=visualstudiocode\&logoColor=white)            | **Visual Studio Code**: editor di codice e debug ligero                                                      |
| ![CLion](https://img.shields.io/badge/CLion-000000?style=flat\&logo=jetbrains\&logoColor=white)                      | **CLion**: IDE C/C++ di JetBrains con integrazione CMake, refactoring e analisi statica                      |

## 🖥️ Compatibilità piattaforme

Questo progetto è stato testato ed eseguito sulle seguenti piattaforme:

* 🪟 **Windows** 10 / 11
* 🐧 **Linux**
* 🍎 **macOS**

## 🛣️ Roadmap

* [x] OOP in C
* [x] Astrazione di thread e mutex
* [x] Utility I/O console
* [x] Scanner di input base
* [x] Strutture dati: Stack, Queue, List
* [ ] Utility avanzate per file
* [ ] Livello GUI (SDL o ncurses) (in futuro)

## 🏗️ Istruzioni di compilazione per OS

### 🪟 Windows (GCC MinGW)

```bash
gcc -std=c99 -Wall -I inc -o main.exe src/*.c
main.exe
```

### 🪟 Windows (Prompt MSVC)

```cmd
cl /I inc /Fe:main.exe src\*.c
main.exe
```

### 🐧 Linux / 🍎 macOS

```bash
gcc -std=c99 -Wall -I inc -o main src/*.c -lpthread
./main
```

> **Nota**: `-lpthread` è necessario per il supporto multithreading.

## 📂 Struttura delle directory

```
Object-Oriented-C-Language/
├── inc/                      # File header
│   ├── algorithm.h
│   ├── console.h
│   ├── main.h
│   ├── Scanner.h
│   ├── System.h
│   └── thread.h
├── src/                      # File sorgente
│   ├── algorithm.c
│   ├── console.c
│   ├── main.c
│   ├── Scanner.c
│   ├── System.c
│   └── thread.c
├── translations/             # File di traduzione
│   ├── ar.md                 # Arabo
│   ├── es.md                 # Spagnolo
│   ├── fr.md                 # Francese
│   ├── hi.md                 # Hindi
│   ├── it.md                 # Italiano (questo file)
│   ├── ja.md                 # Giapponese
│   ├── ko.md                 # Coreano
│   ├── pt.md                 # Portoghese
│   ├── ru.md                 # Russo
│   └── zh.md                 # Cinese
├── LICENSE                   # Informazioni sulla licenza
└── README.md                 # Descrizione del progetto
```

## 🔧 Sviluppo e compilazione

### Requisiti

* GCC (versione ≥ 4.8)
* Make (opzionale)

### Compilazione manuale

```bash
# Dalla directory radice del progetto
gcc -std=c99 -Wall -I inc/ -o main src/*.c
```

### Esempio di Makefile

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

## 🚀 Esecuzione

```bash
# Dopo la compilazione
./main
```

L'esempio crea oggetti, chiama metodi e testa i thread.

## 📑 Struttura API

### 1. System e tipi primitivi

* **SYSTEM out**

  * `out.printf(const string format, ...)`: output formattato
  * `out.println(const string format, ...)`: output formattato con newline

* **SYSTEM in**

  * `in.read() -> int32_t`: legge un carattere da stdin come intero

* **File**

  * Costruttore: `File new_File(const string path, const string mode)`
  * Metodi:

    * `f.scanf(const string format, ...)`: input formattato da file
    * `f.printf(const string format, ...)`: output formattato su file
    * `f.println(const string format, ...)`: output con newline su file
    * `f.open(const string path, const string mode)`: apre il file
    * `f.close()`: chiude il file
    * `f.readLine() -> string`: legge una riga dal file

* **Time**

  * Costruttore: `Time new_Time(void)`
  * Metodi:

    * `t.getSystemTime(Time* t)`: ottiene l'orario di sistema corrente
    * `t.getTime(Time* t)`: ottiene il valore interno di tempo
    * `t.setTime(...)`: imposta data e ora (anno, mese, giorno, ora, minuto, secondo)
    * `t.start()` / `t.stop()`: controllo del timer interno

* **Wrapper di tipi primitivi**

  * `new_String(string s)`

    * Metodi: `s.length()`, `s.charAt(index)`, `s.substring(start, end)`, `s.equals(...)`, `s.toCharArray()`
    * Metodi statici: `String.valueOf(...)`, `String.format(...)`

  * `new_Character(char c)`

    * Metodi: `c.charValue()`, `c.equals(...)`, `Character.isDigit(char)`, `Character.isLetter(char)`

  * `new_Byte(...)`, `new_Short(...)`, `new_Integer(...)`, `new_Long(...)`, `new_Float(...)`, `new_Double(...)`, `new_Boolean(...)`

    * Metodi comuni: `x.getValue()`, `x.toString()`, `x.equals(...)`, `x.compareTo(...)`
    * Metodi statici: `Wrapper.parse<Type>(...)`, `Wrapper.valueOf(...)`
    * Specifico Byte: `b.byteValue()`, `b.toUnsigned()`, `Byte.parseByte(string, base)`
    * Specifico Boolean: `b.booleanValue()`, `b.isTrue()`, `b.isFalse()`, `Boolean.parseBoolean(...)`

### 2. Thread e Mutex

* **Thread**

  * Costruttore: `Thread new_Thread(void* (*function)(void*))`
  * Metodi:

    * `start(...)`, `join()`, `detach()`, `cancel()`, `exit()`, `delete()`

* **Mutex**

  * Costruttore: `Mutex new_Mutex()`
  * Metodi:

    * `lock()`, `unlock()`, `delete()`

### 3. Console

* **Console**

  * Costruttore: `Console new_console(void)`
  * Metodi:

    * `print(...)`, `println(...)`, `readLine()`, `clear()`
    * `setColor(ColorType color)`, `resetColor()`, `kbhit() -> int`

### 4. Scanner

* **Scanner**

  * Costruttore: `Scanner new_Scanner(struct __stdin_t in)`
  * Metodi:

    * `nextChar()`, `nextByte()`, `nextShort()`, `nextInt()`, `nextLong()`
    * `nextUByte()`, `nextUShort()`, `nextUInt()`, `nextULong()`
    * `nextBoolean()`, `nextFloat()`, `nextDouble()`, `nextLDouble()`
    * `next() -> string`, `nextLine() -> string`

    (usa lo spazio bianco come delimitatore, supporta anche lettura per riga.)

### 5. Collezioni (Algorithm)

* **Stack**

  * Costruttore: `Stack new_stack(size_t elementSize)`
  * Metodi: `push(...)`, `pop() -> void*`, `clear()`, `delete()`

* **Queue**

  * Costruttore: `Queue new_queue(size_t elementSize)`
  * Metodi: `push(...)`, `pop() -> void*`, `clear()`, `delete()`

* **Deque**

  * Costruttore: `Deque new_deque(size_t elementSize)`
  * Metodi: `pushFront(...)`, `pushBack(...)`, `popFront()`, `popBack()`, `clear()`, `delete()`

* **List**

  * Costruttore: `List new_list(size_t elementSize)`
  * Metodi: `add(...)`, `get(index)`, `remove(index)`, `size()`, `clear()`, `delete()`

## 🛠️ Guida al contributo

1. **Fork** il progetto
2. **Crea un branch** funzionalità: `git checkout -b feature/YourFeature`
3. **Implementa la funzionalità**
4. **Scrivi test e aggiorna documentazione**
5. **Apri una Pull Request**

Apri un issue per discutere idee prima di implementarle.

## 📄 Licenza

Questo progetto è rilasciato sotto licenza [MIT License](../LICENSE).
