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

#define NUM_RIGHE 20000

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
    while(fgets(riga, DIM_RIGA, fp)) {
        campo = strtok(riga,",");
        lista[counter].num = atoi(campo);//atoi stringa in intero
        campo = strtok(NULL,",");
        lista[counter].titolo = strdup(campo);
        campo = strtok(NULL,",");
        lista[counter].genere = strdup(campo);
        campo = strtok(NULL,",");
        lista[counter].anno = atoi(campo);
        campo = strtok(NULL,",");
        lista[counter].disp = strdup(campo);
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
     for(int k = 0; k < counter; k ++) {
        if(lista[k].anno == anno){
            printf("%d %s %s %d %s\n", lista[k].num, lista[k].titolo, lista[k].genere, lista[k].anno, lista[k].disp);
        }
    }

    return 0;
}