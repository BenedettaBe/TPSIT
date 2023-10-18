#include <stdio.h>
#include <stdlib.h>
#define DIM_MAX 3

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


int main()
{
    int vet[DIM_MAX];
    for (int *k = vet; k < vet+DIM_MAX; k++)
    {
        printf("Inserisci un valore per la cella\n");
        scanf("%d",k);
    }
    printf("Vettore disordinato: \n");
    for (int *i = vet; i < vet+DIM_MAX; i++)
    {
        printf("%d ", *i);
    }
    bubbleSort3(vet, DIM_MAX);
    printf(" \nVettore ordinato: \n");
    for (int *j = vet; j < vet+DIM_MAX; j++)
    {
        printf("%d", *j);
    }
}
