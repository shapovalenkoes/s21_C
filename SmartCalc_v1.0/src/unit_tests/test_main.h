#ifndef TEST_MAIN_H
#define TEST_MAIN_H

#include <check.h>

#include "../SmartCalc_v1/calc.h"

#define ARRAY_SIZE(arr) (sizeof((arr)) / sizeof((arr)[0]))

Suite* calc_suite(void);
Suite* validator_suite(void);

#endif
