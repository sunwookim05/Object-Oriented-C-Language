#include "console.h"

void clear() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void setTextColor(ColorType color) {
    #ifdef _WIN32
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        GetConsoleScreenBufferInfo(hConsole, &csbi);
        SetConsoleTextAttribute(hConsole, (csbi.wAttributes & 0xF0) | color);
    #else
        printf("\x1b[%dm", color);
    #endif
}

void setBackgroundColor(ColorType color) {
    #ifdef _WIN32
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        GetConsoleScreenBufferInfo(hConsole, &csbi);
        SetConsoleTextAttribute(hConsole, (csbi.wAttributes & 0x0F) | (color << 4));
    #else
        printf("\x1b[%dm", color + 10);
    #endif
}

void resetColor() {
    #ifdef _WIN32
        setTextColor(WHITE);
        setBackgroundColor(BLACK);
    #else
        printf("\x1b[0m");
    #endif
}

void setCursorPos(int x, int y) {
    #ifdef _WIN32
        COORD coord;
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    #else
        printf("\033[%d;%dH", y, x);
    #endif
}

void setCursorVisibility(boolean visible) {
    #ifdef _WIN32
        CONSOLE_CURSOR_INFO cursorInfo;
        GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
        cursorInfo.bVisible = visible;
        SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
    #else
        printf("\e[?25%c", visible ? 'h' : 'l');
    #endif
}

void setWindowSize(int width, int height) {
    #ifdef _WIN32
        char command[32];
        snprintf(command, sizeof(command), "mode con: cols=%d lines=%d", width, height);
        system(command);
    #else
        printf("\e[8;%d;%dt", height, width);
    #endif
}

void setWindowTitle(const string title) {
    #ifdef _WIN32
        SetConsoleTitle(title);
    #else
        printf("\033]0;%s\007", title);
    #endif
}

void printfXY(int x, int y, const string format, ...) {
    va_list ap;
    char buf[4096];
    va_start(ap, format);
    vsprintf(buf, format, ap);
    va_end(ap);
    setCursorPos(x, y);
    fprintf(stdout, "%s", buf);
}

void printlnXY(int x, int y, const string format, ...) {
    va_list ap;
    char buf[4096];
    va_start(ap, format);
    vsprintf(buf, format, ap);
    va_end(ap);
    setCursorPos(x, y);
    fprintf(stdout, "%s\n", buf);
}

#ifndef _WIN32
    int kbhit() {
        struct termios oldt, newt;
        int oldf;
        char ch;
        int byteswaiting;

        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO); // Disable canonical mode and echo
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
        oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
        fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

        byteswaiting = read(STDIN_FILENO, &ch, 1);
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
        fcntl(STDIN_FILENO, F_SETFL, oldf);

        if (byteswaiting == 1) {
            return ch;
        }
        return 0; // No input
    }
#endif

Console new_Console(void) {
    return (Console){
        .clear = clear,
        .setTextColor = setTextColor,
        .setBackgroundColor = setBackgroundColor,
        .resetColor = resetColor,
        .setCursorPos = setCursorPos,
        .setCursorVisibility = setCursorVisibility,
        .setWindowSize = setWindowSize,
        .setWindowTitle = setWindowTitle,
        .printfXY = printfXY,
        .printlnXY = printlnXY,
        .kbhit = kbhit
    };
} 