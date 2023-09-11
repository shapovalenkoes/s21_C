#include "calc.h"

Queue to_RPN(Queue *tokens) {
  Queue rpn;
  Stack operators;
  Token current, top;
  init_queue(&rpn);
  init_stack(&operators);

  while (!is_empty_queue(tokens)) {
    current = dequeue(tokens);
    if (current.type == NUMBER || current.type == X) {
      enqueue(&rpn, current);
    } else if (current.func || current.type == LEFT_BRACKET) {
      push(&operators, current);
    } else if (current.is_operator) {
      if (!is_empty_stack(&operators)) {
        top = peek(&operators);
        if (current.priority > top.priority) {
          push(&operators, current);
        } else {
          while (top.priority >= current.priority && top.is_operator) {
            top = pop(&operators);
            enqueue(&rpn, top);
            if (is_empty_stack(&operators)) break;
            top = peek(&operators);
          }
          push(&operators, current);
        }
      } else {
        push(&operators, current);
      }

    } else {  // закрывающая скобка
      top = pop(&operators);

      while (top.type != LEFT_BRACKET) {
        enqueue(&rpn, top);
        top = pop(&operators);
      }
      if (!is_empty_stack(&operators)) {
        top = peek(&operators);
        if (top.func) {
          top = pop(&operators);
          enqueue(&rpn, top);
        }
      }
    }
  }

  while (!is_empty_stack(&operators)) {  // перекладываю остатки из стека
    top = pop(&operators);
    if (top.type != LEFT_BRACKET) {
      enqueue(&rpn, top);
    }
  }

  return rpn;
}
