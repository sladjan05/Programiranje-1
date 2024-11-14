#include <stdio.h>
#include <math.h>

int main(void)
{
    int n;

    do
    {
        printf("Unesite broj n: ");
        scanf("%d", &n);
    } while (n < 1 ? (printf("Broj n mora biti prirodan.\n"), 1) : 0);

    float min = INFINITY;

    while (n--)
    {
        float num;
        scanf("%f", &num);

        if (num < min)
        {
            min = num;
        }
    }

    printf("\n");
    printf("Najmanji broj je %f.\n", min);

    return 0;
}