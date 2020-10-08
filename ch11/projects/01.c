#include <stdio.h>
#include <stdlib.h>

/* modified version of `../../ch02/projects/07.c` */

void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones) {
  if (dollars < 0) {
    printf("INVALID INPUT!\n");
    exit(EXIT_FAILURE);
  }
  else {
    *twenties = dollars / 20;
    dollars %= 20;
    *tens = dollars / 10;
    dollars %= 10;
    *fives = dollars / 5;
    dollars %= 5;
    *ones = dollars;
  }
}

int main()
{
  /*
    Number of $20 bills -> num_of_bills[0]
    Number of $10 bills -> num_of_bills[1]
    Number of $5 bills  -> num_of_bills[2]
    Number of $1 bills  -> num_of_bills[3]
  */
  int amount, num_of_bills[4];
  const int BILLS[4] = {20, 10, 5, 1};

  printf("Enter a dollar amount: ");
  scanf("%d", &amount);
  printf("\n");

  pay_amount(amount, num_of_bills + 0, num_of_bills + 1, num_of_bills + 2, num_of_bills + 3);

  for (int i = 0; i < 4; i++)
  {
    printf("$%-2d bills: %d\n", BILLS[i], num_of_bills[i]);
  }

  return 0;
}