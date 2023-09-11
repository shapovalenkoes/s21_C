#include "s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int status = s21_is_matrix_size_eq(A, A);
  if (!result) status = INCORRECT_MATRIX;
  if (!isfinite(number)) status = CALCULATION_ERROR;

  if (status == OK) {
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows && status == OK; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] * number;
        if (!isfinite(result->matrix[i][j])) status = CALCULATION_ERROR;
      }
    }
  }
  return status;
}
