# Object-Oriented C Language

> Um projeto de exemplo que implementa o paradigma de programação orientada a objetos usando apenas a linguagem C pura.

---

Clique no link abaixo para visualizar o conteúdo traduzido no idioma desejado.

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

## 📖 Visão Geral

Este projeto é um exemplo que implementa os conceitos principais de programação orientada a objetos (abstração, encapsulamento, herança, polimorfismo) usando apenas a linguagem C pura (padrão C99) em uma estrutura modular. Diversos componentes do sistema (`System`), threads (`Thread`), entrada/saída de console (`Console`), scanner de entrada (`Scanner`) e algoritmos (`Algorithm`) são representados como objetos utilizando structs e ponteiros para funções.

## ⚙️ Funcionalidades Principais

* **System**: entrada/saída básica, I/O de arquivos, temporizador, abstração de plataforma
* **Thread**: criação e gerenciamento de threads leves
* **Console**: formatação e controle de I/O de console
* **Scanner**: utilitários de fluxo de entrada
* **Algorithm**: coleções Stack, Queue, Deque, List

## 🧰 Stack de Tecnologias

| Badge                                                                                                                | Descrição                                                                                            |
| -------------------------------------------------------------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------- |
| ![C](https://img.shields.io/badge/C-00599C?style=flat\&logo=c\&logoColor=white)                                      | **Linguagem C**: padrão C99, programação orientada a objetos usando structs e ponteiros para funções |
| ![GCC](https://img.shields.io/badge/GCC-333333?style=flat\&logo=gnu\&logoColor=white)                                | **GCC**: GNU Compiler Collection, usado para compilar programas em C                                 |
| ![Make](https://img.shields.io/badge/Make-064F8C?style=flat\&logo=cmake\&logoColor=white)                            | **Make**: ferramenta de automação de compilação e linkagem                                           |
| ![Makefile](https://img.shields.io/badge/Makefile-000000?style=flat)                                                 | **Makefile**: arquivo de instruções de build para Make                                               |
| ![Windows](https://img.shields.io/badge/Windows-0078D4?style=flat\&logo=windows\&logoColor=white)                    | **Windows API**: funções de sistema e suporte a multithreading (`windows.h`, `conio.h`, `process.h`) |
| ![Linux](https://img.shields.io/badge/Linux-FCC624?style=flat\&logo=linux\&logoColor=black)                          | **Linux**: sistema operacional de código aberto amplamente usado para desenvolvimento                |
| ![MACOS](https://img.shields.io/badge/MACOS-000000?style=flat\&logo=apple\&logoColor=white)                          | **macOS**: sistema operacional Unix para hardware Apple                                              |
| ![POSIX](https://img.shields.io/badge/POSIX%20Threads-000000?style=flat)                                             | **Threads POSIX**: suporte a multithreading em sistemas Unix (`pthread.h`)                           |
| ![Standard Lib](https://img.shields.io/badge/C%20Standard%20Library-000000?style=flat)                               | **Biblioteca Padrão C**: `stdio.h`, `stdlib.h`, `string.h`, `time.h` etc.                            |
| ![OOP](https://img.shields.io/badge/Object--Oriented%20Programming-000000?style=flat)                                | **OOP em C**: encapsulamento, abstração e polimorfismo via structs e ponteiros                       |
| ![Algorithms](https://img.shields.io/badge/Algorithms%20-000000?style=flat)                | **Algoritmos**: implementação de Stack, Queue, Deque, List                                           |
| ![Git](https://img.shields.io/badge/Git-F05032?style=flat\&logo=git\&logoColor=white)                                | **Git**: sistema de controle de versão                                                               |
| ![GitHub](https://img.shields.io/badge/GitHub-181717?style=flat\&logo=github\&logoColor=white)                       | **GitHub**: plataforma de hospedagem e revisão de código                                             |
| ![Vim](https://img.shields.io/badge/Vim-019733?style=flat\&logo=vim\&logoColor=white)                                | **Vim**: editor de texto altamente configurável                                                      |
| ![Visual Studio](https://img.shields.io/badge/Visual%20Studio-5C2D91?style=flat\&logo=visualstudio\&logoColor=white) | **Visual Studio**: IDE poderosa com ferramentas de depuração e análise                               |
| ![VSCode](https://img.shields.io/badge/VSCode-007ACC?style=flat\&logo=visualstudiocode\&logoColor=white)             | **Visual Studio Code**: editor de código com suporte a depuração                                     |
| ![CLion](https://img.shields.io/badge/CLion-000000?style=flat\&logo=jetbrains\&logoColor=white)                      | **CLion**: IDE da JetBrains com análise de código e integração CMake                                 |

## 🖥️ Compatibilidade de Plataformas

Este projeto foi testado e executado nas seguintes plataformas:

* 🪟 **Windows** 10 / 11
* 🐧 **Linux**
* 🍎 **macOS**

## 🛣️ Roadmap

* [x] OOP em C
* [x] Abstração de threads e mutex
* [x] Utilitários de I/O de console
* [x] Scanner de entrada de tipos primitivos
* [x] Estruturas de dados: Stack, Queue, List
* [ ] Utilitários avançados de arquivos
* [ ] Camada GUI usando SDL ou ncurses (planejado)

## 🏗️ Instruções de Build por SO

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

> **Nota**: `-lpthread` é necessário para suporte a multithreading.

## 📂 Estrutura de Diretórios

```
Object-Oriented-C-Language/
├── inc/                      # arquivos de cabeçalho
│   ├── algorithm.h
│   ├── console.h
│   ├── main.h
│   ├── Scanner.h
│   ├── System.h
│   └── thread.h
├── src/                      # arquivos fonte
│   ├── algorithm.c
│   ├── console.c
│   ├── main.c
│   ├── Scanner.c
│   ├── System.c
│   └── thread.c
├── translations/             # arquivos de tradução
│   ├── ar.md                 # Árabe
│   ├── es.md                 # Espanhol
│   ├── fr.md                 # Francês
│   ├── hi.md                 # Hindi
│   ├── it.md                 # Italiano
│   ├── ja.md                 # Japonês
│   ├── ko.md                 # Coreano
│   ├── pt.md                 # Português (este arquivo)
│   ├── ru.md                 # Russo
│   └── zh.md                 # Chinês
├── LICENSE                   # informações de licença
└── README.md                 # descrição do projeto
```

## 🔧 Desenvolvimento e Build

### Requisitos

* GCC (versão ≥ 4.8)
* Make (opcional)

### Compilação Manual

```bash
# na raiz do projeto
gcc -std=c99 -Wall -I inc/ -o main src/*.c
```

### Exemplo de Makefile

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

## 🚀 Como Executar

```bash
# após build
./main
```

O exemplo cria objetos, chama métodos e testa threads.

## 📑 Estrutura da API

### 1. System e Tipos Primitivos

* **SYSTEM out**

  * `out.printf(const string format, ...)` : saída formatada
  * `out.println(const string format, ...)` : saída formatada com quebra de linha

* **SYSTEM in**

  * `in.read() -> int32_t` : lê um caractere do stdin como inteiro

* **File**

  * Construtor: `File new_File(const string path, const string mode)`
  * Métodos:

    * `f.scanf(const string format, ...)` : lê entrada formatada de arquivo
    * `f.printf(const string format, ...)` : saída formatada em arquivo
    * `f.println(const string format, ...)` : saída com quebra de linha em arquivo
    * `f.open(const string path, const string mode)` : abre arquivo
    * `f.close()` : fecha arquivo
    * `f.readLine() -> string` : lê uma linha de arquivo

* **Time**

  * Construtor: `Time new_Time(void)`
  * Métodos:

    * `t.getSystemTime(Time* t)` : obtém hora atual do sistema
    * `t.getTime(Time* t)` : obtém valor interno de tempo
    * `t.setTime(...)` : define tempo (ano, mês, dia, hora, minuto, segundo)
    * `t.start()` / `t.stop()` : controla thread temporizadora

* **Construtores de Wrappers Primitivos**

  * `new_String(string s)`

    * Métodos: `s.length()`, `s.charAt(index)`, `s.substring(start, end)`, `s.equals(...)`, `s.toCharArray()`
    * Métodos estáticos: `String.valueOf(...)`, `String.format(...)`

  * `new_Character(char c)`

    * Métodos: `c.charValue()`, `c.equals(...)`, `Character.isDigit(char)`, `Character.isLetter(char)`

  * `new_Byte(...)`, `new_Short(...)`, `new_Integer(...)`, `new_Long(...)`, `new_Float(...)`, `new_Double(...)`, `new_Boolean(...)`

    * Métodos comuns: `x.getValue()`, `x.toString()`, `x.equals(...)`, `x.compareTo(...)`
    * Métodos estáticos: `Wrapper.parse<Type>(...)`, `Wrapper.valueOf(...)`
    * Exclusivos de Byte: `b.byteValue()`, `b.toUnsigned()`, `Byte.parseByte(string, base)`
    * Exclusivos de Boolean: `b.booleanValue()`, `b.isTrue()`, `b.isFalse()`, `Boolean.parseBoolean(...)`

### 2. Thread e Mutex

* **Thread**

  * Construtor: `Thread new_Thread(void* (*function)(void*))`
  * Métodos:

    * `start(...)`, `join()`, `detach()`, `cancel()`, `exit()`, `delete()`

* **Mutex**

  * Construtor: `Mutex new_Mutex()`
  * Métodos:

    * `lock()`, `unlock()`, `delete()`

### 3. Console

* **Console**

  * Construtor: `Console new_console(void)`
  * Métodos:

    * `print(...)`, `println(...)`, `readLine()`, `clear()`
    * `setColor(ColorType color)`, `resetColor()`, `kbhit() -> int`

### 4. Scanner

* **Scanner**

  * Construtor: `Scanner new_Scanner(struct __stdin_t in)`
  * Métodos:

    * `nextChar()`, `nextByte()`, `nextShort()`, `nextInt()`, `nextLong()`
    * `nextUByte()`, `nextUShort()`, `nextUInt()`, `nextULong()`
    * `nextBoolean()`, `nextFloat()`, `nextDouble()`, `nextLDouble()`
    * `next() -> string`, `nextLine() -> string`

    (por padrão usa espaços como delimitadores e suporta leitura por linhas.)

### 5. Coleções (Algorithm)

* **Stack**

  * Construtor: `Stack new_stack(size_t elementSize)`
  * Métodos: `push(...)`, `pop() -> void*`, `clear()`, `delete()`

* **Queue**

  * Construtor: `Queue new_queue(size_t elementSize)`
  * Métodos: `push(...)`, `pop() -> void*`, `clear()`, `delete()`

* **Deque**

  * Construtor: `Deque new_deque(size_t elementSize)`
  * Métodos: `pushFront(...)`, `pushBack(...)`, `popFront()`, `popBack()`, `clear()`, `delete()`

* **List**

  * Construtor: `List new_list(size_t elementSize)`
  * Métodos: `add(...)`, `get(index)`, `remove(index)`, `size()`, `clear()`, `delete()`

## 🛠️ Guia de Contribuição

1. **Fork** este projeto
2. **Crie uma branch de recurso**: `git checkout -b feature/YourFeature`
3. **Implemente o recurso**
4. **Escreva testes e atualize a documentação**
5. **Abra um Pull Request**

Para discutir ideias, abra uma issue primeiro.

## 📄 Licença

Este projeto está licenciado sob a [Licença MIT](../LICENSE).
