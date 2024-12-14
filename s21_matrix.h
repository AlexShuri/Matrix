#ifndef S21_MATRIX_H
#define S21_MATRIX_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1
#define FAILURE 0

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

int s21_create_matrix(int rows, int columns,
                      matrix_t *result);  // Создание матрицы
void s21_remove_matrix(matrix_t *A);  // Удаление, очиска матрицы
int s21_eq_matrix(matrix_t *A, matrix_t *B);  // Сравнение матриц
int s21_sum_matrix(matrix_t *A, matrix_t *B,
                   matrix_t *result);  // Сложение матриц
int s21_sub_matrix(matrix_t *A, matrix_t *B,
                   matrix_t *result);  // Вычитание матриц
int s21_mult_number(matrix_t *A, double number,
                    matrix_t *result);  // Умножение матрицы на число
int s21_mult_matrix(matrix_t *A, matrix_t *B,
                    matrix_t *result);  // Умножение матриц друг на друга
int s21_transpose(matrix_t *A,
                  matrix_t *result);  // Замена столбцов и строк местами
int s21_calc_complements(matrix_t *A,
                         matrix_t *result);  // Вычеркивание из матрицы
int s21_determinant(matrix_t *A, double *result);  //Определитель матрицы
int s21_inverse_matrix(matrix_t *A, matrix_t *result);  // Обратная матрица

// Service fun
void s21_sum_sub(int znak, matrix_t *A, matrix_t *B, matrix_t *result);
int s21_prov(matrix_t *matrix);
void s21_minor(int rows_zero, int columns_zero, matrix_t *A,
               matrix_t *matrix_t);
double s21_opredelit(matrix_t *A);
#endif  // S21_MATRIX_H