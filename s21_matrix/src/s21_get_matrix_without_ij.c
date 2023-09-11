#include "s21_matrix.h"

int s21_get_matrix_without_ij(matrix_t *A, int i, int j, matrix_t *result) {
  int status = s21_create_matrix(A->rows - 1, A->columns - 1, result);

  if (status == OK) {
    int offset_row = 0;

    for (int row = 0; row < result->rows; row++) {
      if (i == row) {
        offset_row = 1;
      }
      int offset_col = 0;
      for (int col = 0; col < result->columns; col++) {
        if (j == col) {
          offset_col = 1;
        }
        result->matrix[row][col] =
            A->matrix[row + offset_row][col + offset_col];
      }
    }
  }
  return status;
}
