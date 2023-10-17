// Copyright: 2023 Jakub Korytko

#include <stdio.h>
#include <stdlib.h>

// SOLUTION USING ADJUGATE MATRIX METHOD (adj function)

double det3(double A[4][4]) {
    double result = 0;

    result += A[1][1] * A[2][2] * A[3][3];
    result += A[1][2] * A[2][3] * A[3][1];
    result += A[1][3] * A[2][1] * A[3][2];

    result -= A[3][1] * A[2][2] * A[1][3];
    result -= A[3][2] * A[2][3] * A[1][1];
    result -= A[3][3] * A[2][1] * A[1][2];

    return result;
}

double det2(double A[3][3]) {
    double result = 0;

    result += A[1][1] * A[2][2];
    result -= A[2][1] * A[1][2];

    return result;
}

int adj(double A[4][4], int row, int col) {
    double result = 0;

    double B[3][3];
    int x = 1;
    int y = 1;
    for (int i = 1; i < 4; i++) {
        for (int j = 1; j < 4; j++) {
            if (i != row && j != col) {
                B[x][y] = A[i][j];
                y++;
            }
        }
        if (i != row) {
            x++;
        }
        y = 1;
    }

    result = det2(B);

    if ((row + col) % 2 == 0) {
        return result;
    } else {
        return -result;
    }
}

int digitsInNumber(double number) {
    int digits = 0;
    number = abs(number);


    while (number >= 1) {
        number /= 10;
        digits++;
    }

    return digits;
}

int biggestNumberInArray(double array[4][4]) {
    double biggest = abs(array[1][1]);
    for (int i = 1; i < 4; i++) {
        for (int j = 1; j < 4; j++) {
            if (abs(array[i][j]) > biggest) {
                biggest = abs(array[i][j]);
            }
        }
    }
    return biggest;
}

void showMatrix(double matrix[4][4]) {
    double biggest = biggestNumberInArray(matrix);
    int digits = digitsInNumber(biggest);

    for (int i = 1; i < 4; i++) {
        printf("| ");
        for (int j = 1; j < 4; j++) {
            printf("%.2lf ", matrix[i][j]);

            if (j != 3) {
                printf(" ");
            }

            int diff = digits - digitsInNumber(matrix[i][j]);

            for (int k = 0; k < diff; k++) {
                printf(" ");
            }
        }
        printf("|\n");
    }
}

int main() {
    double A[4][4];
    double B[4][4];
    // because we start indexing from 1

    printf("\nEnter the elements of a 3x3 matrix (9 numbers): \n");

    for (int i = 1; i < 4; i++) {
        for (int j = 1; j < 4; j++) {
            scanf("%lf", &A[i][j]);
        }
    }

    double det = det3(A);

    if (det != 0) {
        for (int i = 1; i < 4; i++) {
            for (int j = 1; j < 4; j++) {
                B[j][i] = adj(A, i, j);
            }
        }

        for (int i = 1; i < 4; i++) {
            for (int j = 1; j < 4; j++) {
                B[j][i] *= 1/det;
            }
        }

        printf("\nThe inverse of the matrix:\n\n");
        showMatrix(A);

        printf("\nis the matrix::\n\n");
        showMatrix(B);

    } else {
        printf("The matrix is not invertible");
        return 0;
    }

    return 0;
}
