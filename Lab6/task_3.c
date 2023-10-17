// Copyright: 2023 Jakub Korytko

#include <stdio.h>

int main() {
    FILE *fp, *fp2;
    fp = fopen("task_3-5_DATA.txt", "r");
    fp2 = fopen("task_3.txt", "w");

    while (1) {
        char c = fgetc(fp);

        if (feof(fp))
            break;

        fputc(c, fp2);
    }


    fclose(fp);
    fclose(fp2);

    printf("Plik zostal przekopiowany z pliku task_3-5_DATA.txt "
    "do pliku task_3.txt");

    return 1;
}
