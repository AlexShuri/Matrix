#include "../s21_test.h"

START_TEST(s21_determinant_test_1) {
  double determ = 0.0;
  matrix_t A = {0};
  s21_create_matrix(1, 1, &A);
  s21_init_matrix(1.0, &A);
  s21_determinant(&A, &determ);
  ck_assert_double_eq(determ, 1.0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_test_2) {
  int res = 0;
  double determ = 0.0;
  matrix_t A = {0};
  s21_create_matrix(1, 2, &A);
  res = s21_determinant(&A, &determ);
  ck_assert_int_eq(res, 2);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_test_3) {
  const int size = 4;
  matrix_t m = {0};
  s21_create_matrix(size, size, &m);

  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++) m.matrix[i][j] = j + i;

  double res = 0;
  int code = s21_determinant(&m, &res);
  ck_assert_double_eq_tol(res, 0, 1e-6);
  ck_assert_int_eq(code, 0);

  s21_remove_matrix(&m);
}
END_TEST

START_TEST(s21_determinant_test_4) {
  const int size = 5;
  matrix_t m = {0};
  s21_create_matrix(size, size, &m);
  m.matrix[0][1] = 6;
  m.matrix[0][2] = -2;
  m.matrix[0][3] = -1;
  m.matrix[0][4] = 5;
  m.matrix[1][3] = -9;
  m.matrix[1][4] = -7;
  m.matrix[2][1] = 15;
  m.matrix[2][2] = 35;
  m.matrix[3][1] = -1;
  m.matrix[3][2] = -11;
  m.matrix[3][3] = -2;
  m.matrix[3][4] = 1;
  m.matrix[4][0] = -2;
  m.matrix[4][1] = -2;
  m.matrix[4][2] = 3;
  m.matrix[4][4] = -2;

  double res = 0;
  int code = s21_determinant(&m, &res);
  ck_assert_double_eq_tol(res, 2480, 1e-6);
  ck_assert_int_eq(code, 0);

  s21_remove_matrix(&m);
}
END_TEST

START_TEST(s21_determinant_test_5) {
  matrix_t m = {0};
  int rows = 5;
  rows = -rows;
  s21_create_matrix(rows, rows, &m);
  double res = 0;
  int code = s21_determinant(&m, &res);
  ck_assert_int_eq(code, 1);

  s21_remove_matrix(&m);
}
END_TEST

START_TEST(s21_determinant_test_6) {
  int res = 0;
  double determ = 0.0;
  matrix_t A = {NULL, 0, 0};
  res = s21_determinant(&A, &determ);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
}
END_TEST

Suite *s21_suite_determinant(void) {
  Suite *s = suite_create("s21_determinant");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, s21_determinant_test_1);
  tcase_add_test(tc_core, s21_determinant_test_2);
  tcase_add_test(tc_core, s21_determinant_test_3);
  tcase_add_test(tc_core, s21_determinant_test_4);
  tcase_add_test(tc_core, s21_determinant_test_5);
  tcase_add_test(tc_core, s21_determinant_test_6);

  suite_add_tcase(s, tc_core);
  return s;
}