
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM_RIGA 200
#define NUM_RIGHE 200
#define LUNG 100

typedef struct
{
    char *titolo;
    char *autore;
    int anno;
} Libro;

int leggiFile(Libro *lista, char nome[])
{
    FILE *fp;
    char *campo;
    char riga[DIM_RIGA];
    int numLibri = 0;
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
            campo = strtok(riga, ",");
            lista->titolo = strdup(campo);
            campo = strtok(NULL, ",");
            lista->autore = strdup(campo);
            campo = strtok(NULL, ",");
            lista->anno = atoi(campo);
            lista++;
            numLibri++;
        }
        fclose(fp);
    }
    return numLibri;
}

void scambio(Libro *a, Libro *b)
{
    Libro c;
    c = *a;
    *a = *b;
    *b = c;
}

void bubbleSort(Libro vett[], int n)
{
    int sup, sca, z;
    sup = n - 1;
    while (sup > 0)
    {
        sca = 0;
        for (Libro *p = vett; p < vett + n - 1; p++)
        {
            if (p->anno < (p + 1)->anno)
            {
                scambio(p, p + 1);
                sca = p->anno;
            }
        }
        sup = sca;
    }
}

void stampaArchivio(Libro vett[], int n)
{
    for (Libro *p = vett; p < vett + n; p++)
    {
        printf("%s, %s, %d\n", p->titolo, p->autore, p->anno);
    }
    printf("\n");
}

void stampaAnno(Libro lista[], int n){
    int anno;
    printf("inserisci l'anno: ");
    scanf("%d", &anno);
    for(Libro *p = lista; p < lista+n; p ++) {
        if(p->anno == anno){
            printf("%s %s %d\n", p->titolo, p->autore, p->anno);
        }
    }
}

int main()
{
    Libro *l;
    l = (Libro *)malloc(NUM_RIGHE * sizeof(Libro));
    int nRighe = leggiFile(l, "fileLibri.csv");
    stampaArchivio(l, nRighe);
    bubbleSort(l, nRighe);
    stampaAnno(l, nRighe);
    free(l);

    return 0;
}