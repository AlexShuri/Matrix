#include "../s21_test.h"

START_TEST(s21_sub_matrix_test_1) {
  int res = 0;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t Z = {0};
  matrix_t X = {0};
  s21_create_matrix(4, 4, &A);
  s21_init_matrix(1.0, &A);
  s21_create_matrix(4, 4, &B);
  s21_init_matrix(1.0, &B);
  s21_sub_matrix(&A, &B, &Z);
  s21_create_matrix(4, 4, &X);
  X.matrix[0][0] = 0.0;
  X.matrix[0][1] = 0.0;
  X.matrix[0][2] = 0.0;
  X.matrix[0][3] = 0.0;
  X.matrix[1][0] = 0.0;
  X.matrix[1][1] = 0.0;
  X.matrix[1][2] = 0.0;
  X.matrix[1][3] = 0.0;
  X.matrix[2][0] = 0.0;
  X.matrix[2][1] = 0.0;
  X.matrix[2][2] = 0.0;
  X.matrix[2][3] = 0.0;
  X.matrix[3][0] = 0.0;
  X.matrix[3][1] = 0.0;
  X.matrix[3][2] = 0.0;
  X.matrix[3][3] = 0.0;
  res = s21_eq_matrix(&X, &Z);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&X);
  s21_remove_matrix(&Z);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_sub_matrix_test_2) {
  int res = 0;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t Z = {0};
  s21_create_matrix(0, 0, &A);
  s21_create_matrix(4, 3, &B);
  res = s21_sub_matrix(&A, &B, &Z);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&Z);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_sub_matrix_test_3) {
  int res = 0;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t Z = {0};
  s21_create_matrix(4, 2, &A);
  s21_create_matrix(4, 3, &B);
  res = s21_sub_matrix(&A, &B, &Z);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&Z);
  ck_assert_int_eq(res, 2);
}
END_TEST

START_TEST(s21_sub_matrix_test_4) {
  int res = 0;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t Z = {0};
  matrix_t X = {0};
  s21_create_matrix(4, 2, &A);
  s21_init_matrix(-1.0, &A);
  s21_create_matrix(4, 2, &B);
  s21_init_matrix(3.0, &B);
  s21_sub_matrix(&A, &B, &Z);
  s21_create_matrix(4, 2, &X);
  X.matrix[0][0] = -4.0;
  X.matrix[0][1] = -4.0;
  X.matrix[1][0] = -4.0;
  X.matrix[1][1] = -4.0;
  X.matrix[2][0] = -4.0;
  X.matrix[2][1] = -4.0;
  X.matrix[3][0] = -4.0;
  X.matrix[3][1] = -4.0;
  res = s21_eq_matrix(&X, &Z);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&X);
  s21_remove_matrix(&Z);
  ck_assert_int_eq(res, 0);
}
END_TEST

Suite *s21_suite_sub_matrix(void) {
  Suite *s = suite_create("s21_sub_matrix");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, s21_sub_matrix_test_1);
  tcase_add_test(tc_core, s21_sub_matrix_test_2);
  tcase_add_test(tc_core, s21_sub_matrix_test_3);
  tcase_add_test(tc_core, s21_sub_matrix_test_4);

  suite_add_tcase(s, tc_core);
  return s;
}