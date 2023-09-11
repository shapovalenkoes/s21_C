#include "../s21_math.h"
#include "test_main.h"

START_TEST(test_12) {
  long double my_val = s21_ceil(0.0);
  long double test_val = ceil(0.0);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_13) {
  long double my_val = s21_ceil(-0.0);
  long double test_val = ceil(-0.0);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_14) {
  long double my_val = s21_ceil(-1.2);
  long double test_val = ceil(-1.2);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_15) {
  long double my_val = s21_ceil(1.2);
  long double test_val = ceil(1.2);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_16) {
  long double my_val = s21_ceil(-21.0);
  long double test_val = ceil(-21.0);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_17) {
  long double my_val = s21_ceil(21.0);
  long double test_val = ceil(21.0);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_18) {
  long double my_val = s21_ceil(-0.01);
  long double test_val = ceil(-0.01);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_19) {
  long double my_val = s21_ceil(0.01);
  long double test_val = ceil(0.01);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_20) {
  long double my_val = s21_ceil(21.9);
  long double test_val = ceil(21.9);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_21) {
  long double my_val = s21_ceil(-21.9);
  long double test_val = ceil(-21.9);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_22) {
  long double my_val = s21_ceil(1.79769313486231570e+308);
  long double test_val = ceil(1.79769313486231570e+308);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_23) {
  long double my_val = s21_ceil(2.2250738585072014E-308);
  long double test_val = ceil(2.2250738585072014E-308);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

Suite *s21_ceil_suite(void) {
  Suite *s = suite_create("s21_ceil_test");
  TCase *tc = tcase_create("[s21_ceil] case");

  tcase_add_test(tc, test_12);
  tcase_add_test(tc, test_13);
  tcase_add_test(tc, test_14);
  tcase_add_test(tc, test_15);
  tcase_add_test(tc, test_16);
  tcase_add_test(tc, test_17);
  tcase_add_test(tc, test_18);
  tcase_add_test(tc, test_19);
  tcase_add_test(tc, test_20);
  tcase_add_test(tc, test_21);
  tcase_add_test(tc, test_22);
  tcase_add_test(tc, test_23);
  suite_add_tcase(s, tc);

  tcase_set_timeout(tc, 100);
  return s;
}