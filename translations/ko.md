# Object-Oriented C Language

> 순수 C 언어를 사용하여 객체 지향 프로그래밍 패러다임을 구현한 예제 프로젝트입니다.

---

아래 링크를 클릭하여 원하는 언어로 번역된 내용을 볼 수 있습니다.

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

## 📖 개요

이 프로젝트는 순수 C 언어(C99 표준)만으로 객체 지향 프로그래밍의 핵심 개념(추상화, 캡슐화, 상속, 다형성)을 모듈화된 구조로 구현한 예제입니다. 다양한 시스템 구성 요소(`System`), 스레딩(`Thread`), 콘솔 입출력(`Console`), 입력 스캐닝(`Scanner`), 알고리즘(`Algorithm`)이 struct와 함수 포인터를 사용한 객체 형태로 표현되어 있습니다.

## ⚙️ 주요 기능

* **System**: 기본 입출력, 파일 입출력, 타이머, 플랫폼 추상화
* **Thread**: 경량 스레드 생성 및 관리
* **Console**: 콘솔 입출력 포맷팅 및 제어
* **Scanner**: 입력 스트림 유틸리티
* **Algorithm**: Stack, Queue, Deque, List 컬렉션

## 🧰 기술 스택

| Badge                                                                                                                | Description                                                                     |
| -------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------- |
| ![C](https://img.shields.io/badge/C-00599C?style=flat\&logo=c\&logoColor=white)                                      | **C 언어**: C99 표준, struct와 함수 포인터를 사용한 객체 지향 프로그래밍 구현                            |
| ![GCC](https://img.shields.io/badge/GCC-333333?style=flat\&logo=gnu\&logoColor=white)                                | **GCC**: GNU Compiler Collection, C 프로그램 빌드에 사용                                 |
| ![Make](https://img.shields.io/badge/Make-064F8C?style=flat\&logo=cmake\&logoColor=white)                            | **Make**: 소스 파일 컴파일 및 링크 자동화 도구                                                 |
| ![Makefile](https://img.shields.io/badge/Makefile-000000?style=flat)                                                 | **Makefile**: Make 명령을 위한 빌드 지침 구성 파일                                           |
| ![Windows](https://img.shields.io/badge/Windows-0078D4?style=flat\&logo=windows\&logoColor=white)                    | **Windows API**: Windows 시스템 함수 및 멀티스레딩 지원(`windows.h`, `conio.h`, `process.h`) |
| ![Linux](https://img.shields.io/badge/Linux-000000?style=flat\&logo=linux\&logoColor=white)                          | **Linux**: 프로그래밍 및 개발에 널리 사용되는 오픈 소스 운영체제                                       |
| ![MACOS](https://img.shields.io/badge/MACOS-000000?style=flat\&logo=apple\&logoColor=white)                          | **macOS**: Unix 계열 명령어를 지원하는 Mac 하드웨어 운영체제                                      |
| ![POSIX](https://img.shields.io/badge/POSIX%20Threads-000000?style=flat)                                             | **POSIX 스레드**: 유닉스 기반 시스템의 멀티스레딩 지원(`pthread.h`)                                |
| ![Standard Lib](https://img.shields.io/badge/C%20Standard%20Library-000000?style=flat)                               | **C 표준 라이브러리**: `stdio.h`, `stdlib.h`, `string.h`, `time.h` 등 핵심 라이브러리          |
| ![OOP](https://img.shields.io/badge/Object--Oriented%20Programming-000000?style=flat)                                | **C에서의 OOP**: struct와 함수 포인터를 통한 캡슐화, 추상화, 다형성                                  |
| ![Algorithms](https://img.shields.io/badge/Algorithms%20\(Stack,%20Queue,%20List\)-000000?style=flat)                | **알고리즘**: Stack, Queue, Deque, List 등 데이터 구조 구현                                 |
| ![Git](https://img.shields.io/badge/Git-F05032?style=flat\&logo=git\&logoColor=white)                                | **Git**: 코드 변경 관리를 위한 버전 관리 시스템                                                 |
| ![GitHub](https://img.shields.io/badge/GitHub-181717?style=flat\&logo=github\&logoColor=white)                       | **GitHub**: 코드 공유 및 리뷰를 위한 플랫폼                                                  |
| ![Vim](https://img.shields.io/badge/Vim-019733?style=flat\&logo=vim\&logoColor=white)                                | **Vim**: 효율적인 텍스트 편집을 위한 고도로 구성 가능한 편집기                                         |
| ![Visual Studio](https://img.shields.io/badge/Visual%20Studio-5C2D91?style=flat\&logo=visualstudio\&logoColor=white) | **Visual Studio**: 강력한 디버깅, 코드 분석 및 테스트 도구를 제공하는 C/C++ 개발 IDE                   |
| ![VS Code](https://img.shields.io/badge/VSCode-007ACC?style=flat\&logo=visualstudiocode\&logoColor=white)            | **Visual Studio Code**: 코드 작성 및 디버깅을 위한 소스 코드 편집기                               |
| ![CLion](https://img.shields.io/badge/CLion-000000?style=flat\&logo=jetbrains\&logoColor=white)                      | **CLion**: 강력한 코드 분석, 리팩토링, CMake 통합을 지원하는 JetBrains의 C/C++ IDE                 |

## 🖥️ 플랫폼 호환성

이 프로젝트는 다음 플랫폼에서 테스트되었으며 실행됩니다:

* 🪟 **Windows** 10 / 11
* 🐧 **Linux**
* 🍎 **macOS**

## 🛣️ 로드맵

* [x] C에서의 객체 지향 프로그래밍
* [x] 스레드 및 뮤텍스 추상화
* [x] 콘솔 입출력 유틸리티
* [x] 기본형 입력 스캐너
* [x] 데이터 구조: Stack, Queue, List
* [ ] 고급 파일 유틸리티
* [ ] SDL 또는 ncurses를 이용한 GUI 레이어 (예정)

## 🏗️ OS별 빌드 지침

### 🪟 Windows (GCC MinGW)

```bash
gcc -std=c99 -Wall -I inc -o main.exe src/*.c
main.exe
```

### 🪟 Windows (MSVC 명령 프롬프트)

```cmd
cl /I inc /Fe:main.exe src\*.c
main.exe
```

### 🐧 Linux / 🍎 macOS

```bash
gcc -std=c99 -Wall -I inc -o main src/*.c -lpthread
./main
```

> **참고**: 멀티스레딩 지원을 위해 `-lpthread`가 필요합니다.

## 📂 디렉터리 구조

```
Object-Oriented-C-Language/
├── inc/                      # 헤더 파일
│   ├── algorithm.h
│   ├── console.h
│   ├── main.h
│   ├── Scanner.h
│   ├── System.h
│   └── thread.h
├── src/                      # 소스 파일
│   ├── algorithm.c
│   ├── console.c
│   ├── main.c
│   ├── Scanner.c
│   ├── System.c
│   └── thread.c
├── translations/             # 번역 파일
│   ├── ar.md                 # 아랍어
│   ├── es.md                 # 스페인어
│   ├── fr.md                 # 프랑스어
│   ├── hi.md                 # 힌디어
│   ├── it.md                 # 이탈리아어
│   ├── ja.md                 # 일본어
│   ├── ko.md                 # 한국어 (이 파일)
│   ├── pt.md                 # 포르투갈어
│   ├── ru.md                 # 러시아어
│   └── zh.md                 # 중국어
├── LICENSE                   # 라이선스 정보
└── README.md                 # 프로젝트 설명
```

## 🔧 개발 및 빌드

### 요구 사항

* GCC (버전 ≥ 4.8)
* Make (선택 사항)

### 수동 컴파일

```bash
# 프로젝트 루트 디렉터리에서
gcc -std=c99 -Wall -I inc/ -o main src/*.c
```

### 예제 Makefile

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

## 🚀 실행 방법

```bash
# 빌드 후
./main
```

샘플은 객체를 생성하고 메서드를 호출하며 스레드를 테스트합니다.

## 📑 API 구조

### 1. System 및 기본형 타입

* **SYSTEM out**

  * `out.printf(const string format, ...)` : 형식화된 출력
  * `out.println(const string format, ...)` : 줄바꿈이 포함된 형식화된 출력

* **SYSTEM in**

  * `in.read() -> int32_t` : stdin으로부터 문자를 정수로 읽음

* **File**

  * 생성자: `File new_File(const string path, const string mode)`
  * 메서드:

    * `f.scanf(const string format, ...)` : 파일로부터 형식화된 입력
    * `f.printf(const string format, ...)` : 파일에 형식화된 출력
    * `f.println(const string format, ...)` : 줄바꿈이 포함된 출력
    * `f.open(const string path, const string mode)` : 파일 열기
    * `f.close()` : 파일 닫기
    * `f.readLine() -> string` : 파일에서 한 줄 읽기

* **Time**

  * 생성자: `Time new_Time(void)`
  * 메서드:

    * `t.getSystemTime(Time* t)` : 현재 시스템 시간 가져오기
    * `t.getTime(Time* t)` : 내부 시간 값 가져오기
    * `t.setTime(...)` : 시간 설정 (년, 월, 일, 시, 분, 초)
    * `t.start()` / `t.stop()` : 타이머 스레드 제어

* **기본형 래퍼 생성자**

  * `new_String(string s)`

    * 메서드: `s.length()`, `s.charAt(index)`, `s.substring(start, end)`, `s.equals(...)`, `s.toCharArray()`
    * 정적 메서드: `String.valueOf(...)`, `String.format(...)`

  * `new_Character(char c)`

    * 메서드: `c.charValue()`, `c.equals(...)`, `Character.isDigit(char)`, `Character.isLetter(char)`

  * `new_Byte(...)`, `new_Short(...)`, `new_Integer(...)`, `new_Long(...)`, `new_Float(...)`, `new_Double(...)`, `new_Boolean(...)`

    * 공통 메서드: `x.getValue()`, `x.toString()`, `x.equals(...)`, `x.compareTo(...)`
    * 정적 메서드: `Wrapper.parse<Type>(...)`, `Wrapper.valueOf(...)`
    * Byte 전용: `b.byteValue()`, `b.toUnsigned()`, `Byte.parseByte(string, base)`
    * Boolean 전용: `b.booleanValue()`, `b.isTrue()`, `b.isFalse()`, `Boolean.parseBoolean(...)`

### 2. Thread 및 Mutex

* **Thread**

  * 생성자: `Thread new_Thread(void* (*function)(void*))`
  * 메서드:

    * `start(...)`, `join()`, `detach()`, `cancel()`, `exit()`, `delete()`

* **Mutex**

  * 생성자: `Mutex new_Mutex()`
  * 메서드:

    * `lock()`, `unlock()`, `delete()`

### 3. Console

* **Console**

  * 생성자: `Console new_console(void)`
  * 메서드:

    * `print(...)`, `println(...)`, `readLine()`, `clear()`
    * `setColor(ColorType color)`, `resetColor()`, `kbhit() -> int`

### 4. Scanner

* **Scanner**

  * 생성자: `Scanner new_Scanner(struct __stdin_t in)`
  * 메서드:

    * `nextChar()`, `nextByte()`, `nextShort()`, `nextInt()`, `nextLong()`
    * `nextUByte()`, `nextUShort()`, `nextUInt()`, `nextULong()`
    * `nextBoolean()`, `nextFloat()`, `nextDouble()`, `nextLDouble()`
    * `next() -> string`, `nextLine() -> string`

    (기본적으로 공백을 구분자로 사용하며, 줄 단위 읽기도 지원합니다.)

### 5. 컬렉션 (Algorithm)

* **Stack**

  * 생성자: `Stack new_stack(size_t elementSize)`
  * 메서드: `push(...)`, `pop() -> void*`, `clear()`, `delete()`

* **Queue**

  * 생성자: `Queue new_queue(size_t elementSize)`
  * 메서드: `push(...)`, `pop() -> void*`, `clear()`, `delete()`

* **Deque**

  * 생성자: `Deque new_deque(size_t elementSize)`
  * 메서드: `pushFront(...)`, `pushBack(...)`, `popFront()`, `popBack()`, `clear()`, `delete()`

* **List**

  * 생성자: `List new_list(size_t elementSize)`
  * 메서드: `add(...)`, `get(index)`, `remove(index)`, `size()`, `clear()`, `delete()`

## 🛠️ 기여 가이드

1. **Fork** 이 프로젝트
2. **기능 브랜치 생성**: `git checkout -b feature/YourFeature`
3. **기능 구현**
4. **테스트 작성 및 문서 업데이트**
5. **Pull Request** 생성

아이디어를 논의하려면 먼저 이슈를 열어주세요.

## 📄 라이선스

이 프로젝트는 [MIT License](../LICENSE) 하에 라이선스됩니다.
