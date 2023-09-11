#include <math.h>
#include <stdio.h>

#include "s21_decimal.h"

void init(s21_decimal *dec) {
  dec->bits[LOW] = 0;
  dec->bits[MID] = 0;
  dec->bits[HIGH] = 0;
  dec->bits[SCALE] = 0;
}

int get_bit(s21_decimal *dec, int index) {
  return (dec->bits[index / 32] >> (index % 32)) & 1u;
}

int get_bit_int(int num, int index) { return (num >> index) & 1; }

void set_bit(s21_decimal *dec, int index, int bit) {
  int mask = 1u << (index % 32);
  if (bit)
    dec->bits[index / 32] |= mask;
  else
    dec->bits[index / 32] &= ~mask;
}

void inverse_bit(s21_decimal *dec, int index) {
  int mask = 1u << (index % 32);
  dec->bits[index / 32] ^= mask;
}

int get_sign(s21_decimal *dec) { return (dec->bits[SCALE] & SIGN) >> 31; }

int get_exp(s21_decimal *dec) { return (dec->bits[SCALE] & EXP) >> 16; }

void set_sign(s21_decimal *dec, int sign) { set_bit(dec, 127, sign); }

void set_exp(s21_decimal *dec, int exp) {
  for (int i = 112, j = 0; i < 120; i++, j++) {
    set_bit(dec, i, get_bit_int(exp, j));
  }
}

// void print_bits(s21_decimal *dec) {
//   printf("sign: %d\n", get_sign(dec));
//   printf("exp: %d\n", get_exp(dec));
//   printf("exp_bits:    ");
//   for (int i = 119; i >= 112; i--) {
//     printf("%d", get_bit(dec, i));
//   }
//   printf("\n");
//   printf("bits[LOW]:   ");
//   for (int i = 31; i >= 0; i--) {
//     printf("%d", get_bit(dec, i));
//   }
//   printf("\n");
//   printf("bits[MID]:   ");
//   for (int i = 63; i >= 32; i--) {
//     printf("%d", get_bit(dec, i));
//   }
//   printf("\n");
//   printf("bits[HIGH]:  ");
//   for (int i = 95; i >= 64; i--) {
//     printf("%d", get_bit(dec, i));
//   }
//   printf("\n");
//   printf("bits[SCALE]: ");
//   for (int i = 127; i >= 96; i--) {
//     printf("%d", get_bit(dec, i));
//   }
//   printf("\n");
//   printf("\n");
// }

int is_zero(s21_decimal dec) {
  return (dec.bits[LOW] == 0 && dec.bits[MID] == 0 && dec.bits[HIGH] == 0);
}

s21_buffer to_buffer(s21_decimal src) {
  s21_buffer dst = {0};
  for (int i = 0; i < 3; i++) dst.bits[i] = src.bits[i] & UINT32_MAX;
  dst.exp = get_exp(&src);
  dst.sign = get_sign(&src);
  return dst;
}

s21_decimal to_decimal(s21_buffer src) {
  s21_decimal dst = {0};
  for (int i = 0; i < 3; i++) dst.bits[i] = src.bits[i] & UINT32_MAX;
  set_exp(&dst, src.exp);
  set_sign(&dst, src.sign);
  return dst;
}

int exp_normalize(s21_buffer *value_1, s21_buffer *value_2) {
  int status = OK;
  if (value_1->exp > value_2->exp) {
    while (value_1->exp != value_2->exp) {
      status = mul_buffer_by_ten(value_2);
    }
  } else if (value_2->exp > value_1->exp) {
    while (value_1->exp != value_2->exp) {
      status = mul_buffer_by_ten(value_1);
    }
  }
  return status;
}

int normalize(s21_buffer *value) {
  int status = OK;
  s21_buffer copy = *value;
  unsigned int remainders[28] = {0};
  int i = 0;
  while (copy.exp && is_overflow(copy)) {
    remainders[i++] = div_buffer_by_ten(&copy);
  }
  if (!copy.exp && is_overflow(copy))
    status = INF;
  else {
    copy.bits[0] = bank_round(copy.bits[0], remainders, i);
    *value = copy;
  }
  return status;
}

int is_overflow(s21_buffer value) {
  return value.bits[3] || value.bits[4] || value.bits[5];
}

int getoverflow(s21_buffer *value) {
  unsigned int overflow = 0;
  for (int i = 0; i < 6; i++) {
    value->bits[i] += overflow;
    overflow = value->bits[i] >> 32;
    value->bits[i] &= UINT32_MAX;
  }
  if (is_overflow(*value))
    overflow = 1;
  else
    overflow = 0;
  return overflow;
}

int mul_buffer_by_ten(s21_buffer *value) {
  s21_buffer copy = *value;
  for (int i = 0; i < 6; i++) {
    copy.bits[i] *= 10;
  }
  copy.exp++;
  int status = getoverflow(&copy);
  if (!status && value->exp < MAX_EXP) *value = copy;
  return status;
}

unsigned int div_buffer_by_ten(s21_buffer *value) {
  unsigned int remainder = 0;
  if (value->exp) {
    s21_buffer copy = *value;
    for (int i = 5; i >= 0; i--) {
      copy.bits[i] += (uint64)remainder << 32;
      remainder = copy.bits[i] % 10;
      copy.bits[i] /= 10;
    }
    copy.exp--;
    *value = copy;
  }
  return remainder;
}

int first_remainder_digit(s21_decimal value) {
  s21_buffer tmp = to_buffer(value);
  int result = 0;
  while (tmp.exp) {
    result = div_buffer_by_ten(&tmp);
  }
  return result;
}

int add_buff(s21_buffer value_1, s21_buffer value_2, s21_decimal *result) {
  s21_buffer copy = value_1;
  for (int i = 0; i < 3; i++) {
    copy.bits[i] += value_2.bits[i];
  }
  int status = getoverflow(&copy);
  if (status) status = normalize(&copy);
  *result = to_decimal(copy);
  return status;
}

void sub_buff(s21_buffer value_1, s21_buffer value_2, s21_decimal *result) {
  s21_buffer copy = value_1;
  int carry = 0;
  for (int i = 0; i < 3; i++) {
    copy.bits[i] += carry ? ~(value_2.bits[i] + 1) + 1 : ~value_2.bits[i] + 1;
    carry = 0;
    if (value_1.bits[i] < value_2.bits[i]) carry = 1;
  }
  *result = to_decimal(copy);
}

int is_even(unsigned int num) { return !get_bit_int(num, 0); }

unsigned int bank_round(unsigned int value, unsigned int remainders[],
                        int index) {
  if (remainders[index] > 5) {
    return value + 1;
  } else if (remainders[index] < 5) {
    return value;
  } else {
    while (index > 0) {
      if (remainders[--index]) return value + 1;
    }
    if (is_even(value))
      return value;
    else
      return value + 1;
  }
}

int mul_buff(s21_buffer value_1, s21_buffer value_2, s21_decimal *result) {
  s21_buffer tmp = {0};
  int status = OK;

  tmp.bits[0] = value_1.bits[0] * value_2.bits[0];
  getoverflow(&tmp);
  tmp.bits[1] += value_1.bits[1] * value_2.bits[0];
  getoverflow(&tmp);
  tmp.bits[1] += value_1.bits[0] * value_2.bits[1];
  getoverflow(&tmp);
  tmp.bits[2] += value_1.bits[0] * value_2.bits[2];
  getoverflow(&tmp);
  tmp.bits[1] += value_1.bits[1] * value_2.bits[1];
  getoverflow(&tmp);
  tmp.bits[2] += value_1.bits[2] * value_2.bits[0];
  getoverflow(&tmp);
  tmp.bits[2] += value_1.bits[1] * value_2.bits[2];
  getoverflow(&tmp);
  tmp.bits[2] += value_1.bits[2] * value_2.bits[1];
  getoverflow(&tmp);
  tmp.bits[2] += value_1.bits[2] * value_2.bits[2];
  getoverflow(&tmp);

  tmp.exp = value_1.exp + value_2.exp;
  tmp.sign = value_1.sign ^ value_2.sign;
  normalize(&tmp);
  if (is_overflow(tmp)) {
    if (tmp.sign)
      status = MIN_INF;
    else
      status = INF;
  } else {
    *result = to_decimal(tmp);
  }

  return status;
}
