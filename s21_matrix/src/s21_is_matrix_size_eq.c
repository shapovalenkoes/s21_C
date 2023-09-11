#include "s21_matrix.h"

int s21_is_matrix_size_eq(matrix_t *A, matrix_t *B) {
  int status = INCORRECT_MATRIX;
  if (A && B) {
    if (A->matrix && B->matrix) {
      status = OK;
      if ((A->columns != B->columns) || (A->rows != B->rows)) {
        status = CALCULATION_ERROR;
        if ((A->rows < 1 || A->columns < 1) || (B->rows < 1 || B->columns < 1))
          status = INCORRECT_MATRIX;
      }
    }
  }
  return status;
}
