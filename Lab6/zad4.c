#include <stdio.h>

int main() {

    FILE *fp;
    fp = fopen("zad3-5_DATA.txt", "r");

    fseek(fp, 0, SEEK_END);
    printf("Ilosc znakow w pliku zad3-5_DATA.txt: %d", ftell(fp));

    fclose(fp);

    return 1;
}