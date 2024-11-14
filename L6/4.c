#include <stdio.h>
#include <math.h>

#define EPS 1e-5

int main(void)
{
    float x;
    int n;

    do
    {
        printf("x=");
        scanf("%f", &x);
    } while (x < 0 ? (printf("x mora biti nenegativan.\n"), 1) : 0);

    do
    {
        printf("n=");
        scanf("%d", &n);
    } while (n < 1 ? (printf("n mora biti pozitivan.\n"), 1) : 0);

    float x_i = (x + 1) / n;
    while (1)
    {
        float x_i_next = ((n - 1) * x_i + x / pow(x_i, n - 1)) / n;

        if (fabs(x_i_next - x_i) < EPS)
        {
            break;
        }

        x_i = x_i_next;
    }

    printf("Korijen broja %.5f je %.5f.\n", x, x_i);

    return 0;
}