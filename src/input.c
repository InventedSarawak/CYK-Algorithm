#define _POSIX_C_SOURCE 200809L
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/grammar.h"
#include "../include/utils.h"

// Private function declaration - only used in this file
static char* trim(char* str);

size_t input(char* grammar[MAXLINE]) {
    size_t len = MAXLINE;
    char input[MAXLINE];
    size_t i = 0;
    while (fgets(input, len, stdin) != NULL) {
        if (strcmp(input, "\n") == 0) {
            break;
        }
        grammar[i] = trim(strdup(input));
        if (!grammar[i]) throw_error("strdup");
        i++;
    }
    if (i == 0) return -1;
    return i;
}

Production parse_production(const char* rule) {
    Production p;
    regex_t regex;
    regmatch_t matches[3];  // matches[0]: full match, [1]: LHS, [2]: RHS
    const char* pattern = "^([A-Z])[[:space:]]*->[[:space:]]*(.*)$";

    if (regcomp(&regex, pattern, REG_EXTENDED) != 0) {
        fprintf(stderr, "Could not compile regex\n");
        exit(1);
    }

    if (regexec(&regex, rule, 3, matches, 0) == 0) {
        // Extract LHS (group 1)
        int lhs_start = matches[1].rm_so;
        p.head = rule[lhs_start];  // expecting a single letter

        // Extract RHS (group 2)
        int rhs_start = matches[2].rm_so;
        int rhs_end = matches[2].rm_eo;
        int len = rhs_end - rhs_start;
        p.body = malloc(len + 1);
        if (!p.body) throw_error("malloc");
        strncpy(p.body, rule + rhs_start, len);
        p.body[len] = '\0';
    } else {
        fprintf(stderr, "No match for rule: %s\n", rule);
        p.head = '\0';
        p.body = NULL;
    }

    regfree(&regex);
    return p;
}

// Private function implementation
static char* trim(char* str) {
    // char* original = str;
    while (*str == ' ') str++;

    // Handle trailing spaces
    char* end = str + strlen(str) - 1;
    while (end > str && (*end == ' ' || *end == '\n')) {
        *end = '\0';
        end--;
    }

    return str;
}