# Object-Oriented C Language

> Il s'agit d'un projet d'exemple implémentant le paradigme de programmation orientée objet en pur langage C.

---

Ci-dessous, cliquez sur le lien pour voir le contenu traduit dans la langue souhaitée.

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

## 📖 Aperçu

Ce projet est un exemple modulable implémentant, uniquement en langage C (standard C99), les concepts clés de la programmation orientée objet (abstraction, encapsulation, héritage, polymorphisme). Divers composants système (`System`), threading (`Thread`), entrée/sortie console (`Console`), analyseur d’entrée (`Scanner`) et algorithmes (`Algorithm`) sont représentés sous forme d’objets via des structs et des pointeurs de fonction.

## ⚙️ Fonctionnalités principales

* **System** : Entrée/sortie de base, entrée/sortie de fichiers, minuterie, abstraction de plateforme
* **Thread** : Création et gestion de threads légers
* **Console** : Formatage et contrôle d’entrée/sortie console
* **Scanner** : Utilitaires de flux d’entrée
* **Algorithm** : Collections Stack, Queue, Deque, List

## 🧰 Stack technologique

| Badge                                                                                                                | Description                                                                       |
| -------------------------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------- |
| ![C](https://img.shields.io/badge/C-00599C?style=flat\&logo=c\&logoColor=white)                                      | **Langage C** : Standard C99, implémentation de POO avec structs et pointeurs     |
| ![GCC](https://img.shields.io/badge/GCC-333333?style=flat\&logo=gnu\&logoColor=white)                                | **GCC** : GNU Compiler Collection pour la compilation des programmes C            |
| ![Make](https://img.shields.io/badge/Make-064F8C?style=flat\&logo=cmake\&logoColor=white)                            | **Make** : Outil d’automatisation de compilation                                  |
| ![Makefile](https://img.shields.io/badge/Makefile-000000?style=flat)                                                 | **Makefile** : Fichier de configuration pour les instructions de build            |
| ![Windows](https://img.shields.io/badge/Windows-0078D4?style=flat\&logo=windows\&logoColor=white)                    | **API Windows** : Fonctions système et support multithreading (`windows.h`)       |
| ![Linux](https://img.shields.io/badge/Linux-000000?style=flat\&logo=linux\&logoColor=white)                          | **Linux** : Système d’exploitation open source couramment utilisé                 |
| ![MACOS](https://img.shields.io/badge/MACOS-000000?style=flat\&logo=apple\&logoColor=white)                          | **macOS** : Système Unix sur matériel Apple                                       |
| ![POSIX](https://img.shields.io/badge/POSIX%20Threads-000000?style=flat)                                             | **Threads POSIX** : Support multithreading Unix (`pthread.h`)                     |
| ![Standard Lib](https://img.shields.io/badge/C%20Standard%20Library-000000?style=flat)                               | **Bibliothèque standard C** : `stdio.h`, `stdlib.h`, `string.h`, `time.h`         |
| ![OOP](https://img.shields.io/badge/Object--Oriented%20Programming-000000?style=flat)                                | **POO en C** : Encapsulation, abstraction, polymorphisme via structs et pointeurs |
| ![Algorithms](https://img.shields.io/badge/Algorithms%20\(Stack,%20Queue,%20List\)-000000?style=flat)                | **Algorithmes** : Implémentation de Stack, Queue, Deque, List                     |
| ![Git](https://img.shields.io/badge/Git-F05032?style=flat\&logo=git\&logoColor=white)                                | **Git** : Système de contrôle de version                                          |
| ![GitHub](https://img.shields.io/badge/GitHub-181717?style=flat\&logo=github\&logoColor=white)                       | **GitHub** : Plateforme de partage et revue de code                               |
| ![Vim](https://img.shields.io/badge/Vim-019733?style=flat\&logo=vim\&logoColor=white)                                | **Vim** : Éditeur de texte hautement configurable                                 |
| ![Visual Studio](https://img.shields.io/badge/Visual%20Studio-5C2D91?style=flat\&logo=visualstudio\&logoColor=white) | **Visual Studio** : IDE C/C++ avec débogage et analyse avancés                    |
| ![VSCode](https://img.shields.io/badge/VSCode-007ACC?style=flat\&logo=visualstudiocode\&logoColor=white)             | **Visual Studio Code** : Éditeur de code et débogage                              |
| ![CLion](https://img.shields.io/badge/CLion-000000?style=flat\&logo=jetbrains\&logoColor=white)                      | **CLion** : IDE JetBrains C/C++ avec intégration CMake                            |

## 🖥️ Compatibilité des plateformes

Ce projet a été testé et fonctionne sur :

* 🪟 **Windows** 10 / 11
* 🐧 **Linux**
* 🍎 **macOS**

## 🛣️ Feuille de route

* [x] POO en C
* [x] Abstraction Thread et Mutex
* [x] Utilitaire d’E/S console
* [x] Analyseur d’entrée basique
* [x] Structures de données : Stack, Queue, List
* [ ] Utilitaires de fichiers avancés
* [ ] Couche GUI avec SDL ou ncurses (à venir)

## 🏗️ Instructions de compilation par OS

### 🪟 Windows (GCC MinGW)

```bash
gcc -std=c99 -Wall -I inc -o main.exe src/*.c
main.exe
```

### 🪟 Windows (Invite de commandes MSVC)

```cmd
cl /I inc /Fe:main.exe src\*.c
main.exe
```

### 🐧 Linux / 🍎 macOS

```bash
gcc -std=c99 -Wall -I inc -o main src/*.c -lpthread
./main
```

> \*\*Remarque \*\* : Le lien `-lpthread` est nécessaire pour le support multithreading.

## 📂 Structure du répertoire

```
Object-Oriented-C-Language/
├── inc/                      # Fichiers d'en-tête
│   ├── algorithm.h
│   ├── console.h
│   ├── main.h
│   ├── Scanner.h
│   ├── System.h
│   └── thread.h
├── src/                      # Fichiers source
│   ├── algorithm.c
│   ├── console.c
│   ├── main.c
│   ├── Scanner.c
│   ├── System.c
│   └── thread.c
├── translations/             # Fichiers de traduction
│   ├── ar.md                 # Arabe
│   ├── es.md                 # Espagnol
│   ├── fr.md                 # Français (ce fichier)
│   ├── hi.md                 # Hindi
│   ├── it.md                 # Italien
│   ├── ja.md                 # Japonais
│   ├── ko.md                 # Coréen 
│   ├── pt.md                 # Portugais
│   ├── ru.md                 # Russe
│   └── zh.md                 # Chinois
├── LICENSE                   # Informations de licence
└── README.md                 # Description du projet
```

## 🔧 Développement et compilation

### Exigences

* GCC (version ≥ 4.8)
* Make (optionnel)

### Compilation manuelle

```bash
# Depuis la racine du projet
gcc -std=c99 -Wall -I inc/ -o main src/*.c
```

### Exemple de Makefile

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

## 🚀 Exécution

```bash
# Après compilation
./main
```

L’exemple crée des objets, appelle des méthodes et teste les threads.

## 📑 Structure de l’API

### 1. System et types primitifs

* **SYSTEM out**

  * `out.printf(const string format, ...)` : sortie formatée
  * `out.println(const string format, ...)` : sortie formatée avec saut de ligne

* **SYSTEM in**

  * `in.read() -> int32_t` : lit un caractère de stdin comme entier

* **File**

  * Constructeur : `File new_File(const string path, const string mode)`
  * Méthodes :

    * `f.scanf(const string format, ...)` : entrée formatée depuis le fichier
    * `f.printf(const string format, ...)` : sortie formatée vers le fichier
    * `f.println(const string format, ...)` : sortie formatée avec saut de ligne
    * `f.open(const string path, const string mode)` : ouvrir un fichier
    * `f.close()` : fermer le fichier
    * `f.readLine() -> string` : lire une ligne du fichier

* **Time**

  * Constructeur : `Time new_Time(void)`
  * Méthodes :

    * `t.getSystemTime(Time* t)` : obtenir l’heure système
    * `t.getTime(Time* t)` : obtenir la valeur interne du temps
    * `t.setTime(...)` : définir l’heure (année, mois, jour, heure, minute, seconde)
    * `t.start()` / `t.stop()` : contrôler le thread du minuteur

* **Constructeurs de wrappers primitifs**

  * `new_String(string s)`

    * Méthodes : `s.length()`, `s.charAt(index)`, `s.substring(start, end)`, `s.equals(...)`, `s.toCharArray()`
    * Méthodes statiques : `String.valueOf(...)`, `String.format(...)`

  * `new_Character(char c)`

    * Méthodes : `c.charValue()`, `c.equals(...)`, `Character.isDigit(char)`, `Character.isLetter(char)`

  * `new_Byte(...)`, `new_Short(...)`, `new_Integer(...)`, `new_Long(...)`, `new_Float(...)`, `new_Double(...)`, `new_Boolean(...)`

    * Méthodes communes : `x.getValue()`, `x.toString()`, `x.equals(...)`, `x.compareTo(...)`
    * Méthodes statiques : `Wrapper.parse<Type>(...)`, `Wrapper.valueOf(...)`
    * Spécifique à Byte : `b.byteValue()`, `b.toUnsigned()`, `Byte.parseByte(string, base)`
    * Spécifique à Boolean : `b.booleanValue()`, `b.isTrue()`, `b.isFalse()`, `Boolean.parseBoolean(...)`

### 2. Thread et Mutex

* **Thread**

  * Constructeur : `Thread new_Thread(void* (*function)(void*))`
  * Méthodes :

    * `start(...)`, `join()`, `detach()`, `cancel()`, `exit()`, `delete()`

* **Mutex**

  * Constructeur : `Mutex new_Mutex()`
  * Méthodes :

    * `lock()`, `unlock()`, `delete()`

### 3. Console

* **Console**

  * Constructeur : `Console new_console(void)`
  * Méthodes :

    * `print(...)`, `println(...)`, `readLine()`, `clear()`
    * `setColor(ColorType color)`, `resetColor()`, `kbhit() -> int`

### 4. Scanner

* **Scanner**

  * Constructeur : `Scanner new_Scanner(struct __stdin_t in)`
  * Méthodes :

    * `nextChar()`, `nextByte()`, `nextShort()`, `nextInt()`, `nextLong()`
    * `nextUByte()`, `nextUShort()`, `nextUInt()`, `nextULong()`
    * `nextBoolean()`, `nextFloat()`, `nextDouble()`, `nextLDouble()`
    * `next() -> string`, `nextLine() -> string`

    (par défaut, utilise les espaces comme séparateurs et prend aussi en charge la lecture ligne par ligne.)

### 5. Collections (Algorithm)

* **Stack**

  * Constructeur : `Stack new_stack(size_t elementSize)`
  * Méthodes : `push(...)`, `pop() -> void*`, `clear()`, `delete()`

* **Queue**

  * Constructeur : `Queue new_queue(size_t elementSize)`
  * Méthodes : `push(...)`, `pop() -> void*`, `clear()`, `delete()`

* **Deque**

  * Constructeur : `Deque new_deque(size_t elementSize)`
  * Méthodes : `pushFront(...)`, `pushBack(...)`, `popFront()`, `popBack()`, `clear()`, `delete()`

* **List**

  * Constructeur : `List new_list(size_t elementSize)`
  * Méthodes : `add(...)`, `get(index)`, `remove(index)`, `size()`, `clear()`, `delete()`

## 🛠️ Guide de contribution

1. **Fork** ce projet
2. **Créer une branche fonctionnelle** : `git checkout -b feature/YourFeature`
3. **Implémenter la fonctionnalité**
4. **Écrire des tests et mettre à jour la documentation**
5. **Créer une Pull Request**

Pour discuter des idées, ouvrez d’abord une issue.

## 📄 Licence

Ce projet est sous [licence MIT](../LICENSE).
