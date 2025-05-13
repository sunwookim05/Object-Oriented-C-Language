# Object-Oriented C Language

<div dir="ltr" align="left" style="text-align: left;">

> مشروع مثال يوضح تطبيق نمط برمجة كائنية التوجه باستخدام لغة C خالصة.

---

انقر على الرابط أدناه لرؤية المحتوى المترجم إلى اللغة التي ترغب بها.

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

## 📖 نظرة عامة

هذا المشروع مثال يوضح تطبيق مفاهيم البرمجة كائنية التوجه الأساسية (التجريد، التغليف، الوراثة، التعددية الشكلية) باستخدام لغة C خالصة (معيار C99) في بنية مكدسة.

## ⚙️ الميزات الرئيسية

* **System**: الإدخال والإخراج الأساسي، إدخال وإخراج الملفات، المؤقت، تجريد المنصة
* **Thread**: إنشاء وإدارة خيوط خفيفة الوزن
* **Console**: تنسيق وإدارة إدخال وإخراج وحدة التحكم
* **Scanner**: أدوات لتدفق الإدخال
* **Algorithm**: هياكل بيانات Stack وQueue وDeque وList

## 🧰 تكنولوجيا

| Badge                                                                                                                | الوصف                                                                                             |
| -------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------- |
| ![C](https://img.shields.io/badge/C-00599C?style=flat\&logo=c\&logoColor=white)                                      | **لغة C**: معيار C99، تطبيق البرمجة كائنية التوجه باستخدام struct ومؤشرات الدوال                  |
| ![GCC](https://img.shields.io/badge/GCC-333333?style=flat\&logo=gnu\&logoColor=white)                                | **GCC**: مجموعة مترجم GNU، تُستخدم لبناء برامج C                                                  |
| ![Make](https://img.shields.io/badge/Make-064F8C?style=flat\&logo=cmake\&logoColor=white)                            | **Make**: أداة لأتمتة تجميع وربط الملفات المصدر                                                   |
| ![Makefile](https://img.shields.io/badge/Makefile-000000?style=flat)                                                 | **Makefile**: ملف تعليمات الإنشاء لأمر Make                                                       |
| ![Windows](https://img.shields.io/badge/Windows-0078D4?style=flat\&logo=windows\&logoColor=white)                    | **Windows API**: دوال النظام ودعم تعدد الخيوط (`windows.h`, `conio.h`, `process.h`)               |
| ![Linux](https://img.shields.io/badge/Linux-000000?style=flat\&logo=linux\&logoColor=white)                          | **Linux**: نظام تشغيل مفتوح المصدر واسع الاستخدام                                                 |
| ![MACOS](https://img.shields.io/badge/MACOS-000000?style=flat\&logo=apple\&logoColor=white)                          | **macOS**: نظام تشغيل من عائلة Unix على أجهزة Mac                                                 |
| ![POSIX](https://img.shields.io/badge/POSIX%20Threads-000000?style=flat)                                             | **خيوط POSIX**: دعم تعدد الخيوط في أنظمة Unix (`pthread.h`)                                       |
| ![Standard Lib](https://img.shields.io/badge/C%20Standard%20Library-000000?style=flat)                               | **مكتبة C القياسية**: `stdio.h`, `stdlib.h`, `string.h`, `time.h` وغيرها                          |
| ![OOP](https://img.shields.io/badge/Object--Oriented%20Programming-000000?style=flat)                                | **البرمجة كائنية التوجه في C**: التغليف، التجريد، التعددية الشكلية باستخدام struct ومؤشرات الدوال |
| ![Algorithms](https://img.shields.io/badge/Algorithms%20\(Stack,%20Queue,%20List\)-000000?style=flat)                | **الخوارزميات**: تنفيذ هياكل البيانات Stack، Queue، Deque، List                                   |
| ![Git](https://img.shields.io/badge/Git-F05032?style=flat\&logo=git\&logoColor=white)                                | **Git**: نظام التحكم في الإصدارات                                                                 |
| ![GitHub](https://img.shields.io/badge/GitHub-181717?style=flat\&logo=github\&logoColor=white)                       | **GitHub**: منصة لمشاركة الكود ومراجعاته                                                          |
| ![Vim](https://img.shields.io/badge/Vim-019733?style=flat\&logo=vim\&logoColor=white)                                | **Vim**: محرر نصوص قابل للتخصيص بقوة                                                              |
| ![Visual Studio](https://img.shields.io/badge/Visual%20Studio-5C2D91?style=flat\&logo=visualstudio\&logoColor=white) | **Visual Studio**: IDE يقدم أدوات تصحيح وتحليل واختبار قوية                                       |
| ![VS Code](https://img.shields.io/badge/VSCode-007ACC?style=flat\&logo=visualstudiocode\&logoColor=white)            | **VS Code**: محرر نصوص متقدم للكتابة والتصحيح                                                     |
| ![CLion](https://img.shields.io/badge/CLion-000000?style=flat\&logo=jetbrains\&logoColor=white)                      | **CLion**: IDE من JetBrains يدعم تحليل الكود وإعادة التهيئة وتكامل CMake                          |

## 🖥️ توافق المنصات

هذا المشروع تم اختباره ويعمل على المنصات التالية:

* 🪟 **Windows** 10 / 11
* 🐧 **Linux**
* 🍎 **macOS**

## 🛣️ خارطة الطريق

* [x] البرمجة كائنية التوجه في C
* [x] تجريد الخيوط والقفل (Mutex)
* [x] أدوات إدخال وإخراج وحدة التحكم
* [x] ماسح الإدخال الأساسي
* [x] هياكل البيانات: Stack، Queue، List
* [ ] أدوات ملفات متقدمة
* [ ] طبقة واجهة رسومية باستخدام SDL أو ncurses (قادم)

## 🏗️ تعليمات الإنشاء حسب النظام

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

> **ملاحظة**: لتمكين دعم تعدد الخيوط، نستخدم `-lpthread`.

## 📂 هيكل الدليل

```
Object-Oriented-C-Language/
├── inc/                      # ملفات الرأس
│   ├── algorithm.h
│   ├── console.h
│   ├── main.h
│   ├── Scanner.h
│   ├── System.h
│   └── thread.h
├── src/                      # ملفات المصدر
│   ├── algorithm.c
│   ├── console.c
│   ├── main.c
│   ├── Scanner.c
│   ├── System.c
│   └── thread.c
├── translations/             # ملفات الترجمة
│   ├── ar.md                 # (هذا الملف)العربية
│   ├── es.md                 # الإسبانية
│   ├── fr.md                 # الفرنسية
│   ├── hi.md                 # الهندية
│   ├── it.md                 # الإيطالية
│   ├── ja.md                 # اليابانية
│   ├── ko.md                 # الكورية
│   ├── pt.md                 # البرتغالية
│   ├── ru.md                 # الروسية
│   └── zh.md                 # الصينية
├── LICENSE                   # معلومات الترخيص
└── README.md                 # وصف المشروع
```

## 🔧 التطوير والبناء

### المتطلبات

* GCC (الإصدار ≥ 4.8)
* Make (اختياري)

### التجميع اليدوي

```bash
# من الدليل الجذر للمشروع
gcc -std=c99 -Wall -I inc/ -o main src/*.c
```

### مثال Makefile

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

## 🚀 طريقة التشغيل

```bash
# بعد البناء
./main
```

تقوم العينة بإنشاء الكائنات واستدعاء الأساليب واختبار الخيوط.

## 📑 بنية API

### 1. System والأنواع الأساسية

* **SYSTEM out**

  * `out.printf(const string format, ...)` : إخراج منسق
  * `out.println(const string format, ...)` : إخراج منسق مع سطر جديد

* **SYSTEM in**

  * `in.read() -> int32_t` : قراءة حرف من stdin كقيمة صحيحة

* **File**

  * المنشئ: `File new_File(const string path, const string mode)`
  * الأساليب:

    * `f.scanf(const string format, ...)` : قراءة منسقة من الملف
    * `f.printf(const string format, ...)` : إخراج منسق إلى الملف
    * `f.println(const string format, ...)` : إخراج منسق مع سطر جديد
    * `f.open(const string path, const string mode)` : فتح ملف
    * `f.close()` : إغلاق الملف
    * `f.readLine() -> string` : قراءة سطر من الملف

* **Time**

  * المنشئ: `Time new_Time(void)`
  * الأساليب:

    * `t.getSystemTime(Time* t)` : الحصول على وقت النظام الحالي
    * `t.getTime(Time* t)` : الحصول على القيمة الزمنية الداخلية
    * `t.setTime(...)` : ضبط الوقت (سنة، شهر، يوم، ساعة، دقيقة، ثانية)
    * `t.start()` / `t.stop()` : التحكم في خيط المؤقت

* **منشئو الأغلفة الأساسية**

  * `new_String(string s)`

    * الأساليب: `s.length()`, `s.charAt(index)`, `s.substring(start, end)`, `s.equals(...)`, `s.toCharArray()`
    * الأساليب الثابتة: `String.valueOf(...)`, `String.format(...)`

  * `new_Character(char c)`

    * الأساليب: `c.charValue()`, `c.equals(...)`, `Character.isDigit(char)`, `Character.isLetter(char)`

  * `new_Byte(...)`, `new_Short(...)`, `new_Integer(...)`, `new_Long(...)`, `new_Float(...)`, `new_Double(...)`, `new_Boolean(...)`

    * الأساليب المشتركة: `x.getValue()`, `x.toString()`, `x.equals(...)`, `x.compareTo(...)`
    * الأساليب الثابتة: `Wrapper.parse<Type>(...)`, `Wrapper.valueOf(...)`
    * خاص بـByte: `b.byteValue()`, `b.toUnsigned()`, `Byte.parseByte(string, base)`
    * خاص بـBoolean: `b.booleanValue()`, `b.isTrue()`, `b.isFalse()`, `Boolean.parseBoolean(...)`

### 2. Thread وMutex

* **Thread**

  * المنشئ: `Thread new_Thread(void* (*function)(void*))`
  * الأساليب:

    * `start(...)`, `join()`, `detach()`, `cancel()`, `exit()`, `delete()`

* **Mutex**

  * المنشئ: `Mutex new_Mutex()`
  * الأساليب:

    * `lock()`, `unlock()`, `delete()`

### 3. Console

* **Console**

  * المنشئ: `Console new_console(void)`
  * الأساليب:

    * `print(...)`, `println(...)`, `readLine()`, `clear()`
    * `setColor(ColorType color)`, `resetColor()`, `kbhit() -> int`

### 4. Scanner

* **Scanner**

  * المنشئ: `Scanner new_Scanner(struct __stdin_t in)`
  * الأساليب:

    * `nextChar()`, `nextByte()`, `nextShort()`, `nextInt()`, `nextLong()`
    * `nextUByte()`, `nextUShort()`, `nextUInt()`, `nextULong()`
    * `nextBoolean()`, `nextFloat()`, `nextDouble()`, `nextLDouble()`
    * `next() -> string`, `nextLine() -> string`

    (يستخدم الفراغ كفاصل بشكل افتراضي، ويُدعم قراءة السطر الكامل.)

### 5. المجموعات (Algorithm)

* **Stack**

  * المنشئ: `Stack new_stack(size_t elementSize)`
  * الأساليب: `push(...)`, `pop() -> void*`, `clear()`, `delete()`

* **Queue**

  * المنشئ: `Queue new_queue(size_t elementSize)`
  * الأساليب: `push(...)`, `pop() -> void*`, `clear()`, `delete()`

* **Deque**

  * المنشئ: `Deque new_deque(size_t elementSize)`
  * الأساليب: `pushFront(...)`, `pushBack(...)`, `popFront()`, `popBack()`, `clear()`, `delete()`

* **List**

  * المنشئ: `List new_list(size_t elementSize)`
  * الأساليب: `add(...)`, `get(index)`, `remove(index)`, `size()`, `clear()`, `delete()`

## 🛠️ دليل المساهمة

1. **Fork** المستودع
2. **إنشاء فرع الميزة**: `git checkout -b feature/YourFeature`
3. **تنفيذ الميزة**
4. **كتابة الاختبارات وتحديث الوثائق**
5. **إنشاء Pull Request**

يرجى فتح Issue لمناقشة الأفكار أولاً.

## 📄 الترخيص

هذا المشروع مرخص بموجب [MIT License](../LICENSE).

</div>
