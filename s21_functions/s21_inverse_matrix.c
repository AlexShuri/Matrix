#include "../s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int flag = 0;
  double m = 0.0;
  if (!s21_prov(A)) {
    if (!s21_determinant(A, &m) && m != 0) {
      matrix_t matrix_calc = {0};
      if (!(flag = s21_calc_complements(A, &matrix_calc))) {
        matrix_t matrix_tran = {0};
        if (!(flag = s21_transpose(&matrix_calc, &matrix_tran))) {
          s21_mult_number(&matrix_tran, 1 / m, result);

        } else {
          flag = 2;
        }
        s21_remove_matrix(&matrix_tran);
      } else {
        flag = 2;
      }
      s21_remove_matrix(&matrix_calc);
    } else {
      flag = 2;
    }
  } else {
    flag = 1;
  }
  return flag;
}