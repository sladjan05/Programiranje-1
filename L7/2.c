#include <stdio.h>
#include <math.h>

#define SQR(x) ((x) * (x))

int main(void)
{
    int n;
    do
    {
        printf("n=");
        scanf("%d", &n);
    } while (n < 1 ? printf("n mora biti pozitivan.\n") : 0);

    int a[n], b[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &b[i]);
    }

    int d2 = 0;
    for (int i = 0; i < n; i++)
    {
        d2 += SQR(a[i] - b[i]);
    }

    printf("Euklidska udaljenost iznosi %f.\n", sqrt(d2));

    return 0;
}