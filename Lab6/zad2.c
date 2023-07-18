#include <stdio.h>
#include <stdlib.h>

int main()
{
    char x[100];

    FILE *fp;
    fp = fopen("zad2.txt", "w");

    printf("Podaj ciag znakow do zapisania w pliku: ");
    
    fgets(x, 100, stdin);

    fprintf(fp, "%s", x);

    fclose(fp);

    return 1;
}