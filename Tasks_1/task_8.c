// Copyright: 2023 Jakub Korytko

#include <math.h>
#include <stdio.h>

int main() {
  double a;
  double b;

  printf("Enter the 'a' number: ");
  scanf("%lf", &a);

  printf("Enter the 'b' number: ");
  scanf("%lf", &b);

  double min = fmin(a, b);
  double max = fmax(a, b);

  double percent = min / max * 100;

  printf("%.2f is %.2f %% of the number %.2f", min, percent, max);

  return 0;
}
