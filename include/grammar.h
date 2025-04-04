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

/**
 * Reads grammar rules from standard input and stores them in grammar.
 * @param grammar A array of strings to store the grammar rules
 * @return The number of rules read. Returns -1 if no rules were read.
 */
int input(char* grammar[MAXLINE]);

/**
 * Parses a production rule from a string and returns a Production struct.
 * A production rule should be in the form "A -> BX | C", where A is the
 * head of the production and BX and C are the body. The function will throw
 * an error if the rule is invalid.
 * @param rule A string containing a production rule
 * @return A Production struct containing the head and body of the rule
 */
Production parse_production(const char* rule);

#endif