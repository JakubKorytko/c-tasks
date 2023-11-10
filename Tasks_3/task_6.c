// Copyright: 2023 Jakub Korytko
// LINT_C_FILE

#include <stdio.h>
#include <stdlib.h>

int main() {
  const int size = 10;

  int *arr = (int *)malloc(size * sizeof(int));

  if (!arr) {
    printf("Failed to allocate memory");
    return 1;
  }

  for (int i = 0; i < size; i++) {
    printf("Enter the %d element of the array: ", i + 1);
    scanf("%d", &arr[i]);
  }

  for (int i = 0; i < size - 1; i++) {
    for (int j = i + 1; j > 0; j--) {
      if (arr[j] < arr[j - 1]) {
        int a = arr[j - 1];
        arr[j - 1] = arr[j];
        arr[j] = a;
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
