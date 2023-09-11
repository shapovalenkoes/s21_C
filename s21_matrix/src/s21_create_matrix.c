#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int status = INCORRECT_MATRIX;
  if (result) {
    if ((rows > 0) && (columns > 0)) {
      result->matrix = (double **)calloc(rows, sizeof(double *));
      if (result->matrix) {
        for (int i = 0; i < rows; i++) {
          result->matrix[i] = (double *)calloc(columns, sizeof(double));
          if (result->matrix[i] == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            break;
          }
        }
        result->rows = rows;
        result->columns = columns;
        status = OK;
      } else
        fprintf(stderr, "Memory allocation failed\n");
    }
  }

  return status;
}
