#ifndef S21_TEST_MAIN_H

#define S21_TEST_MAIN_H

#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_math.h"

#define ARRAY_SIZE(arr) (sizeof((arr)) / sizeof((arr)[0]))

Suite *s21_abs_suite(void);
Suite *s21_ceil_suite(void);
Suite *s21_floor_suite(void);
Suite *s21_exp_suite(void);
Suite *s21_log_suite(void);
Suite *s21_pow_suite(void);
Suite *s21_sqrt_suite(void);
Suite *s21_asin_suite(void);
Suite *s21_fabs_suite(void);
Suite *s21_sin_suite(void);
Suite *s21_fmod_suite(void);
Suite *s21_acos_suite(void);
Suite *s21_cos_suite(void);
Suite *s21_tan_suite(void);
Suite *s21_atan_suite(void);

#endif