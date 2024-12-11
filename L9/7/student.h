#pragma once

#include "date.h"

typedef struct
{
    char index_number[8];
    char name[15];
    char surname[20];
    DATUM birth_date;
    float grade;
} STUDENT;

STUDENT student_input();
void student_print_table(int n, STUDENT arr[]);