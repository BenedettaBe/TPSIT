
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
#define LUNG 20

typedef struct 
{
    int anno;
    int mese;
    int giorno;
}Data;

typedef struct 
{
    char cognome[LUNG];
    char nome[LUNG];
    Data nascita;
}Persona;

void leggiFile(Persona *classe, char nome[], int n){
    FILE *fp;
    char* campo;
    char riga[DIM_RIGA];
    fp = fopen(nome, "r");
    if(fp == NULL) {
        printf("il file non esiste");
        exit(1);
    }
    while(fgets(riga, DIM_RIGA, fp)) {
        campo = strtok(NULL,",");
        strcpy(classe->cognome, campo);
        campo = strtok(NULL,",");
        strcpy(classe->cognome, campo);
        campo = strtok(NULL,",");
        classe->nascita.anno = atoi(campo);
        campo = strtok(NULL,",");
        classe->nascita.mese = atoi(campo);
        campo = strtok(NULL,",");
        classe->nascita.giorno = atoi(campo);
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

void scambio(int *a, int *b)
{
    int c;
    c = *a;
    *a = *b;
    *b = c;
}

void bubbleSort3(int vett[], int n)
{
    int *k, sup, sca;
    sup = n - 1;
    int j;
    while (sup > 0)
    {
        j=0;
        sca = 0;
        for (k = vett; k < vett+sup; k++)
        {
            if (*k > *(k + 1))
            {
                scambio(k, (k + 1));
                sca = j;
            }
            j++;
        }
        sup = sca;
    }
}


int main () {
    char nome[] = "classe.csv";
    int numRighe = contaRighe(nome);
    Persona *p;
    p = (Persona*) malloc (numRighe * sizeof(Persona));
    Persona *classe=p;

    leggiFile(classe, nome, numRighe);
    bubbleSort3(classe, numRighe);
    for(Persona *k = classe; k < classe+numRighe; k ++) {
           printf("%s %s %d %d %d\n", k->cognome, k->nome, k->nascita.anno, k->nascita.mese, k->nascita.giorno);
    }

    return 0;
}