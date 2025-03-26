#include "main.h"
#include "System.h"
#include "algorithm.h"
#include "Scanner.h"
#include "thread.h"

import SYSTEM System;

typedef struct TIM {
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t minute;
    uint8_t second;
} TIM;

volatile TIM tim;
volatile boolean threadRun = true;

void* timer(void* arg) {
    Mutex* mutex = (Mutex*)arg;
    uint16_t i = 0;

    while (threadRun) {
        mutex->lock(mutex);
        i++;
        if(i >= 10) {
            i = 0;
            tim.second++;
        }
        if (tim.second >= 60) {
            tim.second = 0;
            tim.minute++;
        }
        if (tim.minute >= 60) {
            tim.minute = 0;
            tim.hour++;
        }
        if (tim.hour >= 24) {
            tim.hour = 0;
            tim.day++;
        }
        int daysInMonth;
        if (tim.month == 2) {
            daysInMonth = (tim.year % 4 == 0 && (tim.year % 100 != 0 || tim.year % 400 == 0)) ? 29 : 28;
        } else if (tim.month == 4 || tim.month == 6 || tim.month == 9 || tim.month == 11) {  
            daysInMonth = 30;
        } else {
            daysInMonth = 31;
        }
        if (tim.day > daysInMonth) {
            tim.day = 1;
            tim.month++;
        }
        if (tim.month > 12) {
            tim.month = 1;
            tim.year++;
        }
        mutex->unlock(mutex);
        SLEEP(100);
    }
    return NULL;
}


void* display(void* arg) {
    Mutex* mutex = (Mutex*)arg;
    while (threadRun) {
        mutex->lock(mutex);
        System.out.printf(" %04d-%02d-%02d %02d:%02d:%02d\r", tim.year, tim.month, tim.day, tim.hour, tim.minute, tim.second);
        mutex->unlock(mutex);
        SLEEP(100);
    }
    return NULL;
}

void* stop(void* arg) {
    Mutex* mutex = (Mutex*)arg;
    for(int i = 0; i < 300; i++) {
        SLEEP(100);
    }
    mutex->lock(mutex);
    threadRun = false;
    mutex->unlock(mutex);
    return NULL;
}

int main(void) {
    Thread timerThread = new_Thread(timer);
    Thread displayThread = new_Thread(display);
    Thread stopThread = new_Thread(stop);
    Mutex mutex = new_Mutex();
    
    tim = (TIM) {
        .year = 2024,
        .month = 12,
        .day = 31,
        .hour = 23,
        .minute = 59,
        .second = 40,
    };

    timerThread.start(&timerThread, &mutex);
    displayThread.start(&displayThread, &mutex);
    stopThread.start(&stopThread, &mutex);
    
    timerThread.join(&timerThread);
    displayThread.join(&displayThread);
    stopThread.join(&stopThread);

    timerThread.delete(&timerThread);
    displayThread.delete(&displayThread);
    stopThread.delete(&stopThread);
    
    mutex.delete(&mutex);
    return 0;
}
