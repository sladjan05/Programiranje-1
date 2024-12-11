#include "product.h"

#include <stdio.h>

ARTIKAL prod_input()
{
    ARTIKAL p;

    printf("==============================\n");
    printf("Identifikator:      ");
    scanf("%d", &p.id);
    printf("Naziv:              ");
    scanf("%s", p.name);
    printf("Cijena:             ");
    scanf("%lf", &p.price);
    printf("Kolicina:           ");
    scanf("%d", &p.quantity);
    printf("==============================\n");

    return p;
}

void prod_print_table(int n, ARTIKAL arr[])
{
    printf("===== ==================== ====== ====== =========\n");
    printf("ID    NAZIV                CIJENA   KOL.    UKUPNO\n");
    printf("===== ==================== ====== ====== =========\n");

    double total = 0;
    for (int i = 0; i < n; i++)
    {
        ARTIKAL p = arr[i];
        double current_total = p.price * p.quantity;

        printf("%-5d %-20s %6.2lf %6d %9.2lf\n", p.id, p.name, p.price, p.quantity, current_total);

        total += current_total;
    }

    printf("==================================================\n");
    printf("                                 UKUPNO: %9.2lf\n", total);
    printf("==================================================\n");
}