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

    console.setTextColor(WHITE);
    System.out.println("[DEBUG] Creating socket...");
    SOCKET sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock == INVALID_SOCKET) {
        console.setTextColor(RED);
        System.out.println("[ERROR] socket() failed: %d", WSAGetLastError());
        return -1;
    }

    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, ip, &serv_addr.sin_addr) <= 0) {
        console.setTextColor(RED);
        System.out.println("[ERROR] inet_pton() failed");
        closesocket(sock);
        return -1;
    }

    console.setTextColor(WHITE);
    System.out.println("[DEBUG] Connecting to server BIGDATA...", ip, port);
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == SOCKET_ERROR) {
        System.out.println("[ERROR] connect() failed: %d", WSAGetLastError());
        closesocket(sock);
        return -1;
    }

    char request[512];
    snprintf(request, sizeof(request),"GET %s HTTP/1.1\r\n""Host: %s:%d\r\n""Connection: close\r\n\r\n",path, ip, port);

    console.setTextColor(WHITE);
    System.out.println("[DEBUG] Sending HTTP GET request...");
    send(sock, request, (int)strlen(request), 0);

    char buffer[2048];
    console.setTextColor(WHITE);
    System.out.println("[DEBUG] Receiving response...");
    int bytes = recv(sock, buffer, sizeof(buffer) - 1, 0);
    if (bytes <= 0) {
        console.setTextColor(RED);
        System.out.println("[ERROR] recv() failed: %d", WSAGetLastError());
        closesocket(sock);
        return -1;
    }
    buffer[bytes] = '\0';

    char http_version[16];
    int status_code = 0;
    char status_text[64] = {0};

    console.setTextColor(WHITE);
    System.out.println("[DEBUG] Parsing HTTP status code...");
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
            System.out.println("[%04d-%02d-%02d %02d:%02d:%02d] Status: 404 Not Found",tm.year, tm.month, tm.day, tm.hour, tm.minute, tm.second);
            File file = new_File("BIGDATAServerMonitorLog.txt", "a");
            file.println(&file, "[%04d-%02d-%02d %02d:%02d:%02d] Status: 404 Not Found",tm.year, tm.month, tm.day, tm.hour, tm.minute, tm.second);
            file.close(&file);
        } else if (code > 0) {
            console.setTextColor(GREEN);
            System.out.println("[%04d-%02d-%02d %02d:%02d:%02d] Status: OK (%d)",tm.year, tm.month, tm.day, tm.hour, tm.minute, tm.second, code);
        } else {
            console.setTextColor(YELLOW);
            System.out.println("[%04d-%02d-%02d %02d:%02d:%02d] Status: Connection Failed",tm.year, tm.month, tm.day, tm.hour, tm.minute, tm.second);
            File file = new_File("BIGDATAServerMonitorLog.txt", "a");
            file.println(&file, "[%04d-%02d-%02d %02d:%02d:%02d] Status: Connection Failed",tm.year, tm.month, tm.day, tm.hour, tm.minute, tm.second);
            file.close(&file);
        }

        fflush(stdout);
        sleep(10000);  // 10 seconds
        console.setTextColor(RESET);
    }
    return NULL;
}

void* checkTime(void* arg){
    Time tm = new_Time();
    while (1) {
        tm.getSystemTime(&tm);
        if(!tm.hour && !tm.minute){
            tm.getSystemTime(&tm);
            File file = new_File("BIGDATAServerMonitorLog.txt", "a");
            file.println(&file, "----- BIGDATA Server Monitor Log Ended %04d-%02d-%02d -----", tm.year, tm.month, tm.day);
        }
        sleep(100);
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
    File file = new_File("BIGDATAServerMonitorLog.txt", "a");
    Time tm = new_Time();

    console.clear();
    console.setWindowTitle("BIGDATA Server Monitor");
    console.setWindowSize(100, 30);
    console.setCursorVisibility(false);

    tm.getSystemTime(&tm);
    file.println(&file, "----- BIGDATA Server Monitor Log Started %04d-%02d-%02d -----", tm.year, tm.month, tm.day);
    file.close(&file);

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
}

int main() {
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