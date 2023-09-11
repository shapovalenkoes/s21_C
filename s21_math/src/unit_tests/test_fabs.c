#include "../s21_math.h"
#include "test_main.h"

START_TEST(fabs_positive) {
  ck_assert_float_eq(s21_fabs(123.0323), fabs(123.0323));
}
END_TEST

START_TEST(fabs_negative) {
  ck_assert_float_eq(s21_fabs(-123.0323), fabs(-123.0323));
}
END_TEST

Suite *s21_fabs_suite(void) {
  Suite *s = suite_create("s21_fabs_test");
  TCase *tc_s21_fabs = tcase_create("[s21_fabs] case");

  tcase_add_test(tc_s21_fabs, fabs_positive);
  tcase_add_test(tc_s21_fabs, fabs_negative);

  suite_add_tcase(s, tc_s21_fabs);

  tcase_set_timeout(tc_s21_fabs, 100);
  return s;
}
