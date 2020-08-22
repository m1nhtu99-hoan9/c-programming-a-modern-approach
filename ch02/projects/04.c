#include <stdio.h>

int main()
{
  float amount, result, tax = 5.0f / 100.0f;

  printf("Enter an amount: ");
  scanf("%f", &amount);

  result = (1 + tax) * amount;
  printf("With tax added: $%.2f\n", result);

  return 0;
}