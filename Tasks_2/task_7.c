// Copyright: 2023 Jakub Korytko

#include <stdio.h>

int gcd(int a, int b) {
  if (a == 0 || b == 0) {
    if (a > b) {
      return a;
    } else if (b > a) {
      return b;
    } else {
      return 0;
    }

  } else if (a % b == 0) {
    return b;
  } else if (a % b != 0) {
    return gcd(b, a % b);
  }
}

int main() {
  int x, y;

  printf(
      "Enter the numbers whose GCD should be found\n"
      "Number a: ");
  scanf("%d", &x);
  printf("Number b: ");
  scanf("%d", &y);

  printf("GCD(%d, %d) is equal to: %d", x, y, gcd(x, y));

  return 0;
}
