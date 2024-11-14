#include <stdio.h>

int gcd(int a, int b)
{
    while (b != 0)
    {
        int t = b;
        b = a % b;
        a = t;
    }

    return a;
}

int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

int main(void)
{
    int a, b;

    do
    {
        printf("Unesite dva prirodna broja: ");
        scanf("%d %d", &a, &b);
    } while (a < 1 || b < 1 ? (printf("Brojevi moraju biti prirodni.\n"), 1) : 0);

    printf("Najmanji zajednicki sadrzilac brojeva %d i %d je %d.\n", a, b, lcm(a, b));

    return 0;
}