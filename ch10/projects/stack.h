#include <stdbool.h>

#ifndef C_PROGRAMMING_A_MODERN_APPROACH_STACK_H

/* Empty the stack */
void stack_make_empty();
/* Return `true` if stack is empty, `false` is not */
bool stack_is_empty();
/* Return `true` if current stack size reaches the stack's limit size */
bool stack_is_full();
/* Add an element to the top end of the stack */
void stack_push(char chr);
/* Remove the element from the top end of the stack then return the current top element */
char stack_pop();

void stack_overflow();
void stack_underflow();

#define C_PROGRAMMING_A_MODERN_APPROACH_STACK_H

#endif //C_PROGRAMMING_A_MODERN_APPROACH_STACK_H
