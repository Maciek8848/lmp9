#include "backsubst.h"
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int backsubst(Matrix *x, Matrix *mat, Matrix *b) {
    // Sprawdzamy, czy rozmiary macierzy są zgodne
    if (mat->rows != mat->cols || mat->rows != b->rows || mat->rows != x->rows) {
        return 2;  // Błąd nieprawidłowych rozmiarów macierzy
    }

    // Alokacja pamięci dla macierzy x (wektor rozwiązania)
    x->data = (double **)malloc(x->rows * sizeof(double *));  // Alokujemy wskaźniki na wiersze
    if (x->data == NULL) {
        return 2;  // Błąd alokacji pamięci
    }

    // Alokacja pamięci dla każdego wiersza (tu tylko jedna kolumna, bo to wektor kolumnowy)
    for (int i = 0; i < x->rows; i++) {
        x->data[i] = (double *)malloc(x->cols * sizeof(double));  // Alokujemy pamięć dla jednej kolumny
        if (x->data[i] == NULL) {
            // Zwolnienie wcześniej zaalokowanej pamięci w przypadku błędu
            for (int j = 0; j < i; j++) {
                free(x->data[j]);
            }
            free(x->data);
            return 2;  // Błąd alokacji pamięci
        }
    }

    int i, j;

    // Wykonujemy wsteczne podstawienie
    for (i = mat->rows - 1; i >= 0; i--) {
        // Sprawdzamy, czy element na diagonalnej jest zerem
        if (mat->data[i][i] == 0) {
            return 1;  // Błąd dzielenia przez 0
        }

        // Inicjalizujemy zmienną do obliczenia x[i]
        x->data[i][0] = b->data[i][0];

        // Odejmuje sumę iloczynów z już obliczonych zmiennych
        for (j = i + 1; j < mat->rows; j++) {
            x->data[i][0] -= mat->data[i][j] * x->data[j][0];
        }

        // Dzielimy przez element diagonalny
        x->data[i][0] /= mat->data[i][i];
    }

    return 0;  // Wsteczne podstawienie zakończone sukcesem
}
