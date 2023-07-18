#include <stdio.h>
#include <string.h>
#include <ctype.h>

char character(char string, int i) {

    char c = string;
    c+=i;
    if (c>122) {
        c-=26;
    } 
    if (c<97) {
        c+=26;
    }
    return c;
}

int main() {

    const int string_max_length = 100;
    char string[string_max_length];
    int choice = 0;

    printf("Podaj ciag znakow: ");
    fgets(string, string_max_length, stdin);
    string[strcspn(string, "\r\n")] = 0;

    printf("Wybierz opcje z menu:\n\n1. Szyfrowanie\n2. Deszyfrowanie\n\nWybor: ");
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

    for (int i = 0; i<string_length; i++) {
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