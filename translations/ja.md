# Object-Oriented C Language

> 純粋なC言語のみを使用してオブジェクト指向プログラミングのパラダイムを実装したサンプルプロジェクトです。

---

お好みの言語で翻訳をご覧いただけます。以下のリンクをクリックしてください。

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

## 📖 概要

このプロジェクトは、C言語（C99標準）のみを使用して、抽象化、カプセル化、継承、ポリモorphismといったオブジェクト指向プログラミングの主要概念をモジュラー構造で実装するサンプルです。システムコンポーネント（`System`）、スレッド管理 (`Thread`)、コンソール I/O (`Console`)、入力スキャナー (`Scanner`)、アルゴリズム (`Algorithm`) などの各機能を、構造体と関数ポインタを使ってオブジェクトとして表現しています。

## ⚙️ 主な機能

* **System**: 基本入出力、ファイル入出力、タイマー、プラットフォーム抽象化
* **Thread**: 軽量スレッドの生成と管理
* **Console**: コンソール I/O のフォーマットと制御
* **Scanner**: 入力ストリームユーティリティ
* **Algorithm**: Stack、Queue、Deque、List コレクション

## 🧰 テクノロジースタック

| バッジ                                                                                                                  | 説明                                                                          |
| -------------------------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------- |
| ![C](https://img.shields.io/badge/C-00599C?style=flat\&logo=c\&logoColor=white)                                      | **C言語**: C99標準、構造体と関数ポインタによるOOP実装                                           |
| ![GCC](https://img.shields.io/badge/GCC-333333?style=flat\&logo=gnu\&logoColor=white)                                | **GCC**: GNUコンパイラコレクション、Cプログラムのビルドに使用                                       |
| ![Make](https://img.shields.io/badge/Make-064F8C?style=flat\&logo=cmake\&logoColor=white)                            | **Make**: ビルド自動化ツール                                                         |
| ![Makefile](https://img.shields.io/badge/Makefile-000000?style=flat)                                                 | **Makefile**: Makeのビルド指示を定義する構成ファイル                                         |
| ![Windows](https://img.shields.io/badge/Windows-0078D4?style=flat\&logo=windows\&logoColor=white)                    | **Windows API**: システム関数およびマルチスレッドサポート (`windows.h`, `conio.h`, `process.h`) |
| ![Linux](https://img.shields.io/badge/Linux-000000?style=flat\&logo=linux\&logoColor=white)                          | **Linux**: オープンソースのOS                                                       |
| ![MACOS](https://img.shields.io/badge/MACOS-000000?style=flat\&logo=apple\&logoColor=white)                          | **macOS**: Unix系コマンドを備えたAppleのOS                                            |
| ![POSIX](https://img.shields.io/badge/POSIX%20Threads-000000?style=flat)                                             | **POSIX Threads**: Unix系のマルチスレッド (`pthread.h`)                              |
| ![Standard Lib](https://img.shields.io/badge/C%20Standard%20Library-000000?style=flat)                               | **C標準ライブラリ**: `stdio.h`, `stdlib.h`, `string.h`, `time.h` など                |
| ![OOP](https://img.shields.io/badge/Object--Oriented%20Programming-000000?style=flat)                                | **CにおけるOOP**: 構造体と関数ポインタによるカプセル化、抽象化、ポリモorphism                             |
| ![Algorithms](https://img.shields.io/badge/Algorithms%20\(Stack,%20Queue,%20List\)-000000?style=flat)                | **アルゴリズム**: スタック、キュー、デック、リストなどのデータ構造                                        |
| ![Git](https://img.shields.io/badge/Git-F05032?style=flat\&logo=git\&logoColor=white)                                | **Git**: バージョン管理システム                                                        |
| ![GitHub](https://img.shields.io/badge/GitHub-181717?style=flat\&logo=github\&logoColor=white)                       | **GitHub**: コラボレーションおよびコードレビューのプラットフォーム                                     |
| ![Vim](https://img.shields.io/badge/Vim-019733?style=flat\&logo=vim\&logoColor=white)                                | **Vim**: 高度にカスタマイズ可能なテキストエディタ                                               |
| ![Visual Studio](https://img.shields.io/badge/Visual%20Studio-5C2D91?style=flat\&logo=visualstudio\&logoColor=white) | **Visual Studio**: デバッグ、コード解析、テストツールを備えたIDE                                 |
| ![VSCode](https://img.shields.io/badge/VSCode-007ACC?style=flat\&logo=visualstudiocode\&logoColor=white)             | **VS Code**: ソースコードエディタ                                                     |
| ![CLion](https://img.shields.io/badge/CLion-000000?style=flat\&logo=jetbrains\&logoColor=white)                      | **CLion**: JetBrainsのC/C++ IDE                                              |

## 🖥️ プラットフォーム互換性

次のプラットフォームでテスト済みです:

* 🪟 **Windows** 10 / 11
* 🐧 **Linux**
* 🍎 **macOS**

## 🛣️ ロードマップ

* [x] C言語でのOOP実装
* [x] スレッド・ミューテックス抽象化
* [x] コンソールI/Oユーティリティ
* [x] 入力スキャナー
* [x] データ構造: スタック、キュー、リスト
* [ ] 高度なファイルユーティリティ
* [ ] SDLまたはncursesを使用したGUIレイヤー（予定）

## 🏗️ OS別ビルド手順

### 🪟 Windows (GCC MinGW)

```bash
gcc -std=c99 -Wall -I inc -o main.exe src/*.c
main.exe
```

### 🪟 Windows (MSVC コマンドプロンプト)

```cmd
cl /I inc /Fe:main.exe src\*.c
main.exe
```

### 🐧 Linux / 🍎 macOS

```bash
gcc -std=c99 -Wall -I inc -o main src/*.c -lpthread
./main
```

> **注**: マルチスレッドサポートには `-lpthread` が必要です。

## 📂 ディレクトリ構造

```
Object-Oriented-C-Language/
├── inc/                   # ヘッダファイル
│   ├── algorithm.h
│   ├── console.h
│   ├── main.h
│   ├── Scanner.h
│   ├── System.h
│   └── thread.h
├── src/                   # ソースファイル
│   ├── algorithm.c
│   ├── console.c
│   ├── main.c
│   ├── Scanner.c
│   ├── System.c
│   └── thread.c
├── translations/          # 翻訳ファイル
│   ├── ja.md              # 日本語 (このファイル)
│   ├── ko.md              # 韓国語
│   ├── ru.md              # ロシア語
│   └── zh.md              # 中国語
├── LICENSE                # ライセンス情報
└── README.md              # プロジェクト説明 
```

## 🔧 開発 & ビルド

### 要件

* GCC (バージョン ≥ 4.8)
* Make (オプション)

### 手動コンパイル

```bash
# プロジェクトルートで実行
gcc -std=c99 -Wall -I inc/ -o main src/*.c
```

### サンプルMakefile

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

## 🚀 実行方法

```bash
# ビルド後
./main
```

サンプルは自動的にオブジェクトを生成し、メソッドを呼び出し、スレッドをテストします。

## 📑 API構造

### 1. System & 基本型

* **SYSTEM out**

  * `out.printf(const string format, ...)`: フォーマット付き出力
  * `out.println(const string format, ...)`: 改行付きフォーマット出力

* **SYSTEM in**

  * `in.read() -> int32_t`: stdinから1文字を整数として読み込む

* **File**

  * コンストラクタ: `File new_File(const string path, const string mode)`
  * メソッド:

    * `f.scanf(const string format, ...)`: ファイルからフォーマット付き入力
    * `f.printf(const string format, ...)`: ファイルへのフォーマット付き出力
    * `f.println(const string format, ...)`: 改行付き出力
    * `f.open(const string path, const string mode)`: ファイルを開く
    * `f.close()`: ファイルを閉じる
    * `f.readLine() -> string`: ファイルから1行読み込む

### 2. Thread & Mutex

* **Thread**

  * コンストラクタ: `Thread new_Thread(void* (*function)(void*))`
  * メソッド: `start(...)`, `join()`, `detach()`, `cancel()`, `exit()`, `delete()`

* **Mutex**

  * コンストラクタ: `Mutex new_Mutex()`
  * メソッド: `lock()`, `unlock()`, `delete()`

### 3. Console

* **Console**

  * コンストラクタ: `Console new_console(void)`
  * メソッド:

    * `print(...)`, `println(...)`, `readLine()`, `clear()`
    * `setColor(ColorType color)`, `resetColor()`, `kbhit() -> int`

### 4. Scanner

* **Scanner**

  * コンストラクタ: `Scanner new_Scanner(struct __stdin_t in)`
  * メソッド:

    * `nextChar()`, `nextByte()`, `nextShort()`, `nextInt()`, `nextLong()`
    * `nextUByte()`, `nextUShort()`, `nextUInt()`, `nextULong()`
    * `nextBoolean()`, `nextFloat()`, `nextDouble()`, `nextLDouble()`
    * `next() -> string`, `nextLine() -> string` (デフォルトで空白区切り)

### 5. コレクション (Algorithm)

* **Stack**

  * コンストラクタ: `Stack new_stack(size_t elementSize)`
  * メソッド: `push(...)`, `pop() -> void*`, `clear()`, `delete()`

* **Queue**

  * コンストラクタ: `Queue new_queue(size_t elementSize)`
  * メソッド: `push(...)`, `pop() -> void*`, `clear()`, `delete()`

* **Deque**

  * コンストラクタ: `Deque new_deque(size_t elementSize)`
  * メソッド: `pushFront(...)`, `pushBack(...)`, `popFront()`, `popBack()`, `clear()`, `delete()`

* **List**

  * コンストラクタ: `List new_list(size_t elementSize)`
  * メソッド: `add(...)`, `get(index)`, `remove(index)`, `size()`, `clear()`, `delete()`

## 🛠️ コントリビューションガイド

1. プロジェクトをフォークします。
2. 機能ブランチを作成します: `git checkout -b feature/YourFeature`
3. 機能を実装します。
4. テストを書いてドキュメントを更新します。
5. Pull Requestを作成して変更を議論します。

事前にIssueを立ててアイデアを相談してください。

## 📄 ライセンス

このプロジェクトは[MITライセンス](LICENSE)の下でライセンスされています。
