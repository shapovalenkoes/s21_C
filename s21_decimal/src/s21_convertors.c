#include "s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  init(dst);
  if (src < 0) {
    set_sign(dst, 1);
    src = -src;
  }
  dst->bits[LOW] = src;
  return OK;
}

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int status = CONVERSION_ERROR;
  init(dst);
  if (!isinf(src) && !isnan(src)) {
    if (src != 0) {
      int sign = src < 0;
      float tmp = fabs(src);
      int off = 0;

      for (; off < 8 && (int)tmp / (int)pow(2, 21) == 0; tmp *= 10, off++)
        ;
      tmp = roundf(tmp);
      converter mant = {0};
      for (; fmod(tmp, 10) == 0 && off > 0; off--, tmp /= 10)
        ;
      mant.fl = tmp;
      int exp = ((*(int *)&tmp & ~0x80000000) >> 23) - 127;
      dst->bits[exp / 32] |= 1u << exp % 32;

      for (int i = exp - 1, j = 22; j >= 0; i--, j--) {
        if ((mant.ui & (1u << j))) dst->bits[i / 32] |= 1u << i % 32;
      }
      set_sign(dst, sign);
      set_exp(dst, off);
    }
    status = OK;
  }
  return status;
}

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int status = OK;

  s21_decimal trunc;
  s21_truncate(src, &trunc);

  if ((get_exp(&trunc) > MAX_EXP) || trunc.bits[HIGH] || trunc.bits[MID] ||
      (trunc.bits[LOW] > INT32_MAX))
    status = CONVERSION_ERROR;
  else {
    *dst = trunc.bits[LOW];
    if (get_sign(&trunc)) *dst = -*dst;
  }
  return status;
}

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  *dst = 0;
  for (int i = 0; i < 96; i++) {
    if (get_bit(&src, i)) *dst += pow(2, i);
  }
  *dst = *dst * pow(10, -get_exp(&src));
  if (get_sign(&src)) *dst = -*dst;
  return OK;
}
