#include <stdio.h>
#include "stack_int.h"

/* Reverse Polish Notation calculator
 * to run this program, compile both this file, `stack_int.h` and `stack_int.c`
 * */

int main () {
  char cur;
  int tmp;

  for (;;) {
    printf("Enter an RPN expression: ");
    intstack_make_empty();
    for (tmp = 0, cur = '\0'; cur != '\n'; ) {
      scanf(" %c", &cur);

      if (cur >= '0' && cur <= '9') {
        intstack_push(cur - '0');
      }
      else if (cur == '+' || cur == '-' || cur == '*' || cur == '/') {
        tmp = intstack_pop();

        switch (cur) {
          case '+':
            tmp += intstack_pop();
            break;
          case '-':
            tmp = intstack_pop() - tmp;
            break;
          case '*':
            tmp *= intstack_pop();
            break;
          case '/':
            tmp = intstack_pop() / tmp;
            break;
        }

        intstack_push(tmp);
      }
      else if (cur == '=') {
        printf("Value of expression: %d\n", intstack_is_empty() ? 0 : intstack_current_top());
        break;
      }
      else {
        return 0;
      }
    }
  }
}

