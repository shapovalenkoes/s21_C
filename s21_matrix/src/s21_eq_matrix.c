#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int status = s21_is_matrix_size_eq(A, B);
  if (status != 0)
    status = FAILURE;
  else {
    status = SUCCESS;
    for (int i = 0; i < A->rows && status == SUCCESS; i++) {
      for (int j = 0; j < A->columns; j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) > 1e-7) {
          status = FAILURE;
          break;
        }
      }
    }
  }

  return status;
}
