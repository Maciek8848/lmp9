#include <stdio.h>
#include "gauss.h"
#include "mat_io.h"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <matrix file> <vector file>\n", argv[0]);
        return 1;
    }

    // Wczytaj macierz A i wektor b
    Matrix *A = loadMatrix(argv[1]);
    Matrix *b = loadMatrix(argv[2]);

    if (A == NULL || b == NULL) {
        printf("Error reading matrices\n");
        return 1;
    }

    // Wywołaj funkcję eliminacji Gaussa
    int res = eliminate(A, b);
    if (res == -1) {
        printf("Error during Gaussian elimination\n");
        freeMatrix(A);
        freeMatrix(b);
        return 1;
    }

    // Wypisz wynik
    printMatrix(A);

    // Zwalnij pamięć
    freeMatrix(A);
    freeMatrix(b);

    return 0;
}
