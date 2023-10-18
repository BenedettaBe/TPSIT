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

int leggiFile(Film lista[], char nome[]){
    FILE *fp;
    int counter = 0;
    char* campo;
    char riga[DIM_RIGA];
    fp = fopen(nome, "r");
    if(fp == NULL) {
        printf("il file non esiste");
        exit(1);
    }
    Film *p = lista;
    while(fgets(riga, DIM_RIGA, fp)) {
        campo = strtok(riga,",");
        p->num = atoi(campo);//atoi stringa in intero
        campo = strtok(NULL,",");
        p->titolo = strdup(campo);
        campo = strtok(NULL,",");
        p->genere = strdup(campo);
        campo = strtok(NULL,",");
        p->anno = atoi(campo);
        campo = strtok(NULL,",");
        p->disp = strdup(campo);
        p ++;
        counter ++;
    }
    fclose(fp);
    return counter;
}

int main () {
    Film lista[NUM_RIGHE];
    char nome[] = "listafilm.csv";
    int counter = leggiFile(lista, nome);
    int anno;
    printf("inserisci l'anno: ");
    scanf("%d", &anno);
    for(Film *p = lista; p < lista+counter; p ++) {
        if(p->anno == anno){
            printf("%d %s %s %d %s\n", p->num, p->titolo, p->genere, p->anno, p->disp);
        }
    }

    return 0;
}