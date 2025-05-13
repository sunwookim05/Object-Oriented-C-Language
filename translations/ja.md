# Object-Oriented C Language

> 純粋な C 言語を使用してオブジェクト指向プログラミングのパラダイムを実装したサンプルプロジェクトです。

---

以下のリンクをクリックすると、お好みの言語で翻訳された内容をご覧いただけます。

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

このプロジェクトは、純粋な C 言語（C99 標準）のみを使用して、オブジェクト指向プログラミングの主要概念（抽象化、カプセル化、継承、多態性）をモジュラー構造で実装したサンプルです。`System`、`Thread`、`Console`、`Scanner`、`Algorithm` といったさまざまなシステムコンポーネントが、struct と関数ポインタを使用したオブジェクトとして表現されています。

## ⚙️ 主な機能

* **System**: 基本入出力、ファイル入出力、タイマー、プラットフォーム抽象化
* **Thread**: 軽量スレッドの作成と管理
* **Console**: コンソール入出力のフォーマットと制御
* **Scanner**: 入力ストリームユーティリティ
* **Algorithm**: Stack、Queue、Deque、List コレクション

## 🧰 技術スタック

| Badge                                                                                                                | Description                                                                       |
| -------------------------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------- |
| ![C](https://img.shields.io/badge/C-00599C?style=flat\&logo=c\&logoColor=white)                                      | **C 言語**: C99 標準、struct と関数ポインタを使用したオブジェクト指向プログラミングの実装                            |
| ![GCC](https://img.shields.io/badge/GCC-333333?style=flat\&logo=gnu\&logoColor=white)                                | **GCC**: GNU Compiler Collection、C プログラムのビルドに使用                                   |
| ![Make](https://img.shields.io/badge/Make-064F8C?style=flat\&logo=cmake\&logoColor=white)                            | **Make**: ソースファイルのコンパイルとリンクを自動化するツール                                              |
| ![Makefile](https://img.shields.io/badge/Makefile-000000?style=flat)                                                 | **Makefile**: Make コマンドのビルド指示を記述した設定ファイル                                          |
| ![Windows](https://img.shields.io/badge/Windows-0078D4?style=flat\&logo=windows\&logoColor=white)                    | **Windows API**: Windows のシステム関数とマルチスレッドサポート（`windows.h`, `conio.h`, `process.h`） |
| ![Linux](https://img.shields.io/badge/Linux-000000?style=flat\&logo=linux\&logoColor=white)                          | **Linux**: プログラミングと開発で広く使用されているオープンソース OS                                         |
| ![MACOS](https://img.shields.io/badge/MACOS-000000?style=flat\&logo=apple\&logoColor=white)                          | **macOS**: Unix 系のコマンドをサポートする Mac ハードウェア用 OS                                      |
| ![POSIX](https://img.shields.io/badge/POSIX%20Threads-000000?style=flat)                                             | **POSIX スレッド**: Unix 系システムのマルチスレッドサポート（`pthread.h`）                               |
| ![Standard Lib](https://img.shields.io/badge/C%20Standard%20Library-000000?style=flat)                               | **C 標準ライブラリ**: `stdio.h`, `stdlib.h`, `string.h`, `time.h` などのコアライブラリ             |
| ![OOP](https://img.shields.io/badge/Object--Oriented%20Programming-000000?style=flat)                                | **C での OOP**: struct と関数ポインタによるカプセル化、抽象化、多態性                                      |
| ![Algorithms](https://img.shields.io/badge/Algorithms%20\(Stack,%20Queue,%20List\)-000000?style=flat)                | **アルゴリズム**: Stack、Queue、Deque、List などのデータ構造の実装                                    |
| ![Git](https://img.shields.io/badge/Git-F05032?style=flat\&logo=git\&logoColor=white)                                | **Git**: コード変更管理のためのバージョン管理システム                                                   |
| ![GitHub](https://img.shields.io/badge/GitHub-181717?style=flat\&logo=github\&logoColor=white)                       | **GitHub**: コード共有とレビューのためのプラットフォーム                                                |
| ![Vim](https://img.shields.io/badge/Vim-019733?style=flat\&logo=vim\&logoColor=white)                                | **Vim**: 効率的なテキスト編集のための高度にカスタマイズ可能なエディタ                                           |
| ![Visual Studio](https://img.shields.io/badge/Visual%20Studio-5C2D91?style=flat\&logo=visualstudio\&logoColor=white) | **Visual Studio**: 強力なデバッグ、コード解析、テストツールを備えた C/C++ 開発 IDE                          |
| ![VS Code](https://img.shields.io/badge/VSCode-007ACC?style=flat\&logo=visualstudiocode\&logoColor=white)            | **Visual Studio Code**: コード作成とデバッグのためのソースコードエディタ                                  |
| ![CLion](https://img.shields.io/badge/CLion-000000?style=flat\&logo=jetbrains\&logoColor=white)                      | **CLion**: 強力なコード解析、リファクタリング、CMake 統合をサポートする JetBrains の C/C++ IDE                |

## 🖥️ プラットフォーム互換性

このプロジェクトは以下のプラットフォームでテストおよび実行されています。

* 🪟 **Windows** 10 / 11
* 🐧 **Linux**
* 🍎 **macOS**

## 🛣️ ロードマップ

* [x] C でのオブジェクト指向プログラミング
* [x] スレッドおよびミューテックスの抽象化
* [x] コンソール入出力ユーティリティ
* [x] 基本型入力スキャナー
* [x] データ構造: Stack、Queue、List
* [ ] 高度なファイルユーティリティ
* [ ] SDL または ncurses を使用した GUI レイヤー（予定）

## 🏗️ OS ごとのビルド手順

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

> **注意**: マルチスレッドサポートには `-lpthread` が必要です。

## 📂 ディレクトリ構造

```
Object-Oriented-C-Language/
├── inc/                      # ヘッダーファイル
│   ├── algorithm.h
│   ├── console.h
│   ├── main.h
│   ├── Scanner.h
│   ├── System.h
│   └── thread.h
├── src/                      # ソースファイル
│   ├── algorithm.c
│   ├── console.c
│   ├── main.c
│   ├── Scanner.c
│   ├── System.c
│   └── thread.c
├── translations/             # 翻訳ファイル
│   ├── ar.md                 # アラビア語
│   ├── es.md                 # スペイン語
│   ├── fr.md                 # フランス語
│   ├── hi.md                 # ヒンディー語
│   ├── it.md                 # イタリア語
│   ├── ja.md                 # 日本語 （このファイル）
│   ├── ko.md                 # 韓国語
│   ├── pt.md                 # ポルトガル語
│   ├── ru.md                 # ロシア語
│   └── zh.md                 # 中国語
├── LICENSE                   # ライセンス情報
└── README.md                 # プロジェクト説明
```

## 🔧 開発およびビルド

### 要件

* GCC (バージョン ≥ 4.8)
* Make (オプション)

### 手動コンパイル

```bash
# プロジェクトルートディレクトリで実行
gcc -std=c99 -Wall -I inc/ -o main src/*.c
```

### サンプル Makefile

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

## 🚀 実行方法

```bash
# ビルド後
./main
```

サンプルはオブジェクトを生成し、メソッドを呼び出し、スレッドをテストします。

## 📑 API 構造

### 1. System と基本型

* **SYSTEM out**

  * `out.printf(const string format, ...)` ： フォーマットされた出力
  * `out.println(const string format, ...)` ： 改行付きフォーマット出力

* **SYSTEM in**

  * `in.read() -> int32_t` ： stdin から文字を整数として読み込み

* **File**

  * コンストラクタ： `File new_File(const string path, const string mode)`
  * メソッド：

    * `f.scanf(const string format, ...)` ： ファイルからのフォーマット入力
    * `f.printf(const string format, ...)` ： ファイルへのフォーマット出力
    * `f.println(const string format, ...)` ： 改行付き出力
    * `f.open(const string path, const string mode)` ： ファイルを開く
    * `f.close()` ： ファイルを閉じる
    * `f.readLine() -> string` ： ファイルから1行読み込む

* **Time**

  * コンストラクタ： `Time new_Time(void)`
  * メソッド：

    * `t.getSystemTime(Time* t)` ： 現在のシステム時間を取得
    * `t.getTime(Time* t)` ： 内部時間値を取得
    * `t.setTime(...)` ： 時刻を設定（年、月、日、時、分、秒）
    * `t.start()` / `t.stop()` ： タイマースレッド制御

* **基本型ラッパーコンストラクタ**

  * `new_String(string s)`

    * メソッド： `s.length()`, `s.charAt(index)`, `s.substring(start, end)`, `s.equals(...)`, `s.toCharArray()`
    * 静的メソッド： `String.valueOf(...)`, `String.format(...)`

  * `new_Character(char c)`

    * メソッド： `c.charValue()`, `c.equals(...)`, `Character.isDigit(char)`, `Character.isLetter(char)`

  * `new_Byte(...)`, `new_Short(...)`, `new_Integer(...)`, `new_Long(...)`, `new_Float(...)`, `new_Double(...)`, `new_Boolean(...)`

    * 共通メソッド： `x.getValue()`, `x.toString()`, `x.equals(...)`, `x.compareTo(...)`
    * 静的メソッド： `Wrapper.parse<Type>(...)`, `Wrapper.valueOf(...)`
    * Byte 固有： `b.byteValue()`, `b.toUnsigned()`, `Byte.parseByte(string, base)`
    * Boolean 固有： `b.booleanValue()`, `b.isTrue()`, `b.isFalse()`, `Boolean.parseBoolean(...)`

### 2. Thread と Mutex

* **Thread**

  * コンストラクタ： `Thread new_Thread(void* (*function)(void*))`
  * メソッド：

    * `start(...)`, `join()`, `detach()`, `cancel()`, `exit()`, `delete()`

* **Mutex**

  * コンストラクタ： `Mutex new_Mutex()`
  * メソッド：

    * `lock()`, `unlock()`, `delete()`

### 3. Console

* **Console**

  * コンストラクタ： `Console new_console(void)`
  * メソッド：

    * `print(...)`, `println(...)`, `readLine()`, `clear()`
    * `setColor(ColorType color)`, `resetColor()`, `kbhit() -> int`

### 4. Scanner

* **Scanner**

  * コンストラクタ： `Scanner new_Scanner(struct __stdin_t in)`
  * メソッド：

    * `nextChar()`, `nextByte()`, `nextShort()`, `nextInt()`, `nextLong()`
    * `nextUByte()`, `nextUShort()`, `nextUInt()`, `nextULong()`
    * `nextBoolean()`, `nextFloat()`, `nextDouble()`, `nextLDouble()`
    * `next() -> string`, `nextLine() -> string`

    （デフォルトでは空白を区切り文字として使用し、行単位読み込みもサポートします。）

### 5. コレクション (Algorithm)

* **Stack**

  * コンストラクタ： `Stack new_stack(size_t elementSize)`
  * メソッド： `push(...)`, `pop() -> void*`, `clear()`, `delete()`

* **Queue**

  * コンストラクタ： `Queue new_queue(size_t elementSize)`
  * メソッド： `push(...)`, `pop() -> void*`, `clear()`, `delete()`

* **Deque**

  * コンストラクタ： `Deque new_deque(size_t elementSize)`
  * メソッド： `pushFront(...)`, `pushBack(...)`, `popFront()`, `popBack()`, `clear()`, `delete()`

* **List**

  * コンストラクタ： `List new_list(size_t elementSize)`
  * メソッド： `add(...)`, `get(index)`, `remove(index)`, `size()`, `clear()`, `delete()`

## 🛠️ 貢献ガイド

1. **Fork** してください
2. **機能ブランチを作成**: `git checkout -b feature/YourFeature`
3. **機能を実装**
4. **テスト作成およびドキュメント更新**
5. **Pull Request を作成**

アイデアを話し合うには、まず issue を開いてください。

## 📄 ライセンス

このプロジェクトは [MIT License](../LICENSE) の下でライセンスされています。
