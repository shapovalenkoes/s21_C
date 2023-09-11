#include "../s21_math.h"
#include "test_main.h"

START_TEST(atan_test_default) {
  char result[32];
  char assert[32];
  sprintf(result, "%.6Lf", s21_atan(-2));
  sprintf(assert, "%.6f", atan(-2));
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(atan_test_subzero) {
  char result[32];
  char assert[32];
  sprintf(result, "%.6Lf", s21_atan(-1.32432));
  sprintf(assert, "%.6f", atan(-1.32432));
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(atan_test_zero) {
  char result[32];
  char assert[32];
  sprintf(result, "%.6Lf", s21_atan(0));
  sprintf(assert, "%.6f", atan(0));
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(atan_test_bigger_p) {
  char result[32];
  char assert[32];
  sprintf(result, "%.6Lf", s21_atan(1.123456789));
  sprintf(assert, "%.6f", atan(1.123456789));
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(atan_test_small) {
  char result[32];
  char assert[32];
  sprintf(result, "%.6Lf", s21_atan(0.000001));
  sprintf(assert, "%.6f", atan(0.000001));
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(atan_test_NAN) {
  long double s21_res;

  s21_res = s21_atan(S21_NAN);
  ck_assert_ldouble_nan(s21_res);
}
END_TEST

START_TEST(atan_test_INF) {
  char result[32];
  char assert[32];

  sprintf(result, "%.6Lf", s21_atan(S21_INF));
  sprintf(assert, "%.6f", atan(S21_INF));
  ck_assert_str_eq(result, assert);

  sprintf(result, "%.6Lf", s21_atan(-S21_INF));
  sprintf(assert, "%.6f", atan(-S21_INF));
  ck_assert_str_eq(result, assert);
}
END_TEST

Suite *s21_atan_suite(void) {
  Suite *s = suite_create("s21_atan_test");
  TCase *tc_s21_atan = tcase_create("[s21_atan] case");

  tcase_add_test(tc_s21_atan, atan_test_default);
  tcase_add_test(tc_s21_atan, atan_test_bigger_p);
  tcase_add_test(tc_s21_atan, atan_test_small);
  tcase_add_test(tc_s21_atan, atan_test_zero);
  tcase_add_test(tc_s21_atan, atan_test_zero);
  tcase_add_test(tc_s21_atan, atan_test_NAN);
  tcase_add_test(tc_s21_atan, atan_test_INF);
  tcase_add_test(tc_s21_atan, atan_test_subzero);

  suite_add_tcase(s, tc_s21_atan);

  tcase_set_timeout(tc_s21_atan, 100);
  return s;
}
