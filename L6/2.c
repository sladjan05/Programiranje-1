#include <stdio.h>

int is_prime(int n)
{
    if (n < 2)
    {
        return 0;
    }

    for (int i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }

    return 1;
}

int main(void)
{
    int n;

    do
    {
        printf("n=");
        scanf("%d", &n);
    } while (n < 1 ? (printf("n mora biti prirodan broj.\n"), 1) : 0);

    while (1)
    {
        if (is_prime(++n))
        {
            printf("Trazeni prost broj je %d.\n", n);
            break;
        }
    }

    return 0;
}