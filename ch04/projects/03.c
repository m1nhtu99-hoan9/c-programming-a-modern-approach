#include <stdio.h>

/* Using a `scanf` trick to reverse a 3-digit number */

int main()
{
  int digits[3], i = 0;

  printf("Please input a 3-digit number: ");
  for (; i < 3; i++) {
    scanf("%1d", &digits[i]);
  }
  printf("\n");

  printf("The reversed number is: ");
  // print these 3 digits in reverse
  for (i = 2; i >= 0; i--) {
    printf("%d", digits[i]);
  }
  printf("\n");

  return 0;
}