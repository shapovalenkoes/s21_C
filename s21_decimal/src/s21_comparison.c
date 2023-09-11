#include "s21_decimal.h"

int s21_is_less(s21_decimal value_1, s21_decimal value_2) {
  int status = TRUE, sign1 = get_sign(&value_1), sign2 = get_sign(&value_2);
  if (s21_is_equal(value_1, value_2))
    status = FALSE;
  else if (!sign1 && sign2)
    status = FALSE;
  else if (sign1 == sign2) {
    s21_buffer buf_1 = to_buffer(value_1);
    s21_buffer buf_2 = to_buffer(value_2);
    exp_normalize(&buf_1, &buf_2);
    for (int i = 2; i >= 0; i--) {
      if (buf_1.bits[i] > buf_2.bits[i]) {
        status = FALSE;
        break;
      } else if (buf_1.bits[i] < buf_2.bits[i])
        break;
    }
    if (sign1) status = !status;
  }
  return status;
}

int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2) {
  return s21_is_less(value_1, value_2) || s21_is_equal(value_1, value_2);
}

int s21_is_greater(s21_decimal value_1, s21_decimal value_2) {
  return s21_is_less(value_2, value_1);
}

int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2) {
  return s21_is_greater(value_1, value_2) || s21_is_equal(value_1, value_2);
}

int s21_is_equal(s21_decimal value_1, s21_decimal value_2) {
  int status = FALSE;
  if (is_zero(value_1) && is_zero(value_2))
    status = TRUE;
  else if (get_sign(&value_2) == get_sign(&value_1)) {
    status = TRUE;
    s21_buffer buf_1 = to_buffer(value_1);
    s21_buffer buf_2 = to_buffer(value_2);
    exp_normalize(&buf_1, &buf_2);
    for (int i = 0; i < 3 && status == TRUE; i++) {
      if (buf_1.bits[i] != buf_2.bits[i]) status = FALSE;
    }
  }
  return status;
}

int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2) {
  return !s21_is_equal(value_1, value_2);
}