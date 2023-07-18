#include <stdio.h>

int numberLength(long long int number) {

    int length = 0;

    while (number != 0) {
        number /= 10;
        length++;
    }

    return length;

}


int main() {

    int x;

    printf("Podaj liczbe: ");
    scanf("%d", &x);

    int size = numberLength(x);

    int arr[size];

    for (int i = 0; i < size; i++) {

        arr[i] = x % 10;

        x /= 10;
        
    }

    int halfSize = size / 2;

    for (int i = 0; i < halfSize; i++) {

        if (arr[i] != arr[size - i - 1]) {
            printf("Liczba nie jest palindromem");
            return 0;
        }
        
    }

    printf("Liczba jest palindromem");

    return 0;

}