// Copyright: 2023 Jakub Korytko
#define _USE_MATH_DEFINES

#include <stdio.h>
#include <math.h>

double f(double x, double mi, double sigma) {
    const double exponent = -pow(x-mi, 2)/(2*pow(sigma, 2));
    const double base = 1/(sigma*sqrt(2*M_PI));

    return base*exp(exponent);
}

int main() {
    double x;
    double mi;
    double sigma;

    printf("Enter 'x': ");
    scanf("%lf", &x);

    printf("Enter 'mi': ");
    scanf("%lf", &mi);

    printf("Enter 'sigma': ");
    scanf("%lf", &sigma);

    printf("f(x) = %lf", f(x, mi, sigma));

    return 0;
}
