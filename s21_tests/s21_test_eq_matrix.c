#include "../s21_test.h"

START_TEST(s21_eq_matrix_test_1) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 1.0001;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3.05;
  A.matrix[1][1] = 4;
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[1][0] = 3.05;
  B.matrix[1][1] = 4;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(s21_eq_matrix_test_2) {
  int res = 0;
  matrix_t A, B;
  s21_create_matrix(3, 2, &A);
  s21_init_matrix(1.0, &A);
  s21_create_matrix(3, 2, &B);
  s21_init_matrix(1.0, &B);
  res = s21_eq_matrix(&A, &B);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  ck_assert_int_eq(res, SUCCESS);
}
END_TEST

START_TEST(s21_eq_matrix_test_3) {
  int res = 0;
  matrix_t A, B;
  s21_create_matrix(3, 2, &A);
  s21_init_matrix(1.0, &A);
  s21_create_matrix(3, 2, &B);
  s21_init_matrix(2.0, &B);
  res = s21_eq_matrix(&B, &A);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  ck_assert_int_eq(res, FAILURE);
}
END_TEST

START_TEST(s21_eq_matrix_test_4) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &B);
  A.matrix[0][0] = 1;
  B.matrix[0][0] = 1;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(s21_eq_matrix_test_5) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[1][0] = 3;
  B.matrix[1][1] = 4;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

Suite *s21_suite_eq_matrix(void) {
  Suite *s = suite_create("s21_eq_matrix");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, s21_eq_matrix_test_1);
  tcase_add_test(tc_core, s21_eq_matrix_test_2);
  tcase_add_test(tc_core, s21_eq_matrix_test_3);
  tcase_add_test(tc_core, s21_eq_matrix_test_4);
  tcase_add_test(tc_core, s21_eq_matrix_test_5);

  suite_add_tcase(s, tc_core);
  return s;
}