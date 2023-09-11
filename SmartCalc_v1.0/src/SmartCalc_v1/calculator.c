#include "calc.h"

int calculate(Queue rpn, double *result, double x) {
  int status = OK;
  Token res = {0.0, P_NUMBER, NUMBER, 1, 0};
  Token current;
  Stack operands;
  init_stack(&operands);
  while (!is_empty_queue(&rpn)) {
    current = dequeue(&rpn);
    if (current.type == NUMBER) {
      push(&operands, current);
    } else if (current.type == X) {
      current.value = x;
      push(&operands, current);
    } else {
      if (current.is_operator) {
        Token tmp_1 = pop(&operands);
        Token tmp_2 = pop(&operands);
        if (calc_oper(current, tmp_1, tmp_2, &res) == ZERO_DIVISION)
          return ZERO_DIVISION;
        else
          push(&operands, res);
      } else {
        Token tmp = pop(&operands);
        calc_func(current, tmp, &res);
        push(&operands, res);
      }
    }
  }
  destroy_stack(&operands);
  *result = res.value;
  return status;
}

int calc_oper(Token oper, Token token_1, Token token_2, Token *result) {
  int status = OK;
  if (oper.type == ADD) {
    result->value = token_1.value + token_2.value;
  } else if (oper.type == SUBTRACT) {
    result->value = token_2.value - token_1.value;
  } else if (oper.type == MULTIPLAY) {
    result->value = token_1.value * token_2.value;
  } else if (oper.type == POWER) {
    result->value = pow(token_2.value, token_1.value);
  } else if (oper.type == DIVISION) {
    if (token_1.value) {
      result->value = token_2.value / token_1.value;
    } else
      status = ZERO_DIVISION;
  } else if (oper.type == MOD) {
    if (token_1.value) {
      result->value = fmod(token_2.value, token_1.value);
    } else
      status = ZERO_DIVISION;
  }

  return status;
}

void calc_func(Token oper, Token token, Token *result) {
  if (oper.type == COS)
    result->value = cos(token.value);
  else if (oper.type == SIN)
    result->value = sin(token.value);
  else if (oper.type == TAN)
    result->value = tan(token.value);
  else if (oper.type == ACOS)
    result->value = acos(token.value);
  else if (oper.type == ASIN)
    result->value = asin(token.value);
  else if (oper.type == ATAN)
    result->value = atan(token.value);
  else if (oper.type == SQRT)
    result->value = sqrt(token.value);
  else if (oper.type == LN)
    result->value = log(token.value);
  else if (oper.type == LOG)
    result->value = log10(token.value);
}
