#include <stdio.h>

int get_check_digit(int digits[12]);

int main()
{
  int ean_digits[12], i;

  printf("Enter the first 12 digits of an EAN: ");
  for (i = 0; i < 12; i++)
  {
    scanf("%1d", &ean_digits[i]);
  }

  printf("Check digit: %d\n", get_check_digit(ean_digits));

  return 0;
}

/* Implementations */
int get_check_digit(int digits[12])
{
  int res = 0, i;

  // add the second, fourth, sixth, eighth, tenth, and twelfth digits
  for (i = 1; i <= 11; i += 2)
  {
    res += digits[i];
  }
  // multiply it by 3
  res *= 3;
  // add it to the sum of the first, third, fifth, seventh, ninth, and eleven digits
  for (i = 0; i <= 10; i += 2)
  {
    res += digits[i];
  }
  // subtract it from the total
  res -= 1;
  // the remainder when the adjusted total is divided by 10
  res %= 10;
  // substract the remainder from 9
  res = 9 - res;

  return res;
}

/*
  12 first digits of an EAN sample: 869148426000
*/