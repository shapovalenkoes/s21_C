#include "s21_math.h"

long double s21_sqrt(double x) {
  long double res = 1.0;
  if (0 > x || S21_ISNAN(x)) {
    res = S21_NAN;
  } else if (1.0 == x) {
    res = 1.0;
  } else if (0.0 == x) {
    res = 0;
  } else if (S21_INF == x) {
    res = S21_INF;
  } else {
    while (1) {
      double tmp = (res + x / res) / 2;
      if (s21_fabs(res - tmp) < S21_EPS) break;
      res = tmp;
    }
  }
  return res;
}