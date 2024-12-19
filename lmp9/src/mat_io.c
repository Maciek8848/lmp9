#include "mat_io.h"
#include <stdio.h>
#include <stdlib.h>

// Funkcja wczytująca macierz z pliku
Matrix* loadMatrix(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file %s\n", filename);
        return NULL;
    }

    int rows, cols;
    fscanf(file, "%d %d", &rows, &cols);

    Matrix *mat = (Matrix*)malloc(sizeof(Matrix));
    mat->rows = rows;
    mat->cols = cols;

    // Alokacja pamięci na dane
    mat->data = (double**)malloc(rows * sizeof(double*));
    for (int i = 0; i < rows; i++) {
        mat->data[i] = (double*)malloc(cols * sizeof(double));
    }

    // Wczytywanie danych
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fscanf(file, "%lf", &mat->data[i][j]);
        }
    }

    fclose(file);
    return mat;
}

// Funkcja wypisująca macierz na ekran
void printMatrix(const Matrix *mat) {
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            printf("%lf ", mat->data[i][j]);
        }
        printf("\n");
    }
}

// Funkcja zwalniająca pamięć
void freeMatrix(Matrix *mat) {
    for (int i = 0; i < mat->rows; i++) {
        free(mat->data[i]);
    }
    free(mat->data);
    free(mat);
}
Matrix *createMatrix(int rows, int cols) {
    Matrix *mat = (Matrix *)malloc(sizeof(Matrix));
    if (!mat) return NULL;
    mat->rows = rows;
    mat->cols = cols;
    mat->data = (double **)malloc(rows * sizeof(double *));
    if (!mat->data) {
        free(mat);
        return NULL;
    }
    for (int i = 0; i < rows; i++) {
        mat->data[i] = (double *)malloc(cols * sizeof(double));
        if (!mat->data[i]) {
            for (int j = 0; j < i; j++) free(mat->data[j]);
            free(mat->data);
            free(mat);
            return NULL;
        }
    }
    return mat;
}
