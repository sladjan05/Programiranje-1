#include <stdio.h>
#include <stdlib.h>

#include "complex.h"

int cx_compare_modulo(const void *a, const void *b)
{
    KOMPLEKS *c1 = (KOMPLEKS *)a;
    KOMPLEKS *c2 = (KOMPLEKS *)b;

    return cx_modulo(*c2) - cx_modulo(*c1);
}

int main(void)
{
    int n;
    do
    {
        printf("Unesite n: ");
        scanf("%d", &n);
    } while (n < 1 ? printf("n mora biti pozitivan.\n")
                   : 0);

    KOMPLEKS arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Unesite %d. kompleksan broj: ", i + 1);
        arr[i] = cx_input();
    }

    qsort(arr, n, sizeof(KOMPLEKS), cx_compare_modulo);

    printf("Sortirani niz: \n");
    for (int i = 0; i < n; i++)
    {
        cx_print(arr[i]);
        printf("\n");
    }

    return 0;
}