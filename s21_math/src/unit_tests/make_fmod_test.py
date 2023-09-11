headers = """
#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "../s21_math.h"
#define BUFF_SIZE 512
"""

call_head = """Suite *s21_math_suite(void) {
  Suite *s = suite_create("s21_fmod");
  TCase *tc = tcase_create("case_fmod");"""

call_tail="""  suite_add_tcase(s, tc);
  return s;
}"""

tail ="""void case_test(Suite *s, int *fail) {
  SRunner *runner = srunner_create(s);
  srunner_set_fork_status(runner, CK_NOFORK);
  srunner_run_all(runner, CK_NORMAL);
  *fail = srunner_ntests_failed(runner);
  srunner_free(runner);
}

int main() {
  int fail = 0;
  case_test(s21_math_suite(), &fail);
  return fail;
}"""

def make_cases():
    cases = list()
    case = str()
    number_test = 0
    # unsigned int
    open_bracket = "{"
    close_bracket = "}"
    values = [0.0, -0.0, 0.5, -0.5, -1.2, 1.2, -21.0, 21.0, -0.01, 0.01, 21.9, -21.9, "1.79769313486231570e+308", "2.2250738585072014E-308", 21212121, -21212121, 21212121.21212121, -21212121.21212121, 0.21212121, -0.21212121]
    for value_1 in values:
        for value_2 in values:
            if value_2 == 0.0:
              case = "START_TEST(test_{0}) {1}\nlong double my_val = s21_fmod({2}, {3});\nck_assert_ldouble_nan(my_val);\n{4}\nEND_TEST\n".format(number_test, open_bracket, value_1, value_2, close_bracket)
            else:  
              case = "START_TEST(test_{0}) {1}\nlong double my_val = s21_fmod({2}, {3});\nlong double test_val = fmod({2}, {3});\nck_assert_ldouble_eq(my_val, test_val);\n{4}\nEND_TEST\n".format(number_test, open_bracket, value_1, value_2, close_bracket)
            cases.append(case)
            number_test += 1
    return cases

def make_calls():
    calls = list()
    number_test = 0
    values = [0.0, -0.0, 0.5, -0.5, -1.2, 1.2, -21.0, 21.0, -0.01, 0.01, 21.9, -21.9, "1.79769313486231570e+308", "2.2250738585072014E-308", 21212121, -21212121, 21212121.21212121, -21212121.21212121, 0.21212121, -0.21212121]
    for value_1 in values:
        for value_2 in values:
            call =  "tcase_add_test(tc, test_{0});\n".format(number_test)
            calls.append(call)
            number_test += 1
    return calls
            

def main():
    cases = make_cases()
    call_cases=make_calls()
    file = open("test_fmod.c", "w")
    file.write(headers)
    for case in cases:
        file.write(case)
        file.write("\n")
    file.write(call_head)
    for call_case in call_cases:
        file.write(call_case)
    file.write(call_tail)
    file.write(tail)
    file.close()

main()
