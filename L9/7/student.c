#include "student.h"

#include <stdio.h>

#include "date.h"

STUDENT student_input()
{
    STUDENT s;

    printf("========================================\n");
    printf("Broj indeksa:       ");
    scanf("%s", &s.index_number);
    printf("Ime:                ");
    scanf("%s", s.name);
    printf("Prezime:            ");
    scanf("%s", s.surname);
    printf("Datum rodenja:      ");
    scanf("%d.%d.%d.", &s.birth_date.day, &s.birth_date.month, &s.birth_date.year);
    printf("Prosjek:            ");
    scanf("%f", &s.grade);
    printf("========================================\n");

    return s;
}

void student_print_table(int n, STUDENT arr[])
{
    printf("RB. PREZIME         IME             DATUM RODJ. PROSJEK\n");
    printf("=== =============== =============== =========== =======\n");

    for (int i = 0; i < n; i++)
    {
        STUDENT s = arr[i];
        printf("%2d. %-15s %-15s %02d.%02d.%4d. %6.2f\n", i + 1, s.surname, s.name, s.birth_date.day, s.birth_date.month, s.birth_date.year, s.grade);
    }

    printf("=== =============== =============== =========== =======\n");
}