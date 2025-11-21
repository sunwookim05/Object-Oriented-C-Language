#include "main.h"
#include "System.h"
#include "algorithm.h"
#include "Scanner.h"
#include "thread.h"
#include "console.h"

import SYSTEM System;

typedef struct {
    Mutex* mutex;
    boolean* running;
    boolean* exitFlag;
} ThreadData;

HHOOK hook;
static ThreadData* gData = NULL;
Console console;

void* SpamThread(void* arg) {
    ThreadData* data = (ThreadData*)arg;
    while (1) {
        data->mutex->lock(data->mutex);
        boolean state = *(data->running);
        boolean exit = *(data->exitFlag);
        data->mutex->unlock(data->mutex);

        if (exit) break;

        if (state) {
            keybd_event(VK_F5, 0, 0, 0);
            keybd_event(VK_F5, 0, KEYEVENTF_KEYUP, 0);
        }
        Sleep(10);
    }
    return NULL;
}

LRESULT CALLBACK LowLevelKeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {
    if (!gData) return CallNextHookEx(NULL, nCode, wParam, lParam);

    KBDLLHOOKSTRUCT* kbd = (KBDLLHOOKSTRUCT*)lParam;

    if (nCode == HC_ACTION && wParam == WM_KEYDOWN) {
        if (kbd->vkCode == VK_F1) {
            gData->mutex->lock(gData->mutex);
            *(gData->running) = true;
            gData->mutex->unlock(gData->mutex);
            return 1;
        }
        if (kbd->vkCode == VK_F2) {
            gData->mutex->lock(gData->mutex);
            *(gData->running) = false;
            gData->mutex->unlock(gData->mutex);
            return 1;
        }
        if (kbd->vkCode == VK_F3) {
            gData->mutex->lock(gData->mutex);
            *(gData->running) = false;
            *(gData->exitFlag) = true;
            gData->mutex->unlock(gData->mutex);
            PostQuitMessage(0);
            return 1;
        }
    }

    return CallNextHookEx(NULL, nCode, wParam, lParam);
}

void* HookThread(void* arg) {
    gData = (ThreadData*)arg;

    hook = SetWindowsHookEx(WH_KEYBOARD_LL, LowLevelKeyboardProc, NULL, 0);

    MSG msg;
    while (!*(gData->exitFlag)) {
        if (GetMessage(&msg, NULL, 0, 0) <= 0) break;
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    UnhookWindowsHookEx(hook);
    return NULL;
}

void* StatusThread(void* arg) {
    ThreadData* data = (ThreadData*)arg;
    while (1) {
        data->mutex->lock(data->mutex);
        boolean running = *(data->running);
        boolean exit = *(data->exitFlag);
        data->mutex->unlock(data->mutex);

        if (exit) {
            console.setTextColor(YELLOW);
            console.printlnXY(0, 0, "Program terminated        ");
            break;
        } else if (running) {
            console.setTextColor(RED);
            console.printlnXY(0, 0, "SpamThread is running...  ");
        } else {
            console.setTextColor(BLUE);
            console.printlnXY(0, 0, "SpamThread is stopped     ");
        }

        Sleep(10);
    }
    return NULL;
}

int main(void) {
    console = new_console();
    console.clear();
    console.setTextColor(YELLOW);
    console.printlnXY(0, 0, "Program started                  ");

    boolean running = false;
    boolean exitFlag = false;
    Mutex mutex = new_Mutex();

    ThreadData data;
    data.mutex = &mutex;
    data.running = &running;
    data.exitFlag = &exitFlag;

    Thread spam = new_Thread(SpamThread);
    Thread hookT = new_Thread(HookThread);
    Thread status = new_Thread(StatusThread);

    spam.start(&spam, &data);
    hookT.start(&hookT, &data);
    status.start(&status, &data);

    while (!exitFlag) {
        Sleep(100);
    }

    console.setTextColor(YELLOW);
    console.printlnXY(0, 0, "Program terminated                  ");
    console.resetColor();

    return 0;
}
