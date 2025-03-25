#include "main.h"
#include "System.h"
#include "algorithm.h"
#include "Scanner.h"
#include "thread.h"

import SYSTEM System;

void* threadRun1(void* args, ...) {
    for(int i = 0; i < 10; i++) {
        System.out.println("Thread 1, %d", i);
        Sleep(1000);
    }
    return null;
}

void* threadRun2(void* args, ...) {
    for(int i = 0; i < 20; i++) {
        System.out.println("Thread 2, %d", i);
        Sleep(1000);
    }
    return null;
}

int main(void){ 
    Thread thread1 = new_Thread(threadRun1);
    Thread thread2 = new_Thread(threadRun2);
    
    return 0;
}