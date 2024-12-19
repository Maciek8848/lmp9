#ifndef _BACKSUBST_H
#define _BACKSUBST_H

#include "mat_io.h"

#ifndef NULL
    #define NULL ((void *) 0)
#endif

/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int  backsubst(Matrix *x, Matrix *mat, Matrix *b);

#endif
