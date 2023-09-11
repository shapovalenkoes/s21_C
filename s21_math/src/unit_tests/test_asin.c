#include "../s21_math.h"
#include "test_main.h"

START_TEST(asin_test_default) {
  char result[32];
  char assert[32];
  sprintf(result, "%.6Lf", s21_asin(0.5));
  sprintf(assert, "%.6f", asin(0.5));
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(asin_test_subzero) {
  char result[32];
  char assert[32];
  sprintf(result, "%.6Lf", s21_asin(-0.3456));
  sprintf(assert, "%.6f", asin(-0.3456));
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(asin_test_zero) {
  char result[32];
  char assert[32];
  sprintf(result, "%.6Lf", s21_asin(0));
  sprintf(assert, "%.6f", asin(0));
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(asin_test_big) {
  char result[32];
  char assert[32];
  sprintf(result, "%.6Lf", s21_asin(1234.5678));
  sprintf(assert, "%.6f", asin(1234.5678));
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(asin_test_small) {
  char result[32];
  char assert[32];
  sprintf(result, "%.6Lf", s21_asin(0.000001));
  sprintf(assert, "%.6f", asin(0.000001));
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(asin_test_NAN) {
  long double s21_res = 0;

  s21_res = s21_asin(S21_NAN);
  ck_assert_ldouble_nan(s21_res);

  s21_res = s21_asin(S21_INF);
  ck_assert_ldouble_nan(s21_res);

  s21_res = s21_asin(S21_MIN_INF);
  ck_assert_ldouble_nan(s21_res);
}
END_TEST

Suite *s21_asin_suite(void) {
  Suite *s = suite_create("s21_asin_test");
  TCase *tc_s21_asin = tcase_create("[s21_asin] case");

  tcase_add_test(tc_s21_asin, asin_test_default);
  tcase_add_test(tc_s21_asin, asin_test_big);
  tcase_add_test(tc_s21_asin, asin_test_small);
  tcase_add_test(tc_s21_asin, asin_test_zero);
  tcase_add_test(tc_s21_asin, asin_test_zero);
  tcase_add_test(tc_s21_asin, asin_test_NAN);
  tcase_add_test(tc_s21_asin, asin_test_subzero);

  suite_add_tcase(s, tc_s21_asin);

  tcase_set_timeout(tc_s21_asin, 100);
  return s;
}
