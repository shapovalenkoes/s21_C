#ifndef S21_TEST_MAIN_H
#define S21_TEST_MAIN_H

#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../s21_decimal.h"

#define ARRAY_SIZE(arr) (sizeof((arr)) / sizeof((arr)[0]))

Suite *another_suite(void);
Suite *arithmetic_suite(void);
Suite *comparison_suite(void);
Suite *convertors_suite(void);

#endif