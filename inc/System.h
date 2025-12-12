#include "main.h"

#ifndef __SYSTEM_H
#define __SYSTEM_H

struct __stdin_t;

#pragma pack(push, 1)
/**
 * @struct SYSTEM
 * @brief The System class contains several useful class fields and methods.
 * It cannot be instantiated.
 *
 * Among the facilities provided by the System class are standard input,
 * standard output, and error output streams; access to externally defined
 * properties and environment variables; a means of loading files and libraries;
 * and a utility method for quickly copying a portion of an array.
 *
 * @since 1.0
 */
typedef struct SYSTEM{
    struct stdout_t{
        /**
         * @brief System out print function.
         * @param format Format string.
         * @param ... Additional arguments.
         * @return void.
         */
        void (*printf)(const string, ...);
        /** 
         * @brief System out println function.
         * @param format Format string.
         * @param ... Additional arguments.
         * @return void.
         */
        void (*println)(const string, ...);
    } out;
    struct __stdin_t{
        /**
         * @brief System in read function.
         * @return Returns an integer value read from the input.
         */
        int32_t (*read)();
    } in;
} SYSTEM;
#pragma pack(pop)

#pragma pack(push, 1)
/**
 * @struct File
 * @brief Represents a file object with utility functions.
 */
typedef struct __FILE{
    FILE* file; ///< The underlying file object.
    /** 
     * @brief Reads a line from the file.
     * @param f The file object.
     * @return The line read from the file.
     */
    int (*scanf)(struct __FILE*, const string, ...); ///< The scanf function.
    /**
     * @brief Reads a line from the file.
     * @param f The file object.
     * @return The line read from the file.
     */
    int (*printf)(struct __FILE*, const string, ...); ///< The printf function.
    /**
     * @brief Reads a line from the file.
     * @param f The file object.
     * @return The line read from the file.
     */
    int (*println)(struct __FILE*, const string, ...); ///< The println function.
    /**
     * @brief Opens the file.
     * @param f The file object.
     * @param name The file name.
     * @param mode The file mode.
     * @return The file object.
     */
    int (*open)(struct __FILE*, const string, const string); ///< The open function.
    /**
     * @brief Closes the file.
     * @param f The file object.
     * @return void.
     */
    void (*close)(struct __FILE*);
}File;
#pragma pack(pop)

/**
 * @brief Constructs a new {@code File} object.
 * @param name The file name.
 * @param mode The file mode.
 * @return The new {@code File} object.
 */
File new_File(const string, const string);


    #ifdef _WIN32
        typedef PROCESS_INFORMATION PROCESS;
    #else
        typedef pid_t PROCESS;
    #endif


#pragma pack(push, 1)
/**
 * @struct Process
 * @brief Represents a process object with utility functions.
 */
typedef struct Process{
    PROCESS pid; //< The process ID.

    /**
     * @brief Starts a new process.
     * @param process The process object.
     * @param name The process name.
     * @return The process object.
    */
    int (*start)(struct Process*, const string);
    /**
     * @brief Kills the process.
     * @param process The process object.
     * @return The process object.
    */
    int (*kill)(struct Process*);
    /**
     * @brief Pauses the process.
     * @param process The process object.
     * @return The process object.
    */
    int (*pause)(struct Process*);
    /**
     * @brief Resumes the process.
     * @param process The process object.
     * @return The process object.
    */
    int (*resume)(struct Process*);
    /**
     * @brief Checks if the process is running.
     * @param process The process object.
     * @return 1 if running, 0 otherwise.
    */
    int (*isRunning)(struct Process*);
    /**
     * @brief Lists all running processes.
     * @param process The process object.
     * @return void.
    */
    void (*list)(struct Process*);
    /**
     * @brief Checks if an application exists.
     * @param process The process object.
     * @param name The application name.
     * @return 1 if exists, 0 otherwise.
    */
    int (*appExists)(struct Process*, const string);
    /**
     * @brief Kills a process by name.
     * @param process The process object.
     * @param name The process name.
     * @return 0 on success, -1 on failure.
    */
    int (*killByName)(struct Process*, const string);

    #ifdef _WIN32
        /**
         * @brief Finds a process by name.
         * @param process The process object.
         * @param name The process name.
         * @return The process ID.
        */
        DWORD (*findByName)(struct Process*, const string);
    #else
        /**
         * @brief Finds a process by name.
         * @param process The process object.
         * @param name The process name.
         * @return The process ID.
        */
        pid_t (*findByName)(struct Process*, const string);
    #endif
} Process;
#pragma pack(pop)



/**
 * @brief Constructs a new {@code Process} object.
 * @param void
 * @return The new {@code Process} object.
 */
Process new_Process(PROCESS pid);

#pragma pack(push, 1)
/**
 * @struct TIME
 * @brief Represents a time object with utility functions.
 */
typedef struct TIME {
    uint16_t year; ///< The year.
    uint8_t month; ///< The month.
    uint8_t day; ///< The day.
    uint8_t hour; ///< The hour.
    uint8_t minute; ///< The minute.
    uint8_t second;//< The second.
    uint16_t millisecond; ///< The millisecond.
    boolean running; ///< The running state.
    ThreadHandle thread; ///< The thread handle.
    MutexHandle mutex; ///< The mutex handle.
    /**
     * @brief Gets the current system time.
     * @param t The time object.
     * @return void.
     */
    void (*getSystemTime)(struct TIME*);
    /**
     * @brief Gets the time.
     * @param t The time object.
     * @return void.
     */
    void (*getTime)(struct TIME*);
    /**
     * @brief Sets the time.
     * @param t The time object.
     * @param year The year.
     * @param month The month.
     * @param day The day.
     * @param hour The hour.
     * @param minute The minute.
     * @param second The second.
     * @return void.
    */
    void (*setTime)(struct TIME*, uint16_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t);
    /**
     * @brief Runs the time.
     * @param t The time object.
     * @return void.
    */
    void (*start)(struct TIME*);
    /**
     * @brief Stops the time.
     * @param t The time object.
     * @return void.
    */
    void (*stop)(struct TIME*);
} Time;
#pragma pack(pop)

/**
 * @brief Constructs a new {@code Time} object.
 * @param void
 * @return The new {@code Time} object.
 */
Time new_Time(void);

#pragma pack(push, 1)
/**
 * @struct String
 * @brief Represents a string object with utility functions.
 */
typedef struct String{
    string value;   ///< The underlying string value.
    /**
     * @brief Returns the character at the specified index.
     * @param str The string.
     * @param index The position of the character.
     * @return The character at the specified index.
     */
    char (*charAt)(const string, size_t);
    /**
     * @brief Compares two strings for equality.
     * @param str1 The first string.
     * @param str2 The second string.
     * @return True if the strings are equal, otherwise false.
     */
    boolean (*equals)(const string, const string);
    /**
     * @brief Returns the length of the string.
     * @param str The string.
     * @return The length of the string.
     */
    size_t (*length)(const string);
    /**
     * @brief Replaces all occurrences of a character with another.
     * @param str The string.
     * @param oldChar The character to be replaced.
     * @param newChar The replacement character.
     * @return A new string with replacements.
     */
    string (*replace)(const string, char, char);
    /**
     * @brief Returns a substring of the string.
     * @param str The string.
     * @param start The starting index.
     * @param end The ending index.
     * @return The substring from start to end.
     */
    string (*substring)(const string, size_t, size_t);
    /**
     * @brief Converts the string to lowercase.
     * @param str The string.
     * @return A new string in lowercase.
     */
    string (*toLowerCase)(const string);
    /**
     * @brief Converts the string to uppercase.
     * @param str The string.
     * @return A new string in uppercase.
     */
    string (*toUpperCase)(const string);
    /**
     * @brief Trims whitespace or specified characters from the string.
     * @param str The string.
     * @param ... Optional characters to trim.
     * @return A trimmed string.
     */
    string (*trim)(const string, ...);
} String;
#pragma pack(pop)

#pragma pack(push, 1)
/**
 * @struct Character
 * @brief Represents a character object with utility functions.
 */
typedef struct Character{
    char value;  ///< The underlying character value.
    /**
     * @brief Compares two characters for equality.
     * @param a The first character.
     * @param b The second character.
     * @return True if equal, otherwise false.
     */
    boolean (*equals)(const char, const char);
    /**
     * @brief Checks if the character is a letter.
     * @param c The character to check.
     * @return True if it is a letter, otherwise false.
     */
    boolean (*isLetter)(const char);
    /**
     * @brief Checks if the character is a digit.
     * @param c The character to check.
     * @return True if it is a digit, otherwise false.
     */
    boolean (*isDigit)(const char);
    /**
     * @brief Checks if the character is either a letter or a digit.
     * @param c The character to check.
     * @return True if it is a letter or digit, otherwise false.
     */
    boolean (*isLetterOrDigit)(const char);
    /**
     * @brief Checks if the character is in lowercase.
     * @param c The character to check.
     * @return True if it is lowercase, otherwise false.
     */
    boolean (*isLowerCase)(const char);
    /**
     * @brief Checks if the character is in uppercase.
     * @param c The character to check.
     * @return True if it is uppercase, otherwise false.
     */
    boolean (*isUpperCase)(const char);
    /**
     * @brief Converts the character to lowercase.
     * @param c The character to convert.
     * @return The lowercase character.
     */
    char (*toLowerCase)(const char);
    /**
     * @brief Converts the character to uppercase.
     * @param c The character to convert.
     * @return The uppercase character.
     */
    char (*toUpperCase)(const char);
    /**
     * @brief Checks if the character is alphabetic.
     * @param c The character to check.
     * @return True if it is alphabetic, otherwise false.
     */
    boolean (*isAlphabetic)(const char);
    /**
     * @brief Checks if the character is a space character.
     * @param c The character to check.
     * @return True if it is a space character, otherwise false.
     */
    boolean (*isSpaceChar)(const char);
    /**
     * @brief Checks if the character is defined.
     * @param c The character to check.
     * @return True if defined, otherwise false.
     */
    boolean (*isDefined)(const char);
} Character;
#pragma pack(pop)

#pragma pack(push, 1)
/**
 * @struct Boolean
 * @brief Represents a boolean object with utility functions.
 */
typedef struct Boolean{
    boolean value;  ///< The underlying boolean value.
    /**
     * @brief Compares two boolean values for equality.
     * @param a The first boolean.
     * @param b The second boolean.
     * @return True if equal, otherwise false.
     */
    boolean (*equals)(const boolean, const boolean);
    /**
     * @brief Performs logical AND on two booleans.
     * @param a The first boolean.
     * @param b The second boolean.
     * @return The result of logical AND.
     */
    boolean (*logicalAnd)(const boolean, const boolean);
    /**
     * @brief Performs logical OR on two booleans.
     * @param a The first boolean.
     * @param b The second boolean.
     * @return The result of logical OR.
     */
    boolean (*logicalOr)(const boolean, const boolean);
    /**
     * @brief Performs logical NOT on a boolean.
     * @param a The boolean to negate.
     * @return The negated boolean.
     */
    boolean (*logicalNot)(const boolean);
    /**
     * @brief Performs logical XOR on two booleans.
     * @param a The first boolean.
     * @param b The second boolean.
     * @return The result of logical XOR.
     */
    boolean (*logicalXor)(const boolean, const boolean);
    /**
     * @brief Parses a string into a boolean.
     * @param str The string to parse.
     * @return The boolean value represented by the string.
     */
    boolean (*parseBoolean)(const string);
    /**
     * @brief Returns the boolean value.
     * @param b The boolean to get the value of.
     * @return The same boolean value.
     */
    boolean (*valueOf)(const boolean);
    /**
     * @brief Compares two booleans.
     * @param a The first boolean.
     * @param b The second boolean.
     * @return An integer result of the comparison.
     */
    int32_t (*compare)(const boolean, const boolean);
} Boolean;
#pragma pack(pop)

#pragma pack(push, 1)
/**
 * @struct Byte
 * @brief Represents an 8-bit integer object with utility functions.
 */
typedef struct Byte{
    int8_t value;  ///< The underlying 8-bit value.
    /**
     * @brief Parses a string into an 8-bit integer.
     * @param str The string to parse.
     * @param ... Additional arguments.
     * @return The parsed 8-bit integer.
     */
    int8_t (*parse)(const string, ...);
    /**
     * @brief Converts an 8-bit integer to a string.
     * @param b The 8-bit integer.
     * @return The string representation.
     */
    string (*toString)(int8_t);
    /**
     * @brief Converts an 8-bit integer to a binary string.
     * @param b The 8-bit integer.
     * @return The binary string representation.
     */
    string (*toBinaryString)(int8_t);
    /**
     * @brief Converts an 8-bit integer to an octal string.
     * @param b The 8-bit integer.
     * @return The octal string representation.
     */
    string (*toOctalString)(int8_t);
    /**
     * @brief Converts an 8-bit integer to a hexadecimal string.
     * @param b The 8-bit integer.
     * @return The hexadecimal string representation.
     */
    string (*toHexString)(int8_t);
    /**
     * @brief Counts the number of one-bits in the 8-bit integer.
     * @param b The 8-bit integer.
     * @return The bit count.
     */
    size_t (*bitCount)(int8_t);
    /**
     * @brief Returns the byte value.
     * @param b The 8-bit integer.
     * @return The byte value.
     */
    int8_t (*byteValue)(int8_t);
    /**
     * @brief Converts the 8-bit integer to a 16-bit short.
     * @param b The 8-bit integer.
     * @return The 16-bit short value.
     */
    int16_t (*shortValue)(int8_t);
    /**
     * @brief Converts the 8-bit integer to a 32-bit integer.
     * @param b The 8-bit integer.
     * @return The 32-bit integer value.
     */
    int32_t (*intValue)(int8_t);
    /**
     * @brief Converts the 8-bit integer to a 64-bit integer.
     * @param b The 8-bit integer.
     * @return The 64-bit integer value.
     */
    int64_t (*longValue)(int8_t);
    /**
     * @brief Converts the 8-bit integer to a float.
     * @param b The 8-bit integer.
     * @return The float value.
     */
    float (*floatValue)(int8_t);
    /**
     * @brief Converts the 8-bit integer to a double.
     * @param b The 8-bit integer.
     * @return The double value.
     */
    double (*doubleValue)(int8_t);
    /**
     * @brief Converts the 8-bit integer to a boolean.
     * @param b The 8-bit integer.
     * @return The boolean value.
     */
    boolean (*booleanValue)(int8_t);
    /**
     * @brief Returns the minimum of two 8-bit integers.
     * @param a The first 8-bit integer.
     * @param b The second 8-bit integer.
     * @return The smaller of the two.
     */
    int8_t (*min)(int8_t, int8_t);
    /**
     * @brief Returns the maximum of two 8-bit integers.
     * @param a The first 8-bit integer.
     * @param b The second 8-bit integer.
     * @return The larger of the two.
     */
    int8_t (*max)(int8_t, int8_t);
} Byte;
#pragma pack(pop)

#pragma pack(push, 1)
/**
 * @struct Short
 * @brief Represents a 16-bit integer object with utility functions.
 */
typedef struct Short{
    int16_t value;  ///< The underlying 16-bit value.
    /**
     * @brief Parses a string into a 16-bit integer.
     * @param str The string to parse.
     * @param ... Additional arguments.
     * @return The parsed 16-bit integer.
     */
    int16_t (*parse)(const string, ...);
    /**
     * @brief Converts a 16-bit integer to a string.
     * @param s The 16-bit integer.
     * @return The string representation.
     */
    string (*toString)(int16_t);
    /**
     * @brief Converts a 16-bit integer to a binary string.
     * @param s The 16-bit integer.
     * @return The binary string representation.
     */
    string (*toBinaryString)(int16_t);
    /**
     * @brief Converts a 16-bit integer to an octal string.
     * @param s The 16-bit integer.
     * @return The octal string representation.
     */
    string (*toOctalString)(int16_t);
    /**
     * @brief Converts a 16-bit integer to a hexadecimal string.
     * @param s The 16-bit integer.
     * @return The hexadecimal string representation.
     */
    string (*toHexString)(int16_t);
    /**
     * @brief Counts the number of one-bits in the 16-bit integer.
     * @param s The 16-bit integer.
     * @return The bit count.
     */
    size_t (*bitCount)(int16_t);
    /**
     * @brief Converts the 16-bit integer to an 8-bit integer.
     * @param s The 16-bit integer.
     * @return The 8-bit integer value.
     */
    int8_t (*byteValue)(int16_t);
    /**
     * @brief Returns the 16-bit integer value.
     * @param s The 16-bit integer.
     * @return The same 16-bit value.
     */
    int16_t (*shortValue)(int16_t);
    /**
     * @brief Converts the 16-bit integer to a 32-bit integer.
     * @param s The 16-bit integer.
     * @return The 32-bit integer value.
     */
    int32_t (*intValue)(int16_t);
    /**
     * @brief Converts the 16-bit integer to a 64-bit integer.
     * @param s The 16-bit integer.
     * @return The 64-bit integer value.
     */
    int64_t (*longValue)(int16_t);
    /**
     * @brief Converts the 16-bit integer to a float.
     * @param s The 16-bit integer.
     * @return The float value.
     */
    float (*floatValue)(int16_t);
    /**
     * @brief Converts the 16-bit integer to a double.
     * @param s The 16-bit integer.
     * @return The double value.
     */
    double (*doubleValue)(int16_t);
    /**
     * @brief Converts the 16-bit integer to a boolean.
     * @param s The 16-bit integer.
     * @return The boolean value.
     */
    boolean (*booleanValue)(int16_t);
    /**
     * @brief Returns the minimum of two 16-bit integers.
     * @param a The first 16-bit integer.
     * @param b The second 16-bit integer.
     * @return The smaller of the two.
     */
    int16_t (*min)(int16_t, int16_t);
    /**
     * @brief Returns the maximum of two 16-bit integers.
     * @param a The first 16-bit integer.
     * @param b The second 16-bit integer.
     * @return The larger of the two.
     */
    int16_t (*max)(int16_t, int16_t);
} Short;
#pragma pack(pop)

#pragma pack(push, 1)
/**
 * @struct Integer
 * @brief Represents a 32-bit integer object with utility functions.
 */
typedef struct Intrger{
    int32_t value;  ///< The underlying 32-bit value.
    /**
     * @brief Parses a string into a 32-bit integer.
     * @param str The string to parse.
     * @param ... Additional arguments.
     * @return The parsed 32-bit integer.
     */
    int32_t (*parse)(const string, ...);
    /**
     * @brief Converts a 32-bit integer to a string.
     * @param i The 32-bit integer.
     * @return The string representation.
     */
    string (*toString)(int32_t);
    /**
     * @brief Converts a 32-bit integer to a binary string.
     * @param i The 32-bit integer.
     * @return The binary string representation.
     */
    string (*toBinaryString)(int32_t);
    /**
     * @brief Converts a 32-bit integer to an octal string.
     * @param i The 32-bit integer.
     * @return The octal string representation.
     */
    string (*toOctalString)(int32_t);
    /**
     * @brief Converts a 32-bit integer to a hexadecimal string.
     * @param i The 32-bit integer.
     * @return The hexadecimal string representation.
     */
    string (*toHexString)(int32_t);
    /**
     * @brief Counts the number of one-bits in the 32-bit integer.
     * @param i The 32-bit integer.
     * @return The bit count.
     */
    size_t (*bitCount)(int32_t);
    /**
     * @brief Converts the 32-bit integer to an 8-bit integer.
     * @param i The 32-bit integer.
     * @return The 8-bit integer value.
     */
    int8_t (*byteValue)(int32_t);
    /**
     * @brief Converts the 32-bit integer to a 16-bit integer.
     * @param i The 32-bit integer.
     * @return The 16-bit integer value.
     */
    int16_t (*shortValue)(int32_t);
    /**
     * @brief Returns the 32-bit integer value.
     * @param i The 32-bit integer.
     * @return The same 32-bit value.
     */
    int32_t (*intValue)(int32_t);
    /**
     * @brief Converts the 32-bit integer to a 64-bit integer.
     * @param i The 32-bit integer.
     * @return The 64-bit integer value.
     */
    int64_t (*longValue)(int32_t);
    /**
     * @brief Converts the 32-bit integer to a float.
     * @param i The 32-bit integer.
     * @return The float value.
     */
    float (*floatValue)(int32_t);
    /**
     * @brief Converts the 32-bit integer to a double.
     * @param i The 32-bit integer.
     * @return The double value.
     */
    double (*doubleValue)(int32_t);
    /**
     * @brief Converts the 32-bit integer to a boolean.
     * @param i The 32-bit integer.
     * @return The boolean value.
     */
    boolean (*booleanValue)(int32_t);
    /**
     * @brief Returns the minimum of two 32-bit integers.
     * @param a The first 32-bit integer.
     * @param b The second 32-bit integer.
     * @return The smaller of the two.
     */
    int32_t (*min)(int32_t, int32_t);
    /**
     * @brief Returns the maximum of two 32-bit integers.
     * @param a The first 32-bit integer.
     * @param b The second 32-bit integer.
     * @return The larger of the two.
     */
    int32_t (*max)(int32_t, int32_t);
} Integer;
#pragma pack(pop)

#pragma pack(push, 1)
/**
 * @struct Long
 * @brief Represents a 64-bit integer object with utility functions.
 */
typedef struct Long{
    int64_t value;  ///< The underlying 64-bit value.
    /**
     * @brief Parses a string into a 64-bit integer.
     * @param str The string to parse.
     * @param ... Additional arguments.
     * @return The parsed 64-bit integer.
     */
    int64_t (*parse)(const string, ...);
    /**
     * @brief Converts a 64-bit integer to a string.
     * @param l The 64-bit integer.
     * @return The string representation.
     */
    string (*toString)(int64_t);
    /**
     * @brief Converts a 64-bit integer to a binary string.
     * @param l The 64-bit integer.
     * @return The binary string representation.
     */
    string (*toBinaryString)(int64_t);
    /**
     * @brief Converts a 64-bit integer to an octal string.
     * @param l The 64-bit integer.
     * @return The octal string representation.
     */
    string (*toOctalString)(int64_t);
    /**
     * @brief Converts a 64-bit integer to a hexadecimal string.
     * @param l The 64-bit integer.
     * @return The hexadecimal string representation.
     */
    string (*toHexString)(int64_t);
    /**
     * @brief Counts the number of one-bits in the 64-bit integer.
     * @param l The 64-bit integer.
     * @return The bit count.
     */
    size_t (*bitCount)(int64_t);
    /**
     * @brief Converts the 64-bit integer to an 8-bit integer.
     * @param l The 64-bit integer.
     * @return The 8-bit integer value.
     */
    int8_t (*byteValue)(int64_t);
    /**
     * @brief Converts the 64-bit integer to a 16-bit integer.
     * @param l The 64-bit integer.
     * @return The 16-bit integer value.
     */
    int16_t (*shortValue)(int64_t);
    /**
     * @brief Converts the 64-bit integer to a 32-bit integer.
     * @param l The 64-bit integer.
     * @return The 32-bit integer value.
     */
    int32_t (*intValue)(int64_t);
    /**
     * @brief Returns the 64-bit integer value.
     * @param l The 64-bit integer.
     * @return The same 64-bit value.
     */
    int64_t (*longValue)(int64_t);
    /**
     * @brief Converts the 64-bit integer to a float.
     * @param l The 64-bit integer.
     * @return The float value.
     */
    float (*floatValue)(int64_t);
    /**
     * @brief Converts the 64-bit integer to a double.
     * @param l The 64-bit integer.
     * @return The double value.
     */
    double (*doubleValue)(int64_t);
    /**
     * @brief Converts the 64-bit integer to a boolean.
     * @param l The 64-bit integer.
     * @return The boolean value.
     */
    boolean (*booleanValue)(int64_t);
    /**
     * @brief Returns the minimum of two 64-bit integers.
     * @param a The first 64-bit integer.
     * @param b The second 64-bit integer.
     * @return The smaller of the two.
     */
    int64_t (*min)(int64_t, int64_t);
    /**
     * @brief Returns the maximum of two 64-bit integers.
     * @param a The first 64-bit integer.
     * @param b The second 64-bit integer.
     * @return The larger of the two.
     */
    int64_t (*max)(int64_t, int64_t);
} Long;
#pragma pack(pop)

#pragma pack(push, 1)
/**
 * @struct Float
 * @brief Represents a floating-point object with utility functions.
 */
typedef struct Float{
    float value;  ///< The underlying float value.
    /**
     * @brief Parses a string into a float.
     * @param str The string to parse.
     * @return The parsed float value.
     */
    float (*parse)(const string);
    /**
     * @brief Converts a float to a string.
     * @param f The float value.
     * @return The string representation.
     */
    string (*toString)(float);
    /**
     * @brief Converts the float to an 8-bit integer.
     * @param f The float value.
     * @return The 8-bit integer value.
     */
    int8_t (*byteValue)(float);
    /**
     * @brief Converts the float to a 16-bit integer.
     * @param f The float value.
     * @return The 16-bit integer value.
     */
    int16_t (*shortValue)(float);
    /**
     * @brief Converts the float to a 32-bit integer.
     * @param f The float value.
     * @return The 32-bit integer value.
     */
    int32_t (*intValue)(float);
    /**
     * @brief Converts the float to a 64-bit integer.
     * @param f The float value.
     * @return The 64-bit integer value.
     */
    int64_t (*longValue)(float);
    /**
     * @brief Returns the float value.
     * @param f The float value.
     * @return The same float value.
     */
    float (*floatValue)(float);
    /**
     * @brief Converts the float to a double.
     * @param f The float value.
     * @return The double value.
     */
    double (*doubleValue)(float);
    /**
     * @brief Converts the float to a boolean.
     * @param f The float value.
     * @return The boolean value.
     */
    boolean (*booleanValue)(float);
    /**
     * @brief Returns the minimum of two floats.
     * @param a The first float.
     * @param b The second float.
     * @return The smaller of the two.
     */
    float (*min)(float, float);
    /**
     * @brief Returns the maximum of two floats.
     * @param a The first float.
     * @param b The second float.
     * @return The larger of the two.
     */
    float (*max)(float, float);
} Float;
#pragma pack(pop)

#pragma pack(push, 1)
/**
 * @struct Double
 * @brief Represents a double-precision floating-point object with utility functions.
 */
typedef struct Double{
    double value;  ///< The underlying double value.
    /**
     * @brief Parses a string into a double.
     * @param str The string to parse.
     * @return The parsed double value.
     */
    double (*parse)(const string);
    /**
     * @brief Converts a double to a string.
     * @param d The double value.
     * @return The string representation.
     */
    string (*toString)(double);
    /**
     * @brief Converts the double to an 8-bit integer.
     * @param d The double value.
     * @return The 8-bit integer value.
     */
    int8_t (*byteValue)(double);
    /**
     * @brief Converts the double to a 16-bit integer.
     * @param d The double value.
     * @return The 16-bit integer value.
     */
    int16_t (*shortValue)(double);
    /**
     * @brief Converts the double to a 32-bit integer.
     * @param d The double value.
     * @return The 32-bit integer value.
     */
    int32_t (*intValue)(double);
    /**
     * @brief Converts the double to a 64-bit integer.
     * @param d The double value.
     * @return The 64-bit integer value.
     */
    int64_t (*longValue)(double);
    /**
     * @brief Converts the double to a float.
     * @param d The double value.
     * @return The float value.
     */
    float (*floatValue)(double);
    /**
     * @brief Returns the double value.
     * @param d The double value.
     * @return The same double value.
     */
    double (*doubleValue)(double);
    /**
     * @brief Converts the double to a boolean.
     * @param d The double value.
     * @return The boolean value.
     */
    boolean (*booleanValue)(double);
    /**
     * @brief Returns the minimum of two doubles.
     * @param a The first double.
     * @param b The second double.
     * @return The smaller of the two.
     */
    double (*min)(double, double);
    /**
     * @brief Returns the maximum of two doubles.
     * @param a The first double.
     * @param b The second double.
     * @return The larger of the two.
     */
    double (*max)(double, double);
} Double;
#pragma pack(pop)

/// Function declarations for creating new instances of the objects

/**
 * @brief Creates a new String object.
 * @param str The initial string.
 * @return A new String instance.
 */
String new_String(string str);

/**
 * @brief Creates a new Character object.
 * @param c The initial character.
 * @return A new Character instance.
 */
Character new_Character(char c);

/**
 * @brief Creates a new Byte object.
 * @param b The initial 8-bit value.
 * @return A new Byte instance.
 */
Byte new_Byte(int8_t b);

/**
 * @brief Creates a new Short object.
 * @param s The initial 16-bit value.
 * @return A new Short instance.
 */
Short new_Short(int16_t s);

/**
 * @brief Creates a new Integer object.
 * @param i The initial 32-bit value.
 * @return A new Integer instance.
 */
Integer new_Integer(int32_t i);

/**
 * @brief Creates a new Long object.
 * @param l The initial 64-bit value.
 * @return A new Long instance.
 */
Long new_Long(int64_t l);

/**
 * @brief Creates a new Float object.
 * @param f The initial float value.
 * @return A new Float instance.
 */
Float new_Float(float f);

/**
 * @brief Creates a new Double object.
 * @param d The initial double value.
 * @return A new Double instance.
 */
Double new_Double(double d);

/**
 * @brief Creates a new Boolean object.
 * @param b The initial boolean value.
 * @return A new Boolean instance.
 */
Boolean new_Boolean(boolean b);

#endif
