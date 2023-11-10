// Copyright: 2023 Jakub Korytko

#include <stdio.h>

int main() {
  int x;
  int y = 0;

  printf("Enter the number whose divisors should be found: ");
  scanf("%d", &x);

  printf("\nThe divisors of the number %d are: ", x);

  for (int i = 1; i <= x; i++) {
    if (x % i == 0) {
      if (y == 0) {
        y++;
      } else {
        printf(", ");
      }
      printf("%d", i);
    }
  }

  return 0;
}
