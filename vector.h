#ifndef VECTOR_H
#define VECTOR_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct e{
	char* word;
	int status;
} mapa_t;

typedef struct d{
	mapa_t *para;
	int size;
	int capacity;
}vector_t;

void add(vector_t *a,char *item, int element);

void init(vector_t *a, int n);

void print(vector_t a);

void zwalnianie(vector_t *tab);

int szukaj(char *key, vector_t *tab);

#endif
