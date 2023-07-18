#include <stdio.h>
#include <string.h>

int main() {

    const int string_max_length = 100;
    char string[string_max_length];

    printf("Podaj ciag znakow: ");
    fgets(string, string_max_length, stdin);
    string[strcspn(string, "\r\n")] = 0;

    int string_length = strlen(string);

    int p = 0;

    printf("Odwrocony kazdy z wyrazow: ");

    for (int i = 0; i<string_length; i++) {

        if (string[i] == ' ' || i==string_length-1) {
            int j = i-1;
            if (i==string_length-1) {
                j+=1;
            }
            for (; j>=p; j--) {
                printf("%c", string[j]);
            }   
            p=i+1;
            printf(" ");
        }
    }

    return 0;
}