#include "main.h"
#include "System.h"
#include "algorithm.h"
#include "Scanner.h"
#include "thread.h"
#include "console.h"

import SYSTEM System;

boolean running = true;

void* timRun(void* arg) {
    Mutex* mutex = (Mutex*)arg;
    Time t = new_Time();
    Console console = new_console();

    while (running) {
        mutex->lock(mutex);
        console.setCursorPos(0, 1);
        console.setTextColor(BLUE);
        t.getSystemTime(&t);
        System.out.printf("Use get Sys Tim %04hd-%02hhd-%02hhd %02hhd:%02hhd:%02hhd\r", t.year, t.month, t.day, t.hour, t.minute, t.second);
        mutex->unlock(mutex);
    } 

    return null;
}

void* isRunning(void* arg) {
    Mutex* mutex = (Mutex*)arg;
    Time t = new_Time();
    t.setTime(&t, 0, 0, 0, 0, 0, 0);

    t.start(&t);

    while(t.minute < 2);

    mutex->lock(mutex);
    running = false;
    mutex->unlock(mutex);

    t.stop(&t);

    return null;
}

int main(void) {
    Time t = new_Time();
    Thread timThread = new_Thread(timRun);
    Console console = new_console();
    Mutex mutex = new_Mutex();

    running = true;

    console.clear();
    console.setCursorVisibility(false);

    t.getSystemTime(&t);

    timThread.start(&timThread, &mutex);

    t.start(&t);

    while(running){
        mutex.lock(&mutex);
        console.setCursorPos(0, 0);
        console.setTextColor(RED);
        System.out.printf("Use Time Thread %04hd-%02hhd-%02hhd %02hhd:%02hhd:%02hhd\r", t.year, t.month, t.day, t.hour, t.minute, t.second);
        mutex.unlock(&mutex);
    }
    
    t.stop(&t);
    
    timThread.join(&timThread);
    timThread.delete(&timThread);

    console.setCursorVisibility(true);
    console.setTextColor(RESET);
    console.clear();

    return 0;
}
