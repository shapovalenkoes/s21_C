#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int status = s21_is_square_matrix(A);
  if (!result) status = CALCULATION_ERROR;

  if (status == OK) {
    double det = 0;
    int n = A->rows;

    if (n == 1) {
      det = A->matrix[0][0];

    } else if (n == 2) {
      det =
          A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];

    } else {
      int sign = 1;
      for (int i = 0; i < A->rows; i++) {
        det += sign * A->matrix[0][i] * s21_calc_minor(A, 0, i);
        sign *= -1;
      }
    }
    *result = det;
  }
  return status;
}
