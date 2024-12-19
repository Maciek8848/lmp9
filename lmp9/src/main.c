#include <stdio.h>
#include "gauss.h"
#include "mat_io.h"
#include "backsubst.h"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <matrix file> <vector file>\n", argv[0]);
        return 1;
    }

    // Wczytanie macierz A i wektor b
    Matrix *A = loadMatrix(argv[1]);
    Matrix *b = loadMatrix(argv[2]);

    if (A == NULL || b == NULL) {
        printf("Error reading matrices\n");
        return 1;
    }


    if (A->rows != b->rows) {
        printf("Matrix and vector dimensions do not match.\n");
        freeMatrix(A);
        freeMatrix(b);
        return 1;
    }


    Matrix *x = createMatrix(A->rows, 1);
    if (x == NULL) {
        printf("Error creating solution vector.\n");
        freeMatrix(A);
        freeMatrix(b);
        return 1;
    }


    int res = eliminate(A, b);
    if (res == -1) {
        printf("Error during Gaussian elimination\n");
        freeMatrix(A);
        freeMatrix(b);
        freeMatrix(x);
        return 1;
    }


    res = backsubst(x, A, b);
    if (res != 0) {
        printf("Error during back substitution\n");
        freeMatrix(A);
        freeMatrix(b);
        freeMatrix(x);
        return 1;
    }


    printf("Solution vector (x):\n");
    printMatrix(x);


    freeMatrix(A);
    freeMatrix(b);
    freeMatrix(x);

    return 0;
}
