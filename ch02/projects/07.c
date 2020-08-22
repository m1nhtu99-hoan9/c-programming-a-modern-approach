#include <stdio.h>

int main()
{
  /*
    Number of $20 bills -> numOfBills[0]
    Number of $10 bills -> numOfBills[1]
    Number of $5 bills  -> numOfBills[2]
    Number of $1 bills  -> numOfBills[3]
  */
  int amount, remainder, numOfBills[4], bills[4] = {20, 10, 5, 1};

  printf("Enter a dollar amount: ");
  scanf("%d", &amount);
  printf("\n");

  for (int i = 0; i < 4; i++)
  {
    if (bills[i] < 10)
    {
      printf(" $%d bills: %d\n", bills[i], amount / bills[i]);
    }
    else
    {
      printf("$%d bills: %d\n", bills[i], amount / bills[i]);
    }
    amount = amount % bills[i];
  }

  return 0;
}