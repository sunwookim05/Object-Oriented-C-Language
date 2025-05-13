# Object-Oriented C Language

> Um projeto de exemplo que implementa o paradigma de programação orientada a objetos usando apenas a linguagem C pura.

---

Você pode visualizar a documentação traduzida no idioma desejado clicando nos links abaixo:

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

## 📖 Visão Geral

Este projeto é um exemplo modular que usa apenas a linguagem C (padrão C99) para implementar conceitos fundamentais de programação orientada a objetos, como abstração, encapsulamento, herança e polimorfismo. Componentes como Sistema (`System`), Thread, Console I/O (`Console`), Scanner de entrada e Algoritmos (`Algorithm`) são representados como objetos usando structs e ponteiros para funções.

## ⚙️ Principais Funcionalidades

* **System**: entrada/saída básica, I/O de arquivos, temporizador, abstração de plataforma
* **Thread**: criação e gerenciamento de threads leves
* **Console**: formatação e controle de I/O de console
* **Scanner**: utilitários para fluxo de entrada
* **Algorithm**: coleções de dados como pilha (stack), fila (queue), deque e listas

## 🧰 Stack Tecnológico

| Badge                                                                                                                | Descrição                                                                       |
| -------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------- |
| ![C](https://img.shields.io/badge/C-00599C?style=flat\&logo=c\&logoColor=white)                                      | **Linguagem C**: padrão C99, implementação OO via structs e ponteiros de função |
| ![GCC](https://img.shields.io/badge/GCC-333333?style=flat\&logo=gnu\&logoColor=white)                                | **GCC**: GNU Compiler Collection, usado para compilar o programa C              |
| ![Make](https://img.shields.io/badge/Make-064F8C?style=flat\&logo=cmake\&logoColor=white)                            | **Make**: ferramenta de automação para compilação e linkagem                    |
| ![Makefile](https://img.shields.io/badge/Makefile-000000?style=flat)                                                 | **Makefile**: arquivo de configuração para Make                                 |
| ![Windows](https://img.shields.io/badge/Windows-0078D4?style=flat\&logo=windows\&logoColor=white)                    | **Windows API**: funções de sistema e suporte a multithreading                  |
| ![Linux](https://img.shields.io/badge/Linux-000000?style=flat\&logo=linux\&logoColor=white)                          | **Linux**: sistema operacional de código aberto                                 |
| ![MACOS](https://img.shields.io/badge/MACOS-000000?style=flat\&logo=apple\&logoColor=white)                          | **macOS**: sistema operacional Unix-based da Apple                              |
| ![POSIX](https://img.shields.io/badge/POSIX%20Threads-000000?style=flat)                                             | **POSIX Threads**: multithreading em sistemas Unix                              |
| ![Standard Lib](https://img.shields.io/badge/C%20Standard%20Library-000000?style=flat)                               | **Biblioteca padrão C**: `stdio.h`, `stdlib.h`, `string.h`, `time.h`, etc.      |
| ![OOP](https://img.shields.io/badge/Object--Oriented%20Programming-000000?style=flat)                                | **OOP em C**: encapsulamento, abstração, polimorfismo via structs e ponteiros   |
| ![Algorithms](https://img.shields.io/badge/Algorithms%20\(Stack,%20Queue,%20List\)-000000?style=flat)                | **Algoritmos**: implementações de pilha, fila, deque e listas                   |
| ![Git](https://img.shields.io/badge/Git-F05032?style=flat\&logo=git\&logoColor=white)                                | **Git**: sistema de controle de versão                                          |
| ![GitHub](https://img.shields.io/badge/GitHub-181717?style=flat\&logo=github\&logoColor=white)                       | **GitHub**: plataforma de colaboração e revisão de código                       |
| ![Vim](https://img.shields.io/badge/Vim-019733?style=flat\&logo=vim\&logoColor=white)                                | **Vim**: editor de texto altamente configurável para codificação eficiente      |
| ![Visual Studio](https://img.shields.io/badge/Visual%20Studio-5C2D91?style=flat\&logo=visualstudio\&logoColor=white) | **Visual Studio**: IDE com ferramentas de depuração, análise e testes           |
| ![VSCode](https://img.shields.io/badge/VSCode-007ACC?style=flat\&logo=visualstudiocode\&logoColor=white)             | **Visual Studio Code**: editor de código leve e versátil                        |
| ![CLion](https://img.shields.io/badge/CLion-000000?style=flat\&logo=jetbrains\&logoColor=white)                      | **CLion**: IDE da JetBrains para desenvolvimento em C/C++                       |

## 🖥️ Compatibilidade de Plataformas

Este projeto foi testado nos seguintes sistemas:

* 🪟 **Windows** 10 / 11
* 🐧 **Linux**
* 🍎 **macOS**

## 🛣️ Roteiro

* [x] Programação orientada a objetos em C
* [x] Abstração de threads e mutexes
* [x] Utilitários de I/O de console
* [x] Scanner de entrada
* [x] Estruturas de dados: pilha, fila, lista
* [ ] Utilitários avançados de arquivos
* [ ] Camada GUI com SDL ou ncurses (planejado)

## 🏗️ Instruções de Build por Plataforma

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

> **Nota**: para suporte a multithreading, adicione a opção `-lpthread`.

## 📂 Estrutura de Diretórios

```
Object-Oriented-C-Language/
├── inc/                      # Arquivos de cabeçalho
│   ├── algorithm.h
│   ├── console.h
│   ├── main.h
│   ├── Scanner.h
│   ├── System.h
│   └── thread.h
├── src/                      # Arquivos-fonte
│   ├── algorithm.c
│   ├── console.c
│   ├── main.c
│   ├── Scanner.c
│   ├── System.c
│   └── thread.c
├── translations/             # Arquivos de tradução
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
├── LICENSE                   # Informações de licença
└── README.md                 # Descrição do projeto
```

## 🔧 Desenvolvimento e Compilação

### Requisitos

* GCC (versão ≥ 4.8)
* Make (opcional)

### Compilação Manual

```bash
# Execute a partir da raiz do projeto
gcc -std=c99 -Wall -I inc/ -o main src/*.c
```

### Exemplo de Makefile

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

## 🚀 Execução

```bash
# Após a compilação
./main
```

O executável realiza automaticamente exemplos de criação de objetos, chamadas de métodos e testes de multithreading.

## 📑 Estrutura da API

### 1. System e Tipos Básicos

* **SYSTEM out**

  * `out.printf(const string format, ...)` : impressão formatada
  * `out.println(const string format, ...)` : impressão formatada com nova linha

* **SYSTEM in**

  * `in.read() -> int32_t` : lê um caractere do stdin e retorna seu valor inteiro

* **File**

  * Construtor: `File new_File(const string path, const string mode)`
  * Métodos:

    * `f.scanf(const string format, ...)` : leitura formatada de arquivo
    * `f.printf(const string format, ...)` : impressão formatada em arquivo
    * `f.println(const string format, ...)` : impressão com nova linha em arquivo
    * `f.open(const string path, const string mode)` : abre um arquivo
    * `f.close()` : fecha o arquivo
    * `f.readLine() -> string` : lê uma linha do arquivo

* **Time**

  * Construtor: `Time new_Time(void)`
  * Métodos:

    * `t.getSystemTime(Time* t)` : obtém o horário do sistema
    * `t.getTime(Time* t)` : obtém o valor interno do temporizador
    * `t.setTime(...)` : define data e hora (ano, mês, dia, hora, minuto, segundo)
    * `t.start()` / `t.stop()` : controla o temporizador

* **Wrappers de Tipos Primitivos**

  * `new_String(string s)`

    * Métodos: `s.length()`, `s.charAt(index)`, `s.substring(start, end)`, `s.equals(...)`, `s.toCharArray()`
    * Métodos estáticos: `String.valueOf(...)`, `String.format(...)`

  * `new_Character(char c)`

    * Métodos: `c.charValue()`, `c.equals(...)`, `Character.isDigit(char)`, `Character.isLetter(char)`

  * `new_Byte(...)`, `new_Short(...)`, `new_Integer(...)`, `new_Long(...)`, `new_Float(...)`, `new_Double(...)`, `new_Boolean(...)`

    * Métodos comuns: `x.getValue()`, `x.toString()`, `x.equals(...)`, `x.compareTo(...)`
    * Métodos estáticos: `Wrapper.parse<Type>(...)`, `Wrapper.valueOf(...)`
    * Especializações de Byte: `b.byteValue()`, `b.toUnsigned()`, `Byte.parseByte(string, base)`
    * Especializações de Boolean: `b.booleanValue()`, `b.isTrue()`, `b.isFalse()`, `Boolean.parseBoolean(...)`

### 2. Thread e Mutex

* **Thread**

  * Construtor: `Thread new_Thread(void* (*function)(void*))`
  * Métodos:

    * `start(...)`, `join()`, `detach()`, `cancel()`, `exit()`, `delete()`

* **Mutex**

  * Construtor: `Mutex new_Mutex()`
  * Métodos: `lock()`, `unlock()`, `delete()`

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

    (utiliza espaços em branco como delimitadores por padrão e suporta leitura de linhas completas)

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

1. Faça um **fork** do projeto.
2. Crie um branch para sua funcionalidade: `git checkout -b feature/SuaFuncionalidade`
3. Implemente sua funcionalidade.
4. Escreva testes e atualize a documentação.
5. Abra uma pull request para discutir suas mudanças.

Abra uma issue para discutir ideias antes de contribuir.

## 📄 Licença

Este projeto está licenciado sob a [MIT License](../LICENSE).
