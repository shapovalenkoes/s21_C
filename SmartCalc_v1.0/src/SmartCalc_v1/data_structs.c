#include "calc.h"

void init_stack(Stack *stack) { stack->top = NULL; }

void init_queue(Queue *queue) {
  queue->front = NULL;
  queue->rear = NULL;
}

int is_empty_stack(Stack *stack) { return stack->top == NULL; }

int is_empty_queue(Queue *queue) { return queue->front == NULL; }

void push(Stack *stack, Token token) {
  Node *new_node = (Node *)calloc(1, sizeof(Node));
  new_node->token = token;
  new_node->next = stack->top;
  stack->top = new_node;
}

void enqueue(Queue *queue, Token token) {
  Node *new_node = (Node *)calloc(1, sizeof(Node));
  new_node->token = token;
  new_node->next = NULL;

  if (is_empty_queue(queue)) {
    queue->front = new_node;
    queue->rear = new_node;
  } else {
    queue->rear->next = new_node;
    queue->rear = new_node;
  }
}

Token pop(Stack *stack) {
  if (is_empty_stack(stack)) {
    // fprintf(stderr, "Stack underflow\n");
    // exit(1);
  }
  Node *tmp = stack->top;
  Token token = tmp->token;
  stack->top = tmp->next;
  free(tmp);
  return token;
}

Token dequeue(Queue *queue) {
  if (is_empty_queue(queue)) {
    // fprintf(stderr, "Queue underflow\n");
    // exit(1);
  }
  Node *tmp = queue->front;
  Token token = tmp->token;

  queue->front = queue->front->next;
  free(tmp);

  if (is_empty_queue(queue)) queue->rear = NULL;

  return token;
}

Token peek(Stack *stack) {
  if (is_empty_stack(stack)) {
    // fprintf(stderr, "Stack underflow\n");
    // exit(1);
  }
  return stack->top->token;
}

void destroy_stack(Stack *stack) {
  while (!is_empty_stack(stack)) {
    pop(stack);
  }
}