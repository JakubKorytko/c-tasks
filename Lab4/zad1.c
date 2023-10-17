// Copyright: 2023 Jakub Korytko

#include <stdio.h>

int main() {
    const int size = 10;

    int a[size], b[size];

    for (int i = 0; i < size; i++) {
        printf("Podaj %d element tablicy: ", i+1);
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < size; i++) {
        b[i] = a[i];
    }

    for (int i = 0; i < size; i++) {
        if (i != size - 1) {
            printf("%d,", b[i]);
        } else {
            printf("%d", b[i]);
        }
    }

    return 0;
}
