#include <stdio.h>

int main() {
    FILE *fp, *fp2;
    fp = fopen("zad3-5_DATA.txt", "r");
    fp2 = fopen("zad3.txt", "w");

    do
    {
        char c = fgetc(fp);

        if (feof(fp))
            break;

        fputc(c, fp2);

    }  while(1);


    fclose(fp);
    fclose(fp2);

    printf("Plik zostal przekopiowany z pliku zad3-5_DATA.txt do pliku zad3.txt");

    return 1;
}