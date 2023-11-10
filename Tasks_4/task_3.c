// Copyright: 2023 Jakub Korytko
// LINT_C_FILE

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int multiple(int arr[], int size, int index) {
  for (int i = index; i < size; i += index) {
    arr[i] = 1;
  }
  return 0;
}

int main() {
  int n;

  printf("Enter the n of the range [2,n]: ");
  scanf("%d", &n);

  int size = n + 1;

  if (n > 1) {
    int *arr = (int *)malloc(size * sizeof(int));

    if (!arr) {
      printf("Failed to allocate memory");
      return 1;
    }

    for (int i = 2; i < size; i++) {
      arr[i] = 0;
    }

    for (int i = 2; i <= sqrt(n); i++) {
      if (arr[i] == 0) {
        for (int j = 2 * i; j < size; j += i) {
          arr[j] = 1;
        }
      }
    }

    printf("Prime numbers in the range [2,%d]: ", n);

    for (int i = 2; i < size; i++) {
      if (arr[i] == 0) {
        printf("%d ", i);
      }
    }

    if (arr) {
      free(arr);
    }

  } else {
    printf("Given 'n' is less than 2");
  }

  return 0;
}
