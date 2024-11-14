#include <stdio.h>
#include <math.h>

int main(void)
{
    float a, b, c;

    do
    {
        printf("Unesite stranicu a: ");
        scanf("%f", &a);
    } while (a < 0 ? (printf("Stranica a mora biti nenegativna.\n"), 1) : 0);

    do
    {
        printf("Unesite stranicu b: ");
        scanf("%f", &b);
    } while (b < 0 ? (printf("Stranica b mora biti nenegativna.\n"), 1) : 0);

    do
    {
        printf("Unesite stranicu c: ");
        scanf("%f", &c);
    } while (c < 0 ? (printf("Stranica c mora biti nenegativna.\n"), 1) : 0);

    printf("\n");

    if (a + b <= c || a + c <= b || b + c <= a)
    {
        printf("Trougao se ne moze konstruisati.\n");
        return 1;
    }

    if (a == b && b == c)
    {
        printf("Trougao je jednakostranicni.\n");
    }
    else if (a == b || b == c || a == c)
    {
        printf("Trougao je jednakokraki.\n");
    }
    else
    {
        printf("Trougao je raznostranicni.\n");
    }

    if (a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a)
    {
        printf("Trougao je pravougli.\n");
    }

    printf("\n");

    float circumference = a + b + c;
    float s = circumference / 2;
    float area = sqrt(s * (s - a) * (s - b) * (s - c));

    printf("Povrsina: %.2f\n", area);
    printf("Obim: %.2f\n", circumference);

    return 0;
}