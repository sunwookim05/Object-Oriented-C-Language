#include "main.h"
#include "System.h"
#include "algorithm.h"
#include "Scanner.h"
#include "thread.h"

import SYSTEM System;

typedef struct TIM {
    uint8_t hour;
    uint8_t minute;
    uint8_t second;
} TIM;

Mutex mutex;
volatile TIM tim;
volatile boolean threadRun = true;

void* timer(void* arg) {
    uint16_t i = 0;
    while (threadRun) {
        mutex.lock(&mutex);
        i++;
        if(i >= 10) {
            i = 0;
            tim.second++;
        }
        if (tim.second == 60) {
            tim.second = 0;
            tim.minute++;
        }
        if (tim.minute == 60) {
            tim.minute = 0;
            tim.hour++;
        }
        mutex.unlock(&mutex);
        SLEEP(100);
    }
    return NULL;
}

void* display(void* arg) {
    while (threadRun) {
        mutex.lock(&mutex);
        System.out.printf("%02d:%02d:%02d\r", tim.hour, tim.minute, tim.second);
        mutex.unlock(&mutex);
        SLEEP(100);
    }
    return NULL;
}

void* stop(void* arg) {
    for(int i = 0; i < 300; i++) {
        SLEEP(100);
    }
    mutex.lock(&mutex);
    threadRun = false;
    mutex.unlock(&mutex);
    return NULL;
}

int main(void) {
    Thread timerThread = new_Thread(timer);
    Thread displayThread = new_Thread(display);
    Thread stopThread = new_Thread(stop);
    mutex = new_Mutex();
    
    tim = (TIM) {
        .hour = 12,
        .minute = 59,
        .second = 40,
    };

    timerThread.start(&timerThread);
    displayThread.start(&displayThread);
    stopThread.start(&stopThread);
    
    timerThread.join(&timerThread);
    displayThread.join(&displayThread);
    stopThread.join(&stopThread);

    timerThread.delete(&timerThread);
    displayThread.delete(&displayThread);
    stopThread.delete(&stopThread);
    
    mutex.delete(&mutex);
    return 0;
}
