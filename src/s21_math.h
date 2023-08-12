#ifndef SRC_S21_MATH_H_
#define SRC_S21_MATH_H_

#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PI 3.14159265358979323846
#define s21_NAN (0.0 / 0.0)
#define s21_INF (1.0 / 0.0)
#define s21_NEGINF (-1.0 / 0.0)
#define s21_E 2.71828182845904523536

// |Функции Маркуса|
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_cos(double x);
long double s21_sin(double x);
long double s21_tan(double x);

// |Функции Никиты|
long double s21_ceil(double x);
int s21_abs(int x);
long double s21_exp(double x);

// |Функции Коляна|
long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);

// |Функции Макса|
long double s21_log(double x);
long double s21_pow(double base, double exp);
long double s21_sqrt(double x);

// |Доп Функции при необходимости|

int s21_isnan(double x);
long double s21_fabs(double x);
long double s21_factorial(int x);
double module(double i);

#endif  // SRC_S21_MATH_H_
