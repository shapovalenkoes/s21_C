#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int status = s21_is_square_matrix(A);
  if (!result) status = INCORRECT_MATRIX;
  double det = 0.0;

  if (status == OK) {
    s21_determinant(A, &det);
    if (det != 0) {
      if (A->rows == 1) {
        s21_create_matrix(1, 1, result);
        result->matrix[0][0] = 1.0 / det;
      } else {
        matrix_t complem;
        matrix_t trans;
        s21_calc_complements(A, &complem);
        s21_transpose(&complem, &trans);
        s21_mult_number(&trans, 1.0 / det, result);
        s21_remove_matrix(&trans);
        s21_remove_matrix(&complem);
      }
    } else
      status = CALCULATION_ERROR;
  }
  return status;
}
