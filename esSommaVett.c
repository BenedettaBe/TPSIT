#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM 5

int calcolaSomma(int vett[DIM], int n){
    int s = 0;
    for(int k= 0; k < n; k ++){
        s = (*(vett + k)) + s;
    }
    return s;
}

int main(){
    int vett[DIM]={2,3,4,5,6};
    int somma;
    somma = calcolaSomma(vett, DIM);

    printf("la somma = %d", somma);
    return 0;
}