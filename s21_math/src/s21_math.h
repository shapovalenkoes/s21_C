#ifndef S21_MATH_H
#define S21_MATH_H

#define S21_M_PI 3.141592653589793238462643383279502884
#define S21_M_PI_2 1.570796326794896619231321691639751442
#define S21_M_PI_4 0.785398163397448309615660845819875721
#define S21_M_E 2.718281828459045235360287471352662498
#define S21_LN10 2.302585092994045684017991454684364208
#define S21_LN2 0.693147180559945309417232121458176568
#define S21_INF 1 / 0.0
#define S21_MIN_INF -1 / 0.0
#define S21_EPS 1e-12
#define S21_NAN (__builtin_nanf(""))
#define S21_ISNAN(x) (x != x)
#define S21_ISINF(x) ((x == S21_INF) || (x == S21_MIN_INF))
#define S21_LDBL_MAX 1.7976931348623158e+308

// -- For work with ceil, floor, fmod --
// Work with double bits.
#define BIAS 1023
#define ONES_MASK ~0
#define BITS_1x11 0x7ff
#define SIGN_LEN 1
#define EXP_LEN 11
#define SIGNIFICANT_LEN 52
// Logic operators.
#define S21_TRUE 21
#define S21_FALSE 0
//--------------------------------------

int s21_abs(int x);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_ceil(double x);
long double s21_cos(double x);
long double s21_exp(double x);
long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_log(double x);
long double s21_pow(double base, double exp);
long double s21_sin(double x);
long double s21_sqrt(double x);
long double s21_tan(double x);

#endif
