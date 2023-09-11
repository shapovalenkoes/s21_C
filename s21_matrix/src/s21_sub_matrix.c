#include "s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int status = s21_is_matrix_size_eq(A, B);
  if (!result) status = INCORRECT_MATRIX;

  if (status == OK) {
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows && status == OK; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
        if (!isfinite(result->matrix[i][j])) status = CALCULATION_ERROR;
      }
    }
  }
  return status;
}
