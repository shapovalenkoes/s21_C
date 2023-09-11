#include "../s21_math.h"
#include "test_main.h"

START_TEST(sin_test_default) {
  char result[32];
  char assert[32];
  for (double i = -1.; i <= 1.; i += 0.1) {
    sprintf(result, "%.6Lf", s21_sin(i));
    sprintf(assert, "%.6f", sin(i));
    ck_assert_str_eq(result, assert);
  }
}
END_TEST

START_TEST(sin_test_zero) {
  ck_assert_double_eq_tol((double)s21_sin(0), sin(0), 1e-7);
  for (long double i = -S21_M_PI; i < 2 * S21_M_PI; i += 0.010456011) {
    ck_assert_double_eq_tol((double)s21_sin(i), sin(i), 1e-7);
  }
}
END_TEST

START_TEST(sin_test_subzero) {
  char result[32];
  char assert[32];
  for (double i = -10.; i <= -1.; i += 0.1) {
    sprintf(result, "%.6Lf", s21_sin(i));
    sprintf(assert, "%.6f", sin(i));
    ck_assert_str_eq(result, assert);
  }
}
END_TEST

START_TEST(sin_test_bigger_p) {
  char result[32];
  char assert[32];
  for (double i = 4.; i <= 100.; i += 1.) {
    sprintf(result, "%.6Lf", s21_sin(i));
    sprintf(assert, "%.6f", sin(i));
    ck_assert_str_eq(result, assert);
  }
}
END_TEST

START_TEST(sin_test_small) {
  char result[32];
  char assert[32];
  for (double i = 1.; i > S21_EPS; i /= 2.) {
    sprintf(result, "%.6Lf", s21_sin(i));
    sprintf(assert, "%.6f", sin(i));
    ck_assert_str_eq(result, assert);
  }
}
END_TEST

START_TEST(sin_test_INF) {
  char result[32];
  char assert[32];
  sprintf(result, "%.6Lf", s21_sin(S21_INF));
  sprintf(assert, "%.6f", sin(S21_INF));
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(sin_test_NAN) {
  long double s21_res;

  s21_res = s21_sin(S21_NAN);
  ck_assert_ldouble_nan(s21_res);

  s21_res = s21_sin(S21_INF);
  ck_assert_ldouble_nan(s21_res);

  s21_res = s21_sin(S21_MIN_INF);
  ck_assert_ldouble_nan(s21_res);
}
END_TEST

Suite *s21_sin_suite(void) {
  Suite *s = suite_create("s21_sin_test");
  TCase *tc_s21_sin = tcase_create("[s21_sin] case");

  tcase_add_test(tc_s21_sin, sin_test_default);
  tcase_add_test(tc_s21_sin, sin_test_bigger_p);
  tcase_add_test(tc_s21_sin, sin_test_small);
  tcase_add_test(tc_s21_sin, sin_test_zero);
  tcase_add_test(tc_s21_sin, sin_test_subzero);
  tcase_add_test(tc_s21_sin, sin_test_INF);
  tcase_add_test(tc_s21_sin, sin_test_NAN);
  suite_add_tcase(s, tc_s21_sin);

  tcase_set_timeout(tc_s21_sin, 100);
  return s;
}
