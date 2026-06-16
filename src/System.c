#include "main.h"
#include "System.h"

void print(const string format, ...) {
    va_list ap;
    char buf[4096];
    va_start(ap, format);
    vsnprintf(buf, sizeof(buf), format, ap);
    va_end(ap);
    fprintf(stdout, "%s", buf);
}

void println(const string format, ...) {
    va_list ap;
    char buf[4096];
    va_start(ap, format);
    vsnprintf(buf, sizeof(buf), format, ap);
    va_end(ap);
    fprintf(stdout, "%s\n", buf);
}

static int32_t readInput(void) {
    return getchar();
}

SYSTEM System = {
    .out = {
        .printf = print,
        .println = println
    },
    .in = {
        .read = readInput
    }
};

static int fileScanf(File* self, const string format, ...) {
    if (self == null || self->file == null || format == null) return EOF;

    va_list ap;
    va_start(ap, format);
    int result = vfscanf(self->file, format, ap);
    va_end(ap);
    return result;
}

static int filePrintf(File* self, const string format, ...) {
    if (self == null || self->file == null || format == null) return EOF;

    va_list ap;
    va_start(ap, format);
    int result = vfprintf(self->file, format, ap);
    va_end(ap);
    return result;
}

static int filePrintln(File* self, const string format, ...) {
    if (self == null || self->file == null || format == null) return EOF;

    va_list ap;
    va_start(ap, format);
    int result = vfprintf(self->file, format, ap);
    va_end(ap);
    fprintf(self->file, "\n");
    return result;
}

static int fileOpen(File* self, const string name, const string mode) {
    if (self == null || name == null || mode == null) return 1;
    if (self->file != null) fclose(self->file);
    self->file = fopen(name, mode);
    return self->file == null ? 1 : 0;
}

static void fileClose(File* self) {
    if (self == null || self->file == null) return;
    fclose(self->file);
    self->file = null;
}

File new_File(const string name, const string mode) {
    return (File) {
        .file = fopen(name, mode),
        .open = fileOpen,
        .close = fileClose,
        .scanf = fileScanf,
        .printf = filePrintf,
        .println = filePrintln
    };
}

/*------------------------------Process Class---------------------------*/

#ifdef _WIN32
DWORD processFindByName(Process* self, const string name);
#else
pid_t processFindByName(Process* self, const string name);
#endif

int processStart(Process* self, const string name) {
    if (self == null || name == null) return -1;

    #ifdef _WIN32
        STARTUPINFO si;
        PROCESS_INFORMATION pi;
        char* command = (char*)malloc(strlen(name) + 1);
        if (command == null) return -1;

        strcpy(command, name);
        ZeroMemory(&si, sizeof(si));
        si.cb = sizeof(si);
        ZeroMemory(&pi, sizeof(pi));
        if (!CreateProcess(null, command, null, null, FALSE, 0, null, null, &si, &pi)) {
            free(command);
            return -1;
        }
        free(command);
        self->pid = pi;
        return 0;
    #else
        pid_t pid = fork();
        if (pid < 0) {
            return -1;
        } else if (pid == 0) {
            execl("/bin/sh", "sh", "-c", name, (char *)null);
            exit(0);
        } else {
            self->pid = pid;
            return 0;
        }
    #endif
}

int processKill(Process* self) {
    if (self == null) return -1;

    #ifdef _WIN32
        if (TerminateProcess(self->pid.hProcess, 0)) {
            CloseHandle(self->pid.hProcess);
            CloseHandle(self->pid.hThread);
            return 0;
        } else {
            return -1;
        }
    #else
        if (kill(self->pid, SIGKILL) == 0) {
            return 0;
        } else {
            return -1;
        }
    #endif
}

int processPause(Process* self) {
    if (self == null) return -1;

    #ifdef _WIN32
        return SuspendThread(self->pid.hThread) == (DWORD)-1 ? -1 : 0;
    #else
        return kill(self->pid, SIGSTOP) == 0 ? 0 : -1;
    #endif
}

int processResume(Process* self) {
    if (self == null) return -1;

    #ifdef _WIN32
        return ResumeThread(self->pid.hThread) == (DWORD)-1 ? -1 : 0;
    #else
        return kill(self->pid, SIGCONT) == 0 ? 0 : -1;
    #endif
}

int processIsRunning(Process* self) {
    if (self == null) return 0;

    #ifdef _WIN32
        DWORD exitCode;
        if (GetExitCodeProcess(self->pid.hProcess, &exitCode)) {
            return exitCode == STILL_ACTIVE ? 1 : 0;
        } else {
            return 0;
        }
    #else
        if (kill(self->pid, 0) == 0) {
            return 1;
        } else {
            return 0;
        }
    #endif
}

void processList(Process* self) {
    (void)self;

    #ifdef _WIN32
        HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
        if (hSnapshot == INVALID_HANDLE_VALUE) {
            return;
        }

        PROCESSENTRY32 pe;
        pe.dwSize = sizeof(PROCESSENTRY32);

        if (!Process32First(hSnapshot, &pe)) {
            CloseHandle(hSnapshot);
            return;
        }

        do {
            printf("PID: %lu\tProcess Name: %s\n", pe.th32ProcessID, pe.szExeFile);
        } while (Process32Next(hSnapshot, &pe));

        CloseHandle(hSnapshot);
        return;
    #else
        FILE* fp = popen("ps -e", "r");
        if (fp == null) {
            return;
        }

        char line[256];
        while (fgets(line, sizeof(line), fp) != null) {
            printf("%s", line);
        }

        pclose(fp);
        return;
    #endif
}

int processAppExists(Process* self, const string name) {
    (void)self;
    if (name == null) return 0;

    #ifdef _WIN32
        HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
        if (hSnapshot == INVALID_HANDLE_VALUE) {
            return 0;
        }

        PROCESSENTRY32 pe;
        pe.dwSize = sizeof(PROCESSENTRY32);

        if (!Process32First(hSnapshot, &pe)) {
            CloseHandle(hSnapshot);
            return 0;
        }

        do {
            if (strcmp(pe.szExeFile, name) == 0) {
                CloseHandle(hSnapshot);
                return 1;
            }
        } while (Process32Next(hSnapshot, &pe));

        CloseHandle(hSnapshot);
        return 0;
    #else
        FILE* fp = popen("ps -e", "r");
        if (fp == null) {
            return 0;
        }

        char line[256];
        while (fgets(line, sizeof(line), fp) != null) {
            if (strstr(line, name) != null) {
                pclose(fp);
                return 1;
            }
        }

        pclose(fp);
        return 0;
    #endif
}

int processKillByName(Process* self, const string name) {
    (void)self;
    if (name == null) return -1;

    #ifdef _WIN32
        HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
        if (hSnapshot == INVALID_HANDLE_VALUE) {
            return -1;
        }

        PROCESSENTRY32 pe;
        pe.dwSize = sizeof(PROCESSENTRY32);

        if (!Process32First(hSnapshot, &pe)) {
            CloseHandle(hSnapshot);
            return -1;
        }

        do {
            if (strcmp(pe.szExeFile, name) == 0) {
                HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, FALSE, pe.th32ProcessID);
                if (hProcess != null) {
                    TerminateProcess(hProcess, 0);
                    CloseHandle(hProcess);
                }
            }
        } while (Process32Next(hSnapshot, &pe));

        CloseHandle(hSnapshot);
        return 0;
    #else
        pid_t pid = processFindByName(self, name);
        return pid > 0 ? kill(pid, SIGKILL) : -1;
    #endif
}

#ifdef _WIN32
    DWORD processFindByName(Process* self, const string name) {
        (void)self;
        if (name == null) return 0;

        HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
        if (hSnapshot == INVALID_HANDLE_VALUE) {
            return 0;
        }

        PROCESSENTRY32 pe;
        pe.dwSize = sizeof(PROCESSENTRY32);

        if (!Process32First(hSnapshot, &pe)) {
            CloseHandle(hSnapshot);
            return 0;
        }

        do {
            if (strcmp(pe.szExeFile, name) == 0) {
                CloseHandle(hSnapshot);
                return pe.th32ProcessID;
            }
        } while (Process32Next(hSnapshot, &pe));

        CloseHandle(hSnapshot);
        return 0;
    }
#else
    pid_t processFindByName(Process* self, const string name) {
        (void)self;
        if (name == null) return 0;

        FILE* fp = popen("ps -e", "r");
        if (fp == null) {
            return 0;
        }

        char line[256];
        pid_t pid = 0;
        while (fgets(line, sizeof(line), fp) != null) {
            if (strstr(line, name) != null) {
                sscanf(line, "%d", &pid);
                break;
            }
        }

        pclose(fp);
        return pid;
    }
#endif

Process new_Process(PROCESS pid) {
    return (Process) {
        .pid = pid,
        .start = processStart,
        .kill = processKill,
        .pause = processPause,
        .resume = processResume,
        .isRunning = processIsRunning,
        .list = processList,
        .appExists = processAppExists,
        .killByName = processKillByName,
        .findByName = processFindByName
    };
}

/*----------------------------------------------------------------------*/

/*------------------------------Time Class------------------------------*/

void getSystemTime(Time* self) {
    if (self == null) return; // null 체크

    #ifdef _WIN32
        SYSTEMTIME st;
        GetLocalTime(&st);
        self->year = (uint16_t)st.wYear;
        self->month = (uint8_t)st.wMonth;
        self->day = (uint8_t)st.wDay;
        self->hour = (uint8_t)st.wHour;
        self->minute = (uint8_t)st.wMinute;
        self->second = (uint8_t)st.wSecond;
        self->millisecond = (uint16_t)st.wMilliseconds;
    #else
        struct timespec ts;
        struct tm now;
        clock_gettime(CLOCK_REALTIME, &ts);
        localtime_r(&ts.tv_sec, &now);
        self->year = (uint16_t)now.tm_year + 1900;
        self->month = (uint8_t)now.tm_mon + 1;
        self->day = (uint8_t)now.tm_mday;
        self->hour = (uint8_t)now.tm_hour;
        self->minute = (uint8_t)now.tm_min;
        self->second = (uint8_t)now.tm_sec;
        self->millisecond = (uint16_t)(ts.tv_nsec / 1.0e6);
    #endif
}

static uint8_t daysInMonthFor(uint16_t year, uint8_t month) {
    boolean isLeapYear = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));

    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return isLeapYear ? 29 : 28;
        default:
            return 31;
    }
}

void getTime(Time* self) {
    if (self == null) return;

    self->year = self->year;
    self->month = self->month;
    self->day = self->day;
    self->hour = self->hour;
    self->minute = self->minute;
    self->second = self->second;
    self->millisecond = self->millisecond;
}

void setTime(Time* self, uint16_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t minute, uint8_t second) {
    if (self == null) return;

    self->year = year;
    self->month = month;
    self->day = day;
    self->hour = hour;
    self->minute = minute;
    self->second = second;
    self->millisecond = 0;
}

#ifdef _WIN32
DWORD WINAPI _timRun(LPVOID arg) {
#else
void* _timRun(void* arg) {
#endif
    Time* self = (Time*)arg;
    uint16_t prev = 0;

    if (self == null) return 0;

    #ifdef _WIN32
        SYSTEMTIME initial;
        GetLocalTime(&initial);
        prev = initial.wMilliseconds;
    #else
        struct timespec initial;
        clock_gettime(CLOCK_REALTIME, &initial);
        prev = (uint16_t)(initial.tv_nsec / 1000000L);
    #endif

    while (self->running) {
        uint16_t current;

        #ifdef _WIN32
                SYSTEMTIME st;
                GetLocalTime(&st);
                current = st.wMilliseconds;
        #else
                struct timespec ts;
                clock_gettime(CLOCK_REALTIME, &ts);
                current = (uint16_t)(ts.tv_nsec / 1000000L);
        #endif
                uint16_t elapsed = (current >= prev) ? (current - prev) : (1000 - prev + current);
                prev = current;

        #ifdef _WIN32
                WaitForSingleObject(self->mutex, INFINITE);
        #else
                pthread_mutex_lock(&self->mutex);
        #endif
        self->millisecond += elapsed;
        while (self->millisecond >= 1000) {
            self->millisecond -= 1000;
            self->second++;
            if (self->second >= 60) {
                self->second = 0;
                self->minute++;
            }
            if (self->minute >= 60) {
                self->minute = 0;
                self->hour++;
            }
            if (self->hour >= 24) {
                self->hour = 0;
                self->day++;
                if (self->day > daysInMonthFor(self->year, self->month)) {
                    self->day = 1;
                    self->month++;
                    if (self->month > 12) {
                        self->month = 1;
                        self->year++;
                    }
                }
            }
        }
        #ifdef _WIN32
                ReleaseMutex(self->mutex);
                sleep_ms(1);
        #else
                pthread_mutex_unlock(&self->mutex);
                sleep_ms(1);
        #endif
    }

    return 0;
}

void startTime(Time* self) {
    if (self != null && !self->running) {
        self->running = true;
        #ifdef _WIN32
                self->thread = CreateThread(null, 0, _timRun, self, 0, null);
        #else
                pthread_create(&self->thread, null, _timRun, self);
        #endif
    }
}

void stopTime(Time* self) {
    if (self == null || !self->running) return;

    self->running = false;
    #ifdef _WIN32
        WaitForSingleObject(self->thread, INFINITE);
        CloseHandle(self->thread);
    #else
        pthread_join(self->thread, null);
    #endif
}

Time new_Time(void) {
    Time time;
    #ifdef _WIN32
        time.mutex = CreateMutex(null, FALSE, null);
    #else
        pthread_mutex_init(&time.mutex, null);
    #endif

    time.millisecond = 0;
    time.second = 0;
    time.minute = 0;
    time.hour = 0;
    time.day = 1;
    time.month = 1;
    time.year = 1970;
    time.getSystemTime = getSystemTime;
    time.getTime = getTime;
    time.setTime = setTime;
    time.start = startTime;
    time.stop = stopTime;
    time.running = false;

    return time;
}

/*----------------------------------------------------------------------*/

#define PARSE_INT(TYPE, FUNC, NAME) \
TYPE parse##NAME(const string str, ...) { \
    return str == null ? 0 : (TYPE)FUNC(str, null, 0); \
}

#define PARSE_FLOAT(TYPE, FUNC, NAME) \
TYPE parse##NAME(const string str) { \
    return str == null ? 0 : FUNC(str, null); \
}

PARSE_INT(int8_t, strtol, Byte)
PARSE_INT(int16_t, strtol, Short)
PARSE_INT(int32_t, strtol, Integer)
PARSE_INT(int64_t, strtoll, Long)
PARSE_FLOAT(float, strtof, Float)
PARSE_FLOAT(double, strtod, Double)


#define TOSTRING(TYPE, FORMAT, NAME) \
string toString##NAME(TYPE value) { \
    int required = snprintf(null, 0, FORMAT, value); \
    if (required < 0) return null; \
    size_t size = (size_t)required + 1U; \
    string str; \
    str = (string)malloc(sizeof(char) * size); \
    if (str == null) return null; \
    snprintf(str, size, FORMAT, value); \
    return str; \
}

TOSTRING(int8_t, "%" SCNd8, Byte)
TOSTRING(int16_t, "%" SCNd16, Short)
TOSTRING(int32_t, "%" SCNd32, Integer)
TOSTRING(int64_t, "%" SCNd64, Long)
TOSTRING(float, "%g", Float)
TOSTRING(double, "%g", Double)

#define TOBINARAYSTRING(TYPE, SIZE, NAME) \
string toBinaryString##NAME(TYPE value) { \
    string binaryString = (string)malloc((SIZE + 1) * sizeof(char)); \
    if (binaryString == null) return null; \
    *(binaryString + SIZE) = '\0';\
    uint64_t unsignedValue = (uint64_t)value; \
    uint64_t mask = UINT64_C(1) << (SIZE - 1); \
    for (size_t i = 0; i < SIZE; i++) { \
        *(binaryString + i) = (unsignedValue & mask) ? '1' : '0'; \
        mask >>= 1; \
    } \
    string ptr = binaryString; \
    while (*ptr == '0' && *(ptr + 1) != '\0') ptr++; \
    if(*ptr == '\0'){ \
        ptr = binaryString; \
        *ptr = '0'; \
        *(ptr + 1) = '\0'; \
    } \
    size_t length = strlen(ptr) + 1; \
    string trimmedBinaryString = (string)malloc(length * sizeof(char)); \
    if (trimmedBinaryString == null) { \
        free(binaryString); \
        return null; \
    } \
    memcpy(trimmedBinaryString, ptr, length); \
    free(binaryString); \
    return trimmedBinaryString; \
}

TOBINARAYSTRING(int8_t, 8, Byte)
TOBINARAYSTRING(int16_t, 16, Short)
TOBINARAYSTRING(int32_t, 32, Integer)
TOBINARAYSTRING(int64_t, 64, Long)

#define TOOCTALSTRING(TYPE, FORMAT, NAME) \
string toOctalString##NAME(TYPE value) { \
    int required = snprintf(null, 0, FORMAT, value); \
    if (required < 0) return null; \
    size_t size = (size_t)required + 1U; \
    string str; \
    str = (string)malloc(sizeof(char) * size); \
    if (str == null) return null; \
    snprintf(str, size, FORMAT, value); \
    return str; \
}

TOOCTALSTRING(int8_t, "%" SCNo8, Byte)
TOOCTALSTRING(int16_t, "%" SCNo16, Short)
TOOCTALSTRING(int32_t, "%" SCNo32, Integer)
TOOCTALSTRING(int64_t, "%" SCNo64, Long)

#define TOHEXSTRING(TYPE, FORMAT, NAME) \
string toHexString##NAME(TYPE value) { \
    int required = snprintf(null, 0, FORMAT, value); \
    if (required < 0) return null; \
    size_t size = (size_t)required + 1U; \
    string str; \
    str = (string)malloc(sizeof(char) * size); \
    if (str == null) return null; \
    snprintf(str, size, FORMAT, value); \
    return str; \
}

TOHEXSTRING(int8_t, "%" SCNx8, Byte)
TOHEXSTRING(int16_t, "%" SCNx16, Short)
TOHEXSTRING(int32_t, "%" SCNx32, Integer)
TOHEXSTRING(int64_t, "%" SCNx64, Long)

#define BITCOUNT(TYPE, SIZE, NAME) \
size_t bitCount##NAME(TYPE value) { \
    size_t count = 0; \
    uint64_t unsignedValue = (uint64_t)value; \
    uint64_t mask = SIZE == 64 ? UINT64_MAX : ((UINT64_C(1) << SIZE) - 1); \
    unsignedValue &= mask; \
    while (unsignedValue) { \
        count += unsignedValue & 1U; \
        unsignedValue >>= 1; \
    } \
    return count; \
}

BITCOUNT(int8_t, 8, Byte)
BITCOUNT(int16_t, 16, Short)
BITCOUNT(int32_t, 32, Integer)
BITCOUNT(int64_t, 64, Long)

#define BYTEVALUE(TYPE, NAME) \
int8_t byteValue##NAME(TYPE value) { \
    return (int8_t)value; \
}

BYTEVALUE(int8_t, Byte)
BYTEVALUE(int16_t, Short)
BYTEVALUE(int32_t, Integer)
BYTEVALUE(int64_t, Long)
BYTEVALUE(float, Float)
BYTEVALUE(double, Double)
BYTEVALUE(boolean, Boolean)

#define SHORTVALUE(TYPE, NAME) \
int16_t shortValue##NAME(TYPE value) { \
    return (int16_t)value; \
}

SHORTVALUE(int8_t, Byte)
SHORTVALUE(int16_t, Short)
SHORTVALUE(int32_t, Integer)
SHORTVALUE(int64_t, Long)
SHORTVALUE(float, Float)
SHORTVALUE(double, Double)
SHORTVALUE(boolean, Boolean)

#define INTVALUE(TYPE, NAME) \
int32_t intValue##NAME(TYPE value) { \
    return (int32_t)value; \
}

INTVALUE(int8_t, Byte)
INTVALUE(int16_t, Short)
INTVALUE(int32_t, Integer)
INTVALUE(int64_t, Long)
INTVALUE(float, Float)
INTVALUE(double, Double)
INTVALUE(boolean, Boolean)

#define LONGVALUE(TYPE, NAME) \
int64_t longValue##NAME(TYPE value) { \
    return (int64_t)value; \
}

LONGVALUE(int8_t, Byte)
LONGVALUE(int16_t, Short)
LONGVALUE(int32_t, Integer)
LONGVALUE(int64_t, Long)
LONGVALUE(float, Float)
LONGVALUE(double, Double)
LONGVALUE(boolean, Boolean)

#define FLOATVALUE(TYPE, NAME) \
float floatValue##NAME(TYPE value) { \
    return (float)value; \
}

FLOATVALUE(int8_t, Byte)
FLOATVALUE(int16_t, Short)
FLOATVALUE(int32_t, Integer)
FLOATVALUE(int64_t, Long)
FLOATVALUE(float, Float)
FLOATVALUE(double, Double)
FLOATVALUE(boolean, Boolean)

#define DOUBLEVALUE(TYPE, NAME) \
double doubleValue##NAME(TYPE value) { \
    return (double)value; \
}

DOUBLEVALUE(int8_t, Byte)
DOUBLEVALUE(int16_t, Short)
DOUBLEVALUE(int32_t, Integer)
DOUBLEVALUE(int64_t, Long)
DOUBLEVALUE(float, Float)
DOUBLEVALUE(double, Double)
DOUBLEVALUE(boolean, Boolean)

#define BOOLEANVALUE(TYPE, NAME) \
boolean booleanValue##NAME(TYPE value) { \
    return value ? true : false; \
}

BOOLEANVALUE(int8_t, Byte)
BOOLEANVALUE(int16_t, Short)
BOOLEANVALUE(int32_t, Integer)
BOOLEANVALUE(int64_t, Long)
BOOLEANVALUE(float, Float)
BOOLEANVALUE(double, Double)
BOOLEANVALUE(boolean, Boolean)

#define MAX(TYPE, NAME) \
TYPE max##NAME(TYPE x, TYPE y) { \
    return x > y ? x : y; \
}

MAX(int8_t, Byte)
MAX(int16_t, Short)
MAX(int32_t, Integer)
MAX(int64_t, Long)
MAX(float, Float)
MAX(double, Double)

#define MIN(TYPE, NAME) \
TYPE min##NAME(TYPE x, TYPE y) { \
    return x < y ? x : y; \
}

MIN(int8_t, Byte)
MIN(int16_t, Short)
MIN(int32_t, Integer)
MIN(int64_t, Long)
MIN(float, Float)
MIN(double, Double)

#define EQUALS(TYPE, NAME) \
boolean equals##NAME(TYPE x, TYPE y) { \
    return x == y; \
}

EQUALS(char, Character)
EQUALS(int8_t, Byte)
EQUALS(int16_t, Short)
EQUALS(int32_t, Integer)
EQUALS(int64_t, Long)
EQUALS(float, Float)
EQUALS(double, Double)
EQUALS(boolean, Boolean)

/*-----------------------------------String Class-----------------------------------*/
char charAt(const string str, size_t index) {
    if (str == null || index >= strlen(str)) return '\0';
    return *(str + index);
}

boolean equals(const string str1, const string str2) {
    if (str1 == null || str2 == null) return str1 == str2;
    return !strcmp(str1, str2);
}

size_t length(const string str) {
    if (str == null) return 0;
    return strlen(str);
}

string replace(const string str, char oldChar, char newChar) {
    if (str == null) return null;

    size_t length = strlen(str);
    string replaced = (string)malloc(sizeof(char) * (length + 1));
    if (replaced == null) return null;

    for (size_t i = 0; i < length; i++) *(replaced + i) = *(str + i) == oldChar ? newChar : *(str + i);
    *(replaced + length) = '\0';
    return replaced;
}

string substring(const string str, size_t beginIndex, size_t endIndex) {
    if (str == null) return null;

    size_t strLength = strlen(str);
    if (beginIndex > strLength) beginIndex = strLength;
    if (endIndex > strLength) endIndex = strLength;
    if (endIndex < beginIndex) endIndex = beginIndex;

    size_t length = endIndex - beginIndex;
    string substr = (string)malloc(sizeof(char) * (length + 1));
    if (substr == null) return null;

    memcpy(substr, str + beginIndex, length);
    *(substr + length) = '\0';
    return substr;
}

string stoLowerCase(const string str) {
    if (str == null) return null;

    size_t length = strlen(str);
    string lower = (string)malloc(sizeof(char) * (length + 1));
    if (lower == null) return null;

    for (size_t i = 0; i < length; i++) {
        char c = *(str + i);
        *(lower + i) = (c >= 'A' && c <= 'Z') ? (char)(c | 0x20) : c;
    }
    *(lower + length) = '\0';
    return lower;
}

string stoUpperCase(const string str) {
    if (str == null) return null;

    size_t length = strlen(str);
    string upper = (string)malloc(sizeof(char) * (length + 1));
    if (upper == null) return null;

    for (size_t i = 0; i < length; i++) {
        char c = *(str + i);
        *(upper + i) = (c >= 'a' && c <= 'z') ? (char)(c & 0xDF) : c;
    }
    *(upper + length) = '\0';
    return upper;
}

string trim(const string str, ...){
    if (!str) return null;

    size_t length = strlen(str);
    size_t beginIndex = 0;
    size_t endIndex = length;

    unsigned char *criteria = (unsigned char*)calloc(256, 1);
    if (!criteria) return null;

    va_list args;
    va_start(args, str);

    int hasArgs = 0;
    int c;
    while ((c = va_arg(args, int)) != 0) {
        criteria[(unsigned char)c] = 1;
        hasArgs = 1;
    }
    va_end(args);

    if (!hasArgs) {
        criteria[' ']  = 1;
        criteria['\t'] = 1;
        criteria['\n'] = 1;
        criteria['\r'] = 1;
    }

    while (beginIndex < length &&
           criteria[(unsigned char)str[beginIndex]]) {
        beginIndex++;
    }

    while (endIndex > beginIndex &&
           criteria[(unsigned char)str[endIndex - 1]]) {
        endIndex--;
    }

    size_t size = endIndex - beginIndex;

    string trimmed = (string)malloc(size + 1);
    if (!trimmed) {
        free(criteria);
        return null;
    }

    if (size > 0)
        memcpy(trimmed, str + beginIndex, size);

    trimmed[size] = '\0';

    free(criteria);
    return trimmed;
}

string* split(const string str, ...) {
    if (!str) return null;

    unsigned char criteria[256];
    memset(criteria, 0, sizeof(criteria));

    va_list args;
    va_start(args, str);

    int hasArgs = 0;
    int c;
    while ((c = va_arg(args, int)) != 0) {
        *(criteria + (unsigned char)c) = 1;
        hasArgs = 1;
    }
    va_end(args);

    if (!hasArgs) {
        *(criteria + ' ')  = 1;
        *(criteria + '\t') = 1;
        *(criteria + '\n') = 1;
        *(criteria + '\r') = 1;
    }

    size_t count = 0;
    size_t i = 0;
    size_t len = strlen(str);

    /* 토큰 개수 계산 */
    while (i < len) {
        while (i < len && *(criteria + (unsigned char)*(str + i)))
            i++;

        if (i < len) {
            count++;
            while (i < len && !*(criteria + (unsigned char)*(str + i)))
                i++;
        }
    }

    string* result = (string*)malloc(sizeof(string) * (count + 1));
    if (!result) return null;

    size_t index = 0;
    i = 0;

    /* 실제 분리 */
    while (i < len) {
        while (i < len && *(criteria + (unsigned char)*(str + i)))
            i++;

        if (i < len) {
            size_t start = i;

            while (i < len && !*(criteria + (unsigned char)*(str + i)))
                i++;

            size_t size = i - start;
            *(result + index) = (string)malloc(size + 1);

            if (!*(result + index)) {
                for (size_t j = 0; j < index; j++)
                    free(*(result + j));
                free(result);
                return null;
            }

            memcpy(*(result + index), str + start, size);
            *(*(result + index) + size) = '\0';
            index++;
        }
    }

    *(result + index) = null;
    return result;
}

/*----------------------------------------------------------------------------------*/

/*---------------------------------Character Class---------------------------------*/
boolean isLetter(const char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

boolean isDigit(const char c) {
    return c >= '0' && c <= '9';
}

boolean isLetterOrDigit(const char c) {
    return isLetter(c) || isDigit(c);
}

boolean isLowerCase(const char c) {
    return c >= 'a' && c <= 'z';
}

boolean isUpperCase(const char c) {
    return c >= 'A' && c <= 'Z';
}

char ctoLowerCase(const char c) {
    return isUpperCase(c) ? c | 0x20 : c;
}

char ctoUpperCase(const char c) {
    return isLowerCase(c) ? (char)(c & 0xDF) : c;
}

boolean isAlphabetic(const char c) {
    return isLetter(c);
}

boolean isSpaceChar(const char c) {
    return c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f' || c == '\v';
}

boolean isDefined(const char c) {
    return c != '\0';
}
/*---------------------------------------------------------------------------------*/

/*---------------------------------Boolean Class---------------------------------*/
int32_t compare(const boolean x, const boolean y) {
    return (int32_t)x - (int32_t)y;
}

boolean logicalAnd(const boolean x, const boolean y) {
    return x & y;
}

boolean logicalOr(const boolean x, const boolean y) {
    return x | y;
}

boolean logicalNot(const boolean x) {
    return !x;
}

boolean logicalXor(const boolean x, const boolean y) {
    return x ^ y;
}

boolean parseBoolean(const string str) {
    if (str == null) return false;

    return ((str[0] | 0x20) == 't' &&
            (str[1] | 0x20) == 'r' &&
            (str[2] | 0x20) == 'u' &&
            (str[3] | 0x20) == 'e' &&
            str[4] == '\0') ? true : false;
}

boolean valueOfBoolean(const boolean value) {
    return value;
}
/*-------------------------------------------------------------------------------*/

/*---------------------------------  new  ---------------------------------*/

_String String = {
    .charAt = charAt,
    .equals = equals,
    .length = length,
    .replace = replace,
    .substring = substring,
    .toLowerCase = stoLowerCase,
    .toUpperCase = stoUpperCase,
    .trim = trim,
    .split = split
};

_Character Character = {
    .equals = equalsCharacter,
    .isLetter = isLetter,
    .isDigit = isDigit,
    .isLetterOrDigit = isLetterOrDigit,
    .isLowerCase = isLowerCase,
    .isUpperCase = isUpperCase,
    .toLowerCase = ctoLowerCase,
    .toUpperCase = ctoUpperCase,
    .isAlphabetic = isAlphabetic,
    .isSpaceChar = isSpaceChar,
    .isDefined = isDefined
};

_Boolean Boolean = {
    .equals = equalsBoolean,
    .logicalAnd = logicalAnd,
    .logicalOr = logicalOr,
    .logicalNot = logicalNot,
    .logicalXor = logicalXor,
    .parseBoolean = parseBoolean,
    .valueOf = valueOfBoolean,
    .compare = compare
};

_Byte Byte = {
    .parse = parseByte,
    .toString = toStringByte,
    .toBinaryString = toBinaryStringByte,
    .toOctalString = toOctalStringByte,
    .toHexString = toHexStringByte,
    .bitCount = bitCountByte,
    .byteValue = byteValueByte,
    .shortValue = shortValueByte,
    .intValue = intValueByte,
    .longValue = longValueByte,
    .floatValue = floatValueByte,
    .doubleValue = doubleValueByte,
    .booleanValue = booleanValueByte,
    .max = maxByte,
    .min = minByte
};

_Short Short = {
    .parse = parseShort,
    .toString = toStringShort,
    .toBinaryString = toBinaryStringShort,
    .toOctalString = toOctalStringShort,
    .toHexString = toHexStringShort,
    .byteValue = byteValueShort,
    .shortValue = shortValueShort,
    .intValue = intValueShort,
    .longValue = longValueShort,
    .floatValue = floatValueShort,
    .doubleValue = doubleValueShort,
    .booleanValue = booleanValueShort,
    .max = maxShort,
    .min = minShort
};

_Integer Integer = {
    .parse = parseInteger,
    .toString = toStringInteger,
    .toBinaryString = toBinaryStringInteger,
    .toOctalString = toOctalStringInteger,
    .toHexString = toHexStringInteger,
    .bitCount = bitCountInteger,
    .byteValue = byteValueInteger,
    .shortValue = shortValueInteger,
    .intValue = intValueInteger,
    .longValue = longValueInteger,
    .floatValue = floatValueInteger,
    .doubleValue = doubleValueInteger,
    .booleanValue = booleanValueInteger,
    .max = maxInteger,
    .min = minInteger
};

_Long Long = {
    .parse = parseLong,
    .toString = toStringLong,
    .toBinaryString = toBinaryStringLong,
    .toOctalString = toOctalStringLong,
    .toHexString = toHexStringLong,
    .byteValue = byteValueLong,
    .shortValue = shortValueLong,
    .intValue = intValueLong,
    .longValue = longValueLong,
    .floatValue = floatValueLong,
    .doubleValue = doubleValueLong,
    .booleanValue = booleanValueLong,
    .max = maxLong,
    .min = minLong
};

_Float Float = {
    .parse = parseFloat,
    .toString = toStringFloat,
    .byteValue = byteValueFloat,
    .shortValue = shortValueFloat,
    .intValue = intValueFloat,
    .longValue = longValueFloat,
    .floatValue = floatValueFloat,
    .doubleValue = doubleValueFloat,
    .booleanValue = booleanValueFloat,
    .max = maxFloat,
    .min = minFloat
};

_Double Double = {
    .parse = parseDouble,
    .toString = toStringDouble,
    .byteValue = byteValueDouble,
    .shortValue = shortValueDouble,
    .intValue = intValueDouble,
    .longValue = longValueDouble,
    .floatValue = floatValueDouble,
    .doubleValue = doubleValueDouble,
    .booleanValue = booleanValueDouble,
    .max = maxDouble,
    .min = minDouble
};
/*-------------------------------------------------------------------------*/
