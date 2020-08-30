#include <stdio.h>
#include "gcd.h"

int main()
{
  int m, n;

  printf("Enter two integers: ");
  scanf("%d%d", &m, &n);

  if (n == 0)
  {
    printf("Invalid input! \n");
    return 1;
  }
  else
  {
    process_find_gcd(&m, &n);
    printf("Greatest common divisor: %d\n", m);
    return 0;
  }
}


