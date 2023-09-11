#include "s21_math.h"

long double s21_ceil(double number) {
  long double compare = 0;
  long double number_ld = (long double)number;
  if (number < 0) {
    compare = -1 * s21_floor(-number);
  } else {
    compare = s21_floor(number);
    compare += (compare == number_ld ? 0.0 : 1.0);
  }
  return compare;
}
