#include <stdio.h>
#include <stdbool.h>

char *MONTH_NAMES[] = {"JANUAR",
                       "FEBRUAR",
                       "MART",
                       "APRIL",
                       "MAJ",
                       "JUN",
                       "JUL",
                       "AVGUST",
                       "SEPTEMBAR",
                       "OKTOBAR",
                       "NOVEMBAR",
                       "DECEMBAR"};

int MONTH_DAYS[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool is_leap_year(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int main(void)
{
    int month, year;

    do
    {
        printf("Unesite mjesec i godinu: ");
        scanf("%d %d", &month, &year);
    } while (month < 1 || month > 12 ? (printf("Neispravan mjesec.\n"), 1)
             : year < 1              ? (printf("Neispravna godina.\n"), 1)
                                     : 0);

    char *month_name = MONTH_NAMES[month - 1];
    int days = MONTH_DAYS[month - 1];

    if (month == 2 && is_leap_year(year))
    {
        days++;
    }

    printf("Mjesec %s %d. godine ima %d dan%c.\n",
           month_name, year,
           days, days == 31 ? '\0' : 'a');

    return 0;
}