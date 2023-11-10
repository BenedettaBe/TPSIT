/*leggere un file csv di un ospedale in cui c'è scitto
nome e cognome di una persona, data di ricovero e stato attuale(ricoverato/non rcoverato)
realizzare un programma che
- stampi tutti i dati
- chiesto un nome in input stampi lo stato
- stampi tutti i pazienti ancora ricoverati
- dato un giorno stampa tutte le persone ricoverate quel giorno*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXPAZIENTI 50
#define DIMRIGA 100

typedef struct
{
    char *nome;
    char *cognome;
    int data;
    char *stato;
} Paziente;

int leggiFile(char *nome, Paziente *pt)
{
    FILE *fp;
    fp = fopen(nome, "r");
    char riga[DIMRIGA];
    char *campo;
    int numRighe = 0;
    if (fp == NULL)
    {
        printf("c'e' stato un problema con il file");
        exit(1);
    }
    else
    {
        while (fgets(riga, DIMRIGA, fp))
        {
            campo = strtok(riga, ",");
            pt->nome = strdup(campo);
            campo = strtok(NULL, ",");
            pt->cognome = strdup(campo);
            campo = strtok(NULL, ",");
            pt->data = atoi(campo);
            campo = strtok(NULL, ",");
            pt->stato = strdup(campo);
            pt++;
            numRighe++;
        }
        fclose(fp);
    }
    return numRighe;
}

void stampaOspedale(Paziente p[], int n)
{
    for (Paziente *k = p; k < p + n; k++)
    {
        printf("Paziente: %s %s %d %s\n", k->nome, k->cognome, k->data, k->stato);
    }
}

void stampaPaziente(Paziente* p, int n)
{
    int tro = -1; // falso
    char *nome;
    printf("inserisci cognome: ");
    fflush(stdin);
    scanf("%s", nome);
     for (Paziente *j = p; j < p + n; j++)
    {
        if (strcmp(j->cognome, nome) == 0){
            printf("%s %s  stato: %s\n", j->nome, j->cognome, j->stato);
            tro=1;
            }
    }
    if(tro == -1){
        printf("paziente non trovato!!!");
    }
}

void stampaRicoverati(Paziente* p, int n)
{
     for (Paziente *j = p; j < p + n; j++)
    {
        if (strcmp(j->stato, "ricoverato") == 0){
             printf("Paziente: %s %s %d %s\n", j->nome, j->cognome, j->data, j->stato);
            }
    }
}

void stampaDaData(Paziente* p, int n)
{
    int data;
    printf("inserisci data: ");
    scanf("%d", &data);
     for (Paziente *j = p; j < p + n; j++)
    {
        if (j->data == data){
             printf("Paziente: %s %s %d %s\n", j->nome, j->cognome, j->data, j->stato);
            }
    }
}

int main()
{
    Paziente *ospedale;
    ospedale = (Paziente *)malloc(MAXPAZIENTI * sizeof(Paziente *));
    int numRighe = leggiFile("ospedale.csv", ospedale);
    stampaOspedale(ospedale, numRighe);
    stampaPaziente(ospedale, numRighe);
    stampaRicoverati(ospedale, numRighe);
    stampaDaData(ospedale, numRighe);

    free(ospedale);
    return 0;
}