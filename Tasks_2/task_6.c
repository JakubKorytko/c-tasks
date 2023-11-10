// Copyright: 2023 Jakub Korytko

#include <stdio.h>

int fibonacci(int n) {
  if (n == 0) {
    return 0;
  } else if (n == 1) {
    return 1;
  } else if (n > 1) {
    return fibonacci(n - 1) + fibonacci(n - 2);
  }
}

int main() {
  int x;

  printf("Enter the term number of the Fibonacci sequence: ");
  scanf("%d", &x);

  printf("The %d term of the sequence is: %d", x, fibonacci(x));

  return 0;
}
