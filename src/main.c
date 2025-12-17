#include <winsock2.h>
#include <ws2tcpip.h>
#include <bcrypt.h>
#include <wincrypt.h>
#include <setjmp.h>

#include "main.h"
#include "System.h"
#include "algorithm.h"
#include "Scanner.h"
#include "thread.h"
#include "console.h"

import SYSTEM System;

#define PASS_FILE "pass.txt"
#define AES_KEY_SIZE 32
#define AES_BLOCK_SIZE 16
#define HMAC_SIZE 32

typedef NTSTATUS (WINAPI *tBCryptOpenAlgorithmProvider)(BCRYPT_ALG_HANDLE*, LPCWSTR, LPCWSTR, ULONG);
typedef NTSTATUS (WINAPI *tBCryptCreateHash)(BCRYPT_ALG_HANDLE, BCRYPT_HASH_HANDLE*, PUCHAR, ULONG, PUCHAR, ULONG, ULONG);
typedef NTSTATUS (WINAPI *tBCryptHashData)(BCRYPT_HASH_HANDLE, PUCHAR, ULONG, ULONG);
typedef NTSTATUS (WINAPI *tBCryptFinishHash)(BCRYPT_HASH_HANDLE, PUCHAR, ULONG, ULONG);
typedef NTSTATUS (WINAPI *tBCryptDestroyHash)(BCRYPT_HASH_HANDLE);
typedef NTSTATUS (WINAPI *tBCryptCloseAlgorithmProvider)(BCRYPT_ALG_HANDLE, ULONG);
typedef NTSTATUS (WINAPI *tBCryptSetProperty)(BCRYPT_ALG_HANDLE, LPCWSTR, PUCHAR, ULONG, ULONG);
typedef NTSTATUS (WINAPI *tBCryptGenerateSymmetricKey)(BCRYPT_ALG_HANDLE, BCRYPT_KEY_HANDLE*, PUCHAR, ULONG, PUCHAR, ULONG, ULONG);
typedef NTSTATUS (WINAPI *tBCryptEncrypt)(BCRYPT_KEY_HANDLE, PUCHAR, ULONG, VOID*, PUCHAR, ULONG, PUCHAR, ULONG, ULONG*, ULONG);
typedef NTSTATUS (WINAPI *tBCryptDecrypt)(BCRYPT_KEY_HANDLE, PUCHAR, ULONG, VOID*, PUCHAR, ULONG, PUCHAR, ULONG, ULONG*, ULONG);
typedef NTSTATUS (WINAPI *tBCryptDestroyKey)(BCRYPT_KEY_HANDLE);

static tBCryptOpenAlgorithmProvider pBCryptOpenAlgorithmProvider = NULL;
static tBCryptCreateHash pBCryptCreateHash = NULL;
static tBCryptHashData pBCryptHashData = NULL;
static tBCryptFinishHash pBCryptFinishHash = NULL;
static tBCryptDestroyHash pBCryptDestroyHash = NULL;
static tBCryptCloseAlgorithmProvider pBCryptCloseAlgorithmProvider = NULL;
static tBCryptSetProperty pBCryptSetProperty = NULL;
static tBCryptGenerateSymmetricKey pBCryptGenerateSymmetricKey = NULL;
static tBCryptEncrypt pBCryptEncrypt = NULL;
static tBCryptDecrypt pBCryptDecrypt = NULL;
static tBCryptDestroyKey pBCryptDestroyKey = NULL;

static volatile boolean allowInjectedInput = false;
static volatile boolean restartRun = false;
static volatile boolean ignoreInput = false;
static HHOOK keyboardHook = NULL;
static HHOOK mouseHook = NULL;

static void resolveImports(void) {
    HMODULE hb = LoadLibraryA("bcrypt.dll");
    if (!hb) return;
    pBCryptOpenAlgorithmProvider = (tBCryptOpenAlgorithmProvider)GetProcAddress(hb, "BCryptOpenAlgorithmProvider");
    pBCryptCreateHash = (tBCryptCreateHash)GetProcAddress(hb, "BCryptCreateHash");
    pBCryptHashData = (tBCryptHashData)GetProcAddress(hb, "BCryptHashData");
    pBCryptFinishHash = (tBCryptFinishHash)GetProcAddress(hb, "BCryptFinishHash");
    pBCryptDestroyHash = (tBCryptDestroyHash)GetProcAddress(hb, "BCryptDestroyHash");
    pBCryptCloseAlgorithmProvider = (tBCryptCloseAlgorithmProvider)GetProcAddress(hb, "BCryptCloseAlgorithmProvider");
    pBCryptSetProperty = (tBCryptSetProperty)GetProcAddress(hb, "BCryptSetProperty");
    pBCryptGenerateSymmetricKey = (tBCryptGenerateSymmetricKey)GetProcAddress(hb, "BCryptGenerateSymmetricKey");
    pBCryptEncrypt = (tBCryptEncrypt)GetProcAddress(hb, "BCryptEncrypt");
    pBCryptDecrypt = (tBCryptDecrypt)GetProcAddress(hb, "BCryptDecrypt");
    pBCryptDestroyKey = (tBCryptDestroyKey)GetProcAddress(hb, "BCryptDestroyKey");
}

/* -------------------------------------------------
   디버거 감지
------------------------------------------------- */
static int isDebuggerDetected(void) {
    BOOL remote = FALSE;
    if (IsDebuggerPresent()) return 1;
    CheckRemoteDebuggerPresent(GetCurrentProcess(), &remote);
    if (remote) return 1;
    return 0;
}

/* -------------------------------------------------
   난독화 키 테이블
------------------------------------------------- */
typedef unsigned char (*fp_char)(void);
unsigned char kR(void){ return 'r'; }
unsigned char kA(void){ return 'a'; }
unsigned char kH(void){ return 'h'; }
unsigned char kF(void){ return 'f'; }
unsigned char kD(void){ return 'd'; }
unsigned char kU(void){ return 'u'; }
unsigned char kBang(void){ return '!'; }

static fp_char keyTable[] = { kR, kA, kH, kF, kD, kU, kBang };
static const int keyTableCount = sizeof(keyTable)/sizeof(keyTable[0]);

static unsigned char obfCall(int idx) {
    idx = (idx * 7 + 13) ^ 0x5A;
    idx = idx % keyTableCount;
    return keyTable[idx]();
}

/* -------------------------------------------------
   키 조립
------------------------------------------------- */
static char globalKey[8];
static int globalKeyReady = 0;
static jmp_buf jb;

static void assembleKeyFlow(void) {
    if (setjmp(jb) == 0) {
        longjmp(jb, 1);
        return;
    }
    char tmp[8];
    tmp[0] = obfCall(1); /* 'a' */
    tmp[1] = obfCall(5); /* 'u' */
    tmp[2] = obfCall(3); /* 'f' */
    tmp[3] = obfCall(0); /* 'r' */
    tmp[4] = obfCall(2); /* 'h' */
    tmp[5] = obfCall(4); /* 'd' */
    tmp[6] = obfCall(6); /* '!' */
    tmp[7] = 0;
    memcpy(globalKey, tmp, 8);
    SecureZeroMemory(tmp, sizeof(tmp));
    globalKeyReady = 1;
}

/* -------------------------------------------------
   constructor: 초기화
------------------------------------------------- */
__attribute__((constructor))
static void earlyInit(void) {
    resolveImports();
    if (isDebuggerDetected()) return;
    assembleKeyFlow();
}

/* -------------------------------------------------
   AES 키 파생
------------------------------------------------- */
static int deriveAESKeyFromAssembled(BYTE outKey[32]) {
    if (!globalKeyReady) return 0;
    BCRYPT_ALG_HANDLE hAlg = 0;
    BCRYPT_HASH_HANDLE hHash = 0;
    BYTE hash[32] = {0};

    if (!pBCryptOpenAlgorithmProvider) return 0;
    if (pBCryptOpenAlgorithmProvider(&hAlg, BCRYPT_SHA256_ALGORITHM, NULL, 0) != 0) return 0;
    if (pBCryptCreateHash(hAlg, &hHash, NULL, 0, NULL, 0, 0) != 0) { pBCryptCloseAlgorithmProvider(hAlg,0); return 0; }
    pBCryptHashData(hHash, (PUCHAR)globalKey, 7, 0);
    pBCryptFinishHash(hHash, hash, 32, 0);
    memcpy(outKey, hash, 32);
    pBCryptDestroyHash(hHash);
    pBCryptCloseAlgorithmProvider(hAlg, 0);
    SecureZeroMemory(hash, sizeof(hash));
    return 1;
}

/* -------------------------------------------------
   AES encrypt/decrypt
------------------------------------------------- */
static DWORD aesEncryptDyn(const BYTE* in, DWORD inLen, BYTE* out) {
    BYTE aesKey[32];
    if (!deriveAESKeyFromAssembled(aesKey)) return 0;

    BCRYPT_ALG_HANDLE hAlg = 0;
    BCRYPT_KEY_HANDLE hKey = 0;
    ULONG outLen = 0;
    BYTE iv[AES_BLOCK_SIZE] = {0};

    if (pBCryptOpenAlgorithmProvider(&hAlg, BCRYPT_AES_ALGORITHM, NULL, 0) != 0) { SecureZeroMemory(aesKey,32); return 0; }
    pBCryptSetProperty(hAlg, BCRYPT_CHAINING_MODE, (PUCHAR)BCRYPT_CHAIN_MODE_CBC, sizeof(BCRYPT_CHAIN_MODE_CBC), 0);
    pBCryptGenerateSymmetricKey(hAlg, &hKey, NULL, 0, aesKey, 32, 0);
    pBCryptEncrypt(hKey, (PUCHAR)in, inLen, NULL, iv, AES_BLOCK_SIZE, out, inLen + AES_BLOCK_SIZE, &outLen, BCRYPT_BLOCK_PADDING);
    pBCryptDestroyKey(hKey);
    pBCryptCloseAlgorithmProvider(hAlg, 0);
    SecureZeroMemory(aesKey, sizeof(aesKey));
    return (DWORD)outLen;
}

static DWORD aesDecryptDyn(const BYTE* in, DWORD inLen, BYTE* out) {
    BYTE aesKey[32];
    if (!deriveAESKeyFromAssembled(aesKey)) return 0;

    BCRYPT_ALG_HANDLE hAlg = 0;
    BCRYPT_KEY_HANDLE hKey = 0;
    ULONG outLen = 0;
    BYTE iv[AES_BLOCK_SIZE] = {0};

    if (pBCryptOpenAlgorithmProvider(&hAlg, BCRYPT_AES_ALGORITHM, NULL, 0) != 0) { SecureZeroMemory(aesKey,32); return 0; }
    pBCryptSetProperty(hAlg, BCRYPT_CHAINING_MODE, (PUCHAR)BCRYPT_CHAIN_MODE_CBC, sizeof(BCRYPT_CHAIN_MODE_CBC), 0);
    pBCryptGenerateSymmetricKey(hAlg, &hKey, NULL, 0, aesKey, 32, 0);
    pBCryptDecrypt(hKey, (PUCHAR)in, inLen, NULL, iv, AES_BLOCK_SIZE, out, inLen, &outLen, BCRYPT_BLOCK_PADDING);
    pBCryptDestroyKey(hKey);
    pBCryptCloseAlgorithmProvider(hAlg, 0);
    SecureZeroMemory(aesKey, sizeof(aesKey));
    return (DWORD)outLen;
}

/* -------------------------------------------------
   HMAC 계산
------------------------------------------------- */
static int computeHMACDyn(BYTE* data, DWORD len, BYTE outHmac[32]) {
    BYTE key[32];
    if (!deriveAESKeyFromAssembled(key)) return 0;

    BCRYPT_ALG_HANDLE hAlg = 0;
    BCRYPT_HASH_HANDLE hHash = 0;
    if (pBCryptOpenAlgorithmProvider(&hAlg, BCRYPT_SHA256_ALGORITHM, NULL, BCRYPT_ALG_HANDLE_HMAC_FLAG) != 0) return 0;
    if (pBCryptCreateHash(hAlg, &hHash, NULL, 0, key, 32, 0) != 0) { pBCryptCloseAlgorithmProvider(hAlg,0); return 0; }
    pBCryptHashData(hHash, data, len, 0);
    pBCryptFinishHash(hHash, outHmac, 32, 0);
    pBCryptDestroyHash(hHash);
    pBCryptCloseAlgorithmProvider(hAlg, 0);
    SecureZeroMemory(key, sizeof(key));
    return 1;
}

/* -------------------------------------------------
   DPAPI wrapper
------------------------------------------------- */
static int dpapiProtectLocal(BYTE* in, DWORD inLen, DATA_BLOB* out) {
    DATA_BLOB inBlob = { inLen, in };
    return CryptProtectData(&inBlob, NULL, NULL, NULL, NULL, CRYPTPROTECT_LOCAL_MACHINE, out);
}
static int dpapiUnprotectLocal(DATA_BLOB* inBlob, BYTE* outBuf, DWORD* outLen) {
    DATA_BLOB dec;
    if (!CryptUnprotectData(inBlob, NULL, NULL, NULL, NULL, 0, &dec)) return 0;
    memcpy(outBuf, dec.pbData, dec.cbData);
    *outLen = dec.cbData;
    LocalFree(dec.pbData);
    return 1;
}

/* -------------------------------------------------
   비밀번호 초기화 및 로드
------------------------------------------------- */
static string initPassword(void) {
    File f = new_File(PASS_FILE, "rb");
    if (!f.file) {
        char pw[128];
        System.out.println("Enter initial password: ");
        fflush(stdout);
        if (!fgets(pw, sizeof(pw), stdin)) return NULL;
        pw[strcspn(pw, "\r\n")] = 0;

        BYTE enc[512];
        DWORD encLen = aesEncryptDyn((BYTE*)pw, (DWORD)strlen(pw), enc);
        if (encLen == 0) return NULL;

        DATA_BLOB dp;
        if (!dpapiProtectLocal(enc, encLen, &dp)) return NULL;

        BYTE hmac[32];
        if (!computeHMACDyn(dp.pbData, dp.cbData, hmac)) { LocalFree(dp.pbData); return NULL; }

        f.open(&f, PASS_FILE, "wb");
        if (!f.file) { LocalFree(dp.pbData); return NULL; }
        fwrite(hmac, 1, 32, f.file);
        fwrite(dp.pbData, 1, dp.cbData, f.file);
        f.close(&f);
        LocalFree(dp.pbData);

        return _strdup(pw);
    }

    BYTE hmacStored[32];
    if (fread(hmacStored, 1, 32, f.file) != 32) { fclose(f.file); return NULL; }
    BYTE blob[1024];
    DWORD blobLen = (DWORD)fread(blob, 1, sizeof(blob), f.file);
    f.close(&f);

    BYTE hmacCalc[32];
    if (!computeHMACDyn(blob, blobLen, hmacCalc)) return NULL;
    if (memcmp(hmacStored, hmacCalc, 32) != 0) {
        System.out.println("HMAC mismatch\n");
        return NULL;
    }

    DATA_BLOB inBlob = { blobLen, blob };
    BYTE dpOut[1024];
    DWORD dpOutLen = 0;
    if (!dpapiUnprotectLocal(&inBlob, dpOut, &dpOutLen)) return NULL;

    BYTE dec[1024];
    DWORD decLen = aesDecryptDyn(dpOut, dpOutLen, dec);
    if (decLen == 0) return NULL;
    dec[decLen] = 0;
    string ret = _strdup((string)dec);
    SecureZeroMemory(dec, sizeof(dec));
    SecureZeroMemory(dpOut, sizeof(dpOut));
    return ret;
}

/* -------------------------------------------------
   비밀번호 변경
------------------------------------------------- */
static int changePassword(void) {
    string oldPw = initPassword();
    if (!oldPw) {
        System.out.println("Existing post-test verification failed");
        return 0;
    }

    char newPw[128];
    System.out.printf("Enter NEW password: ");
    fflush(stdout);

    if (!fgets(newPw, sizeof(newPw), stdin)) {
        SecureZeroMemory(oldPw, strlen(oldPw));
        free(oldPw);
        return 0;
    }
    newPw[strcspn(newPw, "\r\n")] = 0;

    BYTE enc[512];
    DWORD encLen = aesEncryptDyn((BYTE*)newPw, (DWORD)strlen(newPw), enc);
    if (!encLen) {
        SecureZeroMemory(oldPw, strlen(oldPw));
        free(oldPw);
        SecureZeroMemory(newPw, sizeof(newPw));
        return 0;
    }

    DATA_BLOB dp = {0};
    if (!dpapiProtectLocal(enc, encLen, &dp)) {
        SecureZeroMemory(oldPw, strlen(oldPw));
        free(oldPw);
        SecureZeroMemory(newPw, sizeof(newPw));
        return 0;
    }
 
    BYTE hmac[32];
    if (!computeHMACDyn(dp.pbData, dp.cbData, hmac)) {
        LocalFree(dp.pbData);
        SecureZeroMemory(oldPw, strlen(oldPw));
        free(oldPw);
        SecureZeroMemory(newPw, sizeof(newPw));
        return 0;
    }

    File f = new_File(PASS_FILE, "wb");
    if (!f.file) {
        LocalFree(dp.pbData);
        SecureZeroMemory(oldPw, strlen(oldPw));
        free(oldPw);
        SecureZeroMemory(newPw, sizeof(newPw));
        return 0;
    }

    fwrite(hmac, 1, 32, f.file);
    fwrite(dp.pbData, 1, dp.cbData, f.file);
    f.close(&f);
    LocalFree(dp.pbData);

    SecureZeroMemory(oldPw, strlen(oldPw));
    free(oldPw);
    SecureZeroMemory(newPw, sizeof(newPw));

    System.out.println("[+] Password changed successfully\n");
    return 1;
}

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

void sendEnter(void) {
    INPUT ip;
    ZeroMemory(&ip, sizeof(INPUT));
    ip.type = INPUT_KEYBOARD;
    ip.ki.wVk = VK_RETURN;
    ip.ki.dwFlags = 0;
    SendInput(1, &ip, sizeof(INPUT));
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &ip, sizeof(INPUT));
}

void sendString(const string str) {
    size_t len = strlen(str);
    allowInjectedInput = true;
    for (size_t i = 0; i < len; i++) sendChar(str[i]);
    sendEnter();
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
    if (!keyboardHook) keyboardHook = SetWindowsHookEx( WH_KEYBOARD_LL, keyboardProc, GetModuleHandle(NULL), 0);
    if (!mouseHook) mouseHook = SetWindowsHookEx( WH_MOUSE_LL, mouseProc, GetModuleHandle(NULL), 0);
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
    const string ip = "6.1.5.113";
    const string path = "/ui";
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
    SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
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
    sendString("ssh -p 20022 root@6.1.5.113");
    sleep(500);
    string pw = initPassword();
    sendString(pw);
    SecureZeroMemory(pw, strlen(pw));
    free(pw);
    sleep(1000);
    sendString("docker restart ui-docker_tomcat_1");
    tm.getSystemTime(&tm);
    console.setTextColor(MAGENTA);
    System.out.println("[%04hu-%02hhu-%02hhu %02hhu:%02hhu:%02hhu] Server restart",tm.year, tm.month, tm.day, tm.hour, tm.minute, tm.second);
    console.setTextColor(RESET);
    File file = new_File("BIGDATAServerMonitorLog.txt", "a");
    file.println(&file, "[%04hu-%02hhu-%02hhu %02hhu:%02hhu:%02hhu] Server restart",tm.year, tm.month, tm.day, tm.hour, tm.minute, tm.second);
    file.close(&file);
    sleep(10000);
    sendString("exit");
    sleep(1000);
    sendString("exit");
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

int main(int argc, string argv[]) {
    //gcc -std=c99 -Wall -I inc -o main.exe src/*.c -lws2_32 -lbcrypt -lcrypt32
    if (!globalKeyReady) {
        System.out.println("Key not ready (debugger or early init failed)\n");
        return 1;
    }

    if (argc == 2 && strcmp(argv[1], "--change") == 0) {
        if (!changePassword()) {
            System.out.println("Password change failed\n");
            return 1;
        }
    }

    string pw = initPassword();

    if (!pw) {
        System.out.println("Password initialization failed\n");
        return 1;
    }

    SecureZeroMemory(pw, strlen(pw));
    free(pw);

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

