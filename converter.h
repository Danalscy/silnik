#ifndef CONVERTER_H
#define CONVERTER_H
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#define bool int
#define false 0
#define true 1

int priority(char c);

#define is_operator(c)  (c == '!' || c == '&' || c == '|')
#define is_binary(c)     (c == '0' || c == '1')
char *replace_str(char *input,char *co,char *naco);
bool convert(char *input, char *output);

bool wnioskuj(char * expr);
#endif
