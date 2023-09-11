#include "s21_matrix.h"

void s21_initialize_matrix(matrix_t *A, double start, double step) {
  if (A && A->matrix) {
    double value = start;
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        A->matrix[i][j] = value;
        value += step;
      }
    }
  }
}
