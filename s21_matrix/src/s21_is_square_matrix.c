#include "s21_matrix.h"

int s21_is_square_matrix(matrix_t *A) {
  int status = INCORRECT_MATRIX;

  if (A && A->matrix) {
    status = OK;
    if ((A->columns < 1) || (A->rows < 1))
      status = INCORRECT_MATRIX;
    else if (A->columns != A->rows)
      status = CALCULATION_ERROR;
  }

  return status;
}
