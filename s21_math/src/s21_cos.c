#include "s21_math.h"

long double s21_cos(double x) {
  long double result = 0;
  if (S21_ISINF(x) || S21_ISNAN(x))
    result = S21_NAN;
  else {
    x = s21_fmod(x, 2 * S21_M_PI);
    long double tmp = 1;
    unsigned fact = 0;
    while (fact < 50) {
      result += tmp;
      fact += 2;
      tmp *= -(x * x) / ((fact - 1) * fact);
    }
  }
  return result;
}
