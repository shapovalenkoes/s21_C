#include "s21_math.h"

long double s21_atan(double x) {
  int sta = 0, cnt = 0;
  double x2, a;
  if (x < 0.F) {
    x = -x;
    sta |= 1;
  }
  if (x > 1) {
    x = 1.F / x;
    sta |= 2;
  }
  while (x > S21_M_PI / 12) {
    cnt++;
    a = x + s21_sqrt(3);
    a = 1.F / a;
    x *= s21_sqrt(3);
    x -= 1.F;
    x *= a;
  }
  x2 = x * x;
  a = x2 + 1.4087812F;
  a = 0.55913709F / a;
  a += 0.60310579F;
  a -= 0.05160454F * x2;
  a *= x;
  while (cnt > 0) {
    a += S21_M_PI / 6;
    cnt--;
  }
  if (sta & 2) a = S21_M_PI_2 - a;
  if (sta & 1) a = -a;
  return a;
}
