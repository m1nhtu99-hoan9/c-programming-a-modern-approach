#include <stdbool.h>

#ifndef C_PROGRAMMING_A_MODERN_APPROACH_STACK_CHAR_H

/* Empty the stack */
void stack_make_empty();
/* Return `true` if stack is empty, `false` is not */
bool stack_is_empty();
/* Return `true` if current stack size reaches the stack's limit size */
bool stack_is_full();
/* Add an element to the top end of the stack */
void stack_push(char chr);
/* Remove the element from the top end of the stack then return the popped item */
char stack_pop();
/* Return index of the current top element */
int stack_current_top_index();
/* Return the value of the current top element */
char stack_current_top();

/* Behaviours for when the stack is overflow */
void stack_overflow();
/* Behaviours for when the stack is underflow */
void stack_underflow();

#define C_PROGRAMMING_A_MODERN_APPROACH_STACK_CHAR_H

#endif //C_PROGRAMMING_A_MODERN_APPROACH_STACK_CHAR_H
