#include "main.h"

#ifndef __CONSOLE_H
#define __CONSOLE_H

typedef int32_t ColorType;

#ifdef _WIN32  
    #define BLACK       0
    #define DARKBLUE    1
    #define DARKGREEN   2
    #define DARKCYAN    3
    #define DARKRED     4
    #define DARKMAGENTA 5
    #define DARKYELLOW  6
    #define GRAY        7
    #define DARKGRAY    8
    #define BLUE        9
    #define GREEN       10
    #define CYAN        11
    #define RED         12
    #define MAGENTA     13
    #define YELLOW      14
    #define WHITE       15
    #define RESET       15
#else
    #define BLACK       30
    #define DARKBLUE    34
    #define DARKGREEN   32
    #define DARKCYAN    36
    #define DARKRED     31
    #define DARKMAGENTA 35
    #define DARKYELLOW  33
    #define GRAY        37
    #define DARKGRAY    90
    #define BLUE        94
    #define GREEN       92
    #define CYAN        96
    #define RED         91
    #define MAGENTA     95
    #define YELLOW      93
    #define WHITE       97
    #define RESET       0
#endif

#pragma pack(push, 1)
/**
 * @struct Console
 * @brief Console structure for handling console input and output.
 */
typedef struct Console{
    /**
     * @brief Clears the console screen.
     * @return void
     */
    void (*clear)(void);
    /**
     * @brief Sets the console text color.
     * @param color Color to set the text to.
     * @return void
     */
    void (*setTextColor)(ColorType);
    /**
     * @brief Sets the console background color.
     * @param color Color to set the background to.
     * @return void
     */
    void (*setBackgroundColor)(ColorType);
    /**
     * @brief Resets the console text and background color.
     * @return void
     */
    void (*resetColor)(void);
    /**
     * @brief Sets the console cursor position.
     * @param x X-coordinate of the cursor.
     * @param y Y-coordinate of the cursor.
     * @return void
     */
    void (*setCursorPos)(int, int);
    /**
     * @brief Sets the console cursor visibility.
     * @param visible Visibility of the cursor.
     * @return void
     */
    void (*setCursorVisibility)(boolean);
    /**
     * @brief Sets the console window size.
     * @param width Width of the window.
     * @param height Height of the window.
     * @return void
     */
    void (*setWindowSize)(int, int);
    /**
     * @brief Sets the console window title.
     * @param title Title of the window.
     * @return void
     */
    void (*setWindowTitle)(const string);
    /**
     * @brief Prints a formatted string to the console.
     * @param format Format string.
     * @param ... Arguments to format.
     * @return void
     */
    void (*printfXY)(int, int, const string, ...);
    /**
     * @brief Prints a formatted string to the console with a newline.
     * @param format Format string.
     * @param ... Arguments to format.
     * @return void
     */
    void (*printlnXY)(int, int, const string, ...);
    /**
     * @brief Checks if a key has been pressed.
     * @return 1 if a key has been pressed, 0 otherwise.
     */
    int (*kbhit)(void);
}Console;
#pragma pack(pop)

/**
 * @brief Creates a new console instance.
 * @return A new Console instance.
 */
Console new_Console(void);

#endif