#include <stdbool.h>

#ifndef C_PROGRAMMING_A_MODERN_APPROACH_STACK_INT_H

/* Empty the stack */
void intstack_make_empty();
/* Return `true` if stack is empty, `false` is not */
bool intstack_is_empty();
/* Return `true` if current stack size reaches the stack's limit size */
bool intstack_is_full();
/* Add an element to the top end of the stack */
void intstack_push(int num);
/* Remove the element from the top end of the stack then return the popped item */
char intstack_pop();
/* Return index of the current top element */
int intstack_current_length();
/* Return the value of the current top element */
char intstack_current_top();

/* Behaviours for when the stack is overflow */
void stack_overflow();
/* Behaviours for when the stack is underflow */
void stack_underflow();

#define C_PROGRAMMING_A_MODERN_APPROACH_STACK_INT_H

#endif //C_PROGRAMMING_A_MODERN_APPROACH_STACK_INT_H
