// Copyright: 2023 Jakub Korytko

#include <stdio.h>

double volume(double a, double b, double c) { return a * b * c; }

double area(double a, double b, double c) {
  return 2 * (a * b + a * c + b * c);
}

int main() {
  double a;
  double b;
  double c;

  printf("Enter a: ");
  scanf("%lf", &a);

  printf("Enter b: ");
  scanf("%lf", &b);

  printf("Enter c: ");
  scanf("%lf", &c);

  printf("Volume: %lf\n", volume(a, b, c));
  printf("Total surface area: %lf\n", area(a, b, c));

  return 0;
}
