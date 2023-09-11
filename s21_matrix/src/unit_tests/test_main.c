#include "test_main.h"

int main(void) {
  Suite *test_suites[] = {
      s21_calc_complements_suite(), s21_create_matrix_suite(),
      s21_determinant_suite(),      s21_eq_matrix_suite(),
      s21_inverse_matrix_suite(),   s21_mult_matrix_suite(),
      s21_mult_number_suite(),      s21_remove_matrix_suite(),
      s21_sub_matrix_suite(),       s21_sum_matrix_suite(),
      s21_transpose_suite()};

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
