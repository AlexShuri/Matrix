#include "../s21_test.h"

START_TEST(s21_inverse_matrix_test_1) {
  matrix_t m = {0};
  matrix_t result = {0};
  s21_create_matrix(1, 4, &m);
  int code = s21_inverse_matrix(&m, &result);
  ck_assert_int_eq(code, 2);
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(s21_inverse_matrix_test_2) {
  matrix_t m = {0};
  matrix_t result = {0};
  int code = s21_inverse_matrix(&m, &result);
  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(s21_inverse_matrix_test_3) {
  matrix_t A = {0}, C = {0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &C);
  C.matrix[0][0] = 1.0;
  C.matrix[0][1] = -1.0;
  C.matrix[0][2] = 1.0;
  C.matrix[1][0] = -38.0;
  C.matrix[1][1] = 41.0;
  C.matrix[1][2] = -34.0;
  C.matrix[2][0] = 27.0;
  C.matrix[2][1] = -29.0;
  C.matrix[2][2] = 24.0;
  A.matrix[0][0] = 2.0;
  A.matrix[0][1] = 5.0;
  A.matrix[0][2] = 7.0;
  A.matrix[1][0] = 6.0;
  A.matrix[1][1] = 3.0;
  A.matrix[1][2] = 4.0;
  A.matrix[2][0] = 5.0;
  A.matrix[2][1] = -2.0;
  A.matrix[2][2] = -3.0;
  matrix_t B = {0};
  s21_inverse_matrix(&A, &B);
  int res = s21_eq_matrix(&B, &C);
  ck_assert_int_eq(res, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(s21_inverse_matrix_test_4) {
  int res = 0;
  matrix_t A = {0};
  matrix_t Z = {0};
  s21_create_matrix(3, 2, &A);
  s21_init_matrix(1.0, &A);
  res = s21_inverse_matrix(&A, &Z);
  ck_assert_int_eq(res, 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&Z);
}
END_TEST

START_TEST(s21_inverse_matrix_test_5) {
  int res = 0;
  matrix_t A = {0};
  matrix_t Z = {0};
  s21_create_matrix(3, 3, &A);
  s21_init_matrix(1.0, &A);
  s21_remove_matrix(&A);
  res = s21_inverse_matrix(&A, &Z);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&Z);
}
END_TEST

START_TEST(s21_inverse_matrix_test_6) {
  matrix_t A = {0}, C = {0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &C);
  C.matrix[0][0] = 1.0;
  C.matrix[0][1] = -1.0;
  C.matrix[0][2] = 1.0;
  C.matrix[1][0] = -38.0;
  C.matrix[1][1] = 41.0;
  C.matrix[1][2] = -34.0;
  C.matrix[2][0] = 27.0;
  C.matrix[2][1] = -29.0;
  C.matrix[2][2] = 24.0;
  A.matrix[0][0] = 2.0;
  A.matrix[0][1] = 5.0;
  A.matrix[0][2] = 7.0;
  A.matrix[1][0] = 6.0;
  A.matrix[1][1] = 3.0;
  A.matrix[1][2] = 4.0;
  A.matrix[2][0] = 5.0;
  A.matrix[2][1] = -2.0;
  A.matrix[2][2] = -3.0;
  matrix_t B = {0};
  s21_inverse_matrix(&A, &B);
  int res = s21_eq_matrix(&B, &C);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

Suite *s21_suite_inverse_matrix(void) {
  Suite *s = suite_create("s21_inverse_matrix");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, s21_inverse_matrix_test_1);
  tcase_add_test(tc_core, s21_inverse_matrix_test_2);
  tcase_add_test(tc_core, s21_inverse_matrix_test_3);
  tcase_add_test(tc_core, s21_inverse_matrix_test_4);
  tcase_add_test(tc_core, s21_inverse_matrix_test_5);
  tcase_add_test(tc_core, s21_inverse_matrix_test_6);

  suite_add_tcase(s, tc_core);
  return s;
}