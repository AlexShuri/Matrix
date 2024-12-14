#include "../s21_test.h"

START_TEST(s21_calc_complements_test_1) {
  matrix_t expected = {0};
  matrix_t m = {0};
  matrix_t result = {0};
  s21_create_matrix(3, 3, &m);
  s21_create_matrix(3, 3, &expected);
  m.matrix[0][0] = 1;
  m.matrix[0][1] = 2;
  m.matrix[0][2] = 3;

  m.matrix[1][0] = 0;
  m.matrix[1][1] = 4;
  m.matrix[1][2] = 2;

  m.matrix[2][0] = 5;
  m.matrix[2][1] = 2;
  m.matrix[2][2] = 1;

  expected.matrix[0][0] = 0;
  expected.matrix[0][1] = 10;
  expected.matrix[0][2] = -20;

  expected.matrix[1][0] = 4;
  expected.matrix[1][1] = -14;
  expected.matrix[1][2] = 8;

  expected.matrix[2][0] = -8;
  expected.matrix[2][1] = -2;
  expected.matrix[2][2] = 4;

  int code = s21_calc_complements(&m, &result);

  ck_assert_int_eq(s21_eq_matrix(&result, &expected), 1);
  ck_assert_int_eq(code, 0);
  s21_remove_matrix(&m);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(s21_calc_complements_test_2) {
  matrix_t m = {0};
  matrix_t result = {0};
  int code = s21_calc_complements(&m, &result);
  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(s21_calc_complements_test_3) {
  matrix_t m = {0};
  matrix_t result = {0};
  s21_create_matrix(1, 1, &m);
  int code = s21_calc_complements(&m, &result);
  ck_assert_int_eq(code, 2);
  s21_remove_matrix(&m);
  s21_remove_matrix(&result);
}
END_TEST

Suite *s21_suite_calc_complements(void) {
  Suite *s = suite_create("s21_calc_complements");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, s21_calc_complements_test_1);
  tcase_add_test(tc_core, s21_calc_complements_test_2);
  tcase_add_test(tc_core, s21_calc_complements_test_3);

  suite_add_tcase(s, tc_core);
  return s;
}