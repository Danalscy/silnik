#include "interfejs.h"
#define BUFSIZE 8192
void read_table(FILE *dane,vector_t *tab){
 char buf[BUFSIZE];
 fgets(buf,BUFSIZE,dane);
 int n=atoi(buf);
 init(tab,n);
 int ile_wyraz=0;
 int j;
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
 }
}

void wnioskowanie_przod (FILE *wzory,vector_t *tabela){
char pch[200];
 char * boolString[2] = {"FALSE", "TRUE"};
 char final[200];
 char finalword[20];
 int i,j,k=1;
 char bufwzory[BUFSIZE];
 while(fgets(bufwzory,BUFSIZE,wzory)!=NULL){
        printf("Przykład %d:\n",k);
        k++;
        strtok(bufwzory, "\n");
        strcpy(pch,bufwzory);
        for(i=0;i<tabela->size;i++){
                char temp[2];
                sprintf(temp, "%d", szukaj(tabela->para[i].word,tabela));
                strcpy(pch,replace_str(pch,tabela->para[i].word,temp));
        }
        strcpy(pch,replace_str(pch,"&&","&"));
        strcpy(pch,replace_str(pch,"||","|"));
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
        printf("%s\nWyrazenie %s jest %s\n%s\n\n",pch,final,boolString[result],finalword);

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
                }
        else
                add(tabela,finalword,1);
        }
 }

}
