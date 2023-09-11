#include "../s21_math.h"
#include "test_main.h"

START_TEST(cos_test_default) {
  char result[32];
  char assert[32];
  sprintf(result, "%.6Lf", s21_cos(1.5708));
  sprintf(assert, "%.6f", cos(1.5708));
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(cos_test_subzero) {
  char result[32];
  char assert[32];
  sprintf(result, "%.6Lf", s21_cos(-1.5708));
  sprintf(assert, "%.6f", cos(-1.5708));
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(cos_test_zero) {
  char result[32];
  char assert[32];
  sprintf(result, "%.6Lf", s21_cos(0));
  sprintf(assert, "%.6f", cos(0));
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(cos_test_bigger_p) {
  char result[32];
  char assert[32];
  sprintf(result, "%.6Lf", s21_cos(4.));
  sprintf(assert, "%.6f", cos(4));
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(cos_test_small) {
  char result[32];
  char assert[32];
  sprintf(result, "%.6Lf", s21_cos(0.000001));
  sprintf(assert, "%.6f", cos(0.000001));
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(cos_test_NAN) {
  long double s21_res = 0;

  s21_res = s21_cos(S21_NAN);
  ck_assert_ldouble_nan(s21_res);

  s21_res = s21_cos(S21_INF);
  ck_assert_ldouble_nan(s21_res);

  s21_res = s21_cos(S21_MIN_INF);
  ck_assert_ldouble_nan(s21_res);
}
END_TEST

Suite *s21_cos_suite(void) {
  Suite *s = suite_create("s21_cos_test");
  TCase *tc_s21_cos = tcase_create("[s21_cos] case");

  tcase_add_test(tc_s21_cos, cos_test_default);
  tcase_add_test(tc_s21_cos, cos_test_bigger_p);
  tcase_add_test(tc_s21_cos, cos_test_small);
  tcase_add_test(tc_s21_cos, cos_test_zero);
  tcase_add_test(tc_s21_cos, cos_test_subzero);
  tcase_add_test(tc_s21_cos, cos_test_NAN);

  suite_add_tcase(s, tc_s21_cos);

  tcase_set_timeout(tc_s21_cos, 100);
  return s;
}
