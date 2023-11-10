// Copyright: 2023 Jakub Korytko

#include <stdio.h>

int main() {
  const int a = 10;
  const int b = 5;

  printf("The numbers are: %d and %d", a, b);

  printf(
      "\nThe sum: %d\n"
      "The difference: %d\n"
      "The product: %d\n"
      "The quotient: %d\n"
      "The modulo: %d",
      a + b, a - b, a * b, a / b, a % b);

  return 0;
}
