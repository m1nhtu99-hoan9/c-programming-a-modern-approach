#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define STACK_SIZE 100

char contents[STACK_SIZE];
/* position of the stack top */
int top = 0;

void stack_overflow() {
  printf("Stack overflow!!!\n");
  exit(EXIT_FAILURE);
}

void stack_underflow() {
  printf("Stack underflow!!!\n");
  exit(EXIT_FAILURE);
}

void stack_make_empty() {
  top = 0;
}

bool stack_is_empty() {
  return top == 0;
}

bool stack_is_full() {
  return top == STACK_SIZE;
}

void stack_push(char chr) {
  if (stack_is_full())
    stack_overflow();
  else
    contents[top++] = chr;
}

char stack_pop() {
  if (stack_is_empty())
    stack_underflow();
  else
    return contents[--top];
}