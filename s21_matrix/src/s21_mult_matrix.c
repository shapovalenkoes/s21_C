#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int status = s21_is_poss_to_mult(A, B);
  if (!result) status = INCORRECT_MATRIX;

  if (status == OK) {
    s21_create_matrix(A->rows, A->rows, result);
    for (int i = 0; i < A->rows && status == OK; i++) {
      for (int j = 0; j < B->columns && status == OK; j++) {
        for (int k = 0; k < A->columns; k++) {
          result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
          if (!isfinite(result->matrix[i][j])) status = CALCULATION_ERROR;
        }
      }
    }
  }
  return status;
}
