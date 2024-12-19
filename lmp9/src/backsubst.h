#ifndef _BACKSUBST_H
#define _BACKSUBST_H

#include "mat_io.h"

/**
 * Funkcja realizująca metodę podstawienia wstecznego dla układu równań Ax = b.
 * 
 * @param x        - wskaźnik na wektor rozwiązania (będzie zawierał wynik po wykonaniu operacji)
 * @param mat      - wskaźnik na macierz współczynników A
 * @param b        - wskaźnik na wektor prawych stron b
 * @return         - 0 - wsteczne podstawienie zakończone sukcesem,
 *                  - 1 - błąd dzielenia przez 0 (element na diagonali = 0),
 *                  - 2 - błąd nieprawidłowych rozmiarów macierzy (np. macierz A i wektor b mają niezgodne wymiary)
 */
int backsubst(Matrix *x, Matrix *mat, Matrix *b);

#endif // _BACKSUBST_H
