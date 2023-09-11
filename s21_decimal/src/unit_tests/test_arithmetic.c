#include "../s21_decimal.h"
#include "test_main.h"

START_TEST(s21_add_test_1) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal dest = {0};
  int ret = s21_add(value_1, value_2, &dest);
  ck_assert_int_eq(ret, 0);
  ck_assert_uint_eq(dest.bits[0], 0);
  ck_assert_uint_eq(dest.bits[1], 0);
  ck_assert_uint_eq(dest.bits[2], 0);
  ck_assert_uint_eq(dest.bits[3], 0);
}
END_TEST

START_TEST(s21_add_test_2) {
  s21_decimal value_1 = {{1234, 124, 242, 0}};
  s21_decimal value_2 = {0};
  s21_decimal dest = {0};
  int ret = s21_add(value_1, value_2, &dest);
  ck_assert_int_eq(ret, 0);
  ck_assert_uint_eq(dest.bits[0], 1234);
  ck_assert_uint_eq(dest.bits[1], 124);
  ck_assert_uint_eq(dest.bits[2], 242);
  ck_assert_uint_eq(dest.bits[3], 0);
}
END_TEST

START_TEST(s21_add_test_3) {
  s21_decimal value_1 = {{12345, 0, 0, 0}};
  s21_decimal value_2 = {{12345, 0, 0, 0}};
  set_exp(&value_1, 1);
  set_exp(&value_2, 3);
  s21_decimal dest = {0};
  int ret = s21_add(value_1, value_2, &dest);
  ck_assert_int_eq(ret, 0);
  ck_assert_uint_eq(dest.bits[0], 1246845);
  ck_assert_uint_eq(dest.bits[1], 0);
  ck_assert_uint_eq(dest.bits[2], 0);
  ck_assert_uint_eq(dest.bits[3], value_2.bits[3]);
}
END_TEST

START_TEST(s21_add_test_4) {
  s21_decimal value_1 = {{12345, 0, 0, 0}};
  s21_decimal value_2 = {{12345, 0, 0, 0}};
  set_exp(&value_1, 1);
  set_exp(&value_2, 3);
  set_sign(&value_2, 1);
  s21_decimal dest = {0};
  unsigned int res_exp = 3 << 16;
  int ret = s21_add(value_1, value_2, &dest);
  ck_assert_int_eq(ret, 0);
  ck_assert_uint_eq(dest.bits[0], 1222155);
  ck_assert_uint_eq(dest.bits[1], 0);
  ck_assert_uint_eq(dest.bits[2], 0);
  ck_assert_uint_eq(dest.bits[3], res_exp);
}
END_TEST

START_TEST(s21_add_pos_pos) {  //сложение положительных интов
  s21_decimal var1 = {{50, 0, 0, 0}};
  s21_decimal var2 = {{6, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal ch = {{56, 0, 0, 0}};
  int ret = s21_add(var1, var2, &result);
  ck_assert_int_eq(ret, 0);
  ck_assert_uint_eq(result.bits[0], ch.bits[0]);
  ck_assert_uint_eq(result.bits[1], ch.bits[1]);
  ck_assert_uint_eq(result.bits[2], ch.bits[2]);
  ck_assert_uint_eq(result.bits[3], ch.bits[3]);
}
END_TEST

START_TEST(s21_add_pos_posE) {  // сложение положительных со степенью
  s21_decimal var1 = {{50, 0, 0, 0}};
  s21_decimal var2 = {{777, 3, 0, 0}};
  var2.bits[3] = 3 << 16;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal ch = {{50777, 3, 0, 0}};
  ch.bits[3] = 3 << 16;
  int ret = s21_add(var1, var2, &result);
  ck_assert_int_eq(ret, 0);
  ck_assert_uint_eq(result.bits[0], ch.bits[0]);
  ck_assert_uint_eq(result.bits[1], ch.bits[1]);
  ck_assert_uint_eq(result.bits[2], ch.bits[2]);
  ck_assert_uint_eq(result.bits[3], ch.bits[3]);
}
END_TEST

START_TEST(s21_add_posE_posE) {  // сложение положительных со степенью
  s21_decimal var1 = {{8666, 5, 0, 0}};
  var1.bits[3] = 5 << 16;
  s21_decimal var2 = {{777, 3, 0, 0}};
  var2.bits[3] = 10 << 16;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal ch = {{866600777, 500003, 0, 0}};
  ch.bits[3] = 10 << 16;
  int ret = s21_add(var1, var2, &result);
  ck_assert_int_eq(ret, 0);
  ck_assert_uint_eq(result.bits[0], ch.bits[0]);
  ck_assert_uint_eq(result.bits[1], ch.bits[1]);
  ck_assert_uint_eq(result.bits[2], ch.bits[2]);
  ck_assert_uint_eq(result.bits[3], ch.bits[3]);
}
END_TEST

START_TEST(s21_add_neg_neg) {  //сложение отрицательных интов
  s21_decimal var1 = {{50, 0, 0, 0}};
  var1.bits[3] = 1 << 31;
  s21_decimal var2 = {{50, 0, 0, 0}};
  var2.bits[3] = 1 << 31;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal ch = {{100, 0, 0, 0}};
  ch.bits[3] = 1 << 31;
  int ret = s21_add(var1, var2, &result);
  ck_assert_int_eq(ret, 0);
  ck_assert_uint_eq(result.bits[0], ch.bits[0]);
  ck_assert_uint_eq(result.bits[1], ch.bits[1]);
  ck_assert_uint_eq(result.bits[2], ch.bits[2]);
  ck_assert_uint_eq(result.bits[3], ch.bits[3]);
}
END_TEST

START_TEST(s21_add_neg_negE) {  //сложение отрицательных со степенью
  s21_decimal var1 = {{50, 0, 0, 0}};
  var1.bits[3] = 1 << 31;
  s21_decimal var2 = {{777, 3, 0, 0}};
  var2.bits[3] = 3 << 16;
  var2.bits[3] |= (1 << 31);
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal ch = {{50777, 3, 0, 0}};
  ch.bits[3] = 3 << 16;
  ch.bits[3] |= (1 << 31);
  int ret = s21_add(var1, var2, &result);
  ck_assert_int_eq(ret, 0);
  ck_assert_uint_eq(result.bits[0], ch.bits[0]);
  ck_assert_uint_eq(result.bits[1], ch.bits[1]);
  ck_assert_uint_eq(result.bits[2], ch.bits[2]);
  ck_assert_uint_eq(result.bits[3], ch.bits[3]);
}
END_TEST

START_TEST(s21_add_negE_negE) {  //сложение отрицательных со степенью
  s21_decimal var1 = {{50, 60, 0, 0}};
  var1.bits[3] = 1 << 31;
  var1.bits[3] |= 3 << 16;
  s21_decimal var2 = {{4, 5555, 333, 0}};
  var2.bits[3] = 7 << 16;
  var2.bits[3] |= (1 << 31);
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal ch = {{500004, 605555, 333, 0}};
  ch.bits[3] = 7 << 16;
  ch.bits[3] |= (1 << 31);
  int ret = s21_add(var1, var2, &result);
  ck_assert_int_eq(ret, 0);
  ck_assert_uint_eq(result.bits[0], ch.bits[0]);
  ck_assert_uint_eq(result.bits[1], ch.bits[1]);
  ck_assert_uint_eq(result.bits[2], ch.bits[2]);
  ck_assert_uint_eq(result.bits[3], ch.bits[3]);
}
END_TEST

START_TEST(s21_add_pos_neg) {  //сложение положительного и отрицательного
                               //(переход в вычитание)
  s21_decimal var1 = {{50, 50, 0, 0}};
  s21_decimal var2 = {{50, 0, 0, 0}};
  var2.bits[3] = 1 << 31;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal ch = {{0, 50, 0, 0}};
  int ret = s21_add(var1, var2, &result);
  ck_assert_int_eq(ret, 0);
  ck_assert_uint_eq(result.bits[0], ch.bits[0]);
  ck_assert_uint_eq(result.bits[1], ch.bits[1]);
  ck_assert_uint_eq(result.bits[2], ch.bits[2]);
  ck_assert_uint_eq(result.bits[3], ch.bits[3]);
}

START_TEST(s21_add_neg_pos) {  //одна инверсия (тоже переход в вычитание)
  s21_decimal var1 = {{50, 50, 0, 0}};
  var1.bits[3] = 1 << 31;
  s21_decimal var2 = {{0, 50, 0, 0}};
  s21_decimal ch = {{50, 0, 0, 0}};
  ch.bits[3] = 1 << 31;
  s21_decimal result = {{0, 0, 0, 0}};
  int ret = s21_add(var1, var2, &result);
  ck_assert_int_eq(ret, 0);
  ck_assert_uint_eq(result.bits[0], ch.bits[0]);
  ck_assert_uint_eq(result.bits[1], ch.bits[1]);
  ck_assert_uint_eq(result.bits[2], ch.bits[2]);
  ck_assert_uint_eq(result.bits[3], ch.bits[3]);
}
END_TEST

START_TEST(s21_add_0_0) {  //проверка на сложение 0
  s21_decimal var1 = {{0, 0, 0, 0}};
  s21_decimal var2 = {{0, 0, 0, 0}};
  s21_decimal ch = {{0, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  int ret = s21_add(var1, var2, &result);
  ck_assert_int_eq(ret, 0);
  ck_assert_uint_eq(result.bits[0], ch.bits[0]);
  ck_assert_uint_eq(result.bits[1], ch.bits[1]);
  ck_assert_uint_eq(result.bits[2], ch.bits[2]);
  ck_assert_uint_eq(result.bits[3], ch.bits[3]);
}
END_TEST

START_TEST(s21_add_max) {  //проверка на превышение мантиссы
  s21_decimal var1 = {{4294967295, 4294967295, 4294967295, 0}};
  s21_decimal var2 = {{1, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  int ret = s21_add(var1, var2, &result);
  ck_assert_int_eq(ret, 1);
}
END_TEST

START_TEST(
    s21_sub_pos_pos) {  //вычитание положительных чисел с положительным в ответе
  s21_decimal var1 = {{50, 50, 50, 0}};
  s21_decimal var2 = {{50, 50, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal ch = {{0, 0, 50, 0}};
  int ret = s21_sub(var1, var2, &result);
  ck_assert_int_eq(ret, 0);
  ck_assert_uint_eq(result.bits[0], ch.bits[0]);
  ck_assert_uint_eq(result.bits[1], ch.bits[1]);
  ck_assert_uint_eq(result.bits[2], ch.bits[2]);
  ck_assert_uint_eq(result.bits[3], ch.bits[3]);
}
END_TEST

START_TEST(s21_sub_pos_pos2) {  //вычитание положительных чисел с отрицательным
                                //в ответе
  s21_decimal var1 = {{0, 50, 50, 0}};
  s21_decimal var2 = {{50, 50, 50, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal ch = {{50, 0, 0, 0}};
  ch.bits[3] = 1 << 31;
  int ret = s21_sub(var1, var2, &result);
  ck_assert_int_eq(ret, 0);
  ck_assert_uint_eq(result.bits[0], ch.bits[0]);
  ck_assert_uint_eq(result.bits[1], ch.bits[1]);
  ck_assert_uint_eq(result.bits[2], ch.bits[2]);
  ck_assert_uint_eq(result.bits[3], ch.bits[3]);
}
END_TEST

START_TEST(s21_sub_pos_posE) {  //вычитание положительных чисел
  s21_decimal var1 = {{30, 00, 00, 0}};
  s21_decimal var2 = {{55555550, 50, 0, 0}};
  var2.bits[3] = 3 << 16;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal ch = {{55525550, 50, 0, 0}};
  ch.bits[3] = 3 << 16;
  ch.bits[3] |= (1 << 31);
  int ret = s21_sub(var1, var2, &result);
  ck_assert_int_eq(ret, 0);
  ck_assert_uint_eq(result.bits[0], ch.bits[0]);
  ck_assert_uint_eq(result.bits[1], ch.bits[1]);
  ck_assert_uint_eq(result.bits[2], ch.bits[2]);
  ck_assert_uint_eq(result.bits[3], ch.bits[3]);
}
END_TEST

START_TEST(s21_sub_posE_posE) {  //вычитание положительных чисел со степенью
  s21_decimal var1 = {{7, 55, 0, 0}};
  var1.bits[3] = 6 << 16;
  s21_decimal var2 = {{30, 50, 0, 0}};
  var2.bits[3] = 7 << 16;
  s21_decimal ch = {{40, 500, 0, 0}};
  ch.bits[3] = 7 << 16;
  s21_decimal result = {{0, 0, 0, 0}};
  int ret = s21_sub(var1, var2, &result);
  ck_assert_int_eq(ret, 0);
  ck_assert_uint_eq(result.bits[0], ch.bits[0]);
  ck_assert_uint_eq(result.bits[1], ch.bits[1]);
  ck_assert_uint_eq(result.bits[2], ch.bits[2]);
  ck_assert_uint_eq(result.bits[3], ch.bits[3]);
}
END_TEST

START_TEST(s21_sub_neg_neg) {  //вычитание отрицательных чисел
  s21_decimal var1 = {{7, 33, 0, 0}};
  var1.bits[3] = 1 << 31;
  s21_decimal var2 = {{10, 55, 0, 0}};
  var2.bits[3] = 1 << 31;
  s21_decimal ch = {{3, 22, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  int ret = s21_sub(var1, var2, &result);
  ck_assert_int_eq(ret, 0);
  ck_assert_uint_eq(result.bits[0], ch.bits[0]);
  ck_assert_uint_eq(result.bits[1], ch.bits[1]);
  ck_assert_uint_eq(result.bits[2], ch.bits[2]);
  ck_assert_uint_eq(result.bits[3], ch.bits[3]);
}
END_TEST

START_TEST(s21_sub_neg_negE) {  //вычитание отрицтельных чисел со степенью
  s21_decimal var1 = {{7, 55, 0, 0}};
  var1.bits[3] = 1 << 31;
  s21_decimal var2 = {{30, 50, 0, 0}};
  var2.bits[3] = 1 << 31;
  var2.bits[3] |= (2 << 16);
  s21_decimal ch = {{670, 5450, 0, 0}};
  ch.bits[3] = 1 << 31;
  ch.bits[3] |= (2 << 16);
  s21_decimal result = {{0, 0, 0, 0}};
  int ret = s21_sub(var1, var2, &result);
  ck_assert_int_eq(ret, 0);
  ck_assert_uint_eq(result.bits[0], ch.bits[0]);
  ck_assert_uint_eq(result.bits[1], ch.bits[1]);
  ck_assert_uint_eq(result.bits[2], ch.bits[2]);
  ck_assert_uint_eq(result.bits[3], ch.bits[3]);
}
END_TEST

START_TEST(s21_sub_negE_negE) {  //вычитание отрицательных чисел со степенью
  s21_decimal var1 = {{70, 55, 0, 0}};
  var1.bits[3] = 1 << 31;
  var1.bits[3] |= (4 << 16);
  s21_decimal var2 = {{30, 50, 0, 0}};
  var2.bits[3] = 1 << 31;
  var2.bits[3] |= (3 << 16);
  s21_decimal ch = {{230, 445, 0, 0}};
  ch.bits[3] |= (4 << 16);
  s21_decimal result = {{0, 0, 0, 0}};
  int ret = s21_sub(var1, var2, &result);
  ck_assert_int_eq(ret, 0);
  ck_assert_uint_eq(result.bits[0], ch.bits[0]);
  ck_assert_uint_eq(result.bits[1], ch.bits[1]);
  ck_assert_uint_eq(result.bits[2], ch.bits[2]);
  ck_assert_uint_eq(result.bits[3], ch.bits[3]);
}
END_TEST

START_TEST(s21_sub_pos_neg) {  //переход в сложение
  s21_decimal var1 = {{50, 50, 50, 0}};
  s21_decimal var2 = {{50, 50, 50, 0}};
  var2.bits[3] = 1 << 31;
  s21_decimal ch = {{100, 100, 100, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  int ret = s21_sub(var1, var2, &result);
  ck_assert_int_eq(ret, 0);
  ck_assert_uint_eq(result.bits[0], ch.bits[0]);
  ck_assert_uint_eq(result.bits[1], ch.bits[1]);
  ck_assert_uint_eq(result.bits[2], ch.bits[2]);
  ck_assert_uint_eq(result.bits[3], ch.bits[3]);
}
END_TEST

START_TEST(s21_sub_neg_pos) {  //переход в сложение
  s21_decimal var1 = {{50, 50, 50, 0}};
  var1.bits[3] = 1 << 31;
  var1.bits[3] |= 3 << 16;
  s21_decimal var2 = {{50, 50, 50, 0}};
  s21_decimal ch = {{50050, 50050, 50050, 0}};
  ch.bits[3] = 1 << 31;
  ch.bits[3] |= 3 << 16;
  s21_decimal result = {{0, 0, 0, 0}};
  int ret = s21_sub(var1, var2, &result);
  ck_assert_int_eq(ret, 0);
  ck_assert_uint_eq(result.bits[0], ch.bits[0]);
  ck_assert_uint_eq(result.bits[1], ch.bits[1]);
  ck_assert_uint_eq(result.bits[2], ch.bits[2]);
  ck_assert_uint_eq(result.bits[3], ch.bits[3]);
}
END_TEST

START_TEST(s21_sub_0_0) {  //проверка на вычитание 0
  s21_decimal var1 = {{0, 0, 0, 0}};
  s21_decimal var2 = {{0, 0, 0, 0}};
  s21_decimal ch = {{0, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  int ret = s21_sub(var1, var2, &result);
  ck_assert_int_eq(ret, 0);
  ck_assert_uint_eq(result.bits[0], ch.bits[0]);
  ck_assert_uint_eq(result.bits[1], ch.bits[1]);
  ck_assert_uint_eq(result.bits[2], ch.bits[2]);
  ck_assert_uint_eq(result.bits[3], ch.bits[3]);
}
END_TEST

START_TEST(s21_sub_max) {  //проверка на превышение мантиссы
  s21_decimal var1 = {{~0, ~0, ~0, 0}};
  set_sign(&var1, 1);
  s21_decimal var2 = {{10, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  int ret = s21_sub(var1, var2, &result);
  ck_assert_int_eq(ret, 2);
}
END_TEST

START_TEST(mul_0) {
  s21_decimal val1 = {{2, 0, 0, ~(UINT32_MAX / 2)}};
  s21_decimal val2 = {{2, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_1) {
  s21_decimal val1 = {{2, 0, 0, 0}};
  s21_decimal val2 = {{2, 0, 0, ~(UINT32_MAX / 2)}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_2) {
  s21_decimal val1 = {{2, 0, 0, ~(UINT32_MAX / 2)}};
  s21_decimal val2 = {{2, 0, 0, ~(UINT32_MAX / 2)}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_3) {
  s21_decimal val1 = {{2, 0, 0, 0}};
  s21_decimal val2 = {{2, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_4) {
  s21_decimal val1 = {{8, 0, 0, 0}};
  s21_decimal val2 = {{2, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_5) {
  s21_decimal val1 = {{2, 0, 0, 0}};
  s21_decimal val2 = {{8, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_6) {
  s21_decimal val1 = {{8, 0, 0, ~(UINT32_MAX / 2)}};
  s21_decimal val2 = {{2, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_7) {
  s21_decimal val1 = {{2, 0, 0, ~(UINT32_MAX / 2)}};
  s21_decimal val2 = {{8, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_8) {
  s21_decimal val1 = {{UINT32_MAX, UINT32_MAX, UINT32_MAX, ~(UINT32_MAX / 2)}};
  s21_decimal val2 = {{2, 0, 0, ~(UINT32_MAX / 2)}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(1, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_9) {
  s21_decimal val1 = {{UINT32_MAX, UINT32_MAX, UINT32_MAX, ~(UINT32_MAX / 2)}};
  s21_decimal val2 = {{2, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(2, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_10) {
  s21_decimal val1 = {{UINT32_MAX, UINT32_MAX, UINT32_MAX, 0}};
  s21_decimal val2 = {{2, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(1, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_11) {
  s21_decimal val1 = {{UINT32_MAX, UINT32_MAX, UINT32_MAX, ~(UINT32_MAX / 2)}};
  s21_decimal val2 = {{0, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_12) {
  s21_decimal value_1 = {{5, 0, 0, 0}};
  s21_decimal value_2 = {{7, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal check = {{35, 0, 0, 0}};
  int return_value = s21_mul(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(mul_13) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0, 0, 0}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal check = {{1, 0xFFFFFFFE, 0, 0}};
  int return_value = s21_mul(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(mul_14) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{2, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal check = {{0, 0, 0, 0}};
  int return_value = s21_mul(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(mul_16) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{2, 0, 0, 0}};
  set_sign(&value_2, 1);
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal check = {{0, 0, 0, 0}};
  int return_value = s21_mul(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 2);
}
END_TEST

START_TEST(mul_17) {
  s21_decimal value_1 = {{17, 0, 0, 0}};
  set_sign(&value_1, 1);
  s21_decimal value_2 = {{0, 0, 0, 0}};
  s21_decimal result = {0};
  s21_decimal check = {{0, 0, 0, 0}};
  int return_value = s21_mul(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(mul_19) {
  s21_decimal src1, src2;
  int a = -32768;
  int b = 32768;
  int res_our_dec = 0;
  s21_from_int_to_decimal(a, &src1);
  s21_from_int_to_decimal(b, &src2);
  int res_origin = -1073741824;
  s21_decimal res_od = {0};
  s21_mul(src1, src2, &res_od);
  s21_from_decimal_to_int(res_od, &res_our_dec);
  ck_assert_int_eq(res_our_dec, res_origin);
}
END_TEST

START_TEST(div_3) {
  s21_decimal value_1 = {{35, 0, 0, 0}};
  s21_decimal value_2 = {{1, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  int return_value = s21_div(value_1, value_2, &result);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(div_4) {
  s21_decimal value_1 = {{35, 0, 0, 0}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  int return_value = s21_div(value_1, value_2, &result);
  ck_assert_int_eq(return_value, 3);
}
END_TEST

// START_TEST(div_5) {
//   s21_decimal value_1 = {{35, 0, 0, 0}};
//   s21_decimal value_2 = {{5, 0, 0, 0}};
//   s21_decimal result = {{0, 0, 0, 0}};
//   s21_decimal check = {{70, 0, 0, 0}};
//   set_exp(&value_1, 1);
//   set_exp(&value_2, 2);
//   int return_value = s21_div(value_1, value_2, &result);
//   ck_assert_int_eq(s21_is_equal(result, check), 1);
//   ck_assert_int_eq(return_value, 0);
// }
// END_TEST

// START_TEST(div_6) {
//   s21_decimal value_1 = {{0x88888888, 0x88888888, 0x88888888, 0}};
//   s21_decimal value_2 = {{0x2, 0, 0, 0}};
//   set_sign(&value_2, 1);
//   s21_decimal result = {{0, 0, 0, 0}};
//   s21_decimal check = {{0x44444444, 0x44444444, 0x44444444, 0}};
//   set_sign(&check, 1);
//   int return_value = s21_div(value_1, value_2, &result);
//   ck_assert_int_eq(s21_is_equal(result, check), 1);
//   ck_assert_int_eq(return_value, 0);
// }
// END_TEST

// START_TEST(div_7) {
//   s21_decimal value_1 = {{10, 0, 0, 0}};
//   set_sign(&value_1,1);
//   s21_decimal value_2 = {{8, 0, 0, 0}};
//   set_sign(&value_2, 1);
//   s21_decimal result = {{0, 0, 0, 0}};
//   s21_decimal check = {{125, 0, 0, 0}};
//   set_exp(&check, 2);
//   int return_value = s21_div(value_1, value_2, &result);
//   ck_assert_int_eq(s21_is_equal(result, check), 1);
//   ck_assert_int_eq(return_value, 0);
// }
// END_TEST

// START_TEST(div_8) {
//   s21_decimal value_1 = {{15, 0, 0, 0}};
//   set_sign(&value_1, 1);
//   s21_decimal value_2 = {{0, 0, 0, 0}};
//   s21_decimal result = {{0, 0, 0, 0}};
//   s21_decimal check = {{0, 0, 0, 0}};
//   int return_value = s21_div(value_1, value_2, &result);
//   ck_assert_int_eq(s21_is_equal(result, check), 1);
//   ck_assert_int_eq(return_value, 3);
// }
// END_TEST

// START_TEST(div_9) {
//   s21_decimal value_1 = {{10, 0, 0, 0}};
//   s21_decimal value_2 = {{1, 0, 0, 0}};
//   set_exp(&value_2, 2);
//   s21_decimal result = {{0, 0, 0, 0}};
//   s21_decimal check = {{1000u, 0, 0, 0}};
//   int return_value = s21_div(value_1, value_2, &result);
//   ck_assert_int_eq(s21_is_equal(result, check), 1);
//   ck_assert_int_eq(return_value, 0);
// }
// END_TEST

Suite *arithmetic_suite(void) {
  Suite *s = suite_create("Arithmetic");
  TCase *tc_arithmetic = tcase_create("[s21_arithmetic] case");

  // ---------- Arithmetic functions ----------

  suite_add_tcase(s, tc_arithmetic);
  tcase_add_test(tc_arithmetic, s21_add_test_1);
  tcase_add_test(tc_arithmetic, s21_add_test_2);
  tcase_add_test(tc_arithmetic, s21_add_test_3);
  tcase_add_test(tc_arithmetic, s21_add_test_4);
  // s21_arithmetic_sub
  tcase_add_test(tc_arithmetic, s21_sub_pos_pos);
  tcase_add_test(tc_arithmetic, s21_sub_pos_pos2);
  tcase_add_test(tc_arithmetic, s21_sub_pos_posE);
  tcase_add_test(tc_arithmetic, s21_sub_posE_posE);
  tcase_add_test(tc_arithmetic, s21_sub_neg_neg);
  tcase_add_test(tc_arithmetic, s21_sub_neg_negE);
  tcase_add_test(tc_arithmetic, s21_sub_negE_negE);
  tcase_add_test(tc_arithmetic, s21_sub_pos_neg);
  tcase_add_test(tc_arithmetic, s21_sub_neg_pos);
  tcase_add_test(tc_arithmetic, s21_sub_0_0);
  tcase_add_test(tc_arithmetic, s21_sub_max);
  // s21_arithmetic_add
  tcase_add_test(tc_arithmetic, s21_add_pos_pos);
  tcase_add_test(tc_arithmetic, s21_add_pos_posE);
  tcase_add_test(tc_arithmetic, s21_add_posE_posE);
  tcase_add_test(tc_arithmetic, s21_add_neg_neg);
  tcase_add_test(tc_arithmetic, s21_add_neg_negE);
  tcase_add_test(tc_arithmetic, s21_add_negE_negE);
  tcase_add_test(tc_arithmetic, s21_add_pos_neg);
  tcase_add_test(tc_arithmetic, s21_add_neg_pos);
  tcase_add_test(tc_arithmetic, s21_add_0_0);
  tcase_add_test(tc_arithmetic, s21_add_max);
  // tcase_add_test(tc_arithmetic, s21_add_pos29_pos);
  // s21_arithmetic_mul
  tcase_add_test(tc_arithmetic, mul_0);
  tcase_add_test(tc_arithmetic, mul_1);
  tcase_add_test(tc_arithmetic, mul_2);
  tcase_add_test(tc_arithmetic, mul_3);
  tcase_add_test(tc_arithmetic, mul_4);
  tcase_add_test(tc_arithmetic, mul_5);
  tcase_add_test(tc_arithmetic, mul_6);
  tcase_add_test(tc_arithmetic, mul_7);
  tcase_add_test(tc_arithmetic, mul_8);
  tcase_add_test(tc_arithmetic, mul_9);
  tcase_add_test(tc_arithmetic, mul_10);
  tcase_add_test(tc_arithmetic, mul_11);
  tcase_add_test(tc_arithmetic, mul_12);
  tcase_add_test(tc_arithmetic, mul_13);
  tcase_add_test(tc_arithmetic, mul_14);
  tcase_add_test(tc_arithmetic, mul_16);
  tcase_add_test(tc_arithmetic, mul_17);
  tcase_add_test(tc_arithmetic, mul_19);
  // s21_arithmetic_div
  tcase_add_test(tc_arithmetic, div_3);
  tcase_add_test(tc_arithmetic, div_4);

  //   tcase_add_test(tc_arithmetic, div_5);
  //   tcase_add_test(tc_arithmetic, div_6);
  //   tcase_add_test(tc_arithmetic, div_7);
  //   tcase_add_test(tc_arithmetic, div_8);
  //   tcase_add_test(tc_arithmetic, div_9);
  tcase_set_timeout(tc_arithmetic, 100);

  return s;
}