#include <stdio.h>
#include <stdlib.h>

#include "student.h"

int student_compare_birth_date(const void *a, const void *b)
{
    STUDENT *pa = (STUDENT *)a;
    STUDENT *pb = (STUDENT *)b;

    return date_compare(pa->birth_date, pb->birth_date);
}

int main(void)
{
    int n;
    do
    {
        printf("Unesite broj studenata: ");
        scanf("%d", &n);
    } while (n < 1 ? printf("Broj studenata mora biti prirodan broj.\n") : 0);

    STUDENT arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = student_input();
    }

    qsort(arr, n, sizeof(STUDENT), student_compare_birth_date);

    student_print_table(n, arr);

    return 0;
}