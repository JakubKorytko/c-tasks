// Copyright: 2023 Jakub Korytko

#include <stdio.h>

int main() {
  double a;
  double b;

  printf("Enter the first number: ");
  scanf("%lf", &a);

  printf("Enter second number: ");
  scanf("%lf", &b);

  printf(
      "\nProduct: %lf\n"
      "Quotient: %lf",
      a * b, a / b);

  return 0;
}
