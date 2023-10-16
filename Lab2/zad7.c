// Copyright: 2023 Jakub Korytko

#include <stdio.h>

int main() {
    int a;
    int b;
    int c = 3;

    while (c != 4) {
        if (c == 3) {
            printf("Podaj liczbe a: ");
            scanf("%d", &a);

            printf("Podaj liczbe b: ");
            scanf("%d", &b);
        }

        printf(
        "\nOblicz:\n"
        "1. a+b\n"
        "2. a-b\n"
        "3. Zmien liczby\n"
        "4. Koniec\n\n"
        "(Wpisz odpowiedni numer oraz potwierdz enterem) "
        "Wybor: ");

        scanf("%d", &c);

        if (c == 1) {
            printf("\na + b = %d\n", (a + b));
        } else if (c == 2) {
            printf("\na - b = %d\n", (a - b));
        } else {
            if (c != 4 && c != 3) {
                printf("Niepoprawny wybor");
            }
        }
    }

    return 0;
}
