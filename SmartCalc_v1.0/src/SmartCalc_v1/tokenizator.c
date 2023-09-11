#include "calc.h"

Queue get_all_tokens(char *str) {
  Queue tokens;
  init_queue(&tokens);
  char *delimeter = " ";

  char *tok = strtok(str, delimeter);

  while (tok != NULL) {
    enqueue(&tokens, get_token(tok));
    tok = strtok(NULL, delimeter);
  }

  return tokens;
}

Token get_token(char *str) {
  Token token = {0};

  if (isdigit(*str)) {
    token.value = atof(str);
    token.type = NUMBER;
    token.priority = P_NUMBER;
  }

  else if (*str == '+') {
    token.type = ADD;
    token.priority = P_ADD;
    token.is_operator = 1;

  }

  else if (*str == '-') {
    token.type = SUBTRACT;
    token.priority = P_SUBTRACT;
    token.is_operator = 1;
  }

  // else if (*str == '~') {
  //   token.type = UNARY_MINUS;
  //   token.priority = P_UNARY_MINUS;
  // }

  else if (*str == '*') {
    token.type = MULTIPLAY;
    token.priority = P_MULTIPLAY;
    token.is_operator = 1;
  }

  else if (*str == '/') {
    token.type = DIVISION;
    token.priority = P_DIVISION;
    token.is_operator = 1;
  }

  else if (*str == '^') {
    token.type = POWER;
    token.priority = P_POWER;
    token.is_operator = 1;
  }

  else if (*str == 'm' || *str == '%') {
    token.type = MOD;
    token.priority = P_MOD;
    token.is_operator = 1;
  }

  else if (*str == 's') {
    token.func = 1;
    if (str[1] == 'i') {
      token.type = SIN;
      token.priority = P_SIN;

    } else if (str[1] == 'q') {
      token.type = SQRT;
      token.priority = P_SQRT;
    }
  }

  else if (*str == 'c') {
    token.type = COS;
    token.priority = P_COS;
    token.func = 1;
  }

  else if (*str == 't') {
    token.type = TAN;
    token.priority = P_TAN;
    token.func = 1;
  }

  else if (*str == 'l') {
    token.func = 1;
    if (str[1] == 'n') {
      token.type = LN;
      token.priority = P_LN;

    } else if (str[1] == 'o') {
      token.type = LOG;
      token.priority = P_LOG;
    }
  }

  else if (*str == 'a') {
    token.func = 1;
    if (str[1] == 's') {
      token.type = ASIN;
      token.priority = P_ASIN;

    } else if (str[1] == 'c') {
      token.type = ACOS;
      token.priority = P_ACOS;

    } else if (str[1] == 't') {
      token.type = ATAN;
      token.priority = P_ATAN;
    }
  }

  else if (*str == '(') {
    token.type = LEFT_BRACKET;
    token.priority = P_LEFT_BRACKET;
  }

  else if (*str == ')') {
    token.type = RIGHT_BRACKET;
    token.priority = P_RIGHT_BRACKET;
  }

  else if (*str == 'x' || *str == 'X') {
    token.type = X;
    token.priority = P_X;
  }

  return token;
}
