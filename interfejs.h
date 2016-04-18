#ifndef INTERFEJS_H
#define INTERFEJS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"
#include "converter.h"
#include "stack.h"
void read_table(FILE *dane,FILE *wzory,vector_t *tab,vector_t *reguly);
int wnioskowanie_przod(vector_t *tabela, char *szukane,vector_t *reguly);
int wnioskowanie_tyl(vector_t *tabela, char *szukane, vector_t *reguly,stack_st *queue);
#endif
