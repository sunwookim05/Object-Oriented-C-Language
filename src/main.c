#include <winsock2.h>
#include <ws2tcpip.h>

#include "main.h"
#include "System.h"
#include "algorithm.h"
#include "Scanner.h"
#include "thread.h"
#include "console.h"

import SYSTEM System;

static volatile boolean allowInjectedInput = false;
static volatile boolean restartRun = false;
static volatile boolean ignoreInput = false;
static HHOOK keyboardHook = NULL;
static HHOOK mouseHook = NULL;

void sendChar(char c) {
    SHORT vk = VkKeyScan(c);
    INPUT ip[4] = {0};

    if (vk & 0x0100) {
        ip[0].type = INPUT_KEYBOARD;
        ip[0].ki.wVk = VK_SHIFT;
        ip[0].ki.dwFlags = 0;
        SendInput(1, &ip[0], sizeof(INPUT));
    }

    ip[1].type = INPUT_KEYBOARD;
    ip[1].ki.wVk = vk & 0xFF;
    ip[1].ki.dwFlags = 0;
    SendInput(1, &ip[1], sizeof(INPUT));

    ip[2].type = INPUT_KEYBOARD;
    ip[2].ki.wVk = vk & 0xFF;
    ip[2].ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &ip[2], sizeof(INPUT));

    if (vk & 0x0100) {
        ip[3].type = INPUT_KEYBOARD;
        ip[3].ki.wVk = VK_SHIFT;
        ip[3].ki.dwFlags = KEYEVENTF_KEYUP;
        SendInput(1, &ip[3], sizeof(INPUT));
    }
    
    // sleep(100);
}

void sendString(const char* str) {
    allowInjectedInput = true;
    for (size_t i = 0; i < strlen(str); i++) {
        if (str[i] == '\n') {
            INPUT ip;
            ip.type = INPUT_KEYBOARD;
            ip.ki.wVk = VK_RETURN;
            ip.ki.dwFlags = 0;
            SendInput(1, &ip, sizeof(INPUT));
            ip.ki.dwFlags = KEYEVENTF_KEYUP;
            SendInput(1, &ip, sizeof(INPUT));
        } else {
            sendChar(str[i]);
        }
    }
    allowInjectedInput = false;
}

LRESULT CALLBACK keyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode == HC_ACTION && ignoreInput) {
        if (allowInjectedInput) {
            return CallNextHookEx(keyboardHook, nCode, wParam, lParam);
        }
        return 1;
    }
    return CallNextHookEx(keyboardHook, nCode, wParam, lParam);
}


LRESULT CALLBACK mouseProc(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode == HC_ACTION && ignoreInput) {
        switch (wParam) {
            case WM_LBUTTONDOWN:
            case WM_LBUTTONUP:
            case WM_RBUTTONDOWN:
            case WM_RBUTTONUP:
            case WM_MBUTTONDOWN:
            case WM_MBUTTONUP:
            case WM_XBUTTONDOWN:
            case WM_XBUTTONUP:
                return 1;
            case WM_MOUSEMOVE:
            case WM_MOUSEWHEEL:
                return CallNextHookEx(mouseHook, nCode, wParam, lParam);
        }
    }
    return CallNextHookEx(mouseHook, nCode, wParam, lParam);
}

void installInputHook() {
    if (!keyboardHook)
        keyboardHook = SetWindowsHookEx(
            WH_KEYBOARD_LL,
            keyboardProc,
            GetModuleHandle(NULL),
            0
        );

    if (!mouseHook)
        mouseHook = SetWindowsHookEx(
            WH_MOUSE_LL,
            mouseProc,
            GetModuleHandle(NULL),
            0
        );
}

void uninstallInputHook() {
    if (keyboardHook) {
        UnhookWindowsHookEx(keyboardHook);
        keyboardHook = NULL;
    }

    if (mouseHook) {
        UnhookWindowsHookEx(mouseHook);
        mouseHook = NULL;
    }
}


int checkStatus() {
    // Console console = new_Console();
    const char *ip = "6.1.5.113";
    const char *path = "/ui";
    int port = 9090;

    // console.setTextColor(WHITE);
    // System.out.println("[DEBUG] Creating socket...");
    SOCKET sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock == INVALID_SOCKET) {
        // console.setTextColor(RED);
        // System.out.println("[ERROR] socket() failed: %d", WSAGetLastError());
        // File file = new_File("BIGDATAServerMonitorLog.txt", "a");
        // file.println(&file, "[ERROR] socket() failed: %d", WSAGetLastError());
        // file.close(&file);
        return -1;
    }

    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, ip, &serv_addr.sin_addr) <= 0) {
        // console.setTextColor(RED);
        // System.out.println("[ERROR] inet_pton() failed");
        // File file = new_File("BIGDATAServerMonitorLog.txt", "a");
        // file.println(&file, "[ERROR] inet_pton() failed");
        // file.close(&file);
        closesocket(sock);
        return -1;
    }

    // console.setTextColor(WHITE);
    // System.out.println("[DEBUG] Connecting to server BIGDATA...", ip, port);
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == SOCKET_ERROR) {
        // console.setTextColor(RED);
        // System.out.println("[ERROR] connect() failed: %d", WSAGetLastError());
        // File file = new_File("BIGDATAServerMonitorLog.txt", "a");
        // file.println(&file, "[ERROR] connect() failed: %d", WSAGetLastError());
        // file.close(&file);
        closesocket(sock);
        return -1;
    }

    char request[512];
    snprintf(request, sizeof(request),"GET %s HTTP/1.1\r\n""Host: %s:%d\r\n""Connection: close\r\n\r\n",path, ip, port);

    // console.setTextColor(WHITE);
    // System.out.println("[DEBUG] Sending HTTP GET request...");
    send(sock, request, (int)strlen(request), 0);

    char buffer[2048];
    // console.setTextColor(WHITE);
    // System.out.println("[DEBUG] Receiving response...");
    int bytes = recv(sock, buffer, sizeof(buffer) - 1, 0);
    if (bytes <= 0) {
        // console.setTextColor(RED);
        // System.out.println("[ERROR] recv() failed: %d", WSAGetLastError());
        // File file = new_File("BIGDATAServerMonitorLog.txt", "a");
        // file.println(&file, "[ERROR] recv() failed: %d", WSAGetLastError());
        // file.close(&file);
        closesocket(sock);
        return -1;
    }
    buffer[bytes] = '\0';

    char http_version[16];
    int status_code = 0;
    char status_text[64] = {0};

    // console.setTextColor(WHITE);
    // System.out.println("[DEBUG] Parsing HTTP status code...");
    sscanf(buffer, "%15s %d %63[^\r\n]", http_version, &status_code, status_text);

    closesocket(sock);
    return status_code;
}

void focusCmdOnce(void) {
    HWND hwnd;
    int retry = 0;

    while ((hwnd = FindWindowA(NULL, "BIGDATA SSH SESSION")) == NULL && retry++ < 50) {
        Sleep(100);
    }

    if (!hwnd) return;

    ShowWindow(hwnd, SW_SHOW);
    SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, 0, 0,
                 SWP_NOMOVE | SWP_NOSIZE);
    SetForegroundWindow(hwnd);
    SetFocus(hwnd);
}


void* restartBIGDATA(void* arg){
    Mutex* mutex = (Mutex*)arg;
    Console console = new_Console();
    Time tm = new_Time();

    ignoreInput = true;
    system("start \"BIGDATA SSH SESSION\" cmd /k title BIGDATA SSH SESSION");

    focusCmdOnce();
    
    sleep(500);
    sendString("ssh -p 20022 root@6.1.5.113\n");
    sleep(500);
    sendString("aufrhd!\n");
    sleep(1000);
    sendString("docker restart ui-docker_tomcat_1\n");
    tm.getSystemTime(&tm);
    console.setTextColor(MAGENTA);
    System.out.println("[%04hu-%02hhu-%02hhu %02hhu:%02hhu:%02hhu] Server restart",tm.year, tm.month, tm.day, tm.hour, tm.minute, tm.second);
    console.setTextColor(RESET);
    File file = new_File("BIGDATAServerMonitorLog.txt", "a");
    file.println(&file, "[%04hu-%02hhu-%02hhu %02hhu:%02hhu:%02hhu] Server restart",tm.year, tm.month, tm.day, tm.hour, tm.minute, tm.second);
    file.close(&file);
    sleep(10000);
    sendString("exit\n");
    sleep(1000);
    sendString("exit\n");
    ignoreInput = false;

    mutex->lock(mutex);
    restartRun = false;
    mutex->unlock(mutex);

    return null;
}

void* checkBIGDATA(void* arg) {
    Mutex* mutex = (Mutex*)arg;
    Console console = new_Console();
    Time tm = new_Time();

    boolean trigger = false;
    restartRun = false;

    while (true) {
        console.setTextColor(CYAN);
        System.out.println("[INFO] Checking server status...");
        int code = checkStatus();

        tm.getSystemTime(&tm);
        if (code == 404) {
            console.setTextColor(RED);
            System.out.println("[%04hu-%02hhu-%02hhu %02hhu:%02hhu:%02hhu] Status: 404 Not Found",tm.year, tm.month, tm.day, tm.hour, tm.minute, tm.second);
            mutex->lock(mutex);
            if(!restartRun){
                File file = new_File("BIGDATAServerMonitorLog.txt", "a");
                file.println(&file, "[%04hu-%02hhu-%02hhu %02hhu:%02hhu:%02hhu] Status: 404 Not Found",tm.year, tm.month, tm.day, tm.hour, tm.minute, tm.second);
                file.close(&file);
                trigger = true;
            }
            mutex->unlock(mutex);
            

        } else if (code > 0) {
            console.setTextColor(GREEN);
            System.out.println("[%04hu-%02hhu-%02hhu %02hhu:%02hhu:%02hhu] Status: OK (%d)",tm.year, tm.month, tm.day, tm.hour, tm.minute, tm.second, code);
        } else {
            console.setTextColor(YELLOW);
            System.out.println("[%04hu-%02hhu-%02hhu %02hhu:%02hhu:%02hhu] Status: Connection Failed",tm.year, tm.month, tm.day, tm.hour, tm.minute, tm.second);
            mutex->lock(mutex);
            if(!restartRun){
                File file = new_File("BIGDATAServerMonitorLog.txt", "a");
                file.println(&file, "[%04hu-%02hhu-%02hhu %02hhu:%02hhu:%02hhu] Status: Connection Failed",tm.year, tm.month, tm.day, tm.hour, tm.minute, tm.second);
                file.close(&file);
                trigger = true;
            }
            mutex->unlock(mutex);
        }
        
        mutex->lock(mutex);
        if(trigger && !restartRun){
            restartRun = true;
            trigger = false;
            Thread thread = new_Thread(restartBIGDATA);
            thread.start(&thread, mutex);
        }
        mutex->unlock(mutex);

        console.setTextColor(RESET);
        fflush(stdout);
        sleep(1000);
    }
    return null;
}

int isLeapYear(uint16_t year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

uint8_t daysInMonth(uint16_t year, uint8_t month) {
    static const uint8_t days[] = {
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };

    if (month == 2 && isLeapYear(year))
        return 29;

    return days[month - 1];
}

void getYesterday(Time* tm, uint16_t* y, uint8_t* m, uint8_t* d) {
    *y = tm->year;
    *m = tm->month;
    *d = tm->day;

    if (*d > 1) {
        (*d)--;
        return;
    }

    if (*m > 1) {
        (*m)--;
    } else {
        *m = 12;
        (*y)--;
    }

    *d = daysInMonth(*y, *m);
}

void* inputIgnoreThread(void* arg) {
    installInputHook();   // 최초 1회 설치

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    uninstallInputHook();
    return null;
}

void* checkTime(void* arg){
    Time tm = new_Time();
    uint8_t lastMonth, lastDay;
    uint16_t lastYear;

    tm.getSystemTime(&tm);

    getYesterday(&tm, &lastYear, &lastMonth, &lastDay);

    while (1) {
        tm.getSystemTime(&tm);
        if (!(tm.hour | tm.minute | tm.second)) {
            if (tm.day != lastDay) {
                File file = new_File("BIGDATAServerMonitorLog.txt", "a");
                file.println(&file, "----- BIGDATA Server Monitor Log  Ended %04hu-%02hhu-%02hhu -----", lastYear, lastMonth, lastDay);
                file.println(&file, "");
                file.println(&file, "----- BIGDATA Server Monitor Log Started %04hu-%02hhu-%02hhu -----", tm.year, tm.month, tm.day);
                file.close(&file);
                lastYear = tm.year;
                lastMonth = tm.month;
                lastDay = tm.day;
            }
        }
        sleep(50);
    }

    return null;
}

void* screenTime(void* arg){
    Console console = new_Console();
    while (true) {
        console.setTextColor(BLUE);
        System.out.println("Simulating key press to prevent screen lock...");
        console.setTextColor(RESET);
        keybd_event(VK_NONCONVERT, 0, 0, 0);
        keybd_event(VK_NONCONVERT, 0, KEYEVENTF_KEYUP, 0);
        sleep(180000);
    }

    return null;
}

void initlize() {
    Console console = new_Console();
    Time tm = new_Time();
    uint16_t year = 0;
    uint8_t month = 0, day = 0;
    boolean found = false;
    string line = (string)malloc(sizeof(char) * 256);

    console.clear();
    console.setWindowTitle("BIGDATA Server Monitor");
    console.setWindowSize(100, 30);
    console.setCursorVisibility(false);

    File file = new_File("BIGDATAServerMonitorLog.txt", "r");
    
    while(true) {
        if (file.scanf(&file, "%[^\n]\n", line) == EOF)
            break;

        if (sscanf(line, "----- BIGDATA Server Monitor Log Started %04hu-%02hhu-%02hhu -----", &year, &month, &day) == 3) {
            tm.getSystemTime(&tm);
            if (!((year ^ tm.year) | (month ^ tm.month) | (day ^ tm.day))) {
                found = true;
                break;
            }
        }
    }
    file.close(&file);

    if(!found){
        file = new_File("BIGDATAServerMonitorLog.txt", "a");
        tm.getSystemTime(&tm);
        file.println(&file, "----- BIGDATA Server Monitor Log Started %04hu-%02hhu-%02hhu -----", tm.year, tm.month, tm.day);
        file.close(&file);
    }

    free(line);

    console.setTextColor(CYAN);
    System.out.println("[INFO] Initializing Winsock...");
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2,2), &wsaData) != 0) {
        console.setTextColor(RED);
        System.out.println("[ERROR] WSAStartup failed");
        exit(1);
    }
    console.setTextColor(CYAN);
    System.out.println("[INFO] Winsock initialized successfully.");
    console.setTextColor(RESET);
}

int main() {
    //gcc -std=c99 -Wall -I inc -o main.exe src/*.c -lws2_32
    Mutex mutex = new_Mutex();
    Thread inputThread = new_Thread(inputIgnoreThread);
    Thread checkBIGDATAThread = new_Thread(checkBIGDATA);
    Thread checkTimeThread = new_Thread(checkTime);
    Thread screenTimeThread = new_Thread(screenTime);
    
    initlize();
    inputThread.start(&inputThread);
    checkBIGDATAThread.start(&checkBIGDATAThread, &mutex);
    checkTimeThread.start(&checkTimeThread);
    screenTimeThread.start(&screenTimeThread);

    checkBIGDATAThread.join(&checkBIGDATAThread);
    checkTimeThread.join(&checkTimeThread);
    screenTimeThread.join(&screenTimeThread);

    checkBIGDATAThread.delete(&checkBIGDATAThread);
    checkTimeThread.delete(&checkTimeThread);
    screenTimeThread.delete(&screenTimeThread);

    WSACleanup();
    return 0;
}

