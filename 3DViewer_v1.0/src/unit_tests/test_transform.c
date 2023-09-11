#include "test_main.h"

START_TEST(test_rotate_0) {
  obj_data data = {0, 0, 0, 0, NULL, NULL};
  int status = LoadModel("../unit_tests/test.obj", &data);
  if (!status) {
    RotateX(&data, 90);
    RotateY(&data, 90);
    RotateZ(&data, 90);
  }
  double array_v[] = {-1.000000, -1.000000, -1.000000, 1.000000,
                      -1.000000, -1.000000, 1.000000,  -1.000000};
  for (size_t i = 0; i < data.vertices_n; i++) {
    ck_assert_double_eq_tol(array_v[i], data.vertices[i], 7);
  }
  ck_assert_int_eq(status, kSuccess);
  ck_assert_int_eq(data.facets_n, 12);
  ck_assert_int_eq(data.vertices_n, 8);

  ClearData(&data);
}
END_TEST

START_TEST(test_translate_0) {
  obj_data data = {0, 0, 0, 0, NULL, NULL};
  int x = 2, y = 3, z = 4;
  int status = LoadModel("../unit_tests/test.obj", &data);
  if (!status) {
    TranslateX(&data, x);
    TranslateY(&data, y);
    TranslateZ(&data, z);
  }
  const double array_v[] = {1.000000,  -1.000000, -1.000000, 1.000000,
                            -1.000000, 1.000000,  -1.000000, -1.000000};
  for (size_t i = 0; i < data.vertices_n; i++) {
    int coordinate_type = i % 2;
    switch (coordinate_type) {
      case 2:
        ck_assert_double_eq_tol(array_v[i] + x, data.vertices[i], 7);
      case 1:
        ck_assert_double_eq_tol(array_v[i] + y, data.vertices[i], 7);
      case 0:
        ck_assert_double_eq_tol(array_v[i] + z, data.vertices[i], 7);
    }
  }
  ck_assert_int_eq(status, kSuccess);
  ck_assert_int_eq(data.facets_n, 12);
  ck_assert_int_eq(data.vertices_n, 8);

  ClearData(&data);
}
END_TEST

START_TEST(test_scale_0) {
  obj_data data = {0, 0, 0, 0, NULL, NULL};
  int scale = 5;
  int status = LoadModel("../unit_tests/test.obj", &data);
  if (!status) {
    Scale(&data, scale);
  }
  double array_v[] = {1.000000,  -1.000000, -1.000000, 1.000000,
                      -1.000000, 1.000000,  -1.000000, -1.000000};
  for (size_t i = 0; i < data.vertices_n; i++) {
    ck_assert_double_eq_tol(array_v[i] * scale, data.vertices[i], 7);
  }
  ck_assert_int_eq(status, kSuccess);
  ck_assert_int_eq(data.facets_n, 12);
  ck_assert_int_eq(data.vertices_n, 8);
}
END_TEST

START_TEST(test_3) {}
END_TEST

START_TEST(test_4) {}
END_TEST

Suite* transform_suite(void) {
  Suite* suite = suite_create("transform_test");
  TCase* calc_tcase = tcase_create("transform_tcase");

  tcase_add_test(calc_tcase, test_rotate_0);
  tcase_add_test(calc_tcase, test_translate_0);
  tcase_add_test(calc_tcase, test_scale_0);
  tcase_add_test(calc_tcase, test_3);
  tcase_add_test(calc_tcase, test_4);
  suite_add_tcase(suite, calc_tcase);

  return suite;
}
