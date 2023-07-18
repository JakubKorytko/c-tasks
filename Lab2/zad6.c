#include <stdio.h>

int main() {

    int a;

    printf("Podaj liczbe: ");
    scanf("%d", &a);

    if (a%2==0) {
        printf("Parzysta");
    } else {
        printf("Nieparzysta");
    }

    return 0;
}
