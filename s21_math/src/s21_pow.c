#include "s21_math.h"

long double s21_pow(double base, double exps) {
  long double res = 0;
  if (S21_ISNAN(exps)) {
    res = S21_NAN;
  } else if ((base == -1) && (exps == -S21_INF)) {
    res = 1;
  } else if (exps == 0) {
    res = 1;
  } else {
    if (base == 0) {
      if (exps < 0)
        res = S21_INF;
      else
        res = 0;
    } else {
      if (base < 0) {
        res = s21_exp(exps * s21_log(-base));
        if (s21_fmod(exps, 2) != 0) {
          res = res * -1;
        }
      } else {
        res = s21_exp(exps * s21_log(base));
      }
    }
  }
  return res;
}