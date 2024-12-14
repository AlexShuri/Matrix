#include "../s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int flag = 0;
  if (s21_prov(A) == 0) {
    if (A->rows == A->columns) {
      *result = s21_opredelit(A);
    } else {
      flag = 2;
    }
  } else {
    flag = 1;
  }
  return flag;
}