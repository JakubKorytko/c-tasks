// Copyright: 2023 Jakub Korytko
// LINT_C_FILE

#include <stdio.h>
#include <stdlib.h>

int main() {
    const int size = 8;

    int *arr = (int *)malloc(size * sizeof(int));

    if (!arr) {
        printf("Blad alokacji pamieci");
        return 1;
    }

    for (int i = 0; i < size; i++) {
        printf("Podaj %d element tablicy: ", i + 1);
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < size; i++) {
        int x = arr[i], y = i;
        for (int j = i; j < size; j++) {
            if (x > arr[j]) {
                x = arr[j];
                y = j;
            }
        }

        int a = arr[y];
        arr[y] = arr[i];
        arr[i] = a;
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
