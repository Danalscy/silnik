#include "stack.h"
void push(stack_t *stos,int f){
    if(stos->size < 100)
        stos->data[stos->size++]=f;
    else
        printf("stack full \n");
}
void pushst(stack_st *stos,char *f){
	 stos->data[stos->size]=(char*) malloc(strlen(f)+1);
    if(stos->size < 100)
       strcpy(stos->data[stos->size++],f);
    else
        printf("stack full\n");
}
char* popst(stack_st *stos){
    if(stos->size>0)
        return stos->data[--stos->size];
}

int empty(stack_st *stos){
if(stos->size == 0)
     return 1;
  else
     return 0;
}
int pop(stack_t *stos){
    if(stos->size>0)
        return stos->data[--stos->size];
    else
    {
        printf("stack empty\n");
        return 0;
    }
}
char* topst(stack_st *stos){
   if(stos->size>0)
        return stos->data[stos->size-1];
    else
    {
        printf("stack empty\n");
        return 0;
    }
}

int top(stack_t *stos){
   if(stos->size>0)
        return stos->data[stos->size-1];
    else
    {
        printf("stack empty\n");
        return 0;
    }
}

void printstack(stack_t *stos){
	int i;
	printf("printuje stack:");
	for(i=0;i<stos->size;i++)
	printf("%d,",stos->data[i]);
	printf("\n");
}
void printstackst(stack_st *stos){
	int i;
	printf("printuje stack:");
	for(i=0;i<stos->size;i++)
	printf("%s,",stos->data[i]);
	printf("\n");
}

