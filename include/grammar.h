#ifndef GRAMMAR_H
#define GRAMMAR_H

#include <stdlib.h>

#define MAXLINE 256
#define EPSILON 'ε'

typedef struct {
    char head;
    char* body;
} Production;

typedef struct {
    Production* productions;
    size_t len;
} Grammar;

size_t input(char* grammar[MAXLINE]);
Production parse_production(const char* rule);

#endif