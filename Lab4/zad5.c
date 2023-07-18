#include <stdio.h>

int main() {

    const int size = 10;
    int x = 1;

    int arr[size];

    for (int i = 0; i < size; i++) {
        printf("Podaj %d element tablicy: ", i+1);
        scanf("%d", &arr[i]);
    }


    while (x!=0 && size > 1) {
        x = 0;

        for (int i = 0; i < size-1; i++) {
            int a = arr[i];
            int b = arr[i+1];

            if (a>b) {
                x=1;
                arr[i+1] = a;
                arr[i] = b;  
            }
        }
    }

    for (int i = 0; i < size; i++) {
        if (i!=size-1) {
            printf("%d,", arr[i]);
        } else {
            printf("%d", arr[i]);
        }
    }


    return 0;
}