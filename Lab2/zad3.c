#include <stdio.h>

double objetosc(double a, double b, double c) {
    return a*b*c;
}

double pole(double a, double b, double c) {
    return 2*(a*b+a*c+b*c);
}

int main() {

    double a; double b; double c;

    printf("Podaj a: ");
    scanf("%lf", &a);

    printf("Podaj b: ");
    scanf("%lf", &b);

    printf("Podaj c: ");
    scanf("%lf", &c);

    printf("Objetosc: %lf\n", objetosc(a,b,c));
    printf("Pole powierzchni calkowitej: %lf\n", pole(a,b,c));

    return 0;

}
