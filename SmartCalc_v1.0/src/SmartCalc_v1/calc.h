#ifndef CALC_H
#define CALC_H

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

enum return_codes {
  OK = 0,
  CORRECT = 0,
  INCORRECT = 1,
  INF = 1,
  MIN_INF = 2,
  ZERO_DIVISION = 3
};

enum TYPE {
  NUMBER = 1,
  ADD = 2,
  SUBTRACT = 3,
  MULTIPLAY = 4,
  DIVISION = 5,
  POWER = 6,
  MOD = 7,
  UNARY_PLUS = 8,
  UNARY_MINUS = 9,
  COS = 10,
  SIN = 11,
  TAN = 12,
  ACOS = 13,
  ASIN = 14,
  ATAN = 15,
  SQRT = 16,
  LN = 17,
  LOG = 18,
  LEFT_BRACKET = 19,
  RIGHT_BRACKET = 20,
  X = 21
};

enum PRIOR {
  P_NUMBER = 0,
  P_ADD = 1,
  P_SUBTRACT = 1,
  P_MULTIPLAY = 2,
  P_DIVISION = 2,
  P_POWER = 3,
  P_MOD = 2,
  P_UNARY_PLUS = 6,
  P_UNARY_MINUS = 6,
  P_COS = 4,
  P_SIN = 4,
  P_TAN = 4,
  P_ACOS = 4,
  P_ASIN = 4,
  P_ATAN = 4,
  P_SQRT = 4,
  P_LN = 4,
  P_LOG = 4,
  P_LEFT_BRACKET = 5,
  P_RIGHT_BRACKET = 5,
  P_X = 0
};

typedef struct Token {
  double value;
  int priority;
  int type;
  int is_operator;
  int func;
} Token;

typedef struct Node {
  Token token;
  struct Node *next;
} Node;

typedef struct Stack {
  Node *top;
} Stack;

typedef struct Queue {
  Node *front;
  Node *rear;
} Queue;

// Stack
void init_stack(Stack *stack);
int is_empty_stack(Stack *stack);
void push(Stack *stack, Token token);
Token pop(Stack *stack);
Token peek(Stack *stack);
void destroy_stack(Stack *stack);

// Queue
void init_queue(Queue *queue);
int is_empty_queue(Queue *queue);
void enqueue(Queue *queue, Token token);
Token dequeue(Queue *queue);

// Calculator
int calculate(Queue rpn, double *result, double x);
int calc_oper(Token oper, Token token_1, Token token_2, Token *result);
void calc_func(Token oper, Token token, Token *result);

// Validator
int validator(const char *str, char *valid_str);
void squeeze(const char *str, char *sq_str);
int check_bracket_sequence(char *str);
int check_func(char *func, const char *str, int len, int *i, char *valid_str);
int check_all_func(char *str, int len, int *i, char *valid_str);
void check_number(char *str, int *i, char *valid_str);
int check_dot(const char *str, int len, const int *i, char *valid_str);
int check_operators(char *str, int len, int *i, char *valid_str);
int is_operator(char c);
int check_empty_bracket(const char *str, int len, const int *i,
                        char *valid_str);
int check_unary_sign(const char *str, const int *i, char *valid_str);
char *what_operator(const char *str, const int *i);

// Tokenizator
Token get_token(char *str);
Queue get_all_tokens(char *str);
void check_priority(Queue *rpn, Stack *operators, Queue *tokens, Token current);

// Sort station
Queue to_RPN(Queue *tokens);

#endif
