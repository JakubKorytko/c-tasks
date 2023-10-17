// Copyright: 2023 Jakub Korytko

#include <stdio.h>
#include <string.h>

#define StringMaxLength 100

int main() {
    char string[StringMaxLength];

    printf("Enter a string of characters: ");
    fgets(string, StringMaxLength, stdin);
    string[strcspn(string, "\r\n")] = 0;

    int string_length = strlen(string);

    int p = 0;

    printf("Each word reversed: ");

    for (int i = 0; i < string_length; i++) {
        if (string[i] == ' ' || i == string_length-1) {
            int j = i-1;
            if (i == string_length-1) {
                j+=1;
            }
            for (; j >= p; j--) {
                printf("%c", string[j]);
            }
            p = i + 1;
            printf(" ");
        }
    }

    return 0;
}
