#include "s21_math.h"

int check_log(long double *x);

int check_log(long double *x) {
  int flag = 0;
  if (S21_ISNAN(*x)) {
    *x = S21_NAN;
  } else if (*x < 0) {
    *x = -S21_NAN;
  } else if (*x == 0) {
    *x = S21_MIN_INF;
  } else if (*x == 1) {
    *x = 0.0;
  } else if (*x == S21_M_E) {
    *x = 1.0;
  } else if (S21_ISINF(*x)) {
    *x = S21_INF;
  } else
    flag = 1;
  return flag;
}

long double s21_log(double x) {
  long double res = x;
  if (check_log(&res)) {
    res = 0;
    long double compare = 0, error_margin = 0;
    int negative = x > 0 && x < 1;
    if (negative) x = 1.0 / x;
    error_margin = 2 * (x - s21_exp(compare)) / (x + s21_exp(compare));
    while (error_margin >= S21_EPS) {
      compare = res;
      error_margin = 2 * (x - s21_exp(compare)) / (x + s21_exp(compare));
      res = compare + error_margin;
    }
    if (negative) res *= -1;
  }
  return res;
}