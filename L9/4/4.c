#include <stdio.h>

#include "fraction.h"

int main(void)
{
    printf("Unesite razlomke: ");
    RAZLOMAK f = frac_input();
    RAZLOMAK g = frac_input();

    printf("Zbir razlomaka: ");
    frac_print(frac_add(f, g));

    return 0;
}