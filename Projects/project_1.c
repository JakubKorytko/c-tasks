// Copyright: 2023 Jakub Korytko

#include <stdio.h>
#include <math.h>

double series(double x) {
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

    printf("The range is  ( |x| < infinity )\n");

    printf("Enter the start of the range: ");
    scanf("%lf", &a);

    printf("Enter the end of the range: ");
    scanf("%lf", &b);

    printf("Enter the number of subdivisions: ");
    scanf("%d", &c);

    k = (b - a) / c;

    printf("Step = %.2lf\n\n", k);
    printf("%s", table);
    printf("       x  series(x) cos(x)\n");
    printf("%s", table);

    for (x = a; x <= b; x += k) {
        printf("%10.2lf %7.4lf %7.4lf\n", x, series(x), cos(x));
    }

    printf("%s", table);

    return 0;
}
