// Copyright: 2023 Jakub Korytko

#include <stdio.h>

int factorial(int n) {
  int fact = 1;

  for (int i = 1; i <= n; i++) {
    fact *= i;
  }

  return fact;
}

int main() {
  int x = 1;
  int y = 0;

  while (x != 0) {
    if (y == 0) {
      y++;
    } else {
      printf("\nFactorial of %d: %d", x, factorial(x));
    }

    printf("\nCalculate the factorial of (0 to exit): ");
    scanf("%d", &x);
  }

  return 0;
}
