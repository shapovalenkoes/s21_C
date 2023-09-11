#include "../s21_math.h"
#include "test_main.h"

START_TEST(sqrt_positive) {
  ck_assert_ldouble_eq_tol(s21_sqrt(123.9546), sqrt(123.9546), 1e-7);
}
END_TEST

START_TEST(sqrt_negative) { ck_assert_double_nan(s21_sqrt(-123)); }
END_TEST

START_TEST(sqrt_inf) { ck_assert_float_infinite(s21_sqrt(S21_INF)); }
END_TEST

START_TEST(sqrt_zero) { ck_assert_ldouble_eq(s21_sqrt(0), 0.0); }
END_TEST

Suite *s21_sqrt_suite(void) {
  Suite *s = suite_create("s21_sqrt_test");
  TCase *tc_s21_sqrt = tcase_create("[s21_sqrt] case");

  tcase_add_test(tc_s21_sqrt, sqrt_positive);
  tcase_add_test(tc_s21_sqrt, sqrt_negative);
  tcase_add_test(tc_s21_sqrt, sqrt_inf);
  tcase_add_test(tc_s21_sqrt, sqrt_zero);

  suite_add_tcase(s, tc_s21_sqrt);

  tcase_set_timeout(tc_s21_sqrt, 100);
  return s;
}
