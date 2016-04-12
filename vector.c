#include "vector.h"

void add(vector_t *a,char *item, int element) {
  if (a->capacity == a->size) {
    a->capacity *= 2;
    a->para = (mapa_t*)realloc(a->para, a->capacity * sizeof(mapa_t));
  }
  a->para[a->size].status = element;
  a->para[a->size].word=(char*) malloc(strlen(item)+1);
  strcpy (a->para[a->size].word,item);
  a->size++;
}

void init(vector_t *a, int n) {
  a->para = (mapa_t *)malloc(n * sizeof(mapa_t));
  a->size = 0;
  a->capacity = n;
}

int szukaj(char *key, vector_t *tab){
 int i = 0,j=0;
 char *wyraz = tab->para[i].word;
	while (wyraz) {
		if (strcmp(wyraz, key) == 0)
			return tab->para[i].status;
        wyraz = tab->para[++i].word;
	}
 printf("Nie znaleziono %s\n",key);
 return -1;
}

void print(vector_t a){
 int i;
 for(i=0;i<a.size;i++){
	printf("%s %d\n",a.para[i].word,a.para[i].status);
 }
}
