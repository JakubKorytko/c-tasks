// Copyright: 2023 Jakub Korytko

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int multiplicateRow(int **A, int **B, int row, int col, int size) {
    int result = 0;
    for (int i = 1; i < size; i++) {
        result += A[row][i] * B[i][col];
    }
    return result;
}

int digitsInNumber(int number) {
    int digits = 0;

    number = abs(number);

    while (number > 0) {
        number /= 10;
        digits++;
    }
    return digits;
}

int biggestNumberInArray(int **array, int rows, int cols) {
    int biggest = abs(array[1][1]);
    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < cols; j++) {
            if (abs(array[i][j]) > biggest) {
                biggest = abs(array[i][j]);
            }
        }
    }
    return biggest;
}

void showMatrix(int **matrix, int rows, int cols) {
    int biggest = biggestNumberInArray(matrix, rows, cols);
    int digits = digitsInNumber(biggest);

    for (int i = 1; i < rows; i++) {
        printf("| ");
        for (int j = 1; j < cols; j++) {
            printf("%d ", matrix[i][j]);

            if (j != cols - 1) {
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
    int A_size[2], B_size[2];

    printf("Enter the number of rows of the matrix A: ");
    scanf("%d", &A_size[0]);
    printf("Enter the number of columns of the matrix A: ");
    scanf("%d", &A_size[1]);

    // "The program should multiply matrices of any size, if possible"
    // for this reason, we take the sizes of matrix B separately

    printf("\nEnter the number of rows of the matrix B: ");
    scanf("%d", &B_size[0]);
    printf("Enter the number of columns of the matrix B: ");
    scanf("%d", &B_size[1]);

    A_size[0]++;
    A_size[1]++;

    B_size[0]++;
    B_size[1]++;
    // because we start indexing from 1

    int **A = malloc(A_size[0] * sizeof *A);
    int **B = malloc(B_size[0] * sizeof *B);

    int elements[2] = { (A_size[0] - 1) * (A_size[1] - 1),
    (B_size[0] - 1) * (B_size[1] - 1) };

    printf("\nSpecify the elements of the matrix (%d numbers) A: \n",
    elements[0]);

    for (int i = 1; i < A_size[0]; i++) {
        A[i] = malloc(A_size[1] * sizeof *A[i]);
        for (int j = 1; j < A_size[1]; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Specify the elements of the matrix (%d numbers) B: \n",
    elements[1]);

    for (int i = 1; i < B_size[0]; i++) {
        B[i] = malloc(B_size[1] * sizeof * B[i]);
        for (int j = 1; j < B_size[1]; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    printf("\nMatrix A:\n\n");
    showMatrix(A, A_size[0], A_size[1]);

    printf("\nMatrix B:\n\n");
    showMatrix(B, B_size[0], B_size[1]);

    if (A_size[1] == B_size[0]) {
        int **C = malloc(A_size[0] * sizeof *C);
        for (int i = 1; i < A_size[0]; i++) {
            C[i] = malloc(B_size[1] * sizeof *C[i]);
            for (int j = 1; j < B_size[1]; j++) {
                C[i][j] = multiplicateRow(A, B, i, j, A_size[1]);
            }
        }

        printf("\nThe product of A and B: \n\n");
        showMatrix(C, A_size[0], B_size[1]);
    } else {
        printf("\nCannot perform matrix multiplication");
    }

    return 0;
}
