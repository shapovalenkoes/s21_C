#include <stdio.h>

#include "s21_math.h"

long double s21_fmod(double x, double y) {
  long double fmod_value = 0;
  union {
    double f;
    unsigned long i;
  } union_x = {x}, union_y = {y};
  if (y == 0.0) {  // Incorrect case.
    fmod_value = 0.0 / (0.0 * (-1));
  } else if ((union_x.i << 1) < (union_y.i << 1)) {  // x < y case.
    fmod_value = (long double)union_x.f;
  } else if ((union_x.i << 1) == (union_y.i << 1)) {  // x == y case.
    fmod_value = (long double)union_x.f * 0;
  } else {  // Common case.
    unsigned long ones_mask = 0;
    ones_mask = ~ones_mask;
    // Determine sign.
    unsigned long sign =
        (union_x.i) & (ones_mask << (EXP_LEN + SIGNIFICANT_LEN));
    // Determine exponents.
    int exponent_x = union_x.i >> SIGNIFICANT_LEN & BITS_1x11;
    int exponent_y = union_y.i >> SIGNIFICANT_LEN & BITS_1x11;
    // Determine significant parts.
    unsigned long significant_x =
        union_x.i & (ones_mask >> (SIGN_LEN + EXP_LEN));
    unsigned long significant_y =
        union_y.i & (ones_mask >> (SIGN_LEN + EXP_LEN));
    // Normalise significant parts.
    significant_x |= (1ULL << SIGNIFICANT_LEN);
    significant_y |= (1ULL << SIGNIFICANT_LEN);
    // Substract (x - y).
    int substract_flag = S21_TRUE;
    for (unsigned long dif = 0; substract_flag && exponent_x > exponent_y;
         exponent_x--) {
      dif = significant_x - significant_y;
      if (dif == 0) {  // Division without remainder.
        substract_flag = S21_FALSE;
        fmod_value = 0 * x;
      } else if (dif >> (EXP_LEN + SIGNIFICANT_LEN) == 0) {
        significant_x = dif;
      }
      significant_x <<= 1;
    }
    unsigned long dif = significant_x - significant_y;
    if (dif == 0) {  // Division without remainder.
      substract_flag = S21_FALSE;
      fmod_value = 0 * x;
    } else if (dif >> (EXP_LEN + SIGNIFICANT_LEN) == 0) {
      significant_x = dif;
    }
    if (substract_flag) {
      // Update exponent. 53-th bit shoud be one.
      for (; (significant_x >> SIGNIFICANT_LEN) == 0;) {
        significant_x <<= 1;
        exponent_x--;
      }
      // Scale result.
      if (exponent_x > 0) {
        significant_x -= 1ULL << SIGNIFICANT_LEN;
        significant_x |= (unsigned long)(exponent_x) << SIGNIFICANT_LEN;
      } else {
        significant_x >>= -exponent_x + 1;
      }
      significant_x |= sign;
      union {
        double f;
        unsigned long i;
      } result = {0};
      result.i = significant_x;
      fmod_value = (long double)result.f;
    }
  }
  return fmod_value;
}
