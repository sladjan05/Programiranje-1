#include <stdio.h>

int factorial(int n)
{
    int result = 1;

    for (int i = 2; i <= n; i++)
    {
        result *= i;
    }

    return result;
}

int sum_of_factorial_digits(int n)
{
    int sum = 0;

    while (n)
    {
        sum += factorial(n % 10);
        n /= 10;
    }

    return sum;
}

int main(void)
{
    int n;

    do
    {
        printf("n=");
        scanf("%d", &n);
    } while (n < 1 ? (printf("n mora biti prirodan broj.\n"), 1) : 0);

    while (n--)
    {
        if (sum_of_factorial_digits(n) == n)
        {
            printf("Trazeni broj je %d.\n", n);

            return 0;
        }
    }

    printf("Trazeni broj ne postoji.\n");

    return 0;
}