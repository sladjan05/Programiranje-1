#include <stdio.h>
#include <stdlib.h>

#include "product.h"

int prod_compare_id(const void *a, const void *b)
{
    ARTIKAL *pa = (ARTIKAL *)a;
    ARTIKAL *pb = (ARTIKAL *)b;
    return pa->id - pb->id;
}

int main(void)
{
    int n;
    do
    {
        printf("Unesite broj artikala: ");
        scanf("%d", &n);
    } while (n < 1 ? printf("Broj artikala mora biti prirodan broj.\n") : 0);

    ARTIKAL arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = prod_input();
    }

    qsort(arr, n, sizeof(ARTIKAL), prod_compare_id);

    prod_print_table(n, arr);

    return 0;
}