#include <stdio.h>

int sum_of_divisors(int n)
{
    int sum = 0;

    for (int i = 1; i <= n / 2; i++)
    {
        if (n % i == 0)
        {
            sum += i;
        }
    }

    return sum;
}

int main(void)
{
    int a, b;

    do
    {
        printf("Unesite dva prirodna broja: ");
        scanf("%d %d", &a, &b);
    } while (a < 1 || b < 1 ? (printf("Brojevi moraju biti prirodni.\n"), 1) : 0);

    printf("%d i %d %s prijateljski brojevi.\n",
           a, b,
           sum_of_divisors(a) == b && sum_of_divisors(b) == a ? "su" : "nisu");

    return 0;
}