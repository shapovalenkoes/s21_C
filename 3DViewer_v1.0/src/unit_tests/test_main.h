#ifndef TEST_MAIN_H
#define TEST_MAIN_H

#include <check.h>

#include "../viewer/load_model.h"
#include "../viewer/transformations.h"

#define ARRAY_SIZE(arr) (sizeof((arr)) / sizeof((arr)[0]))

Suite* load_suite(void);
Suite* transform_suite(void);

#endif
