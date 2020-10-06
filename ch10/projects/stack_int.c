#include <stdio.h>
#include <stdlib.h>
#include "stack_int.h"

#define STACK_SIZE 100

int contents[STACK_SIZE];
/* position of the stack top */
int top = 0;

void stack_overflow() {
  // printf("Stack overflow!!!\n");
  printf("Your input expression is too complex!\n");
  printf("<debug>Stack contents: \n");
  for (int i; i < top; i++) {
    printf("%d ", contents[i]);
  }
  printf("\n</debug>\n");
  exit(EXIT_FAILURE);
}

void stack_underflow() {
  // printf("Stack underflow!!!\n");
  printf("Not enough operands in your input expression!\n");
  printf("<debug>Stack contents: \n");
  for (int i; i < top; i++) {
    printf("%d ", contents[i]);
  }
  printf("\n</debug>\n");
  exit(EXIT_FAILURE);
}

void intstack_make_empty() {
  top = 0;
}

bool intstack_is_empty() {
  return top == 0;
}

bool intstack_is_full() {
  return top == STACK_SIZE;
}

int intstack_current_length() {
  return top;
}

char intstack_current_top() {
  return contents[top - 1];
}

void intstack_push(int num) {
  if (intstack_is_full()) {
    stack_overflow();
  }
  else {
    /* store the added item in `contents` at the position indicated by `top`
     * and then increment `top` */
    contents[top++] = num;
  }
}

char intstack_pop() {
  if (intstack_is_empty()) {
    stack_underflow();
  }
  else {
    /* popping an item requires decrementing `top`, then using it as an index
     * into contents to fetch the item being popped */
    return contents[--top];
  }
}