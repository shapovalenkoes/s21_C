#include "s21_math.h"

long double s21_asin(double x) {
  long double result = s21_atan(x / s21_sqrt(1 - x * x));
  if (S21_ISNAN(result)) result = S21_NAN;
  return result;
}
