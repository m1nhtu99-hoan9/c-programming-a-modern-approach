#include <stdio.h>
#include <stdlib.h>

/* modified version of `interest.c` */

int main(void)
{
  int i, low_rate, num_years, month, year;
  const int INITIAL_BALANCE = 100.00;
  double value[5] = ;
  const int NUM_RATES = (int)(sizeof(value) / sizeof(value[0]));

  printf("Enter interest rate: ");
  scanf("%d", &low_rate);
  printf("Enter number of years: ");
  scanf("%d", &num_years);

  printf("\nYears");
  for (i = 0; i < NUM_RATES; i++)
  {
    printf("%8d%%", low_rate + i);
    value[i] = INITIAL_BALANCE;
  }
  printf("\n");

  for (year = 1; year <= num_years; year++)
  {
    printf("%3d    ", year);
    for (i = 0; i < NUM_RATES; i++)
    {
      for (month = 1; month <= 12; month++)
        value[i] *= (low_rate + i) / 12 / 100.0 + 1;
      printf("%9.2f", value[i]);
    }
    printf("\n");
  }
  return 0;
}