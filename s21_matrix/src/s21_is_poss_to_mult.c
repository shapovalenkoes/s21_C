#include "s21_matrix.h"

int s21_is_poss_to_mult(matrix_t *A, matrix_t *B) {
  int status = INCORRECT_MATRIX;
  if (A && B) {
    if (A->matrix && B->matrix) status = OK;
    if ((A->columns != B->rows) || (A->rows != B->columns) ||
        (A->rows < 1 || A->columns < 1) || (B->rows < 1 || B->columns < 1)) {
      status = CALCULATION_ERROR;
    }
  }
  return status;
}
