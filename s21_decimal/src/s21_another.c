#include "s21_decimal.h"

int s21_floor(s21_decimal value, s21_decimal *result) {
  s21_truncate(value, result);
  if (get_sign(&value)) {
    if (s21_is_not_equal(value, *result)) {
      s21_decimal one = {{1, 0, 0, 0}};
      s21_sub(*result, one, result);
    }
  }
  return OK;
}

int s21_round(s21_decimal value, s21_decimal *result) {
  s21_truncate(value, result);
  if (first_remainder_digit(value) > 4) {
    s21_decimal one = {{1, 0, 0, 0}};
    s21_add(*result, one, result);
  }
  return OK;
}

int s21_truncate(s21_decimal value, s21_decimal *result) {
  s21_buffer tmp = to_buffer(value);
  while (tmp.exp) {
    div_buffer_by_ten(&tmp);
  }
  *result = to_decimal(tmp);
  return OK;
}

int s21_negate(s21_decimal value, s21_decimal *result) {
  *result = value;
  inverse_bit(result, 127);
  return OK;
}