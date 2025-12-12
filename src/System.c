#include "main.h"
#include "System.h"

void print(const string format, ...) {
    va_list ap;
    char buf[4096];
    va_start(ap, format);
    vsprintf(buf, format, ap);
    va_end(ap);
    fprintf(stdout, "%s", buf);
}

void println(const string format, ...) {
    va_list ap;
    char buf[4096];
    va_start(ap, format);
    vsprintf(buf, format, ap);
    va_end(ap);
    fprintf(stdout, "%s\n", buf);
}

SYSTEM System = {
    .out = {
        .printf = print,
        .println = println
    }
};

static int fileScanf(File* self, const string format, ...) {
    va_list ap;
    va_start(ap, format);
    int result = vfscanf(self->file, format, ap);
    va_end(ap);
    return result;
}

static int filePrintf(File* self, const string format, ...) {
    va_list ap;
    va_start(ap, format);
    int result = vfprintf(self->file, format, ap);
    va_end(ap);
    return result;
}

static int filePrintln(File* self, const string format, ...) {
    va_list ap;
    va_start(ap, format);
    int result = vfprintf(self->file, format, ap);
    va_end(ap);
    fprintf(self->file, "\n");
    return result;
}

static int fileOpen(File* self, const string name, const string mode) {
    self->file = fopen(name, mode);
    return self->file == NULL ? 1 : 0;
}

static void fileClose(File* self) {
    fclose(self->file);
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

int processStart(Process* self, const string name) {
    #ifdef _WIN32
        STARTUPINFO si;
        PROCESS_INFORMATION pi;
        ZeroMemory(&si, sizeof(si));
        si.cb = sizeof(si);
        ZeroMemory(&pi, sizeof(pi));
        if (!CreateProcess(NULL, (LPSTR)name, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
            return -1;
        }
        self->pid = pi;
        return 0;
    #else
        pid_t pid = fork();
        if (pid < 0) {
            return -1;
        } else if (pid == 0) {
            execl("/bin/sh", "sh", "-c", name, (char *)NULL);
            exit(0);
        } else {
            self->pid = pid;
            return 0;
        }
    #endif
}

int processKill(Process* self) {
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
    #ifdef _WIN32
        return SuspendThread(self->pid.hThread) == (DWORD)-1 ? -1 : 0;
    #else
        return kill(self->pid, SIGSTOP) == 0 ? 0 : -1;
    #endif
}

int processResume(Process* self) {
    #ifdef _WIN32
        return ResumeThread(self->pid.hThread) == (DWORD)-1 ? -1 : 0;
    #else
        return kill(self->pid, SIGCONT) == 0 ? 0 : -1;
    #endif
}

int processIsRunning(Process* self) {
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
        if (fp == NULL) {
            return;
        }

        char line[256];
        while (fgets(line, sizeof(line), fp) != NULL) {
            printf("%s", line);
        }

        pclose(fp);
        return;
    #endif
}

int processAppExists(Process* self, const string name) {
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
        if (fp == NULL) {
            return 0;
        }

        char line[256];
        while (fgets(line, sizeof(line), fp) != NULL) {
            if (strstr(line, name) != NULL) {
                pclose(fp);
                return 1;
            }
        }

        pclose(fp);
        return 0;
    #endif
}

int processKillByName(Process* self, const string name) {
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
                if (hProcess != NULL) {
                    TerminateProcess(hProcess, 0);
                    CloseHandle(hProcess);
                }
            }
        } while (Process32Next(hSnapshot, &pe));

        CloseHandle(hSnapshot);
        return 0;
    #else
        char command[256];
        snprintf(command, sizeof(command), "pkill %s", name);
        return system(command);
    #endif
}

#ifdef _WIN32
    DWORD processFindByName(Process* self, const string name) {
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
        FILE* fp = popen("ps -e", "r");
        if (fp == NULL) {
            return 0;
        }

        char line[256];
        pid_t pid = 0;
        while (fgets(line, sizeof(line), fp) != NULL) {
            if (strstr(line, name) != NULL) {
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
    if (self == NULL) return; // NULL 체크

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

void getTime(Time* self) {
    self->year = self->year;
    self->month = self->month;
    self->day = self->day;
    self->hour = self->hour;
    self->minute = self->minute;
    self->second = self->second;
    self->millisecond = self->millisecond;
}

void setTime(Time* self, uint16_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t minute, uint8_t second) {
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
    boolean isLeapYear;
    uint8_t daysInMonth;
    uint16_t prev = 0;
    
    isLeapYear = (self->year % 4 == 0 && (self->year % 100 != 0 || self->year % 400 == 0));
    switch (self->month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12: daysInMonth = 31; break;
        case 4: case 6: case 9: case 11: daysInMonth = 30; break;
        case 2: daysInMonth = isLeapYear ? 29 : 28; break;
        default: daysInMonth = 0; break;
    }

    while (self->running) {
        uint16_t current;

        #ifdef _WIN32
                SYSTEMTIME st;
                GetLocalTime(&st);
                current = st.wMilliseconds;
        #else
                struct timespec ts;
                clock_gettime(CLOCK_REALTIME, &ts);
                current = ts.tv_nsec / 1.0e6;
        #endif
                uint16_t elapsed = (current >= prev) ? (current - prev) : (1000 - prev + current);
                prev = current;

        #ifdef _WIN32
                WaitForSingleObject(&self->mutex, INFINITE);
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
                if (self->day > daysInMonth) {
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
                ReleaseMutex(&self->mutex);
                sleep(1);
        #else
                pthread_mutex_unlock(&self->mutex);
                sleep(1);
        #endif
    }

    return 0;
}

void startTime(Time* self) {
    if (!self->running) {
        self->running = true;
        #ifdef _WIN32
                self->thread = CreateThread(NULL, 0, _timRun, self, 0, NULL);
        #else
                pthread_create(&self->thread, NULL, _timRun, self);
        #endif
    }
}

void stopTime(Time* self) {
        self->running = false;
    #ifdef _WIN32
        WaitForSingleObject(self->thread, INFINITE);
        CloseHandle(self->thread);
    #else
        pthread_join(self->thread, NULL);
    #endif
}

Time new_Time(void) {
    Time time;
    #ifdef _WIN32
        CreateMutex(NULL, FALSE, NULL);
    #else
        pthread_mutex_init(&time.mutex, NULL);
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
    int32_t radix = 10; \
    va_list ap; \
    va_start(ap, str); \
    radix = va_arg(ap, int32_t); \
    va_end(ap); \
    return (TYPE)FUNC(str, null, radix); \
}

#define PARSE_FLOAT(TYPE, FUNC, NAME) \
TYPE parse##NAME(const string str) { \
    return FUNC(str, null); \
}

PARSE_INT(int8_t, strtol, Byte)
PARSE_INT(int16_t, strtol, Short)
PARSE_INT(int32_t, strtol, Integer)
PARSE_INT(int64_t, strtoll, Long)
PARSE_FLOAT(float, strtof, Float)
PARSE_FLOAT(double, strtod, Double)


#define TOSTRING(TYPE, FORMAT, NAME) \
string toString##NAME(TYPE value) { \
    string str; \
    size_t size =  snprintf(NULL, 0, FORMAT, value) + 1; \
    str = (string)malloc(sizeof(char) * size); \
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
    *(binaryString + SIZE) = '\0';\
    TYPE mask = (TYPE)1 << (SIZE - 1); \
    for (size_t i = 0; i < SIZE; i++) { \
        *(binaryString + i) = (value & mask) ? '1' : '0'; \
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
    string str; \
    size_t size =  snprintf(NULL, 0, FORMAT, value) + 1; \
    str = (string)malloc(sizeof(char) * size); \
    snprintf(str, size, FORMAT, value); \
    return str; \
}

TOOCTALSTRING(int8_t, "%" SCNo8, Byte)
TOOCTALSTRING(int16_t, "%" SCNo16, Short)
TOOCTALSTRING(int32_t, "%" SCNo32, Integer)
TOOCTALSTRING(int64_t, "%" SCNo64, Long)

#define TOHEXSTRING(TYPE, FORMAT, NAME) \
string toHexString##NAME(TYPE value) { \
    string str; \
    size_t size =  snprintf(NULL, 0, FORMAT, value) + 1; \
    str = (string)malloc(sizeof(char) * size); \
    snprintf(str, size, FORMAT, value); \
    return str; \
}

TOHEXSTRING(int8_t, "%" SCNx8, Byte)
TOHEXSTRING(int16_t, "%" SCNx16, Short)
TOHEXSTRING(int32_t, "%" SCNx32, Integer)
TOHEXSTRING(int64_t, "%" SCNx64, Long)

#define BITCOUNT(TYPE, NAME) \
size_t bitCount##NAME(TYPE value) { \
    size_t count = 0; \
    while (value) { \
        count += value & 1; \
        value >>= 1; \
    } \
    return count; \
}

BITCOUNT(int8_t, Byte)
BITCOUNT(int16_t, Short)
BITCOUNT(int32_t, Integer)
BITCOUNT(int64_t, Long)

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
    return *(str + index);
}

boolean equals(const string str1, const string str2) {
    return !strcmp(str1, str2);
}

size_t length(const string str) {
    return strlen(str);
}

string replace(const string str, char oldChar, char newChar) {
    size_t length = strlen(str);
    string replaced = (string)malloc(sizeof(char) * (length + 1));
    for (size_t i = 0; i < length; i++) *(replaced + i) = *(str + i) == oldChar ? newChar : *(str + i);
    *(replaced + length) = '\0';
    return replaced;
}

string substring(const string str, size_t beginIndex, size_t endIndex) {
    size_t length = endIndex - beginIndex;
    string substr = (string)malloc(sizeof(char) * (length + 1));
    memcpy(substr, str + beginIndex, length);
    *(substr + length) = '\0';
    return substr;
}

string stoLowerCase(const string str) {
    size_t length = strlen(str);
    string lower = (string)malloc(sizeof(char) * (length + 1));
    for (size_t i = 0; i < length; i++) *(lower + i) = *(str + i) | 0x20;
    *(lower + length) = '\0';
    return lower;
}

string stoUpperCase(const string str) {
    size_t length = strlen(str);
    string upper = (string)malloc(sizeof(char) * (length + 1));
    for (size_t i = 0; i < length; i++) *(upper + i) = *(str + i) & 0xDF;
    *(upper + length) = '\0';
    return upper;
}

string trim(const string str, ...) {
    size_t length = strlen(str);
    size_t beginIndex = 0;
    size_t endIndex = length - 1;
    va_list args;
    int hasArgs = 0;
    char c;
    char *criteria = (char*)malloc(sizeof(char));
    
    if (criteria == NULL) return NULL;
    va_start(args, str); 
    while ((c = (char)va_arg(args, int)) != '\0') {
        criteria = (char*)realloc(criteria, (unsigned char)c + 1);
        if (criteria == NULL) {
            va_end(args);
            return NULL;
        }
        criteria[(unsigned char)c] = 1;
        hasArgs = 1;
    }
    if (!hasArgs) {
        criteria[' '] = 1;
        criteria['\t'] = 1;
        criteria['\n'] = 1;
        criteria['\r'] = 1;
    }
    while (criteria[(unsigned char)*(str + beginIndex)]) beginIndex++;
    while (criteria[(unsigned char)*(str + endIndex)]) endIndex--;
    va_end(args);
    size_t size = (endIndex >= beginIndex) ? endIndex - beginIndex + 1 : 0;
    string trimmed = (string)malloc(sizeof(char) * (size + 1));
    if (trimmed == NULL) {
        free(criteria);
        return NULL;
    }
    if (size > 0) memcpy(trimmed, str + beginIndex, size);
    *(trimmed + size) = '\0';

    free(criteria);
    return trimmed;
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
    return isLowerCase(c) ? c & 0xDF : c;
}

boolean isAlphabetic(const char c) {
    return isLetter(c) || isDigit(c);
}

boolean isSpaceChar(const char c) {
    return !(c ^ ' ');
}

boolean isDefined(const char c) {
    return (c ^ '\0');
}
/*---------------------------------------------------------------------------------*/

/*---------------------------------Boolean Class---------------------------------*/
int32_t compare(const boolean x, const boolean y) {
    return x & y;
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
    return !(((*(str+0)|0x20)^'t') ^ ((*(str+1)|0x20)^'r') ^ ((*(str+2)|0x20)^'u') ^ ((*(str+3)|0x20)^'e')) ? true : false;
}

boolean valueOfBoolean(const boolean value) {
    return value;
}
/*-------------------------------------------------------------------------------*/

/*---------------------------------  new  ---------------------------------*/
String new_String(const string value) {
    return (String) {
        .value = value,
        .charAt = charAt,
        .equals = equals,
        .length = length,
        .replace = replace,
        .substring = substring,
        .toLowerCase = stoLowerCase,
        .toUpperCase = stoUpperCase,
        .trim = trim
    };
}

Character new_Character(const char value) {
    return (Character) {
        .value = value,
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
}

Boolean new_Boolean(const boolean value) {
    return (Boolean) {
        .value = value,
        .equals = equalsBoolean,
        .logicalAnd = logicalAnd,
        .logicalOr = logicalOr,
        .logicalNot = logicalNot,
        .logicalXor = logicalXor,
        .parseBoolean = parseBoolean,
        .valueOf = valueOfBoolean,
        .compare = compare
    };
}

Byte new_Byte(const int8_t value) {
    return (Byte) {
        .value = value,
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
}

Short new_Short(const int16_t value) {
    return (Short) {
        .value = value,
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
}

Integer new_Integer(const int32_t value) {
    return (Integer) {
        .value = value,
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
}

Long new_Long(const int64_t value) {
    return (Long) {
        .value = value,
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
}

Float new_Float(const float value) {
    return (Float) {
        .value = value,
        .parse = parseFloat,
        .toString = toStringFloat,
        .byteValue = byteValueFloat,
        .shortValue = shortValueFloat,
        .intValue = intValueFloat,
        .longValue = longValueFloat,
        .floatValue = floatValueFloat,
        .doubleValue = doubleValueFloat,
        .booleanValue = booleanValueFloat
    };
}

Double new_Double(const double value) {
    return (Double) {
        .value = value,
        .parse = parseDouble,
        .toString = toStringDouble,
        .byteValue = byteValueDouble,
        .shortValue = shortValueDouble,
        .intValue = intValueDouble,
        .longValue = longValueDouble,
        .floatValue = floatValueDouble,
        .doubleValue = doubleValueDouble,
        .booleanValue = booleanValueDouble
    };
}
/*-------------------------------------------------------------------------*/ 