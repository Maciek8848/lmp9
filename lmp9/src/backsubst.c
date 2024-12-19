#include "backsubst.h"
#include <stdio.h>

int backsubst(Matrix *x, Matrix *mat, Matrix *b) {
    // Implementacja podstawienia wstecznego
    int i, j;
    for (i = mat->rows - 1; i >= 0; i--) {
        x->data[i][0] = b->data[i][0];
        for (j = i + 1; j < mat->cols; j++) {
            x->data[i][0] -= mat->data[i][j] * x->data[j][0];
        }
        x->data[i][0] /= mat->data[i][i];
    }
    return 0;
}
