#include "test_main.h"

START_TEST(test_0) {
  double result = 0;
  double ans = 10;

  char str[255] = "5 +  5";
  char valid_str[MAX_SIZE] = "";
  validator(str, valid_str);
  Queue tokens = get_all_tokens(valid_str);
  Queue rpn = to_RPN(&tokens);
  calculate(rpn, &result, 0);

  ck_assert_double_eq_tol(result, ans, 1e-6);
}
END_TEST

START_TEST(test_1) {
  double result = 0;
  double ans = 162;

  char str[255] = "4*5*2*2*2+2";
  char valid_str[MAX_SIZE] = "";
  validator(str, valid_str);
  Queue tokens = get_all_tokens(valid_str);
  Queue rpn = to_RPN(&tokens);
  calculate(rpn, &result, 0);

  ck_assert_double_eq_tol(result, ans, 1e-6);
}
END_TEST

START_TEST(test_2) {
  double result = 0;
  double ans = 20;

  char str[255] = "150/10+5*2/2";
  char valid_str[MAX_SIZE] = "";
  validator(str, valid_str);
  Queue tokens = get_all_tokens(valid_str);
  Queue rpn = to_RPN(&tokens);
  calculate(rpn, &result, 0);

  ck_assert_double_eq_tol(result, ans, 1e-6);
}
END_TEST

START_TEST(test_3) {
  double result = 0;
  double ans = 9;

  char str[255] = "5+5-2*3/6";
  char valid_str[MAX_SIZE] = "";
  validator(str, valid_str);
  Queue tokens = get_all_tokens(valid_str);
  Queue rpn = to_RPN(&tokens);
  calculate(rpn, &result, 0);

  ck_assert_double_eq_tol(result, ans, 1e-6);
}
END_TEST

START_TEST(test_4) {
  double result = 0;
  double ans = 50;

  char str[255] = "x+x";
  char valid_str[MAX_SIZE] = "";
  validator(str, valid_str);
  Queue tokens = get_all_tokens(valid_str);
  Queue rpn = to_RPN(&tokens);
  calculate(rpn, &result, 25);

  ck_assert_double_eq_tol(result, ans, 1e-6);
}
END_TEST

START_TEST(test_5) {
  double result = 0;
  double ans = 0.362358;

  char str[255] = "cos(10mod2.2)";
  char valid_str[MAX_SIZE] = "";
  validator(str, valid_str);
  Queue tokens = get_all_tokens(valid_str);
  Queue rpn = to_RPN(&tokens);
  calculate(rpn, &result, 0);

  ck_assert_double_eq_tol(result, ans, 1e-6);
}
END_TEST

START_TEST(test_6) {
  double result = 0;
  double ans = 1.517427;

  char str[255] = "sqrt(ln(10))";
  char valid_str[MAX_SIZE] = "";
  validator(str, valid_str);
  Queue tokens = get_all_tokens(valid_str);
  Queue rpn = to_RPN(&tokens);
  calculate(rpn, &result, 0);

  ck_assert_double_eq_tol(result, ans, 1e-6);
}
END_TEST

START_TEST(test_7) {
  double result = 0;
  double ans = 0.927107;

  char str[255] = "atan(10)+sin(10)";
  char valid_str[MAX_SIZE] = "";
  validator(str, valid_str);
  Queue tokens = get_all_tokens(valid_str);
  Queue rpn = to_RPN(&tokens);
  calculate(rpn, &result, 0);

  ck_assert_double_eq_tol(result, ans, 1e-6);
}
END_TEST

START_TEST(test_8) {
  double result = 0;
  double ans = 1.570796;

  char str[255] = "asin(1)";
  char valid_str[MAX_SIZE] = "";
  validator(str, valid_str);
  Queue tokens = get_all_tokens(valid_str);
  Queue rpn = to_RPN(&tokens);
  calculate(rpn, &result, 0);

  ck_assert_double_eq_tol(result, ans, 1e-6);
}
END_TEST

START_TEST(test_9) {
  double result = 0;
  double ans = 210;

  char str[255] = "10-20*(-10)";
  char valid_str[MAX_SIZE] = "";
  validator(str, valid_str);
  Queue tokens = get_all_tokens(valid_str);
  Queue rpn = to_RPN(&tokens);
  calculate(rpn, &result, 0);

  ck_assert_double_eq_tol(result, ans, 1e-6);
}
END_TEST

START_TEST(test_10) {
  double result = 0;
  double ans = -132.377067;

  char str[255] =
      "1-sin(1)-sin(1)+sin(1)-cos(1)+tan(1)-(cos(1)-cos(1))-sqrt(1)-2^2/"
      "(4+1-1*23*5/4/6)/((cos(1)+cos(2))/(1+2+3))/7";
  char valid_str[MAX_SIZE] = "";
  validator(str, valid_str);
  Queue tokens = get_all_tokens(valid_str);
  Queue rpn = to_RPN(&tokens);
  calculate(rpn, &result, 0);

  ck_assert_double_eq_tol(result, ans, 1e-6);
}
END_TEST

START_TEST(test_11) {
  double result = 0;
  double ans = 20.998589;

  char str[255] = "ln(35)*5-log(6)+sqrt(16)";
  char valid_str[MAX_SIZE] = "";
  validator(str, valid_str);
  Queue tokens = get_all_tokens(valid_str);
  Queue rpn = to_RPN(&tokens);
  calculate(rpn, &result, 0);

  ck_assert_double_eq_tol(result, ans, 1e-6);
}
END_TEST

START_TEST(test_12) {
  double result = 0;
  double ans = 2.356194;

  char str[255] = "acos(10mod3)+asin(1)+atan(1)";
  char valid_str[MAX_SIZE] = "";
  validator(str, valid_str);
  Queue tokens = get_all_tokens(valid_str);
  Queue rpn = to_RPN(&tokens);
  calculate(rpn, &result, 0);

  ck_assert_double_eq_tol(result, ans, 1e-6);
}
END_TEST

START_TEST(test_13) {
  double result = ZERO_DIVISION;

  char str[255] = "2/0";
  char valid_str[MAX_SIZE] = "";
  validator(str, valid_str);
  Queue tokens = get_all_tokens(valid_str);
  Queue rpn = to_RPN(&tokens);
  int status = calculate(rpn, &result, 0);

  ck_assert_int_eq(result, status);
}
END_TEST

START_TEST(test_15) {
  double result = ZERO_DIVISION;

  char str[255] = "2mod0";
  char valid_str[MAX_SIZE] = "";
  validator(str, valid_str);
  Queue tokens = get_all_tokens(valid_str);
  Queue rpn = to_RPN(&tokens);
  int status = calculate(rpn, &result, 0);

  ck_assert_int_eq(result, status);
}
END_TEST

START_TEST(test_14) {
  double result = INCORRECT;
  char str[255] = ")+ 9 *(435)";
  char valid_str[MAX_SIZE] = "";
  int status = validator(str, valid_str);

  ck_assert_int_eq(result, status);
}
END_TEST
Suite* calc_suite(void) {
  Suite* suite = suite_create("calc_test");
  TCase* calc_tcase = tcase_create("calc_tcase");

  tcase_add_test(calc_tcase, test_0);
  tcase_add_test(calc_tcase, test_1);
  tcase_add_test(calc_tcase, test_2);
  tcase_add_test(calc_tcase, test_3);
  tcase_add_test(calc_tcase, test_4);
  tcase_add_test(calc_tcase, test_5);
  tcase_add_test(calc_tcase, test_6);
  tcase_add_test(calc_tcase, test_7);
  tcase_add_test(calc_tcase, test_8);
  tcase_add_test(calc_tcase, test_9);
  tcase_add_test(calc_tcase, test_10);
  tcase_add_test(calc_tcase, test_11);
  tcase_add_test(calc_tcase, test_12);
  tcase_add_test(calc_tcase, test_13);
  tcase_add_test(calc_tcase, test_14);
  tcase_add_test(calc_tcase, test_15);
  suite_add_tcase(suite, calc_tcase);

  return suite;
}
