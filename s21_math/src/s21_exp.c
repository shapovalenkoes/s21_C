#include "s21_math.h"

int check_exp(double x, long double *res);
int check_exp(double x, long double *res) {
  int flag = 0;
  if (x == S21_INF || x == S21_NAN) {
    *res = x;
  } else if (x == S21_MIN_INF) {
    *res = 0.0;
  } else if (x == 0.0) {
    *res = 1.0;
  } else
    flag = 1;
  return flag;
}

long double s21_exp(double x) {
  long double res = 1.0;
  if (check_exp(x, &res)) {
    long double i = 1.0, add = 1.0;
    for (; s21_fabs(add) > S21_EPS; i++) {
      add *= x / i;
      res += add;
      if (res > S21_LDBL_MAX) {
        res = S21_INF;
        break;
      }
    }
  }
  return res;
}
