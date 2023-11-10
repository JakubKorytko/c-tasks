// Copyright: 2023 Jakub Korytko

#include <stdio.h>

int main() {
  printf("Numbers divisible by 3 in the range 1-200: ");

  for (int i = 1; i <= 200; i++) {
    if (i % 13 == 0) {
      printf("%d", i);
      if (i + 13 <= 200) {
        printf(", ");
      }
    }
  }

  return 0;
}
