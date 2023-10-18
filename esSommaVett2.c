#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM 5

int calcolaSomma(int vett[DIM], int n){
    int s = 0;
    for(int *p = vett; p < vett+DIM; p ++){
        s = s+*p;
    }
    return s;
}

int main(){
    int vett[DIM];
    for(int *p = vett; p < vett+DIM; p ++){
        printf("\ninserisci numero: ");
        scanf("%d", p);
    }
    int somma;
    somma = calcolaSomma(vett, DIM);

    printf("la somma = %d", somma);
    return 0;
}