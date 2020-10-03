#include <stdio.h>

/* the same source code as `../../ch05/projects/05.c` */

float get_tax(float income);

int main()
{
  float income;

  printf("Enter your taxable income: ");
  scanf("%f", &income);

  printf("Tax due: %.2f\n", get_tax(income));

  return 0;
}

/* implementation */

float get_tax(float income)
{
  const int RANGES[5] = {750, 2250, 3750, 5250, 7000};
  float base, ratio, surplus;

  if (income < RANGES[0])
  {
    base = 0;
    ratio = .01;
    surplus = 0;
  }
  else if (income >= RANGES[0] && income < RANGES[1])
  {
    base = 7.50;
    ratio = .02;
    surplus = income - RANGES[0];
  }
  else if (income >= RANGES[1] && income < RANGES[2])
  {
    base = 37.50;
    ratio = .03;
    surplus = income - RANGES[1];
  }
  else if (income >= RANGES[2] && income < RANGES[3])
  {
    base = 82.50;
    ratio = .04;
    surplus = income - RANGES[2];
  }
  else if (income >= RANGES[3] && income < RANGES[4])
  {
    base = 142.50;
    ratio = .05;
    surplus = income - RANGES[3];
  }
  else
  {
    base = 230.00;
    ratio = .06;
    surplus = income - RANGES[4];
  }

  return base + ratio * surplus;
}
