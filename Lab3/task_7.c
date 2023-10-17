// Copyright: 2023 Jakub Korytko

#include <stdio.h>

int nwd(int a, int b) {
    if (a == 0 || b == 0) {
        if (a > b) {
            return a;
        } else if (b > a) {
        return b;
        } else {
            return 0;
        }

    } else if (a % b == 0) {
        return b;
    } else if (a % b != 0) {
        return nwd(b, a%b);
    }
}

int main() {
    int x, y;

    printf("Podaj liczby ktorych NWD znalezc\nLiczba a: ");
    scanf("%d", &x);
    printf("Liczba b: ");
    scanf("%d", &y);

    printf(
    "NWD(%d, %d) wynosi: %d",
    x, y, nwd(x, y));

    return 0;
}
