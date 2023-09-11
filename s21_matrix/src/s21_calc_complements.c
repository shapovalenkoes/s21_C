#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int status = s21_is_square_matrix(A);
  if (!result) status = INCORRECT_MATRIX;

  if (status == OK) {
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->columns; i++) {
      for (int j = 0; j < A->rows; j++) {
        double minor = s21_calc_minor(A, i, j);
        double sign = ((i + j) % 2 == 0) ? 1.0 : -1.0;
        result->matrix[i][j] = sign * minor;
      }
    }
  }
  return status;
}
