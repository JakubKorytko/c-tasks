// Copyright: 2023 Jakub Korytko

#include <stdio.h>
#include <math.h>

// +---------------+
// | Projekt nr 17 |
// +---------------+

double szereg(double x) {
    double s = 1, w = 1;
    for (int i = 1; i <= 100; i++) {
        w *= -x * x / (2 * i * (2 * i - 1));
        s += w;
    }
    return s;
}

int main() {
    int c;
    char table[31] = " ----------------------------\n";
    double a, b, k, x;

    printf("Przedzial to ( |x| < nieskonczonosc )\n");

    printf("Podaj poczatek przedzialu: ");
    scanf("%lf", &a);

    printf("Podaj koniec przedzialu: ");
    scanf("%lf", &b);

    printf("Podaj liczbe podprzedzialow: ");
    scanf("%d", &c);

    k = (b - a) / c;

    printf("Krok = %.2lf\n\n", k);
    printf("%s", table);
    printf("       x  szereg(x) cos(x)\n");
    printf("%s", table);

    for (x = a; x <= b; x += k) {
        printf("%10.2lf %7.4lf %7.4lf\n", x, szereg(x), cos(x));
    }

    printf("%s", table);

    return 0;
}
