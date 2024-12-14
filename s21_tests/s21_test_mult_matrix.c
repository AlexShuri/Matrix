#include "../s21_test.h"

START_TEST(s21_mult_matrix_test_1) {
  int res = 0;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t Z = {0};
  res = s21_mult_matrix(&A, &B, &Z);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&Z);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_mult_matrix_test_2) {
  int res = 0;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t Z = {0};
  matrix_t X = {0};
  s21_create_matrix(4, 2, &A);
  s21_init_matrix(-5.0, &A);
  s21_create_matrix(2, 4, &B);
  s21_init_matrix(1.0, &B);
  s21_mult_matrix(&A, &B, &Z);
  s21_create_matrix(4, 4, &X);
  X.matrix[0][0] = -25.0;
  X.matrix[0][1] = -34.0;
  X.matrix[0][2] = -43.0;
  X.matrix[0][3] = -52.0;
  X.matrix[1][0] = -13.0;
  X.matrix[1][1] = -18.0;
  X.matrix[1][2] = -23.0;
  X.matrix[1][3] = -28.0;
  X.matrix[2][0] = -1.0;
  X.matrix[2][1] = -2.0;
  X.matrix[2][2] = -3.0;
  X.matrix[2][3] = -4.0;
  X.matrix[3][0] = 11.0;
  X.matrix[3][1] = 14.0;
  X.matrix[3][2] = 17.0;
  X.matrix[3][3] = 20.0;
  res = s21_eq_matrix(&X, &Z);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&X);
  s21_remove_matrix(&Z);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_mult_matrix_test_3) {
  int res = 0;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t Z = {0};
  matrix_t X = {0};
  s21_create_matrix(4, 4, &A);
  s21_init_matrix(1.0, &A);
  s21_create_matrix(4, 4, &B);
  s21_init_matrix(1.0, &B);
  s21_mult_matrix(&A, &B, &Z);
  s21_create_matrix(4, 4, &X);
  X.matrix[0][0] = 90.0;
  X.matrix[0][1] = 100.0;
  X.matrix[0][2] = 110.0;
  X.matrix[0][3] = 120.0;
  X.matrix[1][0] = 202.0;
  X.matrix[1][1] = 228.0;
  X.matrix[1][2] = 254.0;
  X.matrix[1][3] = 280.0;
  X.matrix[2][0] = 314.0;
  X.matrix[2][1] = 356.0;
  X.matrix[2][2] = 398.0;
  X.matrix[2][3] = 440.0;
  X.matrix[3][0] = 426.0;
  X.matrix[3][1] = 484.0;
  X.matrix[3][2] = 542.0;
  X.matrix[3][3] = 600.0;
  res = s21_eq_matrix(&X, &Z);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&X);
  s21_remove_matrix(&Z);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_mult_matrix_test_4) {
  int res = 0;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t Z = {0};
  s21_create_matrix(2, 3, &A);
  s21_init_matrix(-5.0, &A);
  s21_create_matrix(2, 2, &B);
  s21_init_matrix(1.0, &B);
  res = s21_mult_matrix(&A, &B, &Z);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&Z);
  ck_assert_int_eq(res, 2);
}
END_TEST

Suite *s21_suite_mult_matrix(void) {
  Suite *s = suite_create("s21_mult_matrix");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, s21_mult_matrix_test_1);
  tcase_add_test(tc_core, s21_mult_matrix_test_2);
  tcase_add_test(tc_core, s21_mult_matrix_test_3);
  tcase_add_test(tc_core, s21_mult_matrix_test_4);

  suite_add_tcase(s, tc_core);
  return s;
}