#include <stdio.h>
#include <stdlib.h>
/*
Scrivi un programma in linguaggio C che consenta all'utente di creare un array dinamico
di interi. Il programma dove avere una dimensione array specificata, usando la
funzione malloc per allocare in modo dinamico gli interi.
L’utente deve poter inserire valori interi, che verranno stampati. Assicurarsi di liberare la
memoria allocata dinamicamente utilizzando la funzione free alla fine del
programma per evitare perdite di memoria.
*/

#define DIM 5

void caricaArray(int array[], int n){
    printf("inserisci gli elementi dell'array: ");
    for(int *p = array; p < array+n; p++){
        scanf("%d", p);
    }
}

void stampaArray(int array[], int n){
    for(int *p = array; p < array+n; p++){
        printf("%d ", *p);
    }
}

int main(){ 
    int* array;
    array = (int*) malloc(DIM * sizeof(int));
    caricaArray(array, DIM);
    stampaArray(array, DIM);
    free(array);

    return 0;
}