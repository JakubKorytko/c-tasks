// Copyright: 2023 Jakub Korytko

#include <stdio.h>

int main() {
    int a, b;

    printf("Enter 'a' of the rectangle: ");
    scanf("%d", &a);

    printf("Enter 'b' of the rectangle: ");
    scanf("%d", &b);

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
