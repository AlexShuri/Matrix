#include "../s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int flag = 0;
  int znak = -1;
  if (!s21_prov(A) && !s21_prov(B)) {
    if ((A->rows == B->rows) && (A->columns == B->columns)) {
      if (!s21_create_matrix(A->rows, A->columns, result)) {
        s21_sum_sub(znak, A, B, result);
      } else {
        flag = 1;
      }
    } else {
      flag = 2;
    }
  } else {
    flag = 1;
  }
  return flag;
}