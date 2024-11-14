#include <stdio.h>

void print_spaces(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" ");
    }
}

int main(void)
{
    int n;

    do
    {
        printf("n=");
        scanf("%d", &n);
    } while (n > 30  ? (printf("n ne moze biti veci od 30.\n"), 1)
             : n < 1 ? (printf("n mora biti pozitivan.\n"), 1)
                     : 0);

    for (int i = 1; i <= n; i++)
    {
        print_spaces(n - i);

        for (int j = 1; j <= i; j++)
        {
            printf("%d", j % 10);
        }

        for (int j = i - 1; j > 0; j--)
        {
            printf("%d", j % 10);
        }

        printf("\n");
    }

    return 0;
}