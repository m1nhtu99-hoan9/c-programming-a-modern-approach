#include <stdio.h>

/* Implementing Horner's Rule */
int main()
{
  float x, result = 1.0f;
  int coeffs[] = {-6, 7, -1, -5, 2, 3};
  printf("Input x: ");
  scanf("%f", &x);

  result = coeffs[5];
  /* for (initialisationStatement; testExpression; updateStatement) */
  for (int i = 5; i > 0; i--)
  {
    result = result * x + coeffs[i-1];
  }

  printf("Result of 3x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6: %.2f\n", result);

  return 0;
}