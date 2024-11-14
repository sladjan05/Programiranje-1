#include <stdio.h>

int main(void)
{
    int num;

    do
    {
        printf("Unesite prirodan broj: ");
        scanf("%d", &num);
    } while (num < 1 ? (printf("Broj mora biti prirodan.\n"), 1) : 0);

    int num_copy = num;
    int sum = 0;
    while (num_copy)
    {
        sum += num_copy % 10;
        num_copy /= 10;
    }

    printf("Suma cifara broja %d je %d.\n", num, sum);

    return 0;
}