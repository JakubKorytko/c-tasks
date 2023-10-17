// Copyright: 2023 Jakub Korytko

#include <stdio.h>

int main() {
    int x;
    int suma;

    printf("Oblicz sume do: ");
    scanf("%d", &x);

    for (int i = 0; i <= x; i++) {
        suma+=i;
    }

    printf("\nSuma jest rowna: %d", suma);

    return 0;
}
