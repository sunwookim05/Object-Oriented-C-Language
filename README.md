# Object-Oriented-C-Language

--------Calculator--------

gcc -c src\Calculator.c -I inc\

gcc -c src\Systemout.c -I inc\

gcc -c src\Scanner.c -I inc\

gcc -c src\main.c -I inc\

gcc -o main Calculator.o Systemout.o Scanner.o main.o

.\main

Run main.exe