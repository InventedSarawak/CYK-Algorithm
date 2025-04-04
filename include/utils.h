#ifndef UTILS_H
#define UTILS_H

/**
 * Prints an error message to stderr and exits the program
 * @param message The error message to display
 */
void throw_error(const char* message);

/**
 * Trims a string by removing leading and trailing whitespace and newline characters.
 * Modifies the given string in-place.
 * @param str The string to trim
 * @return The trimmed string
 */
char* trim(char* str);

#endif