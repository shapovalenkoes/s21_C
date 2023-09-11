#include "calc.h"

int validator(const char *str, char *valid_str) {
  char sq_str[MAX_SIZE] = "";
  squeeze(str, sq_str);

  int status = check_bracket_sequence(sq_str);
  int len = strlen(sq_str);

  for (int i = 0; i < len && status == CORRECT; i++) {
    if (isdigit(sq_str[i])) {
      check_number(sq_str, &i, valid_str);
    } else if (isalpha(sq_str[i])) {
      status = check_all_func(sq_str, len, &i, valid_str);
    } else if (sq_str[i] == '(' || sq_str[i] == ')') {
      status = check_empty_bracket(sq_str, len, &i, valid_str);
    } else if (sq_str[i] == '.') {
      status = check_dot(sq_str, len, &i, valid_str);
    } else {
      status = check_operators(sq_str, len, &i, valid_str);
    }
  }
  return status;
}

void squeeze(const char *str, char *sq_str) {
  int j = 0;
  for (size_t i = 0; i < strlen(str); i++) {
    if (str[i] == ' ')
      continue;
    else
      sq_str[j++] = str[i];
  }
  sq_str[j] = 0;
}

int check_bracket_sequence(char *str) {
  int counter = 0;
  for (size_t i = 0; i < strlen(str); i++) {
    if (str[i] == '(') {
      counter++;
    } else if (str[i] == ')') {
      if (counter == 0) {
        counter = INCORRECT;
        break;
      } else
        counter--;
    }
  }
  return counter;
}

int check_func(char *func, const char *str, int len, int *i, char *valid_str) {
  int status = INCORRECT;

  int func_len = strlen(func);
  int k = *i;

  if ((*i + func_len + 2) <= len) {
    status = CORRECT;
    for (int j = 0; (j < func_len) && (status == CORRECT); j++, k++) {
      if (str[k] != func[j])
        status = INCORRECT;
      else
        *i = k;
    }
    if (str[k] != '(') status = INCORRECT;
  }
  if (status == CORRECT) strcat(valid_str, func);
  return status;
}

int check_all_func(char *str, int len, int *i, char *valid_str) {
  int status = INCORRECT;

  if (str[*i] == 'c')
    status = check_func("cos", str, len, i, valid_str);
  else if (str[*i] == 't')
    status = check_func("tan", str, len, i, valid_str);
  else if (str[*i] == 's') {
    status = check_func("sin", str, len, i, valid_str);
    if (status != CORRECT) {
      status = check_func("sqrt", str, len, i, valid_str);
    }
  } else if (str[*i] == 'l') {
    status = check_func("ln", str, len, i, valid_str);
    if (status != CORRECT) {
      status = check_func("log", str, len, i, valid_str);
    }
  } else if (str[*i] == 'a') {
    status = check_func("asin", str, len, i, valid_str);
    if (status != CORRECT) {
      status = check_func("atan", str, len, i, valid_str);
    }
    if (status != CORRECT) {
      status = check_func("acos", str, len, i, valid_str);
    }
  } else if (str[*i] == 'm') {
    status = (!(str[*i + 1] == 'o' && str[*i + 2] == 'd'));
    if (status == CORRECT) {
      strcat(valid_str, " mod ");
      *i += 2;
    }
  }

  else if (str[*i] == 'x' || str[*i] == 'X') {
    strcat(valid_str, " x ");
    status = CORRECT;
  }

  return status;
}

void check_number(char *str, int *i, char *valid_str) {
  int k = *i;
  int j = 0;
  char buffer[50] = "";

  while (isdigit(str[k])) {
    buffer[j++] = str[k++];
    *i = k - 1;
  }
  strcat(valid_str, buffer);
}

int check_dot(const char *str, int len, const int *i, char *valid_str) {
  int status = INCORRECT;
  if (*i > 0 && (*i + 2 <= len)) {
    if (isdigit(str[*i + 1]) && isdigit(str[*i - 1])) {
      strcat(valid_str, ".");
      status = CORRECT;
    }
  }
  return status;
}

int check_unary_sign(const char *str, const int *i, char *valid_str) {
  int status = 0;
  if (*i == 0 || str[*i - 1] == '(') {
    status = 1;
  }
  if (status) {
    if (str[*i] == '-') strcat(valid_str, " 0 - ");
  }
  return status;
}

int check_operators(char *str, int len, int *i, char *valid_str) {
  int status = INCORRECT;
  int unary = 0;
  if (str[*i] == '-' || str[*i] == '+') {
    unary = check_unary_sign(str, i, valid_str);
    status = CORRECT;
  }

  if (*i > 0 && (*i + 2 <= len) && is_operator(str[*i]) && !unary) {
    if ((str[*i - 1] != '(') && !is_operator(str[*i - 1]) &&
        !is_operator(str[*i + 1]))
      status = CORRECT;

    char *c = what_operator(str, i);
    strcat(valid_str, " ");
    strcat(valid_str, c);
    strcat(valid_str, " ");
  }

  return status;
}
char *what_operator(const char *str, const int *i) {
  char *c;

  if (str[*i] == '-') c = "-";
  if (str[*i] == '+') c = "+";
  if (str[*i] == '*') c = "*";
  if (str[*i] == '/') c = "/";
  if (str[*i] == '^') c = "^";
  if (str[*i] == '%') c = "%";

  return c;
}

int is_operator(char c) {
  return c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '%';
}

int check_empty_bracket(const char *str, int len, const int *i,
                        char *valid_str) {
  int status = INCORRECT;
  int k = *i;

  if (str[k] == '(') {
    if (k + 2 <= len) {
      status = str[k + 1] == ')';
      strcat(valid_str, " ( ");
    }
  } else if (str[k] == ')' && k != 0) {
    status = str[k - 1] == '(';
    strcat(valid_str, " ) ");
  }

  return status;
}
