#include "../s21_math.h"
#include "test_main.h"

START_TEST(acos_test_default) {
  char result[32];
  char assert[32];
  sprintf(result, "%.6Lf", s21_acos(0.5));
  sprintf(assert, "%.6f", acos(0.5));
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(acos_test_subzero) {
  char result[32];
  char assert[32];
  sprintf(result, "%.6Lf", s21_acos(-0.3456));
  sprintf(assert, "%.6f", acos(-0.3456));
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(acos_test_zero) {
  char result[32];
  char assert[32];
  sprintf(result, "%.6Lf", s21_acos(0));
  sprintf(assert, "%.6f", acos(0));
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(acos_test_big) {
  char result[32];
  char assert[32];
  sprintf(result, "%.6Lf", s21_acos(1234.5678));
  sprintf(assert, "%.6f", acos(1234.5678));
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(acos_test_small) {
  char result[32];
  char assert[32];
  sprintf(result, "%.6Lf", s21_acos(0.000001));
  sprintf(assert, "%.6f", acos(0.000001));
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(acos_test_NAN) {
  long double s21_res;

  s21_res = s21_acos(S21_NAN);
  ck_assert_ldouble_nan(s21_res);

  s21_res = s21_acos(S21_INF);
  ck_assert_ldouble_nan(s21_res);

  s21_res = s21_acos(S21_MIN_INF);
  ck_assert_ldouble_nan(s21_res);
}
END_TEST

Suite *s21_acos_suite(void) {
  Suite *s = suite_create("s21_acos_test");
  TCase *tc_s21_acos = tcase_create("[s21_acos] case");

  tcase_add_test(tc_s21_acos, acos_test_default);
  tcase_add_test(tc_s21_acos, acos_test_big);
  tcase_add_test(tc_s21_acos, acos_test_small);
  tcase_add_test(tc_s21_acos, acos_test_zero);
  tcase_add_test(tc_s21_acos, acos_test_zero);
  tcase_add_test(tc_s21_acos, acos_test_NAN);
  tcase_add_test(tc_s21_acos, acos_test_subzero);

  suite_add_tcase(s, tc_s21_acos);

  tcase_set_timeout(tc_s21_acos, 100);
  return s;
}
