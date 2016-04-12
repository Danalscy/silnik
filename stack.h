#ifndef STACK_H
#define STACK_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct a{
	int data[100];
	int size;
} stack_t;

void push(stack_t *stos, int f);

int pop (stack_t *stos);

int top (stack_t *stos);

void printstack(stack_t *stos);

#endif
