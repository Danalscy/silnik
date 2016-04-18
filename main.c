#include "vector.h"
#include "converter.h"
#include "stack.h"
#include "interfejs.h"
#define BUFSIZE 8192

int main(int argc,char **argv){
 
 int wynik;
 FILE *dane=fopen(argv[1],"r"); 
 if (dane == NULL) {
      printf ("Nie mozna przeczytac pliku z danymi\n\n");
      exit (EXIT_FAILURE);
    }
 FILE *wzory=fopen(argv[2],"r");
 if (wzory == NULL) {
      printf ("ERROR:Nie mozna przeczytac pliku ze wzorami\n\n");
      exit (EXIT_FAILURE);
    }
 char *trybtemp=argv[3];
 if (trybtemp == NULL) {
      printf ("ERROR: Brak trybu:\n 1 - wnioskowanie w przod\n-1 - wnioskowanie w tyl\n\n");
      exit (EXIT_FAILURE);
    }

 char *szukane=argv[4];
 if (szukane == NULL) {
      printf ("ERROR: Brak szukanego argumentu\n\n");
      exit (EXIT_FAILURE);
    }

 int tryb=atoi(trybtemp);
 vector_t tabela;
 vector_t reguly;
 stack_st queue;
 queue.size=0;
 read_table(dane,wzory,&tabela,&reguly);
 print(tabela);
 printf("\n");
 char *asd="";
 switch(tryb){
 case 1:
 	wnioskowanie_przod(&tabela,szukane,&reguly);
	break;
 case -1:
	wnioskowanie_tyl(&tabela,szukane,&reguly,&queue);
	wnioskowanie_tyl(&tabela,szukane,&reguly,&queue);
	break;
 default:
 printf("ERROR: Zly typ trybu\n\n");
 exit(EXIT_FAILURE);
 }
 print(tabela);
 zwalnianie(&tabela);
 zwalnianie(&reguly);
 return 0;
}
