#include "../s21_math.h"
#include "test_main.h"

#define BUFF_SIZE 512
START_TEST(test_0) {
  long double my_val = s21_fmod(0.0, 0.0);
  ck_assert_ldouble_nan(my_val);
}
END_TEST

START_TEST(test_1) {
  long double my_val = s21_fmod(0.0, -0.0);
  ck_assert_ldouble_nan(my_val);
}
END_TEST

START_TEST(test_2) {
  long double my_val = s21_fmod(0.0, -1.2);
  long double test_val = fmod(0.0, -1.2);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_3) {
  long double my_val = s21_fmod(0.0, 1.2);
  long double test_val = fmod(0.0, 1.2);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_4) {
  long double my_val = s21_fmod(0.0, -21.0);
  long double test_val = fmod(0.0, -21.0);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_5) {
  long double my_val = s21_fmod(0.0, 21.0);
  long double test_val = fmod(0.0, 21.0);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_6) {
  long double my_val = s21_fmod(0.0, -0.01);
  long double test_val = fmod(0.0, -0.01);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_7) {
  long double my_val = s21_fmod(0.0, 0.01);
  long double test_val = fmod(0.0, 0.01);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_8) {
  long double my_val = s21_fmod(0.0, 21.9);
  long double test_val = fmod(0.0, 21.9);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_9) {
  long double my_val = s21_fmod(0.0, -21.9);
  long double test_val = fmod(0.0, -21.9);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_10) {
  long double my_val = s21_fmod(0.0, 1.79769313486231570e+308);
  long double test_val = fmod(0.0, 1.79769313486231570e+308);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_11) {
  long double my_val = s21_fmod(0.0, 2.2250738585072014E-308);
  long double test_val = fmod(0.0, 2.2250738585072014E-308);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_12) {
  long double my_val = s21_fmod(0.0, 21212121);
  long double test_val = fmod(0.0, 21212121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_13) {
  long double my_val = s21_fmod(0.0, -21212121);
  long double test_val = fmod(0.0, -21212121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_14) {
  long double my_val = s21_fmod(0.0, 21212121.2121);
  long double test_val = fmod(0.0, 21212121.2121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_15) {
  long double my_val = s21_fmod(0.0, -21212121.2121);
  long double test_val = fmod(0.0, -21212121.2121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_16) {
  long double my_val = s21_fmod(0.0, 0.21212121);
  long double test_val = fmod(0.0, 0.21212121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_17) {
  long double my_val = s21_fmod(0.0, -0.21212121);
  long double test_val = fmod(0.0, -0.21212121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_18) {
  long double my_val = s21_fmod(-0.0, 0.0);
  ck_assert_ldouble_nan(my_val);
}
END_TEST

START_TEST(test_19) {
  long double my_val = s21_fmod(-0.0, -0.0);
  ck_assert_ldouble_nan(my_val);
}
END_TEST

START_TEST(test_20) {
  long double my_val = s21_fmod(-0.0, -1.2);
  long double test_val = fmod(-0.0, -1.2);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_21) {
  long double my_val = s21_fmod(-0.0, 1.2);
  long double test_val = fmod(-0.0, 1.2);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_22) {
  long double my_val = s21_fmod(-0.0, -21.0);
  long double test_val = fmod(-0.0, -21.0);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_23) {
  long double my_val = s21_fmod(-0.0, 21.0);
  long double test_val = fmod(-0.0, 21.0);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_24) {
  long double my_val = s21_fmod(-0.0, -0.01);
  long double test_val = fmod(-0.0, -0.01);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_25) {
  long double my_val = s21_fmod(-0.0, 0.01);
  long double test_val = fmod(-0.0, 0.01);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_26) {
  long double my_val = s21_fmod(-0.0, 21.9);
  long double test_val = fmod(-0.0, 21.9);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_27) {
  long double my_val = s21_fmod(-0.0, -21.9);
  long double test_val = fmod(-0.0, -21.9);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_28) {
  long double my_val = s21_fmod(-0.0, 1.79769313486231570e+308);
  long double test_val = fmod(-0.0, 1.79769313486231570e+308);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_29) {
  long double my_val = s21_fmod(-0.0, 2.2250738585072014E-308);
  long double test_val = fmod(-0.0, 2.2250738585072014E-308);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_30) {
  long double my_val = s21_fmod(-0.0, 21212121);
  long double test_val = fmod(-0.0, 21212121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_31) {
  long double my_val = s21_fmod(-0.0, -21212121);
  long double test_val = fmod(-0.0, -21212121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_32) {
  long double my_val = s21_fmod(-0.0, 21212121.2121);
  long double test_val = fmod(-0.0, 21212121.2121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_33) {
  long double my_val = s21_fmod(-0.0, -21212121.2121);
  long double test_val = fmod(-0.0, -21212121.2121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_34) {
  long double my_val = s21_fmod(-0.0, 0.21212121);
  long double test_val = fmod(-0.0, 0.21212121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_35) {
  long double my_val = s21_fmod(-0.0, -0.21212121);
  long double test_val = fmod(-0.0, -0.21212121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_36) {
  long double my_val = s21_fmod(-1.2, 0.0);
  ck_assert_ldouble_nan(my_val);
}
END_TEST

START_TEST(test_37) {
  long double my_val = s21_fmod(-1.2, -0.0);
  ck_assert_ldouble_nan(my_val);
}
END_TEST

START_TEST(test_38) {
  long double my_val = s21_fmod(-1.2, -1.2);
  long double test_val = fmod(-1.2, -1.2);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_39) {
  long double my_val = s21_fmod(-1.2, 1.2);
  long double test_val = fmod(-1.2, 1.2);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_40) {
  long double my_val = s21_fmod(-1.2, -21.0);
  long double test_val = fmod(-1.2, -21.0);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_41) {
  long double my_val = s21_fmod(-1.2, 21.0);
  long double test_val = fmod(-1.2, 21.0);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_42) {
  long double my_val = s21_fmod(-1.2, -0.01);
  long double test_val = fmod(-1.2, -0.01);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_43) {
  long double my_val = s21_fmod(-1.2, 0.01);
  long double test_val = fmod(-1.2, 0.01);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_44) {
  long double my_val = s21_fmod(-1.2, 21.9);
  long double test_val = fmod(-1.2, 21.9);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_45) {
  long double my_val = s21_fmod(-1.2, -21.9);
  long double test_val = fmod(-1.2, -21.9);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_46) {
  long double my_val = s21_fmod(-1.2, 1.79769313486231570e+308);
  long double test_val = fmod(-1.2, 1.79769313486231570e+308);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_47) {
  long double my_val = s21_fmod(-1.2, 2.2250738585072014E-308);
  long double test_val = fmod(-1.2, 2.2250738585072014E-308);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_48) {
  long double my_val = s21_fmod(-1.2, 21212121);
  long double test_val = fmod(-1.2, 21212121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_49) {
  long double my_val = s21_fmod(-1.2, -21212121);
  long double test_val = fmod(-1.2, -21212121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_50) {
  long double my_val = s21_fmod(-1.2, 21212121.2121);
  long double test_val = fmod(-1.2, 21212121.2121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_51) {
  long double my_val = s21_fmod(-1.2, -21212121.2121);
  long double test_val = fmod(-1.2, -21212121.2121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_52) {
  long double my_val = s21_fmod(-1.2, 0.21212121);
  long double test_val = fmod(-1.2, 0.21212121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_53) {
  long double my_val = s21_fmod(-1.2, -0.21212121);
  long double test_val = fmod(-1.2, -0.21212121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_54) {
  long double my_val = s21_fmod(1.2, 0.0);
  ck_assert_ldouble_nan(my_val);
}
END_TEST

START_TEST(test_55) {
  long double my_val = s21_fmod(1.2, -0.0);
  ck_assert_ldouble_nan(my_val);
}
END_TEST

START_TEST(test_56) {
  long double my_val = s21_fmod(1.2, -1.2);
  long double test_val = fmod(1.2, -1.2);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_57) {
  long double my_val = s21_fmod(1.2, 1.2);
  long double test_val = fmod(1.2, 1.2);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_58) {
  long double my_val = s21_fmod(1.2, -21.0);
  long double test_val = fmod(1.2, -21.0);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_59) {
  long double my_val = s21_fmod(1.2, 21.0);
  long double test_val = fmod(1.2, 21.0);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_60) {
  long double my_val = s21_fmod(1.2, -0.01);
  long double test_val = fmod(1.2, -0.01);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_61) {
  long double my_val = s21_fmod(1.2, 0.01);
  long double test_val = fmod(1.2, 0.01);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_62) {
  long double my_val = s21_fmod(1.2, 21.9);
  long double test_val = fmod(1.2, 21.9);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_63) {
  long double my_val = s21_fmod(1.2, -21.9);
  long double test_val = fmod(1.2, -21.9);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_64) {
  long double my_val = s21_fmod(1.2, 1.79769313486231570e+308);
  long double test_val = fmod(1.2, 1.79769313486231570e+308);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_65) {
  long double my_val = s21_fmod(1.2, 2.2250738585072014E-308);
  long double test_val = fmod(1.2, 2.2250738585072014E-308);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_66) {
  long double my_val = s21_fmod(1.2, 21212121);
  long double test_val = fmod(1.2, 21212121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_67) {
  long double my_val = s21_fmod(1.2, -21212121);
  long double test_val = fmod(1.2, -21212121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_68) {
  long double my_val = s21_fmod(1.2, 21212121.2121);
  long double test_val = fmod(1.2, 21212121.2121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_69) {
  long double my_val = s21_fmod(1.2, -21212121.2121);
  long double test_val = fmod(1.2, -21212121.2121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_70) {
  long double my_val = s21_fmod(1.2, 0.21212121);
  long double test_val = fmod(1.2, 0.21212121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_71) {
  long double my_val = s21_fmod(1.2, -0.21212121);
  long double test_val = fmod(1.2, -0.21212121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_72) {
  long double my_val = s21_fmod(-21.0, 0.0);
  ck_assert_ldouble_nan(my_val);
}
END_TEST

START_TEST(test_73) {
  long double my_val = s21_fmod(-21.0, -0.0);
  ck_assert_ldouble_nan(my_val);
}
END_TEST

START_TEST(test_74) {
  long double my_val = s21_fmod(-21.0, -1.2);
  long double test_val = fmod(-21.0, -1.2);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_75) {
  long double my_val = s21_fmod(-21.0, 1.2);
  long double test_val = fmod(-21.0, 1.2);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_76) {
  long double my_val = s21_fmod(-21.0, -21.0);
  long double test_val = fmod(-21.0, -21.0);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_77) {
  long double my_val = s21_fmod(-21.0, 21.0);
  long double test_val = fmod(-21.0, 21.0);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_78) {
  long double my_val = s21_fmod(-21.0, -0.01);
  long double test_val = fmod(-21.0, -0.01);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_79) {
  long double my_val = s21_fmod(-21.0, 0.01);
  long double test_val = fmod(-21.0, 0.01);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_80) {
  long double my_val = s21_fmod(-21.0, 21.9);
  long double test_val = fmod(-21.0, 21.9);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_81) {
  long double my_val = s21_fmod(-21.0, -21.9);
  long double test_val = fmod(-21.0, -21.9);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_82) {
  long double my_val = s21_fmod(-21.0, 1.79769313486231570e+308);
  long double test_val = fmod(-21.0, 1.79769313486231570e+308);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_83) {
  long double my_val = s21_fmod(-21.0, 2.2250738585072014E-308);
  long double test_val = fmod(-21.0, 2.2250738585072014E-308);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_84) {
  long double my_val = s21_fmod(-21.0, 21212121);
  long double test_val = fmod(-21.0, 21212121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_85) {
  long double my_val = s21_fmod(-21.0, -21212121);
  long double test_val = fmod(-21.0, -21212121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_86) {
  long double my_val = s21_fmod(-21.0, 21212121.2121);
  long double test_val = fmod(-21.0, 21212121.2121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_87) {
  long double my_val = s21_fmod(-21.0, -21212121.2121);
  long double test_val = fmod(-21.0, -21212121.2121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_88) {
  long double my_val = s21_fmod(-21.0, 0.21212121);
  long double test_val = fmod(-21.0, 0.21212121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_89) {
  long double my_val = s21_fmod(-21.0, -0.21212121);
  long double test_val = fmod(-21.0, -0.21212121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_90) {
  long double my_val = s21_fmod(21.0, 0.0);
  ck_assert_ldouble_nan(my_val);
}
END_TEST

START_TEST(test_91) {
  long double my_val = s21_fmod(21.0, -0.0);
  ck_assert_ldouble_nan(my_val);
}
END_TEST

START_TEST(test_92) {
  long double my_val = s21_fmod(21.0, -1.2);
  long double test_val = fmod(21.0, -1.2);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_93) {
  long double my_val = s21_fmod(21.0, 1.2);
  long double test_val = fmod(21.0, 1.2);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_94) {
  long double my_val = s21_fmod(21.0, -21.0);
  long double test_val = fmod(21.0, -21.0);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_95) {
  long double my_val = s21_fmod(21.0, 21.0);
  long double test_val = fmod(21.0, 21.0);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_96) {
  long double my_val = s21_fmod(21.0, -0.01);
  long double test_val = fmod(21.0, -0.01);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_97) {
  long double my_val = s21_fmod(21.0, 0.01);
  long double test_val = fmod(21.0, 0.01);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_98) {
  long double my_val = s21_fmod(21.0, 21.9);
  long double test_val = fmod(21.0, 21.9);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_99) {
  long double my_val = s21_fmod(21.0, -21.9);
  long double test_val = fmod(21.0, -21.9);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_100) {
  long double my_val = s21_fmod(21.0, 1.79769313486231570e+308);
  long double test_val = fmod(21.0, 1.79769313486231570e+308);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_101) {
  long double my_val = s21_fmod(21.0, 2.2250738585072014E-308);
  long double test_val = fmod(21.0, 2.2250738585072014E-308);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_102) {
  long double my_val = s21_fmod(21.0, 21212121);
  long double test_val = fmod(21.0, 21212121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_103) {
  long double my_val = s21_fmod(21.0, -21212121);
  long double test_val = fmod(21.0, -21212121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_104) {
  long double my_val = s21_fmod(21.0, 21212121.2121);
  long double test_val = fmod(21.0, 21212121.2121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_105) {
  long double my_val = s21_fmod(21.0, -21212121.2121);
  long double test_val = fmod(21.0, -21212121.2121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_106) {
  long double my_val = s21_fmod(21.0, 0.21212121);
  long double test_val = fmod(21.0, 0.21212121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_107) {
  long double my_val = s21_fmod(21.0, -0.21212121);
  long double test_val = fmod(21.0, -0.21212121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_108) {
  long double my_val = s21_fmod(-0.01, 0.0);
  ck_assert_ldouble_nan(my_val);
}
END_TEST

START_TEST(test_109) {
  long double my_val = s21_fmod(-0.01, -0.0);
  ck_assert_ldouble_nan(my_val);
}
END_TEST

START_TEST(test_110) {
  long double my_val = s21_fmod(-0.01, -1.2);
  long double test_val = fmod(-0.01, -1.2);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_111) {
  long double my_val = s21_fmod(-0.01, 1.2);
  long double test_val = fmod(-0.01, 1.2);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_112) {
  long double my_val = s21_fmod(-0.01, -21.0);
  long double test_val = fmod(-0.01, -21.0);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_113) {
  long double my_val = s21_fmod(-0.01, 21.0);
  long double test_val = fmod(-0.01, 21.0);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_114) {
  long double my_val = s21_fmod(-0.01, -0.01);
  long double test_val = fmod(-0.01, -0.01);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_115) {
  long double my_val = s21_fmod(-0.01, 0.01);
  long double test_val = fmod(-0.01, 0.01);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_116) {
  long double my_val = s21_fmod(-0.01, 21.9);
  long double test_val = fmod(-0.01, 21.9);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_117) {
  long double my_val = s21_fmod(-0.01, -21.9);
  long double test_val = fmod(-0.01, -21.9);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_118) {
  long double my_val = s21_fmod(-0.01, 1.79769313486231570e+308);
  long double test_val = fmod(-0.01, 1.79769313486231570e+308);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_119) {
  long double my_val = s21_fmod(-0.01, 2.2250738585072014E-308);
  long double test_val = fmod(-0.01, 2.2250738585072014E-308);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_120) {
  long double my_val = s21_fmod(-0.01, 21212121);
  long double test_val = fmod(-0.01, 21212121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_121) {
  long double my_val = s21_fmod(-0.01, -21212121);
  long double test_val = fmod(-0.01, -21212121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_122) {
  long double my_val = s21_fmod(-0.01, 21212121.2121);
  long double test_val = fmod(-0.01, 21212121.2121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_123) {
  long double my_val = s21_fmod(-0.01, -21212121.2121);
  long double test_val = fmod(-0.01, -21212121.2121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_124) {
  long double my_val = s21_fmod(-0.01, 0.21212121);
  long double test_val = fmod(-0.01, 0.21212121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_125) {
  long double my_val = s21_fmod(-0.01, -0.21212121);
  long double test_val = fmod(-0.01, -0.21212121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_126) {
  long double my_val = s21_fmod(0.01, 0.0);
  ck_assert_ldouble_nan(my_val);
}
END_TEST

START_TEST(test_127) {
  long double my_val = s21_fmod(0.01, -0.0);
  ck_assert_ldouble_nan(my_val);
}
END_TEST

START_TEST(test_128) {
  long double my_val = s21_fmod(0.01, -1.2);
  long double test_val = fmod(0.01, -1.2);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_129) {
  long double my_val = s21_fmod(0.01, 1.2);
  long double test_val = fmod(0.01, 1.2);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_130) {
  long double my_val = s21_fmod(0.01, -21.0);
  long double test_val = fmod(0.01, -21.0);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_131) {
  long double my_val = s21_fmod(0.01, 21.0);
  long double test_val = fmod(0.01, 21.0);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_132) {
  long double my_val = s21_fmod(0.01, -0.01);
  long double test_val = fmod(0.01, -0.01);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_133) {
  long double my_val = s21_fmod(0.01, 0.01);
  long double test_val = fmod(0.01, 0.01);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_134) {
  long double my_val = s21_fmod(0.01, 21.9);
  long double test_val = fmod(0.01, 21.9);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_135) {
  long double my_val = s21_fmod(0.01, -21.9);
  long double test_val = fmod(0.01, -21.9);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_136) {
  long double my_val = s21_fmod(0.01, 1.79769313486231570e+308);
  long double test_val = fmod(0.01, 1.79769313486231570e+308);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_137) {
  long double my_val = s21_fmod(0.01, 2.2250738585072014E-308);
  long double test_val = fmod(0.01, 2.2250738585072014E-308);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_138) {
  long double my_val = s21_fmod(0.01, 21212121);
  long double test_val = fmod(0.01, 21212121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_139) {
  long double my_val = s21_fmod(0.01, -21212121);
  long double test_val = fmod(0.01, -21212121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_140) {
  long double my_val = s21_fmod(0.01, 21212121.2121);
  long double test_val = fmod(0.01, 21212121.2121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_141) {
  long double my_val = s21_fmod(0.01, -21212121.2121);
  long double test_val = fmod(0.01, -21212121.2121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_142) {
  long double my_val = s21_fmod(0.01, 0.21212121);
  long double test_val = fmod(0.01, 0.21212121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_143) {
  long double my_val = s21_fmod(0.01, -0.21212121);
  long double test_val = fmod(0.01, -0.21212121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_144) {
  long double my_val = s21_fmod(21.9, 0.0);
  ck_assert_ldouble_nan(my_val);
}
END_TEST

START_TEST(test_145) {
  long double my_val = s21_fmod(21.9, -0.0);
  ck_assert_ldouble_nan(my_val);
}
END_TEST

START_TEST(test_146) {
  long double my_val = s21_fmod(21.9, -1.2);
  long double test_val = fmod(21.9, -1.2);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_147) {
  long double my_val = s21_fmod(21.9, 1.2);
  long double test_val = fmod(21.9, 1.2);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_148) {
  long double my_val = s21_fmod(21.9, -21.0);
  long double test_val = fmod(21.9, -21.0);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_149) {
  long double my_val = s21_fmod(21.9, 21.0);
  long double test_val = fmod(21.9, 21.0);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_150) {
  long double my_val = s21_fmod(21.9, -0.01);
  long double test_val = fmod(21.9, -0.01);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_151) {
  long double my_val = s21_fmod(21.9, 0.01);
  long double test_val = fmod(21.9, 0.01);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_152) {
  long double my_val = s21_fmod(21.9, 21.9);
  long double test_val = fmod(21.9, 21.9);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_153) {
  long double my_val = s21_fmod(21.9, -21.9);
  long double test_val = fmod(21.9, -21.9);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_154) {
  long double my_val = s21_fmod(21.9, 1.79769313486231570e+308);
  long double test_val = fmod(21.9, 1.79769313486231570e+308);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_155) {
  long double my_val = s21_fmod(21.9, 2.2250738585072014E-308);
  long double test_val = fmod(21.9, 2.2250738585072014E-308);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_156) {
  long double my_val = s21_fmod(21.9, 21212121);
  long double test_val = fmod(21.9, 21212121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_157) {
  long double my_val = s21_fmod(21.9, -21212121);
  long double test_val = fmod(21.9, -21212121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_158) {
  long double my_val = s21_fmod(21.9, 21212121.2121);
  long double test_val = fmod(21.9, 21212121.2121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_159) {
  long double my_val = s21_fmod(21.9, -21212121.2121);
  long double test_val = fmod(21.9, -21212121.2121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_160) {
  long double my_val = s21_fmod(21.9, 0.21212121);
  long double test_val = fmod(21.9, 0.21212121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_161) {
  long double my_val = s21_fmod(21.9, -0.21212121);
  long double test_val = fmod(21.9, -0.21212121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_162) {
  long double my_val = s21_fmod(-21.9, 0.0);
  ck_assert_ldouble_nan(my_val);
}
END_TEST

START_TEST(test_163) {
  long double my_val = s21_fmod(-21.9, -0.0);
  ck_assert_ldouble_nan(my_val);
}
END_TEST

START_TEST(test_164) {
  long double my_val = s21_fmod(-21.9, -1.2);
  long double test_val = fmod(-21.9, -1.2);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_165) {
  long double my_val = s21_fmod(-21.9, 1.2);
  long double test_val = fmod(-21.9, 1.2);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_166) {
  long double my_val = s21_fmod(-21.9, -21.0);
  long double test_val = fmod(-21.9, -21.0);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_167) {
  long double my_val = s21_fmod(-21.9, 21.0);
  long double test_val = fmod(-21.9, 21.0);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_168) {
  long double my_val = s21_fmod(-21.9, -0.01);
  long double test_val = fmod(-21.9, -0.01);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_169) {
  long double my_val = s21_fmod(-21.9, 0.01);
  long double test_val = fmod(-21.9, 0.01);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_170) {
  long double my_val = s21_fmod(-21.9, 21.9);
  long double test_val = fmod(-21.9, 21.9);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_171) {
  long double my_val = s21_fmod(-21.9, -21.9);
  long double test_val = fmod(-21.9, -21.9);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_172) {
  long double my_val = s21_fmod(-21.9, 1.79769313486231570e+308);
  long double test_val = fmod(-21.9, 1.79769313486231570e+308);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_173) {
  long double my_val = s21_fmod(-21.9, 2.2250738585072014E-308);
  long double test_val = fmod(-21.9, 2.2250738585072014E-308);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_174) {
  long double my_val = s21_fmod(-21.9, 21212121);
  long double test_val = fmod(-21.9, 21212121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_175) {
  long double my_val = s21_fmod(-21.9, -21212121);
  long double test_val = fmod(-21.9, -21212121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_176) {
  long double my_val = s21_fmod(-21.9, 21212121.2121);
  long double test_val = fmod(-21.9, 21212121.2121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_177) {
  long double my_val = s21_fmod(-21.9, -21212121.2121);
  long double test_val = fmod(-21.9, -21212121.2121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_178) {
  long double my_val = s21_fmod(-21.9, 0.21212121);
  long double test_val = fmod(-21.9, 0.21212121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_179) {
  long double my_val = s21_fmod(-21.9, -0.21212121);
  long double test_val = fmod(-21.9, -0.21212121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_180) {
  long double my_val = s21_fmod(1.79769313486231570e+308, 0.0);
  ck_assert_ldouble_nan(my_val);
}
END_TEST

START_TEST(test_181) {
  long double my_val = s21_fmod(1.79769313486231570e+308, -0.0);
  ck_assert_ldouble_nan(my_val);
}
END_TEST

START_TEST(test_182) {
  long double my_val = s21_fmod(1.79769313486231570e+308, -1.2);
  long double test_val = fmod(1.79769313486231570e+308, -1.2);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_183) {
  long double my_val = s21_fmod(1.79769313486231570e+308, 1.2);
  long double test_val = fmod(1.79769313486231570e+308, 1.2);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_184) {
  long double my_val = s21_fmod(1.79769313486231570e+308, -21.0);
  long double test_val = fmod(1.79769313486231570e+308, -21.0);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_185) {
  long double my_val = s21_fmod(1.79769313486231570e+308, 21.0);
  long double test_val = fmod(1.79769313486231570e+308, 21.0);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_186) {
  long double my_val = s21_fmod(1.79769313486231570e+308, -0.01);
  long double test_val = fmod(1.79769313486231570e+308, -0.01);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_187) {
  long double my_val = s21_fmod(1.79769313486231570e+308, 0.01);
  long double test_val = fmod(1.79769313486231570e+308, 0.01);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_188) {
  long double my_val = s21_fmod(1.79769313486231570e+308, 21.9);
  long double test_val = fmod(1.79769313486231570e+308, 21.9);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_189) {
  long double my_val = s21_fmod(1.79769313486231570e+308, -21.9);
  long double test_val = fmod(1.79769313486231570e+308, -21.9);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_190) {
  long double my_val =
      s21_fmod(1.79769313486231570e+308, 1.79769313486231570e+308);
  long double test_val =
      fmod(1.79769313486231570e+308, 1.79769313486231570e+308);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_191) {
  long double my_val =
      s21_fmod(1.79769313486231570e+308, 2.2250738585072014E-308);
  long double test_val =
      fmod(1.79769313486231570e+308, 2.2250738585072014E-308);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_192) {
  long double my_val = s21_fmod(1.79769313486231570e+308, 21212121);
  long double test_val = fmod(1.79769313486231570e+308, 21212121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_193) {
  long double my_val = s21_fmod(1.79769313486231570e+308, -21212121);
  long double test_val = fmod(1.79769313486231570e+308, -21212121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_194) {
  long double my_val = s21_fmod(1.79769313486231570e+308, 21212121.2121);
  long double test_val = fmod(1.79769313486231570e+308, 21212121.2121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_195) {
  long double my_val = s21_fmod(1.79769313486231570e+308, -21212121.2121);
  long double test_val = fmod(1.79769313486231570e+308, -21212121.2121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_196) {
  long double my_val = s21_fmod(1.79769313486231570e+308, 0.21212121);
  long double test_val = fmod(1.79769313486231570e+308, 0.21212121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_197) {
  long double my_val = s21_fmod(1.79769313486231570e+308, -0.21212121);
  long double test_val = fmod(1.79769313486231570e+308, -0.21212121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_198) {
  long double my_val = s21_fmod(2.2250738585072014E-308, 0.0);
  ck_assert_ldouble_nan(my_val);
}
END_TEST

START_TEST(test_199) {
  long double my_val = s21_fmod(2.2250738585072014E-308, -0.0);
  ck_assert_ldouble_nan(my_val);
}
END_TEST

START_TEST(test_200) {
  long double my_val = s21_fmod(2.2250738585072014E-308, -1.2);
  long double test_val = fmod(2.2250738585072014E-308, -1.2);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_201) {
  long double my_val = s21_fmod(2.2250738585072014E-308, 1.2);
  long double test_val = fmod(2.2250738585072014E-308, 1.2);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_202) {
  long double my_val = s21_fmod(2.2250738585072014E-308, -21.0);
  long double test_val = fmod(2.2250738585072014E-308, -21.0);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_203) {
  long double my_val = s21_fmod(2.2250738585072014E-308, 21.0);
  long double test_val = fmod(2.2250738585072014E-308, 21.0);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_204) {
  long double my_val = s21_fmod(2.2250738585072014E-308, -0.01);
  long double test_val = fmod(2.2250738585072014E-308, -0.01);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_205) {
  long double my_val = s21_fmod(2.2250738585072014E-308, 0.01);
  long double test_val = fmod(2.2250738585072014E-308, 0.01);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_206) {
  long double my_val = s21_fmod(2.2250738585072014E-308, 21.9);
  long double test_val = fmod(2.2250738585072014E-308, 21.9);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_207) {
  long double my_val = s21_fmod(2.2250738585072014E-308, -21.9);
  long double test_val = fmod(2.2250738585072014E-308, -21.9);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_208) {
  long double my_val =
      s21_fmod(2.2250738585072014E-308, 1.79769313486231570e+308);
  long double test_val =
      fmod(2.2250738585072014E-308, 1.79769313486231570e+308);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_209) {
  long double my_val =
      s21_fmod(2.2250738585072014E-308, 2.2250738585072014E-308);
  long double test_val = fmod(2.2250738585072014E-308, 2.2250738585072014E-308);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_210) {
  long double my_val = s21_fmod(2.2250738585072014E-308, 21212121);
  long double test_val = fmod(2.2250738585072014E-308, 21212121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_211) {
  long double my_val = s21_fmod(2.2250738585072014E-308, -21212121);
  long double test_val = fmod(2.2250738585072014E-308, -21212121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_212) {
  long double my_val = s21_fmod(2.2250738585072014E-308, 21212121.2121);
  long double test_val = fmod(2.2250738585072014E-308, 21212121.2121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_213) {
  long double my_val = s21_fmod(2.2250738585072014E-308, -21212121.2121);
  long double test_val = fmod(2.2250738585072014E-308, -21212121.2121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_214) {
  long double my_val = s21_fmod(2.2250738585072014E-308, 0.21212121);
  long double test_val = fmod(2.2250738585072014E-308, 0.21212121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_215) {
  long double my_val = s21_fmod(2.2250738585072014E-308, -0.21212121);
  long double test_val = fmod(2.2250738585072014E-308, -0.21212121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_216) {
  long double my_val = s21_fmod(21212121, 0.0);
  ck_assert_ldouble_nan(my_val);
}
END_TEST

START_TEST(test_217) {
  long double my_val = s21_fmod(21212121, -0.0);
  ck_assert_ldouble_nan(my_val);
}
END_TEST

START_TEST(test_218) {
  long double my_val = s21_fmod(21212121, -1.2);
  long double test_val = fmod(21212121, -1.2);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_219) {
  long double my_val = s21_fmod(21212121, 1.2);
  long double test_val = fmod(21212121, 1.2);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_220) {
  long double my_val = s21_fmod(21212121, -21.0);
  long double test_val = fmod(21212121, -21.0);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_221) {
  long double my_val = s21_fmod(21212121, 21.0);
  long double test_val = fmod(21212121, 21.0);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_222) {
  long double my_val = s21_fmod(21212121, -0.01);
  long double test_val = fmod(21212121, -0.01);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_223) {
  long double my_val = s21_fmod(21212121, 0.01);
  long double test_val = fmod(21212121, 0.01);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_224) {
  long double my_val = s21_fmod(21212121, 21.9);
  long double test_val = fmod(21212121, 21.9);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_225) {
  long double my_val = s21_fmod(21212121, -21.9);
  long double test_val = fmod(21212121, -21.9);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_226) {
  long double my_val = s21_fmod(21212121, 1.79769313486231570e+308);
  long double test_val = fmod(21212121, 1.79769313486231570e+308);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_227) {
  long double my_val = s21_fmod(21212121, 2.2250738585072014E-308);
  long double test_val = fmod(21212121, 2.2250738585072014E-308);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_228) {
  long double my_val = s21_fmod(21212121, 21212121);
  long double test_val = fmod(21212121, 21212121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_229) {
  long double my_val = s21_fmod(21212121, -21212121);
  long double test_val = fmod(21212121, -21212121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_230) {
  long double my_val = s21_fmod(21212121, 21212121.2121);
  long double test_val = fmod(21212121, 21212121.2121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_231) {
  long double my_val = s21_fmod(21212121, -21212121.2121);
  long double test_val = fmod(21212121, -21212121.2121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_232) {
  long double my_val = s21_fmod(21212121, 0.21212121);
  long double test_val = fmod(21212121, 0.21212121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_233) {
  long double my_val = s21_fmod(21212121, -0.21212121);
  long double test_val = fmod(21212121, -0.21212121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_234) {
  long double my_val = s21_fmod(-21212121, 0.0);
  ck_assert_ldouble_nan(my_val);
}
END_TEST

START_TEST(test_235) {
  long double my_val = s21_fmod(-21212121, -0.0);
  ck_assert_ldouble_nan(my_val);
}
END_TEST

START_TEST(test_236) {
  long double my_val = s21_fmod(-21212121, -1.2);
  long double test_val = fmod(-21212121, -1.2);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_237) {
  long double my_val = s21_fmod(-21212121, 1.2);
  long double test_val = fmod(-21212121, 1.2);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_238) {
  long double my_val = s21_fmod(-21212121, -21.0);
  long double test_val = fmod(-21212121, -21.0);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_239) {
  long double my_val = s21_fmod(-21212121, 21.0);
  long double test_val = fmod(-21212121, 21.0);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_240) {
  long double my_val = s21_fmod(-21212121, -0.01);
  long double test_val = fmod(-21212121, -0.01);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_241) {
  long double my_val = s21_fmod(-21212121, 0.01);
  long double test_val = fmod(-21212121, 0.01);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_242) {
  long double my_val = s21_fmod(-21212121, 21.9);
  long double test_val = fmod(-21212121, 21.9);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_243) {
  long double my_val = s21_fmod(-21212121, -21.9);
  long double test_val = fmod(-21212121, -21.9);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_244) {
  long double my_val = s21_fmod(-21212121, 1.79769313486231570e+308);
  long double test_val = fmod(-21212121, 1.79769313486231570e+308);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_245) {
  long double my_val = s21_fmod(-21212121, 2.2250738585072014E-308);
  long double test_val = fmod(-21212121, 2.2250738585072014E-308);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_246) {
  long double my_val = s21_fmod(-21212121, 21212121);
  long double test_val = fmod(-21212121, 21212121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_247) {
  long double my_val = s21_fmod(-21212121, -21212121);
  long double test_val = fmod(-21212121, -21212121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_248) {
  long double my_val = s21_fmod(-21212121, 21212121.2121);
  long double test_val = fmod(-21212121, 21212121.2121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_249) {
  long double my_val = s21_fmod(-21212121, -21212121.2121);
  long double test_val = fmod(-21212121, -21212121.2121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_250) {
  long double my_val = s21_fmod(-21212121, 0.21212121);
  long double test_val = fmod(-21212121, 0.21212121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_251) {
  long double my_val = s21_fmod(-21212121, -0.21212121);
  long double test_val = fmod(-21212121, -0.21212121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_252) {
  long double my_val = s21_fmod(21212121.2121, 0.0);
  ck_assert_ldouble_nan(my_val);
}
END_TEST

START_TEST(test_253) {
  long double my_val = s21_fmod(21212121.2121, -0.0);
  ck_assert_ldouble_nan(my_val);
}
END_TEST

START_TEST(test_254) {
  long double my_val = s21_fmod(21212121.2121, -1.2);
  long double test_val = fmod(21212121.2121, -1.2);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_255) {
  long double my_val = s21_fmod(21212121.2121, 1.2);
  long double test_val = fmod(21212121.2121, 1.2);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_256) {
  long double my_val = s21_fmod(21212121.2121, -21.0);
  long double test_val = fmod(21212121.2121, -21.0);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_257) {
  long double my_val = s21_fmod(21212121.2121, 21.0);
  long double test_val = fmod(21212121.2121, 21.0);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_258) {
  long double my_val = s21_fmod(21212121.2121, -0.01);
  long double test_val = fmod(21212121.2121, -0.01);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_259) {
  long double my_val = s21_fmod(21212121.2121, 0.01);
  long double test_val = fmod(21212121.2121, 0.01);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_260) {
  long double my_val = s21_fmod(21212121.2121, 21.9);
  long double test_val = fmod(21212121.2121, 21.9);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_261) {
  long double my_val = s21_fmod(21212121.2121, -21.9);
  long double test_val = fmod(21212121.2121, -21.9);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_262) {
  long double my_val = s21_fmod(21212121.2121, 1.79769313486231570e+308);
  long double test_val = fmod(21212121.2121, 1.79769313486231570e+308);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_263) {
  long double my_val = s21_fmod(21212121.2121, 2.2250738585072014E-308);
  long double test_val = fmod(21212121.2121, 2.2250738585072014E-308);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_264) {
  long double my_val = s21_fmod(21212121.2121, 21212121);
  long double test_val = fmod(21212121.2121, 21212121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_265) {
  long double my_val = s21_fmod(21212121.2121, -21212121);
  long double test_val = fmod(21212121.2121, -21212121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_266) {
  long double my_val = s21_fmod(21212121.2121, 21212121.2121);
  long double test_val = fmod(21212121.2121, 21212121.2121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_267) {
  long double my_val = s21_fmod(21212121.2121, -21212121.2121);
  long double test_val = fmod(21212121.2121, -21212121.2121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_268) {
  long double my_val = s21_fmod(21212121.2121, 0.21212121);
  long double test_val = fmod(21212121.2121, 0.21212121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_269) {
  long double my_val = s21_fmod(21212121.2121, -0.21212121);
  long double test_val = fmod(21212121.2121, -0.21212121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_270) {
  long double my_val = s21_fmod(-21212121.2121, 0.0);
  ck_assert_ldouble_nan(my_val);
}
END_TEST

START_TEST(test_271) {
  long double my_val = s21_fmod(-21212121.2121, -0.0);
  ck_assert_ldouble_nan(my_val);
}
END_TEST

START_TEST(test_272) {
  long double my_val = s21_fmod(-21212121.2121, -1.2);
  long double test_val = fmod(-21212121.2121, -1.2);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_273) {
  long double my_val = s21_fmod(-21212121.2121, 1.2);
  long double test_val = fmod(-21212121.2121, 1.2);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_274) {
  long double my_val = s21_fmod(-21212121.2121, -21.0);
  long double test_val = fmod(-21212121.2121, -21.0);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_275) {
  long double my_val = s21_fmod(-21212121.2121, 21.0);
  long double test_val = fmod(-21212121.2121, 21.0);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_276) {
  long double my_val = s21_fmod(-21212121.2121, -0.01);
  long double test_val = fmod(-21212121.2121, -0.01);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_277) {
  long double my_val = s21_fmod(-21212121.2121, 0.01);
  long double test_val = fmod(-21212121.2121, 0.01);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_278) {
  long double my_val = s21_fmod(-21212121.2121, 21.9);
  long double test_val = fmod(-21212121.2121, 21.9);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_279) {
  long double my_val = s21_fmod(-21212121.2121, -21.9);
  long double test_val = fmod(-21212121.2121, -21.9);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_280) {
  long double my_val = s21_fmod(-21212121.2121, 1.79769313486231570e+308);
  long double test_val = fmod(-21212121.2121, 1.79769313486231570e+308);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_281) {
  long double my_val = s21_fmod(-21212121.2121, 2.2250738585072014E-308);
  long double test_val = fmod(-21212121.2121, 2.2250738585072014E-308);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_282) {
  long double my_val = s21_fmod(-21212121.2121, 21212121);
  long double test_val = fmod(-21212121.2121, 21212121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_283) {
  long double my_val = s21_fmod(-21212121.2121, -21212121);
  long double test_val = fmod(-21212121.2121, -21212121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_284) {
  long double my_val = s21_fmod(-21212121.2121, 21212121.2121);
  long double test_val = fmod(-21212121.2121, 21212121.2121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_285) {
  long double my_val = s21_fmod(-21212121.2121, -21212121.2121);
  long double test_val = fmod(-21212121.2121, -21212121.2121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_286) {
  long double my_val = s21_fmod(-21212121.2121, 0.21212121);
  long double test_val = fmod(-21212121.2121, 0.21212121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_287) {
  long double my_val = s21_fmod(-21212121.2121, -0.21212121);
  long double test_val = fmod(-21212121.2121, -0.21212121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_288) {
  long double my_val = s21_fmod(0.21212121, 0.0);
  ck_assert_ldouble_nan(my_val);
}
END_TEST

START_TEST(test_289) {
  long double my_val = s21_fmod(0.21212121, -0.0);
  ck_assert_ldouble_nan(my_val);
}
END_TEST

START_TEST(test_290) {
  long double my_val = s21_fmod(0.21212121, -1.2);
  long double test_val = fmod(0.21212121, -1.2);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_291) {
  long double my_val = s21_fmod(0.21212121, 1.2);
  long double test_val = fmod(0.21212121, 1.2);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_292) {
  long double my_val = s21_fmod(0.21212121, -21.0);
  long double test_val = fmod(0.21212121, -21.0);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_293) {
  long double my_val = s21_fmod(0.21212121, 21.0);
  long double test_val = fmod(0.21212121, 21.0);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_294) {
  long double my_val = s21_fmod(0.21212121, -0.01);
  long double test_val = fmod(0.21212121, -0.01);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_295) {
  long double my_val = s21_fmod(0.21212121, 0.01);
  long double test_val = fmod(0.21212121, 0.01);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_296) {
  long double my_val = s21_fmod(0.21212121, 21.9);
  long double test_val = fmod(0.21212121, 21.9);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_297) {
  long double my_val = s21_fmod(0.21212121, -21.9);
  long double test_val = fmod(0.21212121, -21.9);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_298) {
  long double my_val = s21_fmod(0.21212121, 1.79769313486231570e+308);
  long double test_val = fmod(0.21212121, 1.79769313486231570e+308);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_299) {
  long double my_val = s21_fmod(0.21212121, 2.2250738585072014E-308);
  long double test_val = fmod(0.21212121, 2.2250738585072014E-308);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_300) {
  long double my_val = s21_fmod(0.21212121, 21212121);
  long double test_val = fmod(0.21212121, 21212121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_301) {
  long double my_val = s21_fmod(0.21212121, -21212121);
  long double test_val = fmod(0.21212121, -21212121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_302) {
  long double my_val = s21_fmod(0.21212121, 21212121.2121);
  long double test_val = fmod(0.21212121, 21212121.2121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_303) {
  long double my_val = s21_fmod(0.21212121, -21212121.2121);
  long double test_val = fmod(0.21212121, -21212121.2121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_304) {
  long double my_val = s21_fmod(0.21212121, 0.21212121);
  long double test_val = fmod(0.21212121, 0.21212121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_305) {
  long double my_val = s21_fmod(0.21212121, -0.21212121);
  long double test_val = fmod(0.21212121, -0.21212121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_306) {
  long double my_val = s21_fmod(-0.21212121, 0.0);
  ck_assert_ldouble_nan(my_val);
}
END_TEST

START_TEST(test_307) {
  long double my_val = s21_fmod(-0.21212121, -0.0);
  ck_assert_ldouble_nan(my_val);
}
END_TEST

START_TEST(test_308) {
  long double my_val = s21_fmod(-0.21212121, -1.2);
  long double test_val = fmod(-0.21212121, -1.2);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_309) {
  long double my_val = s21_fmod(-0.21212121, 1.2);
  long double test_val = fmod(-0.21212121, 1.2);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_310) {
  long double my_val = s21_fmod(-0.21212121, -21.0);
  long double test_val = fmod(-0.21212121, -21.0);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_311) {
  long double my_val = s21_fmod(-0.21212121, 21.0);
  long double test_val = fmod(-0.21212121, 21.0);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_312) {
  long double my_val = s21_fmod(-0.21212121, -0.01);
  long double test_val = fmod(-0.21212121, -0.01);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_313) {
  long double my_val = s21_fmod(-0.21212121, 0.01);
  long double test_val = fmod(-0.21212121, 0.01);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_314) {
  long double my_val = s21_fmod(-0.21212121, 21.9);
  long double test_val = fmod(-0.21212121, 21.9);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_315) {
  long double my_val = s21_fmod(-0.21212121, -21.9);
  long double test_val = fmod(-0.21212121, -21.9);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_316) {
  long double my_val = s21_fmod(-0.21212121, 1.79769313486231570e+308);
  long double test_val = fmod(-0.21212121, 1.79769313486231570e+308);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_317) {
  long double my_val = s21_fmod(-0.21212121, 2.2250738585072014E-308);
  long double test_val = fmod(-0.21212121, 2.2250738585072014E-308);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_318) {
  long double my_val = s21_fmod(-0.21212121, 21212121);
  long double test_val = fmod(-0.21212121, 21212121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_319) {
  long double my_val = s21_fmod(-0.21212121, -21212121);
  long double test_val = fmod(-0.21212121, -21212121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_320) {
  long double my_val = s21_fmod(-0.21212121, 21212121.2121);
  long double test_val = fmod(-0.21212121, 21212121.2121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_321) {
  long double my_val = s21_fmod(-0.21212121, -21212121.2121);
  long double test_val = fmod(-0.21212121, -21212121.2121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_322) {
  long double my_val = s21_fmod(-0.21212121, 0.21212121);
  long double test_val = fmod(-0.21212121, 0.21212121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

START_TEST(test_323) {
  long double my_val = s21_fmod(-0.21212121, -0.21212121);
  long double test_val = fmod(-0.21212121, -0.21212121);
  ck_assert_ldouble_eq(my_val, test_val);
}
END_TEST

Suite *s21_fmod_suite(void) {
  Suite *s = suite_create("s21_fmod_test");
  TCase *tc = tcase_create("[s21_fmod] case");
  tcase_add_test(tc, test_0);
  tcase_add_test(tc, test_1);
  tcase_add_test(tc, test_2);
  tcase_add_test(tc, test_3);
  tcase_add_test(tc, test_4);
  tcase_add_test(tc, test_5);
  tcase_add_test(tc, test_6);
  tcase_add_test(tc, test_7);
  tcase_add_test(tc, test_8);
  tcase_add_test(tc, test_9);
  tcase_add_test(tc, test_10);
  tcase_add_test(tc, test_11);
  tcase_add_test(tc, test_12);
  tcase_add_test(tc, test_13);
  tcase_add_test(tc, test_14);
  tcase_add_test(tc, test_15);
  tcase_add_test(tc, test_16);
  tcase_add_test(tc, test_17);
  tcase_add_test(tc, test_18);
  tcase_add_test(tc, test_19);
  tcase_add_test(tc, test_20);
  tcase_add_test(tc, test_21);
  tcase_add_test(tc, test_22);
  tcase_add_test(tc, test_23);
  tcase_add_test(tc, test_24);
  tcase_add_test(tc, test_25);
  tcase_add_test(tc, test_26);
  tcase_add_test(tc, test_27);
  tcase_add_test(tc, test_28);
  tcase_add_test(tc, test_29);
  tcase_add_test(tc, test_30);
  tcase_add_test(tc, test_31);
  tcase_add_test(tc, test_32);
  tcase_add_test(tc, test_33);
  tcase_add_test(tc, test_34);
  tcase_add_test(tc, test_35);
  tcase_add_test(tc, test_36);
  tcase_add_test(tc, test_37);
  tcase_add_test(tc, test_38);
  tcase_add_test(tc, test_39);
  tcase_add_test(tc, test_40);
  tcase_add_test(tc, test_41);
  tcase_add_test(tc, test_42);
  tcase_add_test(tc, test_43);
  tcase_add_test(tc, test_44);
  tcase_add_test(tc, test_45);
  tcase_add_test(tc, test_46);
  tcase_add_test(tc, test_47);
  tcase_add_test(tc, test_48);
  tcase_add_test(tc, test_49);
  tcase_add_test(tc, test_50);
  tcase_add_test(tc, test_51);
  tcase_add_test(tc, test_52);
  tcase_add_test(tc, test_53);
  tcase_add_test(tc, test_54);
  tcase_add_test(tc, test_55);
  tcase_add_test(tc, test_56);
  tcase_add_test(tc, test_57);
  tcase_add_test(tc, test_58);
  tcase_add_test(tc, test_59);
  tcase_add_test(tc, test_60);
  tcase_add_test(tc, test_61);
  tcase_add_test(tc, test_62);
  tcase_add_test(tc, test_63);
  tcase_add_test(tc, test_64);
  tcase_add_test(tc, test_65);
  tcase_add_test(tc, test_66);
  tcase_add_test(tc, test_67);
  tcase_add_test(tc, test_68);
  tcase_add_test(tc, test_69);
  tcase_add_test(tc, test_70);
  tcase_add_test(tc, test_71);
  tcase_add_test(tc, test_72);
  tcase_add_test(tc, test_73);
  tcase_add_test(tc, test_74);
  tcase_add_test(tc, test_75);
  tcase_add_test(tc, test_76);
  tcase_add_test(tc, test_77);
  tcase_add_test(tc, test_78);
  tcase_add_test(tc, test_79);
  tcase_add_test(tc, test_80);
  tcase_add_test(tc, test_81);
  tcase_add_test(tc, test_82);
  tcase_add_test(tc, test_83);
  tcase_add_test(tc, test_84);
  tcase_add_test(tc, test_85);
  tcase_add_test(tc, test_86);
  tcase_add_test(tc, test_87);
  tcase_add_test(tc, test_88);
  tcase_add_test(tc, test_89);
  tcase_add_test(tc, test_90);
  tcase_add_test(tc, test_91);
  tcase_add_test(tc, test_92);
  tcase_add_test(tc, test_93);
  tcase_add_test(tc, test_94);
  tcase_add_test(tc, test_95);
  tcase_add_test(tc, test_96);
  tcase_add_test(tc, test_97);
  tcase_add_test(tc, test_98);
  tcase_add_test(tc, test_99);
  tcase_add_test(tc, test_100);
  tcase_add_test(tc, test_101);
  tcase_add_test(tc, test_102);
  tcase_add_test(tc, test_103);
  tcase_add_test(tc, test_104);
  tcase_add_test(tc, test_105);
  tcase_add_test(tc, test_106);
  tcase_add_test(tc, test_107);
  tcase_add_test(tc, test_108);
  tcase_add_test(tc, test_109);
  tcase_add_test(tc, test_110);
  tcase_add_test(tc, test_111);
  tcase_add_test(tc, test_112);
  tcase_add_test(tc, test_113);
  tcase_add_test(tc, test_114);
  tcase_add_test(tc, test_115);
  tcase_add_test(tc, test_116);
  tcase_add_test(tc, test_117);
  tcase_add_test(tc, test_118);
  tcase_add_test(tc, test_119);
  tcase_add_test(tc, test_120);
  tcase_add_test(tc, test_121);
  tcase_add_test(tc, test_122);
  tcase_add_test(tc, test_123);
  tcase_add_test(tc, test_124);
  tcase_add_test(tc, test_125);
  tcase_add_test(tc, test_126);
  tcase_add_test(tc, test_127);
  tcase_add_test(tc, test_128);
  tcase_add_test(tc, test_129);
  tcase_add_test(tc, test_130);
  tcase_add_test(tc, test_131);
  tcase_add_test(tc, test_132);
  tcase_add_test(tc, test_133);
  tcase_add_test(tc, test_134);
  tcase_add_test(tc, test_135);
  tcase_add_test(tc, test_136);
  tcase_add_test(tc, test_137);
  tcase_add_test(tc, test_138);
  tcase_add_test(tc, test_139);
  tcase_add_test(tc, test_140);
  tcase_add_test(tc, test_141);
  tcase_add_test(tc, test_142);
  tcase_add_test(tc, test_143);
  tcase_add_test(tc, test_144);
  tcase_add_test(tc, test_145);
  tcase_add_test(tc, test_146);
  tcase_add_test(tc, test_147);
  tcase_add_test(tc, test_148);
  tcase_add_test(tc, test_149);
  tcase_add_test(tc, test_150);
  tcase_add_test(tc, test_151);
  tcase_add_test(tc, test_152);
  tcase_add_test(tc, test_153);
  tcase_add_test(tc, test_154);
  tcase_add_test(tc, test_155);
  tcase_add_test(tc, test_156);
  tcase_add_test(tc, test_157);
  tcase_add_test(tc, test_158);
  tcase_add_test(tc, test_159);
  tcase_add_test(tc, test_160);
  tcase_add_test(tc, test_161);
  tcase_add_test(tc, test_162);
  tcase_add_test(tc, test_163);
  tcase_add_test(tc, test_164);
  tcase_add_test(tc, test_165);
  tcase_add_test(tc, test_166);
  tcase_add_test(tc, test_167);
  tcase_add_test(tc, test_168);
  tcase_add_test(tc, test_169);
  tcase_add_test(tc, test_170);
  tcase_add_test(tc, test_171);
  tcase_add_test(tc, test_172);
  tcase_add_test(tc, test_173);
  tcase_add_test(tc, test_174);
  tcase_add_test(tc, test_175);
  tcase_add_test(tc, test_176);
  tcase_add_test(tc, test_177);
  tcase_add_test(tc, test_178);
  tcase_add_test(tc, test_179);
  tcase_add_test(tc, test_180);
  tcase_add_test(tc, test_181);
  tcase_add_test(tc, test_182);
  tcase_add_test(tc, test_183);
  tcase_add_test(tc, test_184);
  tcase_add_test(tc, test_185);
  tcase_add_test(tc, test_186);
  tcase_add_test(tc, test_187);
  tcase_add_test(tc, test_188);
  tcase_add_test(tc, test_189);
  tcase_add_test(tc, test_190);
  tcase_add_test(tc, test_191);
  tcase_add_test(tc, test_192);
  tcase_add_test(tc, test_193);
  tcase_add_test(tc, test_194);
  tcase_add_test(tc, test_195);
  tcase_add_test(tc, test_196);
  tcase_add_test(tc, test_197);
  tcase_add_test(tc, test_198);
  tcase_add_test(tc, test_199);
  tcase_add_test(tc, test_200);
  tcase_add_test(tc, test_201);
  tcase_add_test(tc, test_202);
  tcase_add_test(tc, test_203);
  tcase_add_test(tc, test_204);
  tcase_add_test(tc, test_205);
  tcase_add_test(tc, test_206);
  tcase_add_test(tc, test_207);
  tcase_add_test(tc, test_208);
  tcase_add_test(tc, test_209);
  tcase_add_test(tc, test_210);
  tcase_add_test(tc, test_211);
  tcase_add_test(tc, test_212);
  tcase_add_test(tc, test_213);
  tcase_add_test(tc, test_214);
  tcase_add_test(tc, test_215);
  tcase_add_test(tc, test_216);
  tcase_add_test(tc, test_217);
  tcase_add_test(tc, test_218);
  tcase_add_test(tc, test_219);
  tcase_add_test(tc, test_220);
  tcase_add_test(tc, test_221);
  tcase_add_test(tc, test_222);
  tcase_add_test(tc, test_223);
  tcase_add_test(tc, test_224);
  tcase_add_test(tc, test_225);
  tcase_add_test(tc, test_226);
  tcase_add_test(tc, test_227);
  tcase_add_test(tc, test_228);
  tcase_add_test(tc, test_229);
  tcase_add_test(tc, test_230);
  tcase_add_test(tc, test_231);
  tcase_add_test(tc, test_232);
  tcase_add_test(tc, test_233);
  tcase_add_test(tc, test_234);
  tcase_add_test(tc, test_235);
  tcase_add_test(tc, test_236);
  tcase_add_test(tc, test_237);
  tcase_add_test(tc, test_238);
  tcase_add_test(tc, test_239);
  tcase_add_test(tc, test_240);
  tcase_add_test(tc, test_241);
  tcase_add_test(tc, test_242);
  tcase_add_test(tc, test_243);
  tcase_add_test(tc, test_244);
  tcase_add_test(tc, test_245);
  tcase_add_test(tc, test_246);
  tcase_add_test(tc, test_247);
  tcase_add_test(tc, test_248);
  tcase_add_test(tc, test_249);
  tcase_add_test(tc, test_250);
  tcase_add_test(tc, test_251);
  tcase_add_test(tc, test_252);
  tcase_add_test(tc, test_253);
  tcase_add_test(tc, test_254);
  tcase_add_test(tc, test_255);
  tcase_add_test(tc, test_256);
  tcase_add_test(tc, test_257);
  tcase_add_test(tc, test_258);
  tcase_add_test(tc, test_259);
  tcase_add_test(tc, test_260);
  tcase_add_test(tc, test_261);
  tcase_add_test(tc, test_262);
  tcase_add_test(tc, test_263);
  tcase_add_test(tc, test_264);
  tcase_add_test(tc, test_265);
  tcase_add_test(tc, test_266);
  tcase_add_test(tc, test_267);
  tcase_add_test(tc, test_268);
  tcase_add_test(tc, test_269);
  tcase_add_test(tc, test_270);
  tcase_add_test(tc, test_271);
  tcase_add_test(tc, test_272);
  tcase_add_test(tc, test_273);
  tcase_add_test(tc, test_274);
  tcase_add_test(tc, test_275);
  tcase_add_test(tc, test_276);
  tcase_add_test(tc, test_277);
  tcase_add_test(tc, test_278);
  tcase_add_test(tc, test_279);
  tcase_add_test(tc, test_280);
  tcase_add_test(tc, test_281);
  tcase_add_test(tc, test_282);
  tcase_add_test(tc, test_283);
  tcase_add_test(tc, test_284);
  tcase_add_test(tc, test_285);
  tcase_add_test(tc, test_286);
  tcase_add_test(tc, test_287);
  tcase_add_test(tc, test_288);
  tcase_add_test(tc, test_289);
  tcase_add_test(tc, test_290);
  tcase_add_test(tc, test_291);
  tcase_add_test(tc, test_292);
  tcase_add_test(tc, test_293);
  tcase_add_test(tc, test_294);
  tcase_add_test(tc, test_295);
  tcase_add_test(tc, test_296);
  tcase_add_test(tc, test_297);
  tcase_add_test(tc, test_298);
  tcase_add_test(tc, test_299);
  tcase_add_test(tc, test_300);
  tcase_add_test(tc, test_301);
  tcase_add_test(tc, test_302);
  tcase_add_test(tc, test_303);
  tcase_add_test(tc, test_304);
  tcase_add_test(tc, test_305);
  tcase_add_test(tc, test_306);
  tcase_add_test(tc, test_307);
  tcase_add_test(tc, test_308);
  tcase_add_test(tc, test_309);
  tcase_add_test(tc, test_310);
  tcase_add_test(tc, test_311);
  tcase_add_test(tc, test_312);
  tcase_add_test(tc, test_313);
  tcase_add_test(tc, test_314);
  tcase_add_test(tc, test_315);
  tcase_add_test(tc, test_316);
  tcase_add_test(tc, test_317);
  tcase_add_test(tc, test_318);
  tcase_add_test(tc, test_319);
  tcase_add_test(tc, test_320);
  tcase_add_test(tc, test_321);
  tcase_add_test(tc, test_322);
  tcase_add_test(tc, test_323);
  suite_add_tcase(s, tc);

  tcase_set_timeout(tc, 100);
  return s;
}
