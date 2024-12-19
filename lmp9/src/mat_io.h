#ifndef MAT_IO_H
#define MAT_IO_H

// Definicja struktury Matrix
typedef struct _Matrix {
    int rows;       // liczba wierszy
    int cols;       // liczba kolumn
    double **data;  // wskaźnik na dwuwymiarową tablicę danych
} Matrix;

// Deklaracje funkcji
Matrix* loadMatrix(const char *filename); // Wczytanie macierzy z pliku
void printMatrix(const Matrix *mat);      // Wypisanie macierzy na ekran
void freeMatrix(Matrix *mat);             // Zwalnianie pamięci

#endif // MAT_IO_H

