# Object-Oriented-C-Language

--------Calculator--------

gcc -c src\Calculator.c -I inc\

gcc -c src\Systemout.c -I inc\

gcc -c src\Scanner.c -I inc\

gcc -c src\main.c -I inc\

gcc -o main Calculator.o Systemout.o Scanner.o main.o

.\main

Run main.exe

--------Scanner--------

gcc -c src\Systemout.c -I inc\

gcc -c src\Scanner.c -I inc\

gcc -c src\ScannerTest.c -I inc\

gcc -o Scanner Systemout.o Scanner.o ScannerTest.o

.\Scanner

Run Scanner.exe