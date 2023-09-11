#include "../s21_math.h"
#include "test_main.h"

#define BUFF_SIZE 512

START_TEST(test_0) {
  long double my_val = s21_floor(0.0);
  long double test_val = floor(0.0);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_1) {
  long double my_val = s21_floor(-0.0);
  long double test_val = floor(-0.0);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_2) {
  long double my_val = s21_floor(-1.2);
  long double test_val = floor(-1.2);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_3) {
  long double my_val = s21_floor(1.2);
  long double test_val = floor(1.2);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_4) {
  long double my_val = s21_floor(-21.0);
  long double test_val = floor(-21.0);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_5) {
  long double my_val = s21_floor(21.0);
  long double test_val = floor(21.0);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_6) {
  long double my_val = s21_floor(-0.01);
  long double test_val = floor(-0.01);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_7) {
  long double my_val = s21_floor(0.01);
  long double test_val = floor(0.01);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_8) {
  long double my_val = s21_floor(21.9);
  long double test_val = floor(21.9);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_9) {
  long double my_val = s21_floor(-21.9);
  long double test_val = floor(-21.9);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_10) {
  long double my_val = s21_floor(1.79769313486231570e+308);
  long double test_val = floor(1.79769313486231570e+308);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_11) {
  long double my_val = s21_floor(2.2250738585072014E-308);
  long double test_val = floor(2.2250738585072014E-308);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

Suite *s21_floor_suite(void) {
  Suite *s = suite_create("s21_floor_test");
  TCase *tc = tcase_create("[s21_floor] case");
  tcase_add_test(tc, test_0);
  tcase_add_test(tc, test_1);
  tcase_add_test(tc, test_2);
  tcase_add_test(tc, test_3);
  tcase_add_test(tc, test_4);
  tcase_add_test(tc, test_5);
  tcase_add_test(tc, test_6);
  tcase_add_test(tc, test_7);
  tcase_add_test(tc, test_8);
  tcase_add_test(tc, test_9);
  tcase_add_test(tc, test_10);
  tcase_add_test(tc, test_11);
  suite_add_tcase(s, tc);

  tcase_set_timeout(tc, 100);

  return s;
}
