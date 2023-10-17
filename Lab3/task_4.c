// Copyright: 2023 Jakub Korytko

#include <stdio.h>
#include <math.h>

int main() {
    int x;

    printf("Enter the number to check: ");
    scanf("%d", &x);

    int y = 1;

    for (int i = 2; i < sqrt(x); i++) {
        if (x % i == 0) {
            y = 0;
        }
    }

    if (y == 1 && x > 1) {
        printf("The number %d is prime", x);
    } else {
        printf("The number %d is not prime", x);
    }

    return 0;
}
