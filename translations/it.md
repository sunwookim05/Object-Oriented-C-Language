# Object-Oriented C Language

> Un progetto di esempio che implementa il paradigma di programmazione orientata agli oggetti usando solo il linguaggio C puro.

---

Puoi visualizzare la documentazione tradotta nella lingua desiderata cliccando sui link qui sotto.

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
  <img src="https://img.shields.io/badge/Commits-1234-blue?style=flat" alt="Commits" />
  <img src="https://img.shields.io/badge/License-MIT-green?style=flat" alt="License" />
  <img src="https://img.shields.io/badge/Version-1.0.0-orange?style=flat" alt="Version" />
</div>

## 📖 Panoramica

Questo progetto è un esempio modulare che utilizza solo il linguaggio C (standard C99) per implementare i concetti chiave della programmazione orientata agli oggetti come astrazione, incapsulamento, ereditarietà e polimorfismo. Componenti vari come Sistema (`System`), Thread, I/O console (`Console`), Scanner di input e Algoritmi (`Algorithm`) vengono rappresentati come oggetti usando struct e puntatori a funzione.

## ⚙️ Funzionalità principali

* **System**: input/output di base, I/O su file, timer, astrazione di piattaforma
* **Thread**: creazione e gestione di thread leggeri
* **Console**: formattazione e controllo dell'I/O della console
* **Scanner**: utilità per lo stream di input
* **Algorithm**: collezioni di dati come stack, coda (queue), deque, liste

## 🧰 Stack tecnologico

| Badge                                                                                                                | Descrizione                                                                                          |
| -------------------------------------------------------------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------- |
| ![C](https://img.shields.io/badge/C-00599C?style=flat\&logo=c\&logoColor=white)                                      | **Linguaggio C**: standard C99, implementazione OO tramite struct e function pointer                 |
| ![GCC](https://img.shields.io/badge/GCC-333333?style=flat\&logo=gnu\&logoColor=white)                                | **GCC**: GNU Compiler Collection, utilizzato per compilare il programma C                            |
| ![Make](https://img.shields.io/badge/Make-064F8C?style=flat\&logo=cmake\&logoColor=white)                            | **Make**: strumento di automazione per compilazione e linking                                        |
| ![Makefile](https://img.shields.io/badge/Makefile-000000?style=flat)                                                 | **Makefile**: file di configurazione per Make                                                        |
| ![Windows](https://img.shields.io/badge/Windows-0078D4?style=flat\&logo=windows\&logoColor=white)                    | **Windows API**: funzioni di sistema e supporto multithreading (`windows.h`, `conio.h`, `process.h`) |
| ![Linux](https://img.shields.io/badge/Linux-000000?style=flat\&logo=linux\&logoColor=white)                          | **Linux**: sistema operativo open source                                                             |
| ![MACOS](https://img.shields.io/badge/MACOS-000000?style=flat\&logo=apple\&logoColor=white)                          | **macOS**: sistema operativo Unix-based di Apple                                                     |
| ![POSIX](https://img.shields.io/badge/POSIX%20Threads-000000?style=flat)                                             | **POSIX Threads**: multithreading su sistemi Unix (`pthread.h`)                                      |
| ![Standard Lib](https://img.shields.io/badge/C%20Standard%20Library-000000?style=flat)                               | **Libreria standard C**: `stdio.h`, `stdlib.h`, `string.h`, `time.h`, ecc.                           |
| ![OOP](https://img.shields.io/badge/Object--Oriented%20Programming-000000?style=flat)                                | **OOP in C**: incapsulamento, astrazione, polimorfismo tramite struct e pointer                      |
| ![Algorithms](https://img.shields.io/badge/Algorithms%20\(Stack,%20Queue,%20List\)-000000?style=flat)                | **Algoritmi**: implementazioni di stack, queue, deque e liste                                        |
| ![Git](https://img.shields.io/badge/Git-F05032?style=flat\&logo=git\&logoColor=white)                                | **Git**: sistema di controllo versione                                                               |
| ![GitHub](https://img.shields.io/badge/GitHub-181717?style=flat\&logo=github\&logoColor=white)                       | **GitHub**: piattaforma di collaborazione e code review                                              |
| ![Vim](https://img.shields.io/badge/Vim-019733?style=flat\&logo=vim\&logoColor=white)                                | **Vim**: editor di testo altamente configurabile per efficiente coding                               |
| ![Visual Studio](https://img.shields.io/badge/Visual%20Studio-5C2D91?style=flat\&logo=visualstudio\&logoColor=white) | **Visual Studio**: IDE con strumenti di debugging, analisi e test                                    |
| ![VSCode](https://img.shields.io/badge/VSCode-007ACC?style=flat\&logo=visualstudiocode\&logoColor=white)             | **Visual Studio Code**: editor di codice leggero e versatile                                         |
| ![CLion](https://img.shields.io/badge/CLion-000000?style=flat\&logo=jetbrains\&logoColor=white)                      | **CLion**: IDE JetBrains per sviluppo C/C++                                                          |

## 🖥️ Compatibilità piattaforme

Questo progetto è stato testato e funziona sui seguenti sistemi:

* 🪟 **Windows** 10 / 11
* 🐧 **Linux**
* 🍎 **macOS**

## 🛣️ Tabella di marcia

* [x] Programmazione orientata agli oggetti in C
* [x] Astrazione di thread e mutex
* [x] Utility di I/O da console
* [x] Scanner di input
* [x] Strutture dati: pila, coda, lista
* [ ] Utility avanzate per file
* [ ] Livello GUI con SDL o ncurses (in programma)

## 🏗️ Istruzioni di compilazione per piattaforma

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

> **Nota**: per il supporto multithreading è necessario aggiungere l'opzione `-lpthread`.

## 📂 Struttura delle directory

```
Object-Oriented-C-Language/
├── inc/                      # File di intestazione
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
└── README.md                 # Descrizione del progetto (questo file)
```

## 🔧 Sviluppo e compilazione

### Requisiti

* GCC (versione ≥ 4.8)
* Make (opzionale)

### Compilazione manuale

```bash
# Esegui dalla radice del progetto
gcc -std=c99 -Wall -I inc/ -o main src/*.c
```

### Esempio di Makefile

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

## 🚀 Esecuzione

```bash
# Dopo la compilazione
./main
```

L'eseguibile esegue automaticamente esempi di creazione di oggetti, chiamate di metodi e test multithread.

## 📑 Struttura API

### 1. System e tipi base

* **SYSTEM out**

  * `out.printf(const string format, ...)` : stampa formattata
  * `out.println(const string format, ...)` : stampa formattata con newline

* **SYSTEM in**

  * `in.read() -> int32_t` : legge un carattere da stdin e restituisce il valore intero

* **File**

  * Costruttore: `File new_File(const string path, const string mode)`
  * Metodi:

    * `f.scanf(const string format, ...)` : legge formattato da file
    * `f.printf(const string format, ...)` : stampa formattata su file
    * `f.println(const string format, ...)` : stampa formattata con newline su file
    * `f.open(const string path, const string mode)` : apre un file
    * `f.close()` : chiude il file
    * `f.readLine() -> string` : legge una riga dal file

* **Time**

  * Costruttore: `Time new_Time(void)`
  * Metodi:

    * `t.getSystemTime(Time* t)` : ottiene l'orario di sistema corrente
    * `t.getTime(Time* t)` : ottiene il valore interno del timer
    * `t.setTime(...)` : imposta data e ora (anno, mese, giorno, ora, minuti, secondi)
    * `t.start()` / `t.stop()` : controlla il timer

* **Wrapper dei tipi primitivi**

  * `new_String(string s)`

    * Metodi: `s.length()`, `s.charAt(index)`, `s.substring(start, end)`, `s.equals(...)`, `s.toCharArray()`
    * Metodi statici: `String.valueOf(...)`, `String.format(...)`

  * `new_Character(char c)`

    * Metodi: `c.charValue()`, `c.equals(...)`, `Character.isDigit(char)`, `Character.isLetter(char)`

  * `new_Byte(...)`, `new_Short(...)`, `new_Integer(...)`, `new_Long(...)`, `new_Float(...)`, `new_Double(...)`, `new_Boolean(...)`

    * Metodi comuni: `x.getValue()`, `x.toString()`, `x.equals(...)`, `x.compareTo(...)`
    * Metodi statici: `Wrapper.parse<Type>(...)`, `Wrapper.valueOf(...)`
    * Byte specifici: `b.byteValue()`, `b.toUnsigned()`, `Byte.parseByte(string, base)`
    * Boolean specifici: `b.booleanValue()`, `b.isTrue()`, `b.isFalse()`, `Boolean.parseBoolean(...)`

### 2. Thread e Mutex

* **Thread**

  * Costruttore: `Thread new_Thread(void* (*function)(void*))`
  * Metodi:

    * `start(...)`, `join()`, `detach()`, `cancel()`, `exit()`, `delete()`

* **Mutex**

  * Costruttore: `Mutex new_Mutex()`
  * Metodi: `lock()`, `unlock()`, `delete()`

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

    (utilizza spazi bianchi come delimitatori per impostazione predefinita e supporta la lettura di intere righe)

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

## 🛠️ Guida per i contributi

1. Fai un **fork** del progetto.
2. Crea un branch per la tua funzionalità: `git checkout -b feature/YourFeature`
3. Implementa la funzionalità.
4. Scrivi i test e aggiorna la documentazione.
5. Crea una pull request per discutere le modifiche.

Apri un issue per discutere le idee prima di contribuire.

## 📄 Licenza

Questo progetto è rilasciato sotto la licenza [MIT License](../LICENSE).
