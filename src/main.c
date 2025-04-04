#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>

#include "../include/grammar.h"
#include "../include/utils.h"

int main(void) {
    char** rules = (char**)malloc(MAXLINE * sizeof(char*));
    if (!rules) throw_error("malloc");

    size_t rules_count = input(rules);
    if (rules_count == -1) throw_error("input");

    // Allocate the productions array.
    Grammar grammar;
    grammar.len = rules_count;
    grammar.productions = malloc(rules_count * sizeof(Production));
    if (!grammar.productions) throw_error("malloc");

    // Parse each rule and store it in the grammar.
    for (size_t i = 0; i < rules_count; i++) {
        grammar.productions[i] = parse_production(rules[i]);
    }

    // Display the productions.
    for (size_t i = 0; i < grammar.len; i++) {
        printf("Production %zu: %c -> %s\n", i, grammar.productions[i].head, grammar.productions[i].body);
    }

    // Free allocated memory.
    for (size_t i = 0; i < grammar.len; i++) {
        free(grammar.productions[i].body);
    }
    free(grammar.productions);

    return 0;
}