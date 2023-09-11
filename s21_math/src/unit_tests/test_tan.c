#include "../s21_math.h"
#include "test_main.h"

START_TEST(tan_test_default) {
  char result[32];
  char assert[32];
  sprintf(result, "%.6Lf", s21_tan(1.57));
  sprintf(assert, "%.6f", tan(1.57));
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(tan_test_bigger_p) {
  char result[32];
  char assert[32];
  sprintf(result, "%.6Lf", s21_tan(4));
  sprintf(assert, "%.6f", tan(4));
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(tan_test_NAN) {
  char result[32];
  char assert[32];
  sprintf(result, "%.6Lf", s21_tan(S21_NAN));
  sprintf(assert, "%.6f", tan(S21_NAN));
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(tan_test_INF) {
  char result[32];
  char assert[32];
  sprintf(result, "%.6Lf", s21_tan(S21_INF));
  sprintf(assert, "%.6f", tan(S21_INF));
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(tan_test_small) {
  char result[32];
  char assert[32];
  sprintf(result, "%.6Lf", s21_tan(0.000001));
  sprintf(assert, "%.6f", tan(0.000001));
  ck_assert_str_eq(result, assert);
}
END_TEST

Suite *s21_tan_suite(void) {
  Suite *s = suite_create("s21_tan_test");
  TCase *tc_s21_tan = tcase_create("[s21_tan] case");

  tcase_add_test(tc_s21_tan, tan_test_default);
  tcase_add_test(tc_s21_tan, tan_test_bigger_p);
  tcase_add_test(tc_s21_tan, tan_test_NAN);
  tcase_add_test(tc_s21_tan, tan_test_INF);
  tcase_add_test(tc_s21_tan, tan_test_small);

  suite_add_tcase(s, tc_s21_tan);

  tcase_set_timeout(tc_s21_tan, 100);
  return s;
}
