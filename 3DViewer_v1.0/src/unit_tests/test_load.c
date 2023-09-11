#include "test_main.h"

START_TEST(test_0) {
  obj_data data = {0, 0, 0, 0, NULL, NULL};
  int status = LoadModel("../unit_tests/test.obj", &data);
  double array_v[] = {1.000000,  -1.000000, -1.000000, 1.000000,
                      -1.000000, 1.000000,  -1.000000, -1.000000};
  for (size_t i = 0; i < data.vertices_n; i++) {
    ck_assert_double_eq_tol(array_v[i], data.vertices[i], 7);
  }
  int array_f[] = {1, 2, 2, 3, 3, 1, 7, 6, 6, 5, 5, 7, 4, 5, 5, 1, 1, 4,
                   5, 6, 6, 2, 2, 5, 2, 6, 6, 7, 7, 2, 0, 3, 3, 7, 7, 0,
                   0, 1, 1, 3, 3, 0, 4, 7, 7, 5, 5, 4, 0, 4, 4, 1, 1, 0,
                   1, 5, 5, 2, 2, 1, 3, 2, 2, 7, 7, 3, 4, 0, 0, 7, 7, 4};
  for (size_t i = 0; i < data.edges_n * 2; i++) {
    ck_assert_int_eq(array_f[i], data.facets[i]);
  }
  ck_assert_int_eq(status, kSuccess);
  ck_assert_int_eq(data.facets_n, 12);
  ck_assert_int_eq(data.vertices_n, 8);

  ClearData(&data);
}
END_TEST

Suite* load_suite(void) {
  Suite* suite = suite_create("load_test");
  TCase* calc_tcase = tcase_create("load_tcase");

  tcase_add_test(calc_tcase, test_0);
  suite_add_tcase(suite, calc_tcase);

  return suite;
}
