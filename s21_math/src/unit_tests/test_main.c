#include "test_main.h"

int main(void) {
  Suite *test_suites[] = {
      s21_abs_suite(),  s21_fabs_suite(), s21_sqrt_suite(), s21_pow_suite(),
      s21_exp_suite(),  s21_log_suite(),  s21_asin_suite(), s21_floor_suite(),
      s21_ceil_suite(), s21_sin_suite(),  s21_fmod_suite(), s21_acos_suite(),
      s21_cos_suite(),  s21_tan_suite(),  s21_atan_suite()};

  SRunner *sr = srunner_create(test_suites[0]);
  srunner_set_fork_status(sr, CK_NOFORK);

  int failed;

  for (size_t i = 1; i < ARRAY_SIZE(test_suites); i++)
    srunner_add_suite(sr, test_suites[i]);

  srunner_run_all(sr, CK_ENV);
  failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return failed == 0 ? 0 : 1;
}