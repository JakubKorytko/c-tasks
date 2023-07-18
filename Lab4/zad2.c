#include <stdio.h>

int isPresent(int *arr, int size, int value)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == value)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{

    const int size = 10;
    int j = 0;

    int a[size], b[size];

    for (int i = 0; i < size; i++)
    {
        printf("Podaj %d element tablicy: ", i + 1);
        scanf("%d", &a[i]);

        if (isPresent(a, i, a[i]) == 1 && isPresent(b, i, a[i]) == 0)
        {
            b[j] = a[i];
            j++;
        }
    }

    if (j != 0)
    {
        printf("Powtarzajace sie elementy: ");

        for (int i = 0; i < j; i++)
        {
            if (i != (j-1))
            {
                printf("%d,", b[i]);
            }
            else
            {
                printf("%d", b[i]);
            }
        }
    }
    else
    {
        printf("Brak powtarzajacych sie elementow");
    }

    return 0;
}