#ifndef INTERFEJS_H
#define INTERFEJS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"
#include "converter.h"
void read_table(FILE *dane,vector_t *tabela);
void wnioskowanie_przod(FILE *dane,vector_t *tabela);
#endif
