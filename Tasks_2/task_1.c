// Copyright: 2023 Jakub Korytko

#include <stdio.h>

int main() {
  int x;
  int sum;

  printf("Calculate the sum to: ");
  scanf("%d", &x);

  for (int i = 0; i <= x; i++) {
    sum += i;
  }

  printf("\nThe sum is equal to: %d", sum);

  return 0;
}
