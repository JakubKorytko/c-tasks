// Copyright: 2023 Jakub Korytko

#include <math.h>
#include <stdio.h>

int main() {
  double a1;
  double a2;

  double b1;
  double b2;

  double c1;
  double c2;

  printf("Enter a1, b1, c1 (a1x+ b1y = c1) \na1: ");
  scanf("%lf", &a1);
  printf("b1: ");
  scanf("%lf", &b1);
  printf("c1: ");
  scanf("%lf", &c1);

  printf("Enter a2, b2, c2 (a2x+ b2y = c2) \na2: ");
  scanf("%lf", &a2);
  printf("b2: ");
  scanf("%lf", &b2);
  printf("c2: ");
  scanf("%lf", &c2);

  double w = a1 * b2 - a2 * b1;
  double wx = c1 * b2 - c2 * b1;
  double wy = a1 * c2 - a2 * c1;

  if (w == 0 && wx == 0 && wy == 0) {
    printf("\nThe system has infinitely many solutions");
  } else if (w == 0 && wx != 0 && wy != 0) {
    printf("\nThe system has no solution");
  } else if (w != 0) {
    double x = wx / w;
    double y = wy / w;
    printf("\nThe solution to the system is: x=%lf, y=%lf", x, y);
  } else {
    printf("\nProgram error");
  }

  return 0;
}
