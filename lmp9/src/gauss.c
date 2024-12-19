#include "gauss.h"

// Funkcja eliminacji Gaussa (przykład)
int eliminate(Matrix *A, Matrix *b) {
    int i, j, k;
    double factor;

    // Implementacja eliminacji Gaussa
    for (i = 0; i < A->rows; i++) {
        // Normalizowanie wiersza i
        if (A->data[i][i] == 0) {
            // Obsługuje przypadek, gdy pivot jest zerowy
            return -1;
        }
        for (j = i + 1; j < A->cols; j++) {
            factor = A->data[j][i] / A->data[i][i];
            for (k = i; k < A->cols; k++) {
                A->data[j][k] -= factor * A->data[i][k];
            }
            b->data[j][0] -= factor * b->data[i][0];
        }
    }

    return 0;
}
