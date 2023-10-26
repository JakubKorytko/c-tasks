// Copyright: 2023 Jakub Korytko
// LINT_C_FILE

// C++ specific warning, but it's a C file
// NOLINTNEXTLINE(runtime/int)
#define LL long long int

#include <stdio.h>
#include <stdlib.h>

int isPresent(int *arr, int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return 1;
        }
    }
    return 0;
}

int numberLength(LL number) {
    int length = 0;

    while (number != 0) {
        number /= 10;
        length++;
    }

    return length;
}

int numberIntoArray(int size, LL number) {
    int res = 1;
    int isFirstPresentOccurence = 0;
    int j = 0;

    int *arr = (int *)malloc(size * sizeof(int));
    int *alreadyPrintedNumbers = (int *)malloc(size * sizeof(int));

    if (!arr || !alreadyPrintedNumbers) {
        printf("Failed to allocate memory");
        exit(1);
    }

    for (int i = 0; i < size; i++) {
        int num = number % 10;

        if (
        isPresent(arr, i, num) == 1 &&
        isPresent(alreadyPrintedNumbers, j, num) == 0) {
            alreadyPrintedNumbers[j] = num;
            j++;
            if (isFirstPresentOccurence == 0) {
                printf("Repeated digits: ");
                isFirstPresentOccurence = 1;
            } else {
                printf(", ");
            }
            printf("%d", num);
            res = 0;
        }

        arr[i] = num;

        number /= 10;
    }

    if (arr) {
        free(arr);
    }

    if (alreadyPrintedNumbers) {
        free(alreadyPrintedNumbers);
    }

    printf("\n");

    return res;
}

int main() {
    LL x;

    printf("Enter the number: ");
    scanf("%lld", &x);

    printf("\n%lld\n", x);

    int res = numberIntoArray(numberLength(x), x);

    if (res) {
        printf("The numbers are different");
    }
}
