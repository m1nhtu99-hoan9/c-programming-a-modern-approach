#include <stdio.h>
#include "stack.h"

/* Using stack to check if brackets/braces are nested properly
 * to run this program, compile both this file, `stack.h` and `stack.c` */

int main() {
  char cur;

  printf("Enter parentheses and/or braces: ");
  for (cur = getchar(); cur != '\n'; cur = getchar()) {
    if (cur == '(' || cur == '{') {
      /* after this point, the latest opening bracket/brace will be put on top of the stack */
      stack_push(cur);
    }
    else if (cur == ')' && stack_pop() != '(') {
      /* if the currently reading character doesn't matches the latest opening bracket */
      printf("Round brackets are not nested properly!\n");
      return 1;
    }
    else if (cur == '}' && stack_pop() != '}') {
      /* if the currently reading character doesn't matches the latest opening brace */
      printf("Braces are not nested properly!\n");
      return 1;
    }
  }

  if (stack_is_empty()) {
    printf("Parentheses/braces are nested properly!\n");
  }
  else {
    /* the program reaches here if user input contains invalid characters */
    printf("Parentheses/braces are not nested properly!\n");
  }

  return 0;
}

