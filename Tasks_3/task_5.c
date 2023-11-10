// Copyright: 2023 Jakub Korytko
// LINT_C_FILE

#include <stdio.h>
#include <stdlib.h>

int main() {
  const int size = 10;
  int x = 1;

  int *arr = (int *)malloc(size * sizeof(int));

  if (!arr) {
    printf("Failed to allocate memory");
    return 1;
  }

  for (int i = 0; i < size; i++) {
    printf("Enter the %d element of the array: ", i + 1);
    scanf("%d", &arr[i]);
  }

  while (x != 0 && size > 1) {
    x = 0;

    for (int i = 0; i < size - 1; i++) {
      int a = arr[i];
      int b = arr[i + 1];

      if (a > b) {
        x = 1;
        arr[i + 1] = a;
        arr[i] = b;
      }
    }
  }

  for (int i = 0; i < size; i++) {
    if (i != size - 1) {
      printf("%d,", arr[i]);
    } else {
      printf("%d", arr[i]);
    }
  }

  if (arr) {
    free(arr);
  }

  return 0;
}
