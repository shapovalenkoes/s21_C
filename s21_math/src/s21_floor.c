#include "s21_math.h"

int s21_get_exponent(double number);

long double s21_floor(double number) {
  long double return_num = 0;
  int exponent = s21_get_exponent(number);
  if (exponent <= SIGNIFICANT_LEN) {
    if (number < 0) {
      return_num = -1 * s21_ceil(-number);
    } else if (exponent >= 0) {
      union {
        double f;
        unsigned long i;
      } floor_number = {number};
      unsigned long number_int = ~0;
      number_int <<= (SIGNIFICANT_LEN - exponent);
      floor_number.i &= number_int;
      return_num = (long double)floor_number.f;
    }
  } else {
    return_num = (long double)number;
  }
  return return_num;
}

int s21_get_exponent(double number) {
  union {
    double f;
    unsigned long i;
  } unum = {0};
  unum.f = number;
  int exponent = unum.i >> SIGNIFICANT_LEN & BITS_1x11;
  return exponent - BIAS;
}
