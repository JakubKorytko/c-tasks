// Copyright: 2023 Jakub Korytko
#define _USE_MATH_DEFINES

#include <math.h>
#include <stdio.h>

double square() {
  double a;

  printf("\nEnter the side of the square: ");
  scanf("%lf", &a);

  return 4 * a;
}

double circle() {
  double r;

  printf("\nEnter the radius of the circle: ");
  scanf("%lf", &r);

  return M_PI * pow(r, 2);
}

double triangle() {
  double a;
  double h;

  printf("\nEnter the side of the triangle: ");
  scanf("%lf", &a);

  printf("\nEnter the height of the triangle: ");
  scanf("%lf", &h);

  return (1.0 / 2) * a * h;
}

int main() {
  int p = 0;

  while (p != 4) {
    printf(
        "\nCalculate the field of:\n"
        "1. Triangle\n"
        "2. Square\n"
        "3. Circle\n"
        "4. Exit\n\n"
        "(Enter the correct number and confirm with enter) "
        "Choice: ");

    scanf("%d", &p);

    if (p == 1) {
      printf("\nThe area of the triangle is %lf\n", triangle());
    } else if (p == 2) {
      printf("\nThe area of the square is %lf\n", square());
    } else if (p == 3) {
      printf("\nThe area of the circle is %lf\n", circle());
    } else {
      if (p != 4) {
        printf("\nWrong choice");
      }
    }
  }

  return 0;
}
