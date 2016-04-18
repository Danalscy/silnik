#ifndef STACK_H
#define STACK_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct a{
	int data[100];
	int size;
} stack_t;

typedef struct b{
	char *data[100];
	int size;
} stack_st;

void push(stack_t *stos, int f);

int pop (stack_t *stos);

int top (stack_t *stos);

void printstack(stack_t *stos);
void printstackst(stack_st *stos);

void pushst(stack_st *stos, char* f);
int empty(stack_st *stos);
char* popst (stack_st *stos);

char* topst (stack_st *stos);


#endif
