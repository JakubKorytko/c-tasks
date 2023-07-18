#include <stdio.h>

int main() {
    FILE *fp;
    fp = fopen("zad1.txt", "w");

    for (int i = 0; i < 5; i++) {
        int x;
        printf("Podaj %d liczbe do zapisania w pliku: ", i+1);
        scanf("%d", &x);
        fprintf(fp, "%d", x);
        if (i!=4) {
            fprintf(fp, ", ");
        }
    }
    
    fclose(fp);
    fp = fopen("zad1.txt", "r");
    
    printf("\n\nWczytane z pliku liczby: ");

    do
    {
        char c = fgetc(fp);

        if (feof(fp))
            break;
 
        printf("%c", c);

    }  while(1);

    return 1;
}