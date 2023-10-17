// Copyright: 2023 Jakub Korytko
// LINT_C_FILE

#include <stdio.h>
#include <stdlib.h>

int numberLength(
    long long int number  // NOLINT(runtime/int)
    /* C++ specific warning, but it's a C file*/ ) {
    int length = 0;

    while (number != 0) {
        number /= 10;
        length++;
    }

    return length;
}

int main() {
    int x;

    printf("Enter the number: ");
    scanf("%d", &x);

    int size = numberLength(x);

    int *arr = (int *)malloc(size * sizeof(int));

    if (!arr) {
        printf("Failed to allocate memory");
        exit(1);
    }

    for (int i = 0; i < size; i++) {
        arr[i] = x % 10;

        x /= 10;
    }

    int halfSize = size / 2;

    char *res_string = "The number is a palindrome";

    for (int i = 0; i < halfSize; i++) {
        if (arr[i] != arr[size - i - 1]) {
            res_string = "The number is not a palindrome";
        }
    }

    printf("%s", res_string);

    return 0;
}
