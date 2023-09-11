#include "s21_matrix.h"

double s21_calc_minor(matrix_t *A, int i, int j) {
  double minor;

  matrix_t B;
  s21_get_matrix_without_ij(A, i, j, &B);
  s21_determinant(&B, &minor);
  s21_remove_matrix(&B);

  return minor;
}
