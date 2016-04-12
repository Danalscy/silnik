#include "vector.h"
#include "converter.h"
#include "stack.h"
#include "interfejs.h"
#define BUFSIZE 8192

int main(int argc,char **argv){
 
 int wynik;
 FILE *dane=fopen(argv[1],"r");
 FILE *wzory=fopen(argv[2],"r");
// int tryb=atoi(argv[3]);
 char *szukane=argv[3];
 char bufwzory[BUFSIZE];
 int i,j,n,ile_wyraz=0;
 vector_t tabela;
 read_table(dane,&tabela);
 print(tabela);
 printf("\n");
 wnioskowanie_przod(wzory,&tabela);
 print(tabela);
 return 0;
}
