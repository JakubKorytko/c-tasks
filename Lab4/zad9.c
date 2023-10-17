// Copyright: 2023 Jakub Korytko

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define StringMaxLength 100

char character(char string, int i) {
    char c = string;
    c+=i;
    if (c > 122) {
        c -= 26;
    }
    if (c < 97) {
        c+=26;
    }
    return c;
}

int main() {
    char string[StringMaxLength];
    int choice = 0;

    printf("Podaj ciag znakow: ");
    fgets(string, StringMaxLength, stdin);
    string[strcspn(string, "\r\n")] = 0;

    printf(
    "Wybierz opcje z menu:\n\n"
    "1. Szyfrowanie\n"
    "2. Deszyfrowanie\n\n"
    "Wybor: ");

    scanf("%d", &choice);

    if (choice != 1 && choice != 2) {
        printf("Wybrano zla opcje.\n");
        return 0;
    }
    int string_length = strlen(string);

    int p = 0;

    if (choice == 1) {
        printf("Zaszyfrowany kazdy z wyrazow: ");
    } else {
        printf("Odszyfrowany kazdy z wyrazow: ");
    }

    for (int i = 0; i < string_length; i++) {
        if (string[i] != ' ') {
            char loweredChar = tolower(string[i]);
            char c = character(loweredChar, 9-6*choice);
            printf("%c", toupper(c));
        } else {
            printf(" ");
        }
    }

    return 0;
}
