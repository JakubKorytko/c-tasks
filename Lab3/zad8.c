// Copyright: 2023 Jakub Korytko
// LINT_C_FILE

#include <stdio.h>
#include <math.h>

int main() {
    int n;
    int m = 0;

    int res;

    while (1) {
        printf("Podaj ilosc liczb: ");
        res = scanf("%d", &n);

        if (res == 1 && n > 0) {
            printf("\n");
            break;
        } else {
            while (getchar() != '\n') {
                continue;
            }

            printf("\nPodaj liczbe naturalna\n\n");
        }
    }

    int geo = 1;
    int ar = 0;

    for (int i = 0; i < n; i++) {
        printf("Podaj %d liczbe: ", i+1);
        scanf("%d", &m);
        geo *= m;
        ar += m;
    }

    float geo_avg = pow(geo, 1 / (float)n);
    float ar_avg = ar/(float)n;

    printf("Srednia geometryczna: %f, "
    "arytmetyczna: %f",
    geo_avg, ar_avg);

    return 0;
}
