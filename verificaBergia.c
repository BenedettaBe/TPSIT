#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM_RIGA 200
#define NUM_RIGHE 200
#define TOTALE 2200

typedef struct
{
    char *data;
    char *cognome;
    int quota;
} Persona;

typedef struct
{
    char *nome;
    int quota;
} Alunno;

int leggiFileTot(Persona *lista, char nome[])
{
    FILE *fp;
    char *campo;
    char riga[DIM_RIGA];
    int totale = 0;
    fp = fopen(nome, "r");
    if (fp == NULL)
    {
        printf("il file non esiste");
        exit(1);
    }
    else
    {
        while (fgets(riga, DIM_RIGA, fp))
        {
            campo = strtok(riga, ";");
            lista->data = strdup(campo);
            campo = strtok(NULL, ";");
            lista->cognome = strdup(campo);
            campo = strtok(NULL, ";");
            lista->quota = atoi(campo);
            lista++;
        }
        fclose(fp);
    }
    return totale;
}

int contaRighe(Persona *lista, char nome[])
{
    FILE *fp;
    char riga[DIM_RIGA];
    int num = 0;
    fp = fopen(nome, "r");
    if (fp == NULL)
    {
        printf("il file non esiste");
        exit(1);
    }
    else
    {
        while (fgets(riga, DIM_RIGA, fp))
        {
            num++;
        }
        fclose(fp);
    }
    return num;
}

void cercaNome(Persona *p, char nome[], int n, Alunno a)
{
    int tro = -1; // falso
    a.quota = 0;
    for (Persona *j = p; j < p + n; j++)
    {
        if (strcmp(j->cognome, nome) == 0)
        {
            printf("%s %s %d\n", j->data, j->cognome, j->quota);
            a.nome = nome;
            a.quota = a.quota + j->quota;
            tro = 1;
        }
    }
    if (tro == -1)
    {
        printf("alunno non trovato!!!");
    }
    else{
        printf("mancano %d euro", (100-a.quota));
    }
}

void controlloStudenti(Persona *p, int n)
{
    for (Persona *j = p; j < p + n; j++)
    {
        printf("\n%s %d", j->cognome, j->quota);
        if (j->quota < 100)
        {
            printf(" DA CONTROLLARE");
        }
    }
}

int totale(Persona *p, int n)
{
    int totale = 0;
    for (Persona *j = p; j < p + n; j++)
    {

        totale = totale + j->quota;
    }
    return totale;
}
int main()
{
    Persona *classe;
    int soldi;
    Alunno io;
    classe = (Persona *)malloc(NUM_RIGHE * sizeof(Persona));
    leggiFileTot(classe, "4AROB_GITA.csv");
    int numStudenti = contaRighe(classe, "4AROB_GITA.csv");
    
    int tot = totale(classe, numStudenti);
    printf("il totale e': %d\n", tot);
    if (tot < TOTALE)
    {
        soldi = TOTALE - tot;
        printf("mancano %d euro\n", soldi);
    }

printf("\n");
    cercaNome(classe, "Bergia", numStudenti, io);
printf("\n");
    controlloStudenti(classe, numStudenti);

    free(classe);

    return 0;
}