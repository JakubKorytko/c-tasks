// Copyright: 2023 Jakub Korytko
// LINT_C_FILE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void free_array(char **arr, int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i]) {
            free(arr[i]);
        }
    }
    if (arr) {
        free(arr);
    }
}

int findModulo(int *arr, int size) {
    int matches[5] = {1, 1, 1, 1, 1};
    int primeNumbers[5] = {127, 131, 137, 139, 149};

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < size; j++) {
            int mod = arr[j] % primeNumbers[i];
            if (!(mod >= 65 && mod <= 90)) {
                matches[i] = 0;
            }
        }
    }

    if (matches[0] == 1) {
        return 127;
    } else if (matches[1] == 1) {
        return 131;
    } else if (matches[2] == 1) {
        return 137;
    } else if (matches[3] == 1) {
        return 139;
    } else if (matches[4] == 1) {
        return 149;
    } else {
        return -1;
    }
}

int main() {
    int t;

    scanf("%d", &t);

    char **words = (char **)malloc(t * sizeof(char *));

    if (!words) {
        printf("Failed to allocate memory");
        exit(1);
    }

    for (int i = 0; i < t; i++) {
        words[i] = (char *)malloc(25 * sizeof(char));

        if (!words[i]) {
            printf("Failed to allocate memory");
            free_array(words, i);
            exit(1);
        }
    }

    int *dividers = (int *)malloc(t * sizeof(int));

    if (!dividers) {
        printf("Failed to allocate memory");
        free_array(words, t);
        exit(1);
    }

    for (int i = 0; i < t; i++) {
        int s;
        scanf("%d", &s);

        int *arr = (int *)malloc(s * sizeof(int));

        if (!arr) {
            printf("Failed to allocate memory");
            free_array(words, t);

            if (dividers) {
                free(dividers);
            }

            exit(1);
        }

        for (int j = 0; j < s; j++) {
            scanf("%d", &arr[j]);
        }

        int mod = findModulo(arr, s);
        dividers[i] = mod;

        if (mod != -1) {
            for (int k = 0; k <= s; k++) {
                if (k == s) {
                    words[i][k] = '\0';
                } else {
                    words[i][k] = (char)(arr[k] % mod);
                }
            }
        } else {
            strncpy(words[i], "ILLEGIBLE", 25);
        }

        if (arr) {
            free(arr);
        }
    }

    printf("\n");

    for (int i = 0; i < t; i++) {
        if (dividers[i] != -1) {
            printf("%d ", dividers[i]);
        }
        printf("%s\n", words[i]);
    }

    if (dividers) {
        free(dividers);
    }

    free_array(words, t);

    return 1;
}
