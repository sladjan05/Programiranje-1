#include <stdio.h>
#include <stdbool.h>

bool is_prime(int n)
{
    if (n < 2)
    {
        return false;
    }

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}

int main(void)
{
    int n;
    do
    {
        printf("n=");
        scanf("%d", &n);
    } while (n < 1 ? printf("n mora biti pozitivan.\n") : n >= 20 ? printf("n mora biti manji od 20.\n")
                                                                  : 0);

    int mat[n][n];
    for (int i = 0; i < n * n; i++)
    {
        scanf("%d", &mat[i / n][i % n]);
    }

    printf("Prosti brojevi u matrici su: ");
    for (int i = 0; i < n * n; i++)
    {
        if (is_prime(mat[i / n][i % n]))
        {
            printf("%d ", mat[i / n][i % n]);
        }
    }

    return 0;
}