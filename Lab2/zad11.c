// Copyright: 2023 Jakub Korytko

#include <stdio.h>
#include <math.h>

int main() {
    double a1;
    double a2;

    double b1;
    double b2;

    double c1;
    double c2;

    printf("Podaj a1, b1, c1 (a1x+ b1y = c1) \na1: ");
    scanf("%lf", &a1);
    printf("b1: ");
    scanf("%lf", &b1);
    printf("c1: ");
    scanf("%lf", &c1);

    printf("Podaj a2, b2, c2 (a2x+ b2y = c2) \na2: ");
    scanf("%lf", &a2);
    printf("b2: ");
    scanf("%lf", &b2);
    printf("c2: ");
    scanf("%lf", &c2);

    double w = a1*b2 - a2*b1;
    double wx = c1*b2 - c2*b1;
    double wy = a1*c2-a2*c1;

    if (w == 0 && wx == 0 && wy == 0) {
        printf("\nUklad ma nieskonczenie wiele rozwiazan");
    } else if (w == 0 && wx != 0 && wy != 0) {
        printf("\nUklad nie ma rozwiazania");
    } else if (w != 0) {
        double x = wx/w;
        double y = wy/w;
        printf("\nRozwiazaniem ukladu jest x=%lf, y=%lf", x, y);
    } else {
        printf("\nBlad programu");
    }

    return 0;
}
