#include <stdio.h>

int main()
{
  int n;

  n = 0;
  if (n >= 1 <= 10)
    printf("n is between 1 and 10\n"); // logically wrong

  n = 5;
  printf("%d\n", n == 1 - 10);

  return 0;
}