#ifndef S21_TEST_H
#define S21_TEST_H

#include <check.h>

#include "s21_matrix.h"

#define SUCCESS 1
#define FAILURE 0

Suite *s21_suite_create_matrix(void);
Suite *s21_suite_eq_matrix(void);
Suite *s21_suite_sum_matrix(void);
Suite *s21_suite_sub_matrix(void);
Suite *s21_suite_mult_number(void);
Suite *s21_suite_mult_matrix(void);
Suite *s21_suite_transpose(void);
Suite *s21_suite_determinant(void);
Suite *s21_suite_calc_complements(void);
Suite *s21_suite_inverse_matrix(void);

void s21_init_matrix(double number, matrix_t *matrix);
#endif  // S21_TEST_H