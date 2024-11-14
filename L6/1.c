#include <stdio.h>

int _pow(int base, int exp)
{
    int result = 1;

    for (int i = 0; i < exp; i++)
    {
        result *= base;
    }

    return result;
}

int main(void)
{
    int b;

    do
    {
        printf("Unesite broj b: ");
        scanf("%d", &b);
    } while (b < 0 ? (printf("Broj b mora biti nenegativan.\n"), 1) : 0);

    int sum = 0;
    for (int i = 1; b != 0; i++)
    {
        int digit = b % 10;
        sum += _pow(digit, i);

        b /= 10;
    }

    printf("Suma je %d.\n", sum);

    return 0;
}