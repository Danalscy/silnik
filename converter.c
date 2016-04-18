#include "converter.h"

int priority(char c)
{
    switch(c)    {
        case '|':
            return 1;
        case '&':
            return 2;
        case '!':
            return 3;
    }
    return 0;
}

bool convert(char *input, char *output){
	stack_t stos;
	stos.size=0;
	char *strpos = input, *strend = input + strlen(input);
	char current, *outpos = output;
	char     temp;
        while(strpos<strend){
	current = *strpos;
        if(current != ' ')    {
            if(is_binary(current))  {
                *outpos = current;
		 ++outpos;
            }
	    else if(is_operator(current))  {
                while(stos.size > 0)    {
                    temp = top(&stos);
                    if(is_operator(temp) &&(priority(current) < priority(temp)))   {
			char tmp=pop(&stos);
        		*outpos = tmp;
                        ++outpos;   
                    }
                    else   {
                        break;
                    }
                }
		push(&stos,(int)current);
            }
            else if(current == '(')   {
		push(&stos,(int)current);
            }
            else if(current == ')')    {
                bool closed = false;
                while(stos.size > 0)     {
                    temp = top(&stos);
                    if(temp == '(')    {
                        closed = true;
                        break;
                    }
                    else  {
			char tmp=pop(&stos);
      			*outpos = tmp;
                        ++outpos;
                    }
                }
                if(!closed)  {
                    printf("Error: NAWIASY\n");
                    return false;
                }
                pop(&stos);
            }
            else  {
                printf("Error: ZLE ZNAKI %c\n", current);
                return false; 
            }
        }
        ++strpos;
    }
    while(stos.size > 0)  {
        temp = top(&stos);
        if(temp == '(' || temp == ')')   {
            printf("Error: NAWIASY\n");
            return false;
        }
	char tmp=pop(&stos);
        *outpos = tmp;
        ++outpos;
    }
	*outpos = 0;
	printf("%s\n",output);
    return true;
}

bool wnioskuj(char * expr)  {
 stack_t equation;
 equation.size=0;
 char *output = (char*) malloc(strlen(expr)+1);
 char c;
 if(!convert(expr, output))
	return false;  
 int i,x,y;
 for(i=0;output[i]!='\0';i++)  {
	c = output[i];
	//printf("%c\n",c);
	if(is_binary(c))  {
                push(&equation,c-'0');
        }
	if(c=='!'){
		x=pop(&equation)^1;
		push(&equation,x);
	}
	if(c=='&'){
		x=pop(&equation);
		y=pop(&equation);
		push(&equation,x&&y);
	}
	if(c=='|'){
		x=pop(&equation);
		y=pop(&equation);
		push(&equation,x||y);
	}
	//printf("Ile na stosie: %d\n",equation.size);
	//printstack(&equation);
 }
 return pop(&equation);
}

char *replace_str(char *s, char *old, char *new) {
 char *tmp;
 int i,count=0;
 int newlen = strlen(new);
 int oldlen = strlen(old);
 for (i = 0; s[i] != '\0'; i++){
        if (strstr(&s[i], old) == &s[i]){
            count++;
            i += oldlen - 1;
        }
 }
 tmp = (char *)malloc(i + count * (newlen - oldlen));
 i = 0;
    while (*s)
    {
        if (strstr(s, old) == s) 
        {
            strcpy(&tmp[i], new);
            i += newlen; 
            s += oldlen;
        }
        else
        tmp[i++] = *s++;
    }
 tmp[i] = '\0';
 return tmp;

}



