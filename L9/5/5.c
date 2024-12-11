#include <stdio.h>

#include "triangle.h"

int main(void)
{
    TROUGAO t = tr_input();

    printf("Obim trougla: %.2lf\n", tr_perimeter(t));
    printf("Povrsina trougla: %.2lf\n", tr_area(t));

    return 0;
}