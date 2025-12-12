#include <winsock2.h>
#include <ws2tcpip.h>

#include "main.h"
#include "System.h"
#include "algorithm.h"
#include "Scanner.h"
#include "thread.h"
#include "console.h"

import SYSTEM System;

int checkStatus() {
    Console console = new_Console();
    const char *ip = "6.1.5.113";
    const char *path = "/ui";
    int port = 9090;

    // console.setTextColor(WHITE);
    // System.out.println("[DEBUG] Creating socket...");
    SOCKET sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock == INVALID_SOCKET) {
        console.setTextColor(RED);
        System.out.println("[ERROR] socket() failed: %d", WSAGetLastError());
        File file = new_File("BIGDATAServerMonitorLog.txt", "a");
        file.println(&file, "[ERROR] socket() failed: %d", WSAGetLastError());
        file.close(&file);
        return -1;
    }

    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, ip, &serv_addr.sin_addr) <= 0) {
        console.setTextColor(RED);
        System.out.println("[ERROR] inet_pton() failed");
        File file = new_File("BIGDATAServerMonitorLog.txt", "a");
        file.println(&file, "[ERROR] inet_pton() failed");
        file.close(&file);
        closesocket(sock);
        return -1;
    }

    // console.setTextColor(WHITE);
    // System.out.println("[DEBUG] Connecting to server BIGDATA...", ip, port);
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == SOCKET_ERROR) {
        console.setTextColor(RED);
        System.out.println("[ERROR] connect() failed: %d", WSAGetLastError());
        File file = new_File("BIGDATAServerMonitorLog.txt", "a");
        file.println(&file, "[ERROR] connect() failed: %d", WSAGetLastError());
        file.close(&file);
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
        console.setTextColor(RED);
        System.out.println("[ERROR] recv() failed: %d", WSAGetLastError());
        File file = new_File("BIGDATAServerMonitorLog.txt", "a");
        file.println(&file, "[ERROR] recv() failed: %d", WSAGetLastError());
        file.close(&file);
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

void* checkBIGDATA(void* arg) {
    Console console = new_Console();
    Time tm = new_Time();
    while (1) {
        console.setTextColor(CYAN);
        System.out.println("[INFO] Checking server status...");
        int code = checkStatus();

        // 404 -> Not Found, others -> OK
        tm.getSystemTime(&tm);
        if (code == 404) {
            console.setTextColor(RED);
            System.out.println("[%04hu-%02hhu-%02hhu %02hhu:%02hhu:%02hhu] Status: 404 Not Found",tm.year, tm.month, tm.day, tm.hour, tm.minute, tm.second);
            File file = new_File("BIGDATAServerMonitorLog.txt", "a");
            file.println(&file, "[%04hu-%02hhu-%02hhu %02hhu:%02hhu:%02hhu] Status: 404 Not Found",tm.year, tm.month, tm.day, tm.hour, tm.minute, tm.second);
            file.close(&file);
        } else if (code > 0) {
            console.setTextColor(GREEN);
            System.out.println("[%04hu-%02hhu-%02hhu %02hhu:%02hhu:%02hhu] Status: OK (%d)",tm.year, tm.month, tm.day, tm.hour, tm.minute, tm.second, code);
        } else {
            console.setTextColor(YELLOW);
            System.out.println("[%04hu-%02hhu-%02hhu %02hhu:%02hhu:%02hhu] Status: Connection Failed",tm.year, tm.month, tm.day, tm.hour, tm.minute, tm.second);
            File file = new_File("BIGDATAServerMonitorLog.txt", "a");
            file.println(&file, "[%04hu-%02hhu-%02hhu %02hhu:%02hhu:%02hhu] Status: Connection Failed",tm.year, tm.month, tm.day, tm.hour, tm.minute, tm.second);
            file.close(&file);
        }

        fflush(stdout);
        sleep(1000);  // 10 seconds
        console.setTextColor(RESET);
    }
    return NULL;
}

void* checkTime(void* arg){
    Time tm = new_Time();
    uint8_t lastDay = 255;

    while (1) {
        tm.getSystemTime(&tm);
        if (!(tm.hour | tm.minute | tm.second)) { // 자정인지 확인
            if (tm.day != lastDay) {
                File file = new_File("BIGDATAServerMonitorLog.txt", "a");
                file.println(&file,"----- BIGDATA Server Monitor Log Ended %04hu-%02hhu-%02hhu -----",tm.year, tm.month, tm.day);
                file.close(&file);
                lastDay = tm.day;
            }
        }
        sleep(50);
    }

    return NULL;
}

void* screenTime(void* arg){
    Time tm = new_Time();
    Console console = new_Console();
    tm.setTime(&tm, 0, 0, 0, 0, 0, 0);
    tm.start(&tm);
    while (1) {
        if(tm.minute == 3){
            console.setTextColor(BLUE);
            System.out.println("Simulating key press to prevent screen lock...");
            console.setTextColor(RESET);
            tm.setTime(&tm, 0, 0, 0, 0, 0, 0);
            keybd_event(VK_NONCONVERT, 0, 0, 0);
            keybd_event(VK_NONCONVERT, 0, KEYEVENTF_KEYUP, 0);
        }
        sleep(10000);
    }
    tm.stop(&tm);

    return NULL;
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
        // 한 줄 읽기
        if (file.scanf(&file, "%[^\n]\n", line) == EOF)
            break;

        // 날짜 헤더인지 검사
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
    Thread checkBIGDATAThread = new_Thread(checkBIGDATA);
    Thread checkTimeThread = new_Thread(checkTime);
    Thread screenTimeThread = new_Thread(screenTime);
    
    initlize();
    checkBIGDATAThread.start(&checkBIGDATAThread);
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

/*
#include <windows.h>
#include <stdio.h>
#include <string.h>

void sendChar(char c) {
    SHORT vk = VkKeyScan(c);
    INPUT ip[4] = {0};

    // Shift 필요 여부
    if (vk & 0x0100) { // high byte = shift, ctrl, alt
        ip[0].type = INPUT_KEYBOARD;
        ip[0].ki.wVk = VK_SHIFT;
        ip[0].ki.dwFlags = 0; // 누름
        SendInput(1, &ip[0], sizeof(INPUT));
    }

    // 실제 문자 입력
    ip[1].type = INPUT_KEYBOARD;
    ip[1].ki.wVk = vk & 0xFF;
    ip[1].ki.dwFlags = 0; // 누름
    SendInput(1, &ip[1], sizeof(INPUT));

    ip[2].type = INPUT_KEYBOARD;
    ip[2].ki.wVk = vk & 0xFF;
    ip[2].ki.dwFlags = KEYEVENTF_KEYUP; // 뗌
    SendInput(1, &ip[2], sizeof(INPUT));

    // Shift 뗌
    if (vk & 0x0100) {
        ip[3].type = INPUT_KEYBOARD;
        ip[3].ki.wVk = VK_SHIFT;
        ip[3].ki.dwFlags = KEYEVENTF_KEYUP;-+
        SendInput(1, &ip[3], sizeof(INPUT));
    }

    // Sleep(1); // 문자 간 딜레이
}

void sendString(const char* str) {
    for (size_t i = 0; i < strlen(str); i++) {
        if (str[i] == '\n') {
            // Enter 키
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
}

int main() {
    system("start cmd");
    Sleep(500); // CMD 대기

    sendString("ssh -p 20022 bigdata@6.1.5.113\n");   // SSH 비번 입력
    Sleep(3000);

    sendString("Tgcn9060!\n");   // SSH 비번 입력
    Sleep(1000);

    sendString("sudo su\n");      // sudo 실행
    Sleep(1000);

    sendString("Tgcn9060!\n");   // sudo 비번 입력
    Sleep(1000);

    sendString("docker restart ui-docker_tomcat_1\n"); // 명령 실행
    Sleep(5000);
    sendString("exit\n");
    Sleep(500);
    sendString("exit\n");
    Sleep(500);
    sendString("exit\n");

    return 0;
}

*/