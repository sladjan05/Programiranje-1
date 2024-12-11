#include <stdio.h>

#include "bigint.h"

int main(void)
{
    int n;
    do
    {
        printf("Unesite n: ");
        scanf("%d", &n);
    } while (n < 1 ? printf("n mora biti pozitivan.\n") : n > 100 ? printf("n ne moze biti veci od 100.\n")
                                                                  : 0);

    BigInt fact = bi_factorial(bi_from_int(n));
    bi_print(fact);
    printf("\n");

    return 0;
}