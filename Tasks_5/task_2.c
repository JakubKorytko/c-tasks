// Copyright: 2023 Jakub Korytko

#include <stdio.h>
#include <stdlib.h>

int main() {
    char x[100];

    FILE *fp;
    fp = fopen("task_2.txt", "w");

    printf("Enter a string of characters to save in the file: ");

    fgets(x, 100, stdin);

    fprintf(fp, "%s", x);

    fclose(fp);

    return 1;
}
