// Copyright: 2023 Jakub Korytko

#include <stdio.h>

int main() {
    double a;
    double b;

    printf("Podaj pierwsza liczbe: ");
    scanf("%lf", &a);

    printf("Podaj druga liczbe: ");
    scanf("%lf", &b);

    printf("\nIloczyn: %lf\nIloraz: %lf", a*b, a/b);

    return 0;
}
