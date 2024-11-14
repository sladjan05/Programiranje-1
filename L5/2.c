#include <stdio.h>

int main(void)
{
    int n;

    do
    {
        printf("Unesite broj n: ");
        scanf("%d", &n);
    } while (n < 1 ? (printf("Broj n mora biti prirodan.\n"), 1) : 0);

    int positiveCount = 0;

    while (n--)
    {
        int num;
        scanf("%d", &num);

        if (num > 0)
        {
            positiveCount++;
        }
    }

    printf("\n");
    printf("Pozitivnih brojeva ima %d.\n", positiveCount);

    return 0;
}