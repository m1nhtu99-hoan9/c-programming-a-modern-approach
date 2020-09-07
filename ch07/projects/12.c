#include <stdio.h>
#include <ctype.h>

/** 
 * Naively simplified arithmetic expression parser 
 * Expresion evaluation is left-associative 
 * & no operator takes precedence over any other operator
 * */

int main()
{
  float cur = 0.0f, res = 0.0f;
  char chr;

  printf("Enter an expression: ");
  // initialise `res` with the first operand of the input expression
  scanf("%f", &res);

  // consume chars being the in buffer using `getchar` calls
  while ((chr = getchar()) != '\n')
  {
    // at this point, operator character at the head of buffer was already
    // removed out of the buffer & stored in `chr`
    switch (chr)
    {
    case '+':
      scanf("%f", &cur);
      res += cur;
      break;
    case '-':
      scanf("%f", &cur);
      res -= cur;
      break;
    case '*':
      scanf("%f", &cur);
      res *= cur;
      break;
    case '/':
      scanf("%f", &cur);
      res /= cur;
      break;
    default:
      // if is not an operator, skip!
      continue;
    }
  }

  printf("Value of expression: %.2f", res);

  return 0;
}