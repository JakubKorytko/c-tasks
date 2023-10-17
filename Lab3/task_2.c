// Copyright: 2023 Jakub Korytko

#include <stdio.h>

int main() {
    printf("Liczby podzielne przez 3 w przedziale 1-200: ");

    for (int i = 1; i <= 200; i++) {
        if (i % 13 == 0) {
            printf("%d", i);
            if (i + 13 <= 200) {
                printf(", ");
            }
        }
    }

    return 0;
}
