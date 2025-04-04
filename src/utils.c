#define _POSIX_C_SOURCE 200809L
#include "../include/utils.h"

#include <stdio.h>
#include <stdlib.h>

void throw_error(const char* message) {
    fprintf(stderr, "Error: %s\n", message);
    exit(1);
}

char* trim(char* str) {
    while (*str == ' ') str++;
    char* end = str + strlen(str) - 1;
    while (end > str && (*end == ' ' || *end == '\n')) {
        *end = '\0';
        end--;
    }
    return str;
}