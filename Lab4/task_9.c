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

    printf("Enter a string of characters: ");
    fgets(string, StringMaxLength, stdin);
    string[strcspn(string, "\r\n")] = 0;

    printf(
    "Select an option from the menu:\n\n"
    "1. Encryption\n"
    "2. Decryption\n\n"
    "Choice: ");

    scanf("%d", &choice);

    if (choice != 1 && choice != 2) {
        printf("Wrong choice.\n");
        return 0;
    }
    int string_length = strlen(string);

    int p = 0;

    if (choice == 1) {
        printf("Each word encrypted: ");
    } else {
        printf("Each word decrypted: ");
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
