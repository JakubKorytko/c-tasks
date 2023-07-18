#include <stdio.h>
#include <math.h>

int main() {
    double a;
    double b;

    printf("Podaj liczbe a: ");
    scanf("%lf", &a);

    printf("Podaj liczbe b: ");
    scanf("%lf", &b);

    double min = fmin(a,b);
    double max = fmax(a,b);

    double percent = min/max*100;

    printf("%.2f stanowi %.2f %% liczby %.2f",min,percent,max);

    return 0;
}

