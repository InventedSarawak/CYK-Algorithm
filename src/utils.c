#define _POSIX_C_SOURCE 200809L
#include "../include/utils.h"

#include <stdio.h>
#include <stdlib.h>

void throw_error(const char* message) {
    fprintf(stderr, "Error: %s\n", message);
    exit(1);
}