# Object-Oriented-C-Language

--------Calculator--------

gcc -c Calculator.c -I ..\inc

gcc -c Systemout.c -I ..\inc

gcc -c Scanner.c -I ..\inc

gcc -c main.c -I ..\inc

gcc -o main Calculator.o Systemout.o Scanner.o main.o

.\main

Run main.exe

--------Scanner--------

gcc -c Systemout.c -I ..\inc

gcc -c Scanner.c -I ..\inc

gcc -c ScannerTest.c -I ..\inc

gcc -o Scanner Systemout.o Scanner.o ScannerTest.o

.\Scanner

Run Scanner.exe