// Copyright: 2023 Jakub Korytko

#include <stdio.h>
#include <math.h>

double y1 (double x) {return log10(x)+10;}
double y2 (double x) {return pow(1.5, x);}
double y3 (double x) {return exp(x);}

int main() {
    double x;
    double y;

    printf("Enter the X of the point: ");
    scanf("%lf", &x);

    printf("Enter the Y of the point: ");
    scanf("%lf", &y);

    if (y > y2(x) && y < y3(x) && y < y1(x)) {
        printf("The point is located between the functions");
    } else {
        printf("The point is not located between the functions");
    }

    return 0;
}
