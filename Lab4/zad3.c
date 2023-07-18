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

int numberLength(long long int number)
{

    int length = 0;

    while (number != 0)
    {
        number /= 10;
        length++;
    }

    return length;
}

int numberIntoArray(int size, long long int number)
{

    int res = 1;
    int isFirstPresentOccurence = 0;
    int j = 0;

    int arr[size];
    int alreadyPrintedNumbers[size];

    for (int i = 0; i < size; i++)
    {

        int num = number % 10;

        if (isPresent(arr, i, num) == 1 && isPresent(alreadyPrintedNumbers, j, num) == 0)
        {
            alreadyPrintedNumbers[j] = num;
            j++;
            if (isFirstPresentOccurence == 0)
            {
                printf("Powtarzajace sie cyfry: ");
                isFirstPresentOccurence = 1;
            }
            else
            {
                printf(", ");
            }
            printf("%d", num);
            res = 0;
        }

        arr[i] = num;

        number /= 10;
    }

    return res;
}

int main()
{

    long long int x;

    printf("Podaj liczbe: ");
    scanf("%lld", &x);

    printf("\n%lld\n", x);

    int res = numberIntoArray(numberLength(x), x);

    if (res)
    {
        printf("Cyfry sa rozne");
    }
}