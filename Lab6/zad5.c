#include <stdio.h>
#include <ctype.h>

int main() {

    char text[26];

    for (int i=0; i<26; i++) {
        text[i] = 0;
    }

    FILE *fp;
    fp = fopen("zad3-5_DATA.txt", "r");

    do
    {
        int x = tolower(fgetc(fp));
        if (x >= 97 && x <=122) {
            text[x-97] += 1;
        }

        if (feof(fp))
            break;

    }  while(1);

    for (int i=0; i<26; i++) {

        if (text[i] != 0) {
            printf("%c: %d\n", i+97, text[i]);
        }
    }

    return 1;

}