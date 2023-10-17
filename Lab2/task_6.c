// Copyright: 2023 Jakub Korytko

#include <stdio.h>

int main() {
    int a;

    printf("Enter the number: ");
    scanf("%d", &a);

    if (a%2 == 0) {
        printf("Even");
    } else {
        printf("Odd");
    }

    return 0;
}
