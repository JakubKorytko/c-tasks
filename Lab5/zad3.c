#include <stdio.h>
#include <math.h>

int multiple(int tab[], int size, int index)
{
    for (int i = index; i < size; i += index)
    {
        tab[i] = 1;
    }
    return 0;
}

int main()
{

    int n;

    printf("Podaj n przedzialu [2,n]: ");
    scanf("%d", &n);

    int size = n + 1;

    if (n > 1)
    {
        int tab[size];

        for (int i = 2; i < size; i++)
        {
            tab[i] = 0;
        }

        for (int i = 2; i <= sqrt(n); i++)
        {
            
            if (tab[i] == 0)
            {
                for (int j = 2*i; j < size; j += i)
                {
                    tab[j] = 1;
                }
            }
        }

        printf("Liczby pierwsze z przedzialu [2,%d]: ", n);

        for (int i = 2; i < size; i++)
        {
            if (tab[i] == 0)
            {
                printf("%d ", i);
            }
        }
    }
    else
    {
        printf("Podano n mniejsze niz 2");
    }

    return 0;
}