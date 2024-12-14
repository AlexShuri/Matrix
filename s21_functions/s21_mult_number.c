#include "../s21_matrix.h"  //

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int flag = 0;
  if (!s21_prov(A)) {
    if (!s21_create_matrix(A->rows, A->columns, result)) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++)
          result->matrix[i][j] = A->matrix[i][j] * number;
      }
    } else {
      flag = 1;
    }
  } else {
    flag = 1;
  }
  return flag;
}