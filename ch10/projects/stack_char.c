#include <stdio.h>
#include <stdlib.h>
#include "stack_char.h"

#define STACK_SIZE 100

char contents[STACK_SIZE];
/* position of the stack top */
int top = 0;

void stack_overflow() {
  // printf("Stack overflow!!!\n");
  printf("Your input is too long!\n");
  exit(EXIT_FAILURE);
}

void stack_underflow() {
  // printf("Stack underflow!!!\n");
  printf("Parentheses/braces are not nested properly!\n");
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

int stack_current_top_index() {
  return top;
}

char stack_current_top() {
  return contents[top];
}

void stack_push(char chr) {
  if (stack_is_full()) {
    stack_overflow();
  }
  else {
    /* store the added item in `contents` at the position indicated by `top`
     * and then increment `top` */
    contents[top++] = chr;
  }
}

char stack_pop() {
  if (stack_is_empty()) {
    stack_underflow();
  }
  else {
    /* popping an item requires decrementing `top`, then using it as an index
     * into contents to fetch the item being popped */
    return contents[--top];
  }
}