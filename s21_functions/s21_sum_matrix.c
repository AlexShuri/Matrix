#include "../s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int flag = 0;
  int znak = 1;
  if (s21_prov(A) == 0 && s21_prov(B) == 0) {
    if ((A->rows == B->rows) && (A->columns == B->columns)) {
      s21_sum_sub(znak, A, B, result);
    } else {
      flag = 2;
    }
  } else {
    flag = 1;
  }
  return flag;
}