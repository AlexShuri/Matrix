#include "../s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int flag = 0;
  if (!s21_prov(A)) {
    if (!s21_create_matrix(A->rows, A->columns, result)) {
      matrix_t matrix_m = {0};
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          s21_minor(i, j, A, &matrix_m);
          double m = 0.0;
          if (!s21_determinant(&matrix_m, &m)) {
            result->matrix[i][j] = m * pow(-1, (i + j));
          } else {
            flag = 2;
          }
          s21_remove_matrix(&matrix_m);
        }
      }
    } else {
      flag = 1;
    }
  } else {
    flag = 1;
  }
  return flag;
}