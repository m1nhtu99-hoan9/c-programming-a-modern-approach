#include <stdio.h>
#include "gcd.h"

/* Ask the user to input a fraction, return the fraction to lowest terms */

int main()
{
  int m, n, gcd;
  printf("Enter the fraction: ");
  scanf("%d/%d", &m, &n);
  
  gcd = find_gcd(m,n);

  printf("In lowest terms: %d/%d\n", m / gcd, n / gcd);
  return 0;
}
