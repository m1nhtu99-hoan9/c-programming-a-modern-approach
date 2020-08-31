#include <stdio.h>

/* Calculate approximate value of algebraic constant e */

int main()
{
  unsigned long acc_factorial = 1; // 8 bytes
  double res = 1;                  // 8 bytes
  int i, n;

  printf("e = 1 + 1/1! + 1/2! + 1/3! + ... + 1/n!\n");
  printf("n = ?: ");
  scanf("%d", &n);

  if (n < 0)
  {
    printf("Invalid input!");
    return 1;
  }
  else
  {
    for (i = 1; i <= n; i++)
    {
      acc_factorial *= i;
      res += 1. / acc_factorial;
    }
    printf("e = %lf\n", res);

    return 0;
  }
}
