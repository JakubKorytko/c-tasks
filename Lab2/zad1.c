// Copyright: 2023 Jakub Korytko

#include <stdio.h>

int main() {
    const int a = 10;
    const int b = 5;

    printf("Liczby to: %d oraz %d", a, b);

    printf("\nSuma: %d\nRoznica: %d\nIloczyn: %d\nIloraz: %d\nModulo: %d",
    a+b, a-b, a*b, a/b, a%b);

    return 0;
}
