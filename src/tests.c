#include <check.h>
#include <math.h>
#include <stdio.h>

#include "s21_math.h"

// <=== TEST CASES: s21_ceil ===>

START_TEST(tc_ceil_1) {
  double test_value = 1.123456f;
  long double result = s21_ceil(test_value), expecting = ceil(test_value);

  ck_assert_double_eq(expecting, result);
}
END_TEST

START_TEST(tc_ceil_2) {
  double test_value = -1.123456f;
  long double result = s21_ceil(test_value), expecting = ceil(test_value);

  ck_assert_double_eq(expecting, result);
}
END_TEST

START_TEST(tc_ceil_3) {
  double test_value = s21_NAN;
  char result[32] = {0}, expecting[32] = {0};

  sprintf(result, "%Lf", s21_ceil(test_value));
  sprintf(expecting, "%lf", ceil(test_value));

  ck_assert_str_eq(expecting, result);
}
END_TEST

START_TEST(tc_ceil_4) {
  double test_value = s21_INF;
  long double result = s21_ceil(test_value), expecting = ceil(test_value);

  ck_assert_double_eq(expecting, result);
}
END_TEST

START_TEST(tc_ceil_5) {
  double test_value = -s21_INF;
  long double result = s21_ceil(test_value), expecting = ceil(test_value);

  ck_assert_double_eq(expecting, result);
}
END_TEST

START_TEST(tc_ceil_6) {
  double test_value = 10;
  long double result = s21_ceil(test_value), expecting = ceil(test_value);

  ck_assert_double_eq(expecting, result);
}
END_TEST

// <=== TEST CASES: s21_log ===>

START_TEST(tc_log_1) {
  ck_assert_double_nan(s21_log(s21_NAN));
  ck_assert_double_eq(log(0), s21_log(0));
  ck_assert_double_nan(s21_log(-3));
  ck_assert_double_eq(log(s21_INF), s21_log(s21_INF));
  ck_assert_double_nan(s21_log(-s21_INF));
  ck_assert_double_eq(log(1), s21_log(1));
  ck_assert_double_eq(log(s21_E), s21_log(s21_E));
  ck_assert_double_eq_tol(log(2), s21_log(2), 1e-6);
}
END_TEST

START_TEST(tc_log_2) {
  long double x = -1.1f;
  ck_assert_ldouble_nan(log(x));
  ck_assert_ldouble_nan(s21_log(x));
}
END_TEST

START_TEST(tc_log_3) {
  long double x = 0.000000000000000000000000000000001f;
  ck_assert_ldouble_eq_tol(log(x), s21_log(x), 0.00000001f);
}
END_TEST

START_TEST(tc_log_4) {
  long double x = 5000000.000000000000000000000000000000001f;
  ck_assert_ldouble_eq_tol(log(x), s21_log(x), 0.00000001f);
}
END_TEST

START_TEST(tc_log_5) {
  long double x = 0.0f;
  ck_assert_ldouble_infinite(log(x));
  ck_assert_ldouble_infinite(s21_log(x));
}
END_TEST

START_TEST(tc_log_6) {
  for (double k = 0.000005; k < 1; k *= 5) {
    double a = s21_log(k);
    double b = log(k);
    ck_assert_double_eq_tol(a, b, 1e-6);
  }
}
END_TEST

// <=== TEST CASES: s21_pow ===>

START_TEST(tc_pow_1) {
  long double x = 1.1f;
  ck_assert_ldouble_eq_tol(pow(x, 1), s21_pow(x, 1), 0.00000001f);
}
END_TEST

START_TEST(tc_pow_2) {
  long double x = 1.1f;
  ck_assert_ldouble_eq_tol(pow(x, 0), s21_pow(x, 0), 0.00000001f);
}
END_TEST

START_TEST(tc_pow_3) {
  long double x = -0.1f;
  ck_assert_ldouble_eq_tol(pow(x, -1), s21_pow(x, -1), 0.00000001f);
}
END_TEST

START_TEST(tc_pow_4) {
  long double x = -0.1f;
  ck_assert_ldouble_nan(log(pow(x, -1.123)));
  ck_assert_ldouble_nan(s21_log(s21_pow(x, -1.123)));
}
END_TEST

START_TEST(tc_pow_5) {
  long double x = -1231231230.0000000000000000000000000000000123f;
  ck_assert_ldouble_nan(pow(x, 0.00000001));
  ck_assert_ldouble_nan(s21_pow(x, 0.00000001));
}
END_TEST

START_TEST(tc_pow_6) {
  for (double i = -10; i < 10; i += 1.5) {
    for (double j = -7; j < 15; j++) {
      long double a = s21_pow(i, j);
      long double b = pow(i, j);
      if ((!isnan(a) && !isnan(b)) && !(a == s21_INF && b == s21_INF) &&
          !(a == -s21_INF && b == -s21_INF)) {
        ck_assert_double_eq_tol(a, b, 1e1);
      }
    }
  }
}
END_TEST

START_TEST(tc_pow_7) {
  ck_assert_double_eq(pow(s21_INF, 0), s21_pow(s21_INF, 0));
  ck_assert_double_eq(pow(s21_INF, -1), s21_pow(s21_INF, -1));
  ck_assert_double_eq(pow(-1, -s21_INF), s21_pow(-1, -s21_INF));
  ck_assert_double_eq(pow(0, s21_INF), s21_pow(0, s21_INF));
  ck_assert_double_nan(s21_pow(0, s21_NAN));
  ck_assert_double_eq(pow(NAN, 0), s21_pow(s21_NAN, 0));
  ck_assert_double_nan(s21_pow(s21_NAN, s21_NAN));
  ck_assert_double_eq(pow(s21_INF, s21_INF), s21_pow(s21_INF, s21_INF));
  ck_assert_double_eq(pow(s21_INF, -s21_INF), s21_pow(s21_INF, -s21_INF));
  ck_assert_double_eq(pow(-s21_INF, s21_INF), s21_pow(-s21_INF, s21_INF));
  ck_assert_double_eq(pow(-s21_INF, -s21_INF), s21_pow(-s21_INF, -s21_INF));
  ck_assert_double_eq(pow(1, -s21_INF), s21_pow(1, -s21_INF));
  ck_assert_double_eq(pow(1, NAN), s21_pow(1, s21_NAN));
  ck_assert_double_nan(s21_pow(s21_NAN, s21_INF));
  ck_assert_double_nan(s21_pow(s21_INF, s21_NAN));
  ck_assert_double_nan(s21_pow(s21_NAN, -s21_INF));
  ck_assert_double_nan(s21_pow(-s21_INF, s21_NAN));
  ck_assert_double_eq(pow(2, s21_INF), s21_pow(2, s21_INF));
  ck_assert_double_eq(pow(0.5, s21_INF), s21_pow(0.5, s21_INF));
  ck_assert_double_eq(pow(-2, s21_INF), s21_pow(-2, s21_INF));
  ck_assert_double_eq(pow(2, -s21_INF), s21_pow(2, -s21_INF));
  ck_assert_double_eq(pow(0.5, -s21_INF), s21_pow(0.5, -s21_INF));
  ck_assert_double_eq(pow(-2, -s21_INF), s21_pow(-2, -s21_INF));
}
END_TEST

// <=== TEST CASES: s21_sqrt ===>

START_TEST(tc_sqrt_1) {
  long double x = 1.1f;
  ck_assert_ldouble_eq_tol(sqrt(x), s21_sqrt(x), 0.00000001f);
}
END_TEST

START_TEST(tc_sqrt_2) {
  ck_assert_double_nan(s21_sqrt(s21_NAN));
  ck_assert_double_nan(sqrt(s21_NAN));
  ck_assert_double_eq(s21_sqrt(s21_INF), sqrt(s21_INF));
  ck_assert_double_nan(s21_sqrt(-s21_INF));
  ck_assert_double_nan(sqrt(-s21_INF));
  ck_assert_double_nan(s21_sqrt(-1));
  ck_assert_double_nan(sqrt(-1));
  ck_assert_double_eq_tol(s21_sqrt(100), sqrt(100), 1e-5);
}
END_TEST

START_TEST(tc_sqrt_3) {
  long double x = s21_E;
  ck_assert_double_eq_tol(s21_sqrt(x), sqrt(x), 1e-1);
}
END_TEST

Suite *ts_log() {
  Suite *suite = suite_create("ts_log");
  TCase *test_case = tcase_create("tc_log");
  tcase_add_test(test_case, tc_log_1);
  tcase_add_test(test_case, tc_log_2);
  tcase_add_test(test_case, tc_log_3);
  tcase_add_test(test_case, tc_log_4);
  tcase_add_test(test_case, tc_log_5);
  tcase_add_test(test_case, tc_log_6);
  suite_add_tcase(suite, test_case);
  return suite;
}
START_TEST(tc_abs_1) {
  int test_value = 1;
  int result = s21_abs(test_value), expecting = abs(test_value);

  ck_assert_int_eq(expecting, result);
}
END_TEST

START_TEST(tc_abs_2) {
  int test_value = -1;
  int result = s21_abs(test_value), expecting = abs(test_value);

  ck_assert_int_eq(expecting, result);
}
END_TEST

START_TEST(tc_abs_3) {
  int test_value = 2147483647;
  int result = s21_abs(test_value), expecting = abs(test_value);

  ck_assert_int_eq(expecting, result);
}
END_TEST

START_TEST(tc_abs_4) {
  int test_value = -2147483647;
  int result = s21_abs(test_value), expecting = abs(test_value);

  ck_assert_int_eq(expecting, result);
}
END_TEST

// <=== TEST CASES: s21_exp ===>

START_TEST(tc_exp_1) {
  double test_value = 1;
  long double result = s21_exp(test_value), expecting = exp(test_value);

  ck_assert_double_eq(expecting, result);
}
END_TEST

START_TEST(tc_exp_2) {
  double test_value = s21_NAN;
  char result[32] = {0}, expecting[32] = {0};

  sprintf(result, "%Lf", s21_exp(test_value));
  sprintf(expecting, "%lf", exp(test_value));

  ck_assert_str_eq(expecting, result);
}
END_TEST

START_TEST(tc_exp_3) {
  double test_value = s21_INF;
  long double result = s21_exp(test_value), expecting = exp(test_value);

  ck_assert_double_eq(expecting, result);
}
END_TEST

START_TEST(tc_exp_4) {
  double test_value = -s21_INF;
  long double result = s21_exp(test_value), expecting = exp(test_value);

  ck_assert_double_eq(expecting, result);
}
END_TEST

START_TEST(tc_exp_5) {
  double test_value = 1.1223;
  long double result = s21_exp(test_value), expecting = exp(test_value);

  ck_assert_double_eq(expecting, result);
}
END_TEST

START_TEST(tc_exp_6) {
  double test_value = -34.57886;
  long double result = s21_exp(test_value), expecting = exp(test_value);

  ck_assert_double_eq(expecting, result);
}
END_TEST

START_TEST(tc_exp_7) {
  double test_value = -123456789.97531;
  long double result = s21_exp(test_value), expecting = exp(test_value);

  ck_assert_double_eq(expecting, result);
}
END_TEST

START_TEST(tc_exp_8) {
  double test_value = 709.8;
  long double result = s21_exp(test_value), expecting = exp(test_value);

  ck_assert_double_eq(expecting, result);
}
END_TEST

START_TEST(tc_exp_9) {
  double test_value = 7093562174.8454;
  long double result = s21_exp(test_value), expecting = exp(test_value);

  ck_assert_double_eq(expecting, result);
}
END_TEST

START_TEST(tc_exp_10) {
  double test_value = 0.0;
  long double result = s21_exp(test_value), expecting = exp(test_value);

  ck_assert_double_eq(expecting, result);
}
END_TEST

// <=== TEST CASES: s21_fabs ===>

START_TEST(tc_fabs) {
  ck_assert_ldouble_eq(s21_fabs(50.0), fabs(50.0));
  ck_assert_ldouble_eq(s21_fabs(-40.0), fabs(-40.0));
  ck_assert_ldouble_eq(s21_fabs(-612367.54783), fabs(-612367.54783));
  ck_assert_ldouble_eq(s21_fabs(0.0), fabs(0.0));
  ck_assert_float_eq(s21_fabs(s21_INF), fabs(s21_INF));
}
END_TEST

// <=== TEST CASES: s21_floor ===>

START_TEST(tc_floor_1) {
  double test_value = 1.123456f;
  long double result = s21_floor(test_value), expecting = floor(test_value);

  ck_assert_double_eq(expecting, result);
}
END_TEST

START_TEST(tc_floor_2) {
  double test_value = -1.123456f;
  long double result = s21_floor(test_value), expecting = floor(test_value);

  ck_assert_double_eq(expecting, result);
}
END_TEST

START_TEST(tc_floor_3) {
  double test_value = s21_NAN;
  char result[32] = {0}, expecting[32] = {0};

  sprintf(result, "%Lf", s21_floor(test_value));
  sprintf(expecting, "%lf", floor(test_value));

  ck_assert_str_eq(expecting, result);
}
END_TEST

START_TEST(tc_floor_4) {
  double test_value = s21_INF;
  long double result = s21_floor(test_value), expecting = floor(test_value);

  ck_assert_double_eq(expecting, result);
}
END_TEST

START_TEST(tc_floor_5) {
  double test_value = -s21_INF;
  long double result = s21_floor(test_value), expecting = floor(test_value);

  ck_assert_double_eq(expecting, result);
}
END_TEST

START_TEST(tc_floor_6) {
  double test_value = 10;
  long double result = s21_floor(test_value), expecting = floor(test_value);

  ck_assert_double_eq(expecting, result);
}
END_TEST

START_TEST(tc_fmod) {
  double x = 0.0;
  double y = 0.0;
  ck_assert_ldouble_nan(s21_fmod(x, y));
  x = 4.5;
  y = 2.0;
  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 1e-6);
  x = -200000.567;
  y = 2.0;
  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 1e-6);
  x = 0.7;
  y = -2.0;
  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 1e-6);
  x = -0.99;
  y = 2.0;
  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 1e-6);
  x = 1.0;
  y = 0.0;
  ck_assert_ldouble_nan(s21_fmod(x, y));
  x = -1.0;
  y = 0.0;
  ck_assert_ldouble_nan(s21_fmod(x, y));
  x = 1.0 / 0.0;
  y = 0.0;
  ck_assert_ldouble_nan(s21_fmod(x, y));
  x = 0.0;
  y = 1.0 / 0.0;
  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 1e-6);
  x = -1.0 / 0.0;
  y = 0.0;
  ck_assert_ldouble_nan(s21_fmod(x, y));
  x = 0.0;
  y = -1.0 / 0.0;
  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 1e-6);
}
END_TEST

// <=== TEST CASES: s21_sin ===>

START_TEST(tc_sin) {
  char result[32] = {0}, expecting[32] = {0};
  double test_value = s21_NAN;
  ck_assert_ldouble_eq_tol(s21_sin(100), sin(100), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-100), sin(-100), 1e-6);

  sprintf(result, "%Lf", s21_sin(test_value));
  sprintf(expecting, "%lf", sin(test_value));
  ck_assert_str_eq(expecting, result);
  test_value = s21_INF;
  sprintf(result, "%Lf", s21_sin(test_value));
  sprintf(expecting, "%lf", sin(test_value));
  ck_assert_str_eq(expecting, result);

  ck_assert_ldouble_eq_tol(s21_sin(0), sin(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(PI / 6), sin(PI / 6), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(PI / 4), sin(PI / 4), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(PI / 3), sin(PI / 3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(PI / 2), sin(PI / 2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(PI), sin(PI), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(3 * PI / 2), sin(3 * PI / 2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(2 * PI), sin(2 * PI), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-PI / 6), sin(-PI / 6), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-PI / 4), sin(-PI / 4), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-PI / 3), sin(-PI / 3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-PI / 2), sin(-PI / 2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-PI), sin(-PI), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-3 * PI / 2), sin(-3 * PI / 2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-2 * PI), sin(-2 * PI), 1e-6);
}
END_TEST

// <=== TEST CASES: s21_cos ===>

START_TEST(tc_cos) {
  char result[32] = {0}, expecting[32] = {0};
  double test_value = s21_NAN;
  ck_assert_ldouble_eq_tol(s21_cos(100), cos(100), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-100), cos(-100), 1e-6);

  sprintf(result, "%Lf", s21_cos(test_value));
  sprintf(expecting, "%lf", cos(test_value));
  ck_assert_str_eq(expecting, result);
  test_value = s21_INF;
  sprintf(result, "%Lf", s21_cos(test_value));
  sprintf(expecting, "%lf", cos(test_value));
  ck_assert_str_eq(expecting, result);

  ck_assert_ldouble_eq_tol(s21_cos(0), cos(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(PI / 6), cos(PI / 6), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(PI / 4), cos(PI / 4), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(PI / 3), cos(PI / 3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(PI / 2), cos(PI / 2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(PI), cos(PI), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(3 * PI / 2), cos(3 * PI / 2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(2 * PI), cos(2 * PI), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-PI / 6), cos(-PI / 6), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-PI / 4), cos(-PI / 4), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-PI / 3), cos(-PI / 3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-PI / 2), cos(-PI / 2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-PI), cos(-PI), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-3 * PI / 2), cos(-3 * PI / 2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-2 * PI), cos(-2 * PI), 1e-6);
}
END_TEST

// <=== TEST CASES: s21_tan ===>

START_TEST(tc_tan) {
  char result[32] = {0}, expecting[32] = {0};
  double test_value = s21_NAN;
  ck_assert_ldouble_eq_tol(s21_tan(100), tan(100), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(-100), tan(-100), 1e-6);

  sprintf(result, "%Lf", s21_tan(test_value));
  sprintf(expecting, "%lf", tan(test_value));
  ck_assert_str_eq(expecting, result);
  test_value = s21_INF;
  sprintf(result, "%Lf", s21_tan(test_value));
  sprintf(expecting, "%lf", tan(test_value));
  ck_assert_str_eq(expecting, result);

  ck_assert_ldouble_eq_tol(s21_tan(0), tan(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(PI / 6), tan(PI / 6), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(PI / 4), tan(PI / 4), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(PI / 3), tan(PI / 3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(PI / 2), tan(PI / 2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(PI), tan(PI), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(3 * PI / 2), tan(3 * PI / 2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(2 * PI), tan(2 * PI), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(-PI / 6), tan(-PI / 6), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(-PI / 4), tan(-PI / 4), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(-PI / 3), tan(-PI / 3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(-PI / 2), tan(-PI / 2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(-PI), tan(-PI), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(-3 * PI / 2), tan(-3 * PI / 2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(-2 * PI), tan(-2 * PI), 1e-6);
}
END_TEST

// <=== TEST CASES: s21_asin ===>

START_TEST(tc_asin) {
  ck_assert_ldouble_nan(s21_asin(100));
  ck_assert_double_nan(asin(100));
  ck_assert_ldouble_nan(s21_asin(-100));
  ck_assert_double_nan(asin(-100));

  ck_assert_ldouble_nan(s21_asin(s21_NAN));
  ck_assert_double_nan(asin(s21_NAN));
  ck_assert_ldouble_nan(s21_asin(s21_INF));
  ck_assert_double_nan(asin(s21_INF));

  ck_assert_ldouble_eq_tol(s21_asin(0), asin(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(PI / 6), asin(PI / 6), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(PI / 4), asin(PI / 4), 1e-6);

  ck_assert_ldouble_eq_tol(s21_asin(-PI / 6), asin(-PI / 6), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(-PI / 4), asin(-PI / 4), 1e-6);
}
END_TEST

// <=== TEST CASES: s21_acos ===>

START_TEST(tc_acos) {
  ck_assert_ldouble_nan(s21_acos(100));
  ck_assert_double_nan(acos(100));
  ck_assert_ldouble_nan(s21_acos(-100));
  ck_assert_double_nan(acos(-100));

  ck_assert_ldouble_nan(s21_acos(s21_NAN));
  ck_assert_double_nan(acos(s21_NAN));
  ck_assert_ldouble_nan(s21_acos(s21_INF));
  ck_assert_double_nan(acos(s21_INF));

  ck_assert_ldouble_eq_tol(s21_acos(0), acos(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(PI / 6), acos(PI / 6), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(PI / 4), acos(PI / 4), 1e-6);

  ck_assert_ldouble_eq_tol(s21_acos(-PI / 6), acos(-PI / 6), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(-PI / 4), acos(-PI / 4), 1e-6);
}
END_TEST

// <=== TEST CASES: s21_atan ===>

START_TEST(tc_atan) {
  ck_assert_ldouble_eq_tol(s21_atan(100), atan(100), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(-100), atan(-100), 1e-6);

  ck_assert_ldouble_nan(s21_atan(s21_NAN));
  ck_assert_double_nan(atan(s21_NAN));
  ck_assert_ldouble_eq_tol(s21_atan(s21_INF), atan(s21_INF), 1e-6);

  ck_assert_ldouble_eq_tol(s21_atan(0), atan(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(PI / 6), atan(PI / 6), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(PI / 4), atan(PI / 4), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(PI / 3), atan(PI / 3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(PI / 2), atan(PI / 2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(PI), atan(PI), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(3 * PI / 2), atan(3 * PI / 2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(2 * PI), atan(2 * PI), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(-PI / 6), atan(-PI / 6), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(-PI / 4), atan(-PI / 4), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(-PI / 3), atan(-PI / 3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(-PI / 2), atan(-PI / 2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(-PI), atan(-PI), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(-3 * PI / 2), atan(-3 * PI / 2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(-2 * PI), atan(-2 * PI), 1e-6);
}
END_TEST

Suite *ts_ceil() {
  Suite *suite = suite_create("ts_ceil");
  TCase *test_case = tcase_create("tc_ceil");

  tcase_add_test(test_case, tc_ceil_1);
  tcase_add_test(test_case, tc_ceil_2);
  tcase_add_test(test_case, tc_ceil_3);
  tcase_add_test(test_case, tc_ceil_4);
  tcase_add_test(test_case, tc_ceil_5);
  tcase_add_test(test_case, tc_ceil_6);
  suite_add_tcase(suite, test_case);

  return suite;
}

Suite *ts_sin() {
  Suite *suite = suite_create("ts_sin");
  TCase *test_case = tcase_create("tc_sin");

  tcase_add_test(test_case, tc_sin);

  suite_add_tcase(suite, test_case);

  return suite;
}

Suite *ts_abs() {
  Suite *suite = suite_create("ts_abs");
  TCase *test_case = tcase_create("tc_abs");

  tcase_add_test(test_case, tc_abs_1);
  tcase_add_test(test_case, tc_abs_2);
  tcase_add_test(test_case, tc_abs_3);
  tcase_add_test(test_case, tc_abs_4);
  suite_add_tcase(suite, test_case);

  return suite;
}
Suite *ts_cos() {
  Suite *suite = suite_create("ts_cos");
  TCase *test_case = tcase_create("tc_cos");

  tcase_add_test(test_case, tc_cos);

  suite_add_tcase(suite, test_case);

  return suite;
}

Suite *ts_exp() {
  Suite *suite = suite_create("ts_exp");
  TCase *test_case = tcase_create("tc_exp");

  tcase_add_test(test_case, tc_exp_1);
  tcase_add_test(test_case, tc_exp_2);
  tcase_add_test(test_case, tc_exp_3);
  tcase_add_test(test_case, tc_exp_4);
  tcase_add_test(test_case, tc_exp_5);
  tcase_add_test(test_case, tc_exp_6);
  tcase_add_test(test_case, tc_exp_7);
  tcase_add_test(test_case, tc_exp_8);
  tcase_add_test(test_case, tc_exp_9);
  tcase_add_test(test_case, tc_exp_10);
  suite_add_tcase(suite, test_case);

  return suite;
}
Suite *ts_tan() {
  Suite *suite = suite_create("ts_tan");
  TCase *test_case = tcase_create("tc_tan");

  tcase_add_test(test_case, tc_tan);

  suite_add_tcase(suite, test_case);

  return suite;
}

Suite *ts_fabs() {
  Suite *suite = suite_create("ts_fabs");
  TCase *test_case = tcase_create("tc_fabs");

  tcase_add_test(test_case, tc_fabs);
  suite_add_tcase(suite, test_case);

  return suite;
}

Suite *ts_asin() {
  Suite *suite = suite_create("ts_asin");
  TCase *test_case = tcase_create("tc_asin");

  tcase_add_test(test_case, tc_asin);

  suite_add_tcase(suite, test_case);

  return suite;
}

Suite *ts_floor() {
  Suite *suite = suite_create("ts_floor");
  TCase *test_case = tcase_create("tc_floor");

  tcase_add_test(test_case, tc_floor_1);
  tcase_add_test(test_case, tc_floor_2);
  tcase_add_test(test_case, tc_floor_3);
  tcase_add_test(test_case, tc_floor_4);
  tcase_add_test(test_case, tc_floor_5);
  tcase_add_test(test_case, tc_floor_6);
  suite_add_tcase(suite, test_case);

  return suite;
}
Suite *ts_acos() {
  Suite *suite = suite_create("ts_acos");
  TCase *test_case = tcase_create("tc_acos");

  tcase_add_test(test_case, tc_acos);

  suite_add_tcase(suite, test_case);

  return suite;
}

Suite *ts_pow() {
  Suite *suite = suite_create("ts_pow");
  TCase *test_case = tcase_create("tc_pow");
  tcase_add_test(test_case, tc_pow_1);
  tcase_add_test(test_case, tc_pow_2);
  tcase_add_test(test_case, tc_pow_3);
  tcase_add_test(test_case, tc_pow_4);
  tcase_add_test(test_case, tc_pow_5);
  tcase_add_test(test_case, tc_pow_6);
  tcase_add_test(test_case, tc_pow_7);
  suite_add_tcase(suite, test_case);
  return suite;
}

Suite *ts_fmod() {
  Suite *suite = suite_create("ts_fmod");
  TCase *test_case = tcase_create("tc_fmod");

  tcase_add_test(test_case, tc_fmod);

  suite_add_tcase(suite, test_case);
  return suite;
}

Suite *ts_sqrt() {
  Suite *suite = suite_create("ts_sqrt");
  TCase *test_case = tcase_create("tc_sqrt");
  tcase_add_test(test_case, tc_sqrt_1);
  tcase_add_test(test_case, tc_sqrt_2);
  tcase_add_test(test_case, tc_sqrt_3);
  suite_add_tcase(suite, test_case);
  suite_add_tcase(suite, test_case);

  return suite;
}
Suite *ts_atan() {
  Suite *suite = suite_create("ts_atan");
  TCase *test_case = tcase_create("tc_atan");

  tcase_add_test(test_case, tc_atan);

  suite_add_tcase(suite, test_case);

  return suite;
}

int main(void) {
  Suite *test_suites[] = {ts_ceil(),  ts_abs(),  ts_exp(),  ts_fabs(),
                          ts_floor(), ts_fmod(), ts_log(),  ts_pow(),
                          ts_sqrt(),  ts_sin(),  ts_cos(),  ts_tan(),
                          ts_asin(),  ts_acos(), ts_atan(), NULL};
  int failed = 0;

  for (Suite **s = test_suites; *s != NULL; s++) {
    SRunner *runner = srunner_create(*s);
    srunner_run_all(runner, CK_NORMAL);
    failed += srunner_ntests_failed(runner);
    srunner_free(runner);
  }

  return failed;
}
