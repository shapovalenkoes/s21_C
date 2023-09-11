#include "s21_decimal.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int status = OK;
  int sign_1 = get_sign(&value_1);
  int sign_2 = get_sign(&value_2);
  s21_buffer buff_1 = to_buffer(value_1);
  s21_buffer buff_2 = to_buffer(value_2);
  status = exp_normalize(&buff_1, &buff_2);

  if (sign_1 == sign_2) {
    status = add_buff(buff_1, buff_2, result);
  } else {
    s21_decimal tmp_1 = {0};
    s21_decimal tmp_2 = {0};
    if (sign_1) {
      s21_negate(value_1, &tmp_1);
      tmp_2 = value_2;
    } else {
      s21_negate(value_2, &tmp_2);
      tmp_1 = value_1;
    }
    if (s21_is_less(tmp_1, tmp_2)) {
      sub_buff(buff_2, buff_1, result);
      sign_1 = 0;
    } else {
      sub_buff(buff_1, buff_2, result);
      sign_2 = 0;
    }
  }
  int sign = sign_1 | sign_2;
  set_sign(result, sign);
  return status;
}

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int status = OK;
  s21_decimal copy = {0};
  int sign_1 = get_sign(&value_1);
  int sign_2 = get_sign(&value_2);

  if (sign_1 == sign_2) {
    s21_negate(value_2, &copy);
    status = s21_add(value_1, copy, result);
  } else {
    s21_decimal tmp_1 = {0};
    s21_decimal tmp_2 = {0};
    if (sign_1) {
      s21_negate(value_1, &tmp_1);
      tmp_2 = value_2;
    } else {
      s21_negate(value_2, &tmp_2);
      tmp_1 = value_1;
    }
    status = s21_add(tmp_1, tmp_2, result);
    set_sign(result, sign_1);
  }
  return status ? MIN_INF : OK;
}

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  s21_buffer buff_1 = to_buffer(value_1);
  s21_buffer buff_2 = to_buffer(value_2);
  int status = mul_buff(buff_1, buff_2, result);
  return status;
}

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int status = OK;
  if (is_zero(value_2))
    status = ZERO_DIVISION;
  else {
    init(result);
    // int exp = get_exp(&value_1) - get_exp(&value_2);
    int sign_1 = get_sign(&value_1);
    int sign_2 = get_sign(&value_2);
    if (sign_1 != sign_2) set_sign(result, 1);
  }
  return status;
}
