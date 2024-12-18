#include <stdio.h>
#include <stdbool.h>

bool prost(int n)
{
    if (n < 2)
        return false;

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }

    return true;
}

int main(void)
{
    int n;
    do
    {
        printf("n = ");
        scanf("%d", &n);
    } while (n < 0 ? printf("n mora biti prirodan broj.\n") : 0);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Prosti brojevi su: ");
    for (int i = 0; i < n; i++)
    {
        if (prost(arr[i]))
        {
            printf("%d ", arr[i]);
        }
    }

    return 0;
}