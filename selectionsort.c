
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void scambio(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    // selectionSort
    int vett[5] = {7, 5, 9, 8, 4};
    int n = 5;
    int *kmin;

    printf("%d\n", vett);
    for (int *k = vett; k < vett + n; k++)
    {
        kmin = k;
        for (int *j = k + 1; j < k + n; j++)
        {
            if (*kmin > *j)
                kmin = j;
        }
        if (kmin != k)
            scambio(k, kmin);
        
    }

    for (int *j = vett; j < (vett + n); j++)
    {
        printf("%d\n", *j);
    }

    return 0;
}