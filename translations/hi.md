# Object-Oriented C Language

> यह एक शुद्ध C भाषा (C99 मानक) का उपयोग करके ऑब्जेक्ट-ओरिएंटेड प्रोग्रामिंग पैरेडाइम को लागू करने वाला उदाहरण प्रोजेक्ट है।

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

## 📖 अवलोकन

यह प्रोजेक्ट केवल C भाषा (C99 मानक) का उपयोग करके ऑब्जेक्ट-ओरिएंटेड प्रोग्रामिंग के मूल तत्वों (सारांशण, एनकैप्सुलेशन, विरासत, बहुरूपता) को मॉड्यूलर संरचना में लागू करने का एक उदाहरण है। विभिन्न सिस्टम घटक (`System`), थ्रेडिंग (`Thread`), कंसोल इनपुट/आउटपुट (`Console`), इनपुट स्कैनिंग (`Scanner`), एल्गोरिथ्म (`Algorithm`) को struct और फ़ंक्शन पॉइंटर का उपयोग करके ऑब्जेक्ट रूप में दर्शाया गया है।

## ⚙️ प्रमुख सुविधाएँ

* **System**: बुनियादी इनपुट/आउटपुट, फ़ाइल इनपुट/आउटपुट, टाइमर, प्लेटफ़ॉर्म अमूर्तता
* **Thread**: हल्की वज़न वाली थ्रेड निर्माण और प्रबंधन
* **Console**: कंसोल इनपुट/आउटपुट फ़ॉर्मेटिंग और नियंत्रण
* **Scanner**: इनपुट स्ट्रीम यूटिलिटीज़
* **Algorithm**: Stack, Queue, Deque, List संग्रह

## 🧰 प्रौद्योगिकी स्टैक

| Badge                                                                                                                | Description                                                                                             |
| -------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------- |
| ![C](https://img.shields.io/badge/C-00599C?style=flat\&logo=c\&logoColor=white)                                      | **C भाषा**: C99 मानक, struct और फ़ंक्शन पॉइंटर का उपयोग करके ऑब्जेक्ट-ओरिएंटेड प्रोग्रामिंग कार्यान्वयन |
| ![GCC](https://img.shields.io/badge/GCC-333333?style=flat\&logo=gnu\&logoColor=white)                                | **GCC**: GNU Compiler Collection, C प्रोग्राम निर्माण में उपयोग                                         |
| ![Make](https://img.shields.io/badge/Make-064F8C?style=flat\&logo=cmake\&logoColor=white)                            | **Make**: स्रोत फ़ाइलों के संकलन और लिंक को स्वचालित करने वाला उपकरण                                    |
| ![Makefile](https://img.shields.io/badge/Makefile-000000?style=flat)                                                 | **Makefile**: Make कमांड के लिए बिल्ड निर्देशों को परिभाषित करने वाली फ़ाइल                             |
| ![Windows](https://img.shields.io/badge/Windows-0078D4?style=flat\&logo=windows\&logoColor=white)                    | **Windows API**: Windows सिस्टम फ़ंक्शन और मल्टीथ्रेडिंग समर्थन (`windows.h`, `conio.h`, `process.h`)   |
| ![Linux](https://img.shields.io/badge/Linux-FCC624?style=flat\&logo=linux\&logoColor=black)                          | **Linux**: एक लोकप्रिय ओपन-सोर्स ऑपरेटिंग सिस्टम                                                        |
| ![MACOS](https://img.shields.io/badge/MACOS-000000?style=flat\&logo=apple\&logoColor=white)                          | **macOS**: Unix-आधारित Mac ऑपरेटिंग सिस्टम                                                              |
| ![POSIX](https://img.shields.io/badge/POSIX%20Threads-000000?style=flat)                                             | **POSIX थ्रेड**: Unix-आधारित सिस्टम में मल्टीथ्रेडिंग समर्थन (`pthread.h`)                              |
| ![Standard Lib](https://img.shields.io/badge/C%20Standard%20Library-000000?style=flat)                               | **C मानक लाइब्रेरी**: `stdio.h`, `stdlib.h`, `string.h`, `time.h` आदि मूल लाइब्रेरी                     |
| ![OOP](https://img.shields.io/badge/Object--Oriented%20Programming-000000?style=flat)                                | **OOP in C**: struct और फ़ंक्शन पॉइंटर द्वारा एनकैप्सुलेशन, सारांशण, बहुरूपता                           |
| ![Algorithms](https://img.shields.io/badge/Algorithms%20\(Stack,%20Queue,%20List\)-000000?style=flat)                | **एल्गोरिथ्म**: Stack, Queue, Deque, List जैसी डेटा संरचनाएँ                                            |
| ![Git](https://img.shields.io/badge/Git-F05032?style=flat\&logo=git\&logoColor=white)                                | **Git**: कोड संस्करण नियंत्रण के लिए सिस्टम                                                             |
| ![GitHub](https://img.shields.io/badge/GitHub-181717?style=flat\&logo=github\&logoColor=white)                       | **GitHub**: कोड साझा करने और समीक्षा के लिए मंच                                                         |
| ![Vim](https://img.shields.io/badge/Vim-019733?style=flat\&logo=vim\&logoColor=white)                                | **Vim**: कुशल टेक्स्ट संपादन के लिए एक अत्यधिक अनुकूलनीय संपादक                                         |
| ![Visual Studio](https://img.shields.io/badge/Visual%20Studio-5C2D91?style=flat\&logo=visualstudio\&logoColor=white) | **Visual Studio**: शक्तिशाली डिबगिंग, कोड विश्लेषण और परीक्षण उपकरण प्रदान करने वाला C/C++ IDE          |
| ![VS Code](https://img.shields.io/badge/VSCode-007ACC?style=flat\&logo=visualstudiocode\&logoColor=white)            | **Visual Studio Code**: स्रोत कोड लेखन और डिबगिंग के लिए संपादक                                         |
| ![CLion](https://img.shields.io/badge/CLion-000000?style=flat\&logo=jetbrains\&logoColor=white)                      | **CLion**: JetBrains द्वारा C/C++ IDE, मजबूत कोड विश्लेषण, रिफैक्टरिंग, और CMake एकीकरण समर्थन          |

## 🖥️ प्लेटफ़ॉर्म संगतता

यह प्रोजेक्ट निम्नलिखित प्लेटफ़ॉर्म पर परीक्षण किया गया है और चलता है:

* 🪟 **Windows** 10 / 11
* 🐧 **Linux**
* 🍎 **macOS**

## 🛣️ रोडमैप

* [x] C में ऑब्जेक्ट-ओरिएंटेड प्रोग्रामिंग
* [x] थ्रेड और म्यूटेक्स अमूर्तता
* [x] कंसोल इनपुट/आउटपुट यूटिलिटी
* [x] प्रिमिटिव इनपुट स्कैनर
* [x] डेटा संरचनाएँ: Stack, Queue, List
* [ ] उन्नत फ़ाइल यूटिलिटी
* [ ] SDL या ncurses का उपयोग करके GUI लेयर (योजना)

## 🏗️ OS के लिए बिल्ड निर्देश

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

> **नोट**: मल्टीथ्रेडिंग समर्थन के लिए `-lpthread` आवश्यक है।

## 📂 निर्देशिका संरचना

```
Object-Oriented-C-Language/
├── inc/                      # हेडर फ़ाइलें
│   ├── algorithm.h
│   ├── console.h
│   ├── main.h
│   ├── Scanner.h
│   ├── System.h
│   └── thread.h
├── src/                      # स्रोत फ़ाइलें
│   ├── algorithm.c
│   ├── console.c
│   ├── main.c
│   ├── Scanner.c
│   ├── System.c
│   └── thread.c
├── translations/             # अनुवाद फाइलें
│   ├── ar.md                 # अरबी
│   ├── es.md                 # स्पेनिश
│   ├── fr.md                 # फ्रेंच
│   ├── hi.md                 # हिंदी (यह फ़ाइल)
│   ├── it.md                 # इतालवी
│   ├── ja.md                 # जापानी
│   ├── ko.md                 # कोरियाई
│   ├── pt.md                 # पुर्तगाली
│   ├── ru.md                 # रूसी
│   └── zh.md                 # चीनी
├── LICENSE                   # लाइसेंस सूचना
└── README.md                 # प्रोजेक्ट विवरण
```

## 🔧 विकास और बिल्ड

### आवश्यकताएँ

* GCC (संस्करण ≥ 4.8)
* Make (वैकल्पिक)

### मैनुअल कंपाइल

```bash
# प्रोजेक्ट रूट डायरेक्टरी में
gcc -std=c99 -Wall -I inc/ -o main src/*.c
```

### नमूना Makefile

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

## 🚀 चलाने का तरीका

```bash
# बिल्ड के बाद
./main
```

उदाहरण ऑब्जेक्ट बनाता है, विधियाँ कॉल करता है, और थ्रेड का परीक्षण करता है।

## 📑 API संरचना

### 1. System और प्रिमिटिव प्रकार

* **SYSTEM out**

  * `out.printf(const string format, ...)` : फ़ॉर्मेट किए गए आउटपुट
  * `out.println(const string format, ...)` : लाइन ब्रेक के साथ फ़ॉर्मेट किए गए आउटपुट

* **SYSTEM in**

  * `in.read() -> int32_t` : stdin से एक अक्षर को पूर्णांक के रूप में पढ़ें

* **File**

  * कंस्ट्रक्टर: `File new_File(const string path, const string mode)`
  * मेथड:

    * `f.scanf(const string format, ...)` : फ़ाइल से फ़ॉर्मेटेड इनपुट
    * `f.printf(const string format, ...)` : फ़ाइल में फ़ॉर्मेटेड आउटपुट
    * `f.println(const string format, ...)` : लाइन ब्रेक सहित आउटपुट
    * `f.open(const string path, const string mode)` : फ़ाइल खोलें
    * `f.close()` : फ़ाइल बंद करें
    * `f.readLine() -> string` : फ़ाइल से एक पंक्ति पढ़ें

* **Time**

  * कंस्ट्रक्टर: `Time new_Time(void)`
  * मेथड:

    * `t.getSystemTime(Time* t)` : वर्तमान सिस्टम समय प्राप्त करें
    * `t.getTime(Time* t)` : आंतरिक समय मान प्राप्त करें
    * `t.setTime(...)` : समय सेट करें (वर्ष, माह, दिन, घंटे, मिनट, सेकंड)
    * `t.start()` / `t.stop()` : टाइमर थ्रेड नियंत्रित करें

* **प्रिमिटिव रैपर कंस्ट्रक्टर**

  * `new_String(string s)`

    * मेथड: `s.length()`, `s.charAt(index)`, `s.substring(start, end)`, `s.equals(...)`, `s.toCharArray()`
    * स्थैतिक मेथड: `String.valueOf(...)`, `String.format(...)`

  * `new_Character(char c)`

    * मेथड: `c.charValue()`, `c.equals(...)`, `Character.isDigit(char)`, `Character.isLetter(char)`

  * `new_Byte(...)`, `new_Short(...)`, `new_Integer(...)`, `new_Long(...)`, `new_Float(...)`, `new_Double(...)`, `new_Boolean(...)`

    * सामान्य मेथड: `x.getValue()`, `x.toString()`, `x.equals(...)`, `x.compareTo(...)`
    * स्थैतिक मेथड: `Wrapper.parse<Type>(...)`, `Wrapper.valueOf(...)`
    * Byte के लिए: `b.byteValue()`, `b.toUnsigned()`, `Byte.parseByte(string, base)`
    * Boolean के लिए: `b.booleanValue()`, `b.isTrue()`, `b.isFalse()`, `Boolean.parseBoolean(...)`

### 2. Thread और Mutex

* **Thread**

  * कंस्ट्रक्टर: `Thread new_Thread(void* (*function)(void*))`
  * मेथड:

    * `start(...)`, `join()`, `detach()`, `cancel()`, `exit()`, `delete()`

* **Mutex**

  * कंस्ट्रक्टर: `Mutex new_Mutex()`
  * मेथड:

    * `lock()`, `unlock()`, `delete()`

### 3. Console

* **Console**

  * कंस्ट्रक्टर: `Console new_console(void)`
  * मेथड:

    * `print(...)`, `println(...)`, `readLine()`, `clear()`
    * `setColor(ColorType color)`, `resetColor()`, `kbhit() -> int`

### 4. Scanner

* **Scanner**

  * कंस्ट्रक्टर: `Scanner new_Scanner(struct __stdin_t in)`
  * मेथड:

    * `nextChar()`, `nextByte()`, `nextShort()`, `nextInt()`, `nextLong()`
    * `nextUByte()`, `nextUShort()`, `nextUInt()`, `nextULong()`
    * `nextBoolean()`, `nextFloat()`, `nextDouble()`, `nextLDouble()`
    * `next() -> string`, `nextLine() -> string`

    (डिफ़ॉल्ट रूप से सफेद-अंतर को विभाजक के रूप में उपयोग किया जाता है और लाइन-आधारित पढ़ाई भी समर्थित है।)

### 5. संग्रह (Algorithm)

* **Stack**

  * कंस्ट्रक्टर: `Stack new_stack(size_t elementSize)`
  * मेथड: `push(...)`, `pop() -> void*`, `clear()`, `delete()`

* **Queue**

  * कंस्ट्रक्टर: `Queue new_queue(size_t elementSize)`
  * मेथड: `push(...)`, `pop() -> void*`, `clear()`, `delete()`

* **Deque**

  * कंस्ट्रक्टर: `Deque new_deque(size_t elementSize)`
  * मेथड: `pushFront(...)`, `pushBack(...)`, `popFront()`, `popBack()`, `clear()`, `delete()`

* **List**

  * कंस्ट्रक्टर: `List new_list(size_t elementSize)`
  * मेथड: `add(...)`, `get(index)`, `remove(index)`, `size()`, `clear()`, `delete()`

## 🛠️ योगदान गाइड

1. **इस प्रोजेक्ट को Fork करें**
2. **फ़ीचर ब्रांच बनाएँ**: `git checkout -b feature/YourFeature`
3. **फ़ीचर लागू करें**
4. **टेस्ट लिखें और दस्तावेज़ अपडेट करें**
5. **Pull Request** बनाएं

विचारों पर चर्चा करने के लिए पहले एक issue खोलें।

## 📄 लाइसेंस

यह प्रोजेक्ट [MIT License](../LICENSE) के अंतर्गत लाइसेंस प्राप्त है।
