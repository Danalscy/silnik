#include "interfejs.h"
#define BUFSIZE 8192
void read_table(FILE *dane,FILE *wzory,vector_t *tab,vector_t *reguly){
 char buf[BUFSIZE];
 fgets(buf,BUFSIZE,dane);
 int n=atoi(buf);
 init(tab,n);
 int ile_wyraz=0;
 int j,k;
 while(fgets(buf,BUFSIZE,dane)!=NULL){
        for(j=0;buf[j]!=' ';j++){
                ile_wyraz++;
        }
        char *tmp=(char*) malloc ((ile_wyraz) * sizeof(char));
        for(j=0;j<ile_wyraz;j++){
                tmp[j]=buf[j];
        }
        tmp[ile_wyraz]='\0';
        for(j=ile_wyraz;buf[j]!='\0';j++){
                if(buf[j]=='T')
                        add(tab,tmp,1);
                if(buf[j]=='F')
                        add(tab,tmp,0);
        }
        ile_wyraz=0;
	free(tmp);
 }
char bufwzory[BUFSIZE];
 fgets(bufwzory,BUFSIZE,wzory);
  n=atoi(bufwzory);
 init(reguly,n);

 while(fgets(bufwzory,BUFSIZE,wzory)!=NULL){
	strtok(bufwzory, "\n");
	add(reguly,bufwzory,0);
	k++;
 }
}

int wnioskowanie_przod (vector_t *tabela, char *szukane,vector_t *reguly){
 char pch[200];
 char tamp[200];
 char *testifnot;
 char *boolString[2] = {"FALSE", "TRUE"};
 char final[200];
 char finalword[20];
 int i,j,k=1;
 for(i=0;i<tabela->size;i++){
 if (strcmp(szukane,tabela->para[i].word)==0){
	printf("Znaleziono %s o wartości %s (było podane w danych)\n\n",szukane,boolString[szukaj(szukane,tabela)]);
	return 1;
	}
 }
 bool czyniema;
 char bufwzory[BUFSIZE];
 for(k=0;k<reguly->size;k++){
        printf("Przykład %d:\n",k+1);
	strcpy(tamp,reguly->para[k].word);
	printf("%s\n",tamp);
	testifnot = strtok (tamp," !&|()>,.-\n");	
	czyniema=1;
	while (testifnot != NULL && *testifnot!='='){
		if(szukaj(testifnot,tabela)==-1){
		printf("Nie znaleziono podargumentu %s\n",testifnot);
		czyniema=0;
		}
		//printf ("%s %d\n",pch,szukaj(pch,tabela));
		testifnot = strtok (NULL," !&|()>,.-\n");
	}
	if(czyniema==0)printf("\n");
	else{
	strcpy(bufwzory,reguly->para[k].word);
        strcpy(pch,bufwzory);
	strcpy(pch,replace_str(pch,"&&","&"));
        strcpy(pch,replace_str(pch,"||","|"));
	for(i=0;i<tabela->size;i++){
                char temp[2];
                sprintf(temp, "%d", szukaj(tabela->para[i].word,tabela));
                strcpy(pch,replace_str(pch,tabela->para[i].word,temp));
        }
        for(i=0;pch[i]!='=';i++){
                final[i]=pch[i];
        }
        final[i]='\0';
        for(j=0;pch[i]!='\0';i++,j++){
                        finalword[j]=pch[i];
        }
        finalword[j]='\0';
        strcpy(finalword,replace_str(finalword,"=",""));
        strcpy(finalword,replace_str(finalword," ",""));
        strcpy(finalword,replace_str(finalword,">",""));
        bool result=wnioskuj(final);
        printf("%s\nWyrazenie %s jest %s\n\n",pch,final,boolString[result]);
        char *asdtmp=(char*) malloc(strlen(finalword));
        if(finalword[0]=='!'){
                        for(j=0;j<strlen(finalword);j++){
                                asdtmp[j]=finalword[j+1];
                        }
                        asdtmp[j]='\0';
        }
        if(result){
                if(finalword[0]=='!'){
                        add(tabela,asdtmp,0);
			if(strcmp(asdtmp,szukane)==0){
				printf("Znaleziono %s o wartości %s\n\n",szukane,boolString[szukaj(szukane,tabela)]);
				return 1;
			}
                }
        	else{
                	add(tabela,finalword,1);
			if(strcmp(finalword,szukane)==0){
				printf("Znaleziono %s o wartości %s\n\n",szukane,boolString[szukaj(szukane,tabela)]);
				return 1;
			}

        	}
	}
	free(asdtmp);
	}
 }
 printf("\nSzukanego argumentu %s nie da sie wywnioskowac\n",szukane);
 return -1;
}

int wnioskowanie_tyl(vector_t *tabela,char *szukane,vector_t *reguly,stack_st *queue){
 char pch[200];
 char tamp[200];
 char final[200];
 char *podargument;
 char *boolString[3] = {"FALSE", "TRUE","UNKNOWN"};
 int i,j,k;
 char finalword[20];
 bool czyniema;
 char bufwzory[BUFSIZE];
 for(i=0;i<tabela->size;i++){
 if (strcmp(szukane,tabela->para[i].word)==0){
	printf("Znaleziono %s o wartości %s \n\n",szukane,boolString[szukaj(szukane,tabela)]);
	return true;
	}
 }
 bool czyjest=0,czyznowu=true;
 int indexy[reguly->size];
 for(k=0;k<reguly->size;k++){
			strcpy(pch,reguly->para[k].word);
	for(i=0;pch[i]!='=';i++){}
        for(j=0;pch[i]!='\0';i++,j++){
                        finalword[j]=pch[i];
        }
        finalword[j]='\0';
	strcpy(finalword,replace_str(finalword,"=",""));
        strcpy(finalword,replace_str(finalword," ",""));
        strcpy(finalword,replace_str(finalword,">",""));
        char *asdtmp=(char*) malloc(strlen(finalword));
	if(finalword[0]=='!'){
                        for(j=0;j<strlen(finalword);j++){
                                finalword[j]=finalword[j+1];
                        }
                        finalword[j]='\0';
        }
	
	if(strcmp(szukane,finalword)==0) {
		indexy[k]=1;
		czyjest = 1;	
	}
 }	
	if(czyjest==0){
		printf("%s nie istnieje jako wynik funkcji\n\n",szukane);
		exit(EXIT_FAILURE);
	}
	else	printf("Jest %s\n\n",szukane);
	
	char **pomoc;
	for(k=0;k<reguly->size;k++){
		if(indexy[k]==1){

		printf("Linia %d:\n%s\n",k+1,reguly->para[k].word);
			strcpy(tamp,reguly->para[k].word);
			podargument = strtok (tamp," !&|()>,.-\n");	
			czyniema=1;
			while (podargument != NULL && *podargument!='='){
				//pomoc[a]=podargument;
				//a++;
				printf("DODAJEMY %s DO STOSU\n",podargument);
				pushst(queue,podargument);
				/*if(wnioskowanie_tyl(tabela,podargument,reguly,queue)==false){
				czyznowu=false;
				}*/
				podargument = strtok (NULL," !&|()>,.-\n");
			}
	printf("\n");
	printstackst(queue);
	printf("\n\n");
	strcpy(bufwzory,reguly->para[k].word);
        strcpy(pch,bufwzory);
	strcpy(pch,replace_str(pch,"&&","&"));
        strcpy(pch,replace_str(pch,"||","|"));
	for(i=0;i<tabela->size;i++){
                char temp[2];
                sprintf(temp, "%d", szukaj(tabela->para[i].word,tabela));
                strcpy(pch,replace_str(pch,tabela->para[i].word,temp));
        }
        for(i=0;pch[i]!='=';i++){
                final[i]=pch[i];
        }
        final[i]='\0';
        for(j=0;pch[i]!='\0';i++,j++){
                        finalword[j]=pch[i];
        }
        finalword[j]='\0';
        strcpy(finalword,replace_str(finalword,"=",""));
        strcpy(finalword,replace_str(finalword," ",""));
        strcpy(finalword,replace_str(finalword,">",""));
        bool result=wnioskuj(final);
        printf("%s\nWyrazenie %s jest %s\n\n",pch,final,boolString[result]);
        char *asdtmp=(char*) malloc(strlen(finalword));
        if(finalword[0]=='!'){
                        for(j=0;j<strlen(finalword);j++){
                                asdtmp[j]=finalword[j+1];
                        }
                        asdtmp[j]='\0';
        }
        if(result){
                if(finalword[0]=='!'){
                        add(tabela,asdtmp,0);
			if(strcmp(asdtmp,szukane)==0){
				printf("Znaleziono %s o wartości %s\n\n",szukane,boolString[szukaj(szukane,tabela)]);
				return 1;
			}
                }
        	else{
                	add(tabela,finalword,1);
			if(strcmp(finalword,szukane)==0){
				printf("Znaleziono %s o wartości %s\n\n",szukane,boolString[szukaj(szukane,tabela)]);
				return 1;
			}

        	}
	}
	free(asdtmp);

		while(!empty(queue)){
			//printf("%d: %s\n",i,topst(queue));		
			if(wnioskowanie_tyl(tabela,popst(queue),reguly,queue)==false){
				czyznowu=false;
				}
		//	pomoc[i]=NULL;
		}
		//printf("Dupa\n\n");
		//k=0;
		}
		
	}
	
	if(czyznowu==true){
		return true;
	}
return false;
}
