#ifndef S21_DECIMAL_H
#define S21_DECIMAL_H

#include <math.h>
#include <stdint.h>
#include <stdio.h>

#define SIGN 0x80000000  // применяем к bits[SCALE]
#define EXP 0x00ff0000   // применяем к bits[SCALE]
#define MAX_EXP 28

typedef unsigned long uint64;

enum return_codes {
  OK = 0,
  INF = 1,
  MIN_INF = 2,
  ZERO_DIVISION = 3,
  FALSE = 0,
  TRUE = 1,
  CONVERSION_ERROR = 1,
  COMPUTATION_ERROR = 1
};

enum bits { LOW, MID, HIGH, SCALE };

typedef struct decimal_struct {
  unsigned int bits[4];
} s21_decimal;

typedef struct decimal_buff {
  uint64 bits[6];
  int exp;
  int sign;
} s21_buffer;

typedef union {
  float fl;
  unsigned int ui;
} converter;

// Arithmetic Operators
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

// Comparison Operators
int s21_is_less(s21_decimal, s21_decimal);
int s21_is_less_or_equal(s21_decimal, s21_decimal);
int s21_is_greater(s21_decimal, s21_decimal);
int s21_is_greater_or_equal(s21_decimal, s21_decimal);
int s21_is_equal(s21_decimal, s21_decimal);
int s21_is_not_equal(s21_decimal, s21_decimal);

// Convertors and parsers
int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

// Another functions
int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);

// utils
void init(s21_decimal *dec);
int get_bit(s21_decimal *dec, int index);
int get_bit_int(int num, int index);
void set_bit(s21_decimal *dec, int index, int bit);
void inverse_bit(s21_decimal *dec, int index);
int get_sign(s21_decimal *dec);
int get_exp(s21_decimal *dec);
void set_sign(s21_decimal *dec, int sign);
void set_exp(s21_decimal *dec, int exp);
void print_bits(s21_decimal *dec);
int is_zero(s21_decimal dec);
s21_buffer to_buffer(s21_decimal src);
s21_decimal to_decimal(s21_buffer src);
int getoverflow(s21_buffer *value);
int is_overflow(s21_buffer value);
unsigned int div_buffer_by_ten(s21_buffer *value);
int mul_buffer_by_ten(s21_buffer *value);
int exp_normalize(s21_buffer *value_1, s21_buffer *value_2);
int first_remainder_digit(s21_decimal value);
int add_buff(s21_buffer value_1, s21_buffer value_2, s21_decimal *result);
void sub_buff(s21_buffer value_1, s21_buffer value_2, s21_decimal *result);
int is_even(unsigned int num);
unsigned int bank_round(unsigned int value, unsigned int remainders[],
                        int index);
int mul_buff(s21_buffer value_1, s21_buffer value_2, s21_decimal *result);
#endif