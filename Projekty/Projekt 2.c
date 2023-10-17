// Copyright: 2023 Jakub Korytko

#include <stdio.h>
#include <math.h>

// +-----------+
// | Projekt L |
// +-----------+

int sum(int x) {
    int s = 0;
    int l = x;

    while (l > 0) {
        int i = 1, p = 0;

        while (i * 10 < l) {
            i *= 10;
        }

        p = floor(l / i);

        s += p;

        l -= p * i;
    }

    return s;
}

int main() {
    int koniec = 0, k = 0, l = 1, c = 0;

    printf("Podaj wartosc koncowa: ");
    scanf("%d", &koniec);

    do {
        printf("Podaj %d element: ", l);
        scanf("%d", &k);
        if (k < koniec && k >= 10 && k < 1000 && sum(k) % 2 != 0) {
            c++;
        }
        l += 1;
    } while (k < koniec);

    printf("Liczba elementow spelniajacych warunek: %d", c);

    return 0;
}
