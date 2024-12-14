#include "../s21_test.h"

START_TEST(s21_create_matrix_test_1) {
  int result = 0;
  matrix_t A = {0};
  result = s21_create_matrix(1, 1, &A);
  ck_assert_int_eq(result, 0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_test_2) {
  int result = 0;
  matrix_t A = {0};
  result = s21_create_matrix(2, 2, &A);
  ck_assert_int_eq(result, 0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_test_3) {
  int result = 0;
  matrix_t A = {0};
  result = s21_create_matrix(3, 3, &A);
  ck_assert_int_eq(result, 0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_test_4) {
  int result = 0;
  matrix_t A = {0};
  result = s21_create_matrix(10, 10, &A);
  ck_assert_int_eq(result, 0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_test_5) {
  int result = 0;
  matrix_t A = {0};
  result = s21_create_matrix(10, 15, &A);
  ck_assert_int_eq(result, 0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_test_6) {
  int result = 0;
  matrix_t A = {0};
  result = s21_create_matrix(11, 10, &A);
  ck_assert_int_eq(result, 0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_test_7) {
  int result = 0;
  matrix_t A = {0};
  result = s21_create_matrix(1, 0, &A);
  ck_assert_int_eq(result, 1);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_test_8) {
  int result = 0;
  matrix_t A = {0};
  result = s21_create_matrix(1, 1, &A);
  ck_assert_int_eq(result, 0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_test_9) {
  int result = 0;
  matrix_t A = {0};
  result = s21_create_matrix(0, 0, &A);
  ck_assert_int_eq(result, 1);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_test_10) {
  int result = 0;
  matrix_t A = {0};
  result = s21_create_matrix(-1, 1, &A);
  ck_assert_int_eq(result, 1);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_test_11) {
  int result = 0;
  matrix_t A = {0};
  result = s21_create_matrix(-9, -9, &A);
  ck_assert_int_eq(result, 1);
  s21_remove_matrix(&A);
}
END_TEST

Suite *s21_suite_create_matrix(void) {
  Suite *s = suite_create("s21_create_matrix");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, s21_create_matrix_test_1);
  tcase_add_test(tc_core, s21_create_matrix_test_2);
  tcase_add_test(tc_core, s21_create_matrix_test_3);
  tcase_add_test(tc_core, s21_create_matrix_test_4);
  tcase_add_test(tc_core, s21_create_matrix_test_5);
  tcase_add_test(tc_core, s21_create_matrix_test_6);
  tcase_add_test(tc_core, s21_create_matrix_test_7);
  tcase_add_test(tc_core, s21_create_matrix_test_8);
  tcase_add_test(tc_core, s21_create_matrix_test_9);
  tcase_add_test(tc_core, s21_create_matrix_test_10);
  tcase_add_test(tc_core, s21_create_matrix_test_11);

  suite_add_tcase(s, tc_core);
  return s;
}