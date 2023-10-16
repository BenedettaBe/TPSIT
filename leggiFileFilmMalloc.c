/*
author: Bergia Benedetta
date:
es:
testo
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM_RIGA 200

#define NUM_RIGHE 200

typedef struct {
    int num;
    char* titolo;
    char* genere;
    int anno;
    char* disp;
} Film;

void leggiFile(Film *lista, char nome[], int n){
    FILE *fp;
    char* campo;
    char riga[DIM_RIGA];
    fp = fopen(nome, "r");
    if(fp == NULL) {
        printf("il file non esiste");
        exit(1);
    }
    while(fgets(riga, DIM_RIGA, fp)) {
        campo = strtok(riga,",");
        lista->num = atoi(campo);//atoi stringa in intero
        campo = strtok(NULL,",");
        lista->titolo = strdup(campo);
        campo = strtok(NULL,",");
        lista->genere = strdup(campo);
        campo = strtok(NULL,",");
        lista->anno = atoi(campo);
        campo = strtok(NULL,",");
        lista->disp = strdup(campo);
        lista ++;
    }
    fclose(fp);
}

int contaRighe(char nome[]){
    FILE *fp;
    int counter = 0;
    char* campo;
    char riga[DIM_RIGA];
    fp = fopen(nome, "r");
    if(fp == NULL) {
        printf("il file non esiste");
        exit(1);
    }
    while(fgets(riga, DIM_RIGA, fp)) {
        counter ++;
    }
    fclose(fp);
    return counter;
}

int main () {
    char nome[] = "listafilm.csv";
    int numRighe = contaRighe(nome);
    Film *p;
    p = (Film*) malloc (numRighe * sizeof(Film));
    Film *lista=p;
    leggiFile(lista, nome, numRighe);
    /*int anno;
    printf("inserisci l'anno: ");
    scanf("%d", &anno);*/
    for(Film *p = lista; p < lista+numRighe; p ++) {
        //if(p->anno == anno){
            printf("%d %s %s %d %s\n", p->num, p->titolo, p->genere, p->anno, p->disp);
        //}
    }

    return 0;
}