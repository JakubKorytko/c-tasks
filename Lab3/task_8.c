// Copyright: 2023 Jakub Korytko
// LINT_C_FILE

#include <stdio.h>
#include <math.h>

int main() {
    int n;
    int m = 0;

    int res;

    while (1) {
        printf("Enter the amount of numbers: ");
        res = scanf("%d", &n);

        if (res == 1 && n > 0) {
            printf("\n");
            break;
        } else {
            while (getchar() != '\n') {
                continue;
            }

            printf("\nEnter a natural number\n\n");
        }
    }

    int geo = 1;
    int ar = 0;

    for (int i = 0; i < n; i++) {
        printf("Enter the %d number: ", i+1);
        scanf("%d", &m);
        geo *= m;
        ar += m;
    }

    float geo_avg = pow(geo, 1 / (float)n);
    float ar_avg = ar/(float)n;

    printf("Geometric mean: %f, "
    "Arithmetic mean: %f",
    geo_avg, ar_avg);

    return 0;
}
