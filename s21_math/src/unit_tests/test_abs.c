#include "../s21_math.h"
#include "test_main.h"

START_TEST(abs_positive) { ck_assert_int_eq(s21_abs(123), abs(123)); }
END_TEST

START_TEST(abs_negative) { ck_assert_int_eq(s21_abs(-123), abs(-123)); }
END_TEST

Suite *s21_abs_suite(void) {
  Suite *s = suite_create("s21_abs_test");
  TCase *tc_s21_abs = tcase_create("[s21_abs] case");

  tcase_add_test(tc_s21_abs, abs_positive);
  tcase_add_test(tc_s21_abs, abs_negative);

  suite_add_tcase(s, tc_s21_abs);

  tcase_set_timeout(tc_s21_abs, 100);
  return s;
}
