#include <stdio.h>
#include <math.h>

int main()
{
  float x, result = 0.0f;
  int coeffs[6] = {-6, 7, -1, -5, 2, 3};
  printf("Input x: ");
  scanf("%f", &x);
  
  /* for (initializationStatement; testExpression; updateStatement) */
  for (int i = 0; i < 6; i++)
  {
    result += coeffs[i] * pow(x, i);
  }

  printf("Result of 3x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6: %.2f\n", result);
  
  return 0;
}

/* To compile this file on Ubuntu: 
    `gcc ./05.c -lm`
  `-lm` option helps to link with `libm.a`
*/