#include "s21_test.h"

void s21_init_matrix(double number, matrix_t *matrix) {
  for (int i = 0; i < matrix->rows; i++) {
    for (int j = 0; j < matrix->columns; j++) {
      matrix->matrix[i][j] = number;
      number++;
    }
  }
}

int main() {
  int error = 0;
  SRunner *sr = srunner_create(NULL);

  srunner_add_suite(sr, s21_suite_create_matrix());
  srunner_add_suite(sr, s21_suite_eq_matrix());
  srunner_add_suite(sr, s21_suite_sum_matrix());
  srunner_add_suite(sr, s21_suite_sub_matrix());
  srunner_add_suite(sr, s21_suite_mult_number());
  srunner_add_suite(sr, s21_suite_mult_matrix());
  srunner_add_suite(sr, s21_suite_transpose());
  srunner_add_suite(sr, s21_suite_determinant());
  srunner_add_suite(sr, s21_suite_calc_complements());
  srunner_add_suite(sr, s21_suite_inverse_matrix());

  srunner_run_all(sr, CK_NORMAL);

  error = srunner_ntests_failed(sr);

  srunner_free(sr);
  return !error ? 0 : 1;
}
