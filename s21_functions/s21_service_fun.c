#include "../s21_matrix.h"

int s21_prov(matrix_t *matrix) {
  int flag = 0;
  if (matrix->matrix == NULL) {
    flag = 1;
  } else {
    flag = 0;
  }
  return flag;
}

void s21_sum_sub(int znak, matrix_t *A, matrix_t *B, matrix_t *result) {
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < -A->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j] * znak;
    }
  }
}

void s21_minor(int rows_zero, int columns_zero, matrix_t *A,
               matrix_t *matrix_m) {
  int rows_m = A->rows - 1;
  int columns_m = A->columns - 1;
  if (!s21_create_matrix(rows_m, columns_m, matrix_m)) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        if (i != rows_zero && j != columns_zero) {
          int i_m = i;
          int j_m = j;
          if (i > rows_zero) i_m--;
          if (j > columns_zero) j_m--;
          matrix_m->matrix[i_m][j_m] = A->matrix[i][j];
        }
      }
    }
  }
}

double s21_opredelit(matrix_t *A) {
  double result = 0.0;
  if (A->rows == 1) {
    result = A->matrix[0][0];
  } else if (A->rows == 2) {
    result =
        A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
  } else {
    matrix_t matrix_m = {0};
    for (int i = 0; i < A->columns; i++) {
      s21_minor(0, i, A, &matrix_m);
      result += A->matrix[0][i] * s21_opredelit(&matrix_m) * pow(-1, i);
      s21_remove_matrix(&matrix_m);
    }
  }
  return result;
}