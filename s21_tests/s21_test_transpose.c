#include "../s21_test.h"

START_TEST(s21_transpose_test_1) {
  int res = 0;
  matrix_t A = {0};
  matrix_t B = {0};
  res = s21_transpose(&A, &B);
  ck_assert_int_eq(res, 2);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_transpose_test_2) {
  int res = 0;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t T = {0};
  s21_create_matrix(3, 4, &A);
  s21_init_matrix(1.0, &A);
  s21_create_matrix(4, 3, &B);
  B.matrix[0][0] = 1.0;
  B.matrix[0][1] = 5.0;
  B.matrix[0][2] = 9.0;
  B.matrix[1][0] = 2.0;
  B.matrix[1][1] = 6.0;
  B.matrix[1][2] = 10.0;
  B.matrix[2][0] = 3.0;
  B.matrix[2][1] = 7.0;
  B.matrix[2][2] = 11.0;
  B.matrix[3][0] = 4.0;
  B.matrix[3][1] = 8.0;
  B.matrix[3][2] = 12.0;
  s21_transpose(&A, &T);
  res = s21_eq_matrix(&T, &B);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&T);
}
END_TEST

Suite *s21_suite_transpose(void) {
  Suite *s = suite_create("s21_transpose");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, s21_transpose_test_1);
  tcase_add_test(tc_core, s21_transpose_test_2);

  suite_add_tcase(s, tc_core);
  return s;
}