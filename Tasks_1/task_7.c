// Copyright: 2023 Jakub Korytko

#include <stdio.h>

int main() {
    int a;
    int b;
    int c = 3;

    while (c != 4) {
        if (c == 3) {
            printf("Enter the 'a' number: ");
            scanf("%d", &a);

            printf("Enter the 'b' number: ");
            scanf("%d", &b);
        }

        printf(
        "\nCalculate:\n"
        "1. a+b\n"
        "2. a-b\n"
        "3. Change the numbers\n"
        "4. Exit\n\n"
        "(Enter the correct number and confirm with enter) "
        "Choice: ");

        scanf("%d", &c);

        if (c == 1) {
            printf("\na + b = %d\n", (a + b));
        } else if (c == 2) {
            printf("\na - b = %d\n", (a - b));
        } else {
            if (c != 4 && c != 3) {
                printf("Incorrect choice");
            }
        }
    }

    return 0;
}
