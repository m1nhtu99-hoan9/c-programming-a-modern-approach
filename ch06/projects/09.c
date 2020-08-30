#include <stdio.h>

/* Simple Interest 
    modified version of `../../ch02/projects/08.c`
*/

int main()
{
  float loan, interestRate, monthlyRate, payment;
  char ordinals[3][7] = {"first\0", "second\0", "third\0"};

  printf("Enter amount of loan: ");
  scanf("%f", &loan);
  printf("Enter interest rate: ");
  scanf("%f", &interestRate);

  // convert `interestRate` to its percentage
  interestRate = interestRate / 100;
  // calculate monthly flat interest rate
  monthlyRate = interestRate / 12;

  for (int i = 0; i < 3; i++)
  {
    printf("Enter %s month payment: ", ordinals[i]);
    scanf("%f", &payment);

    /* every month, the balance is increased by 
       the balance times the monthly interest rate 
       and decreased by the amount of payment
    */
    loan *= (1 + monthlyRate);
    loan -= payment;

    printf("Balance remaining after %s payment: %.2f\n", ordinals[i], loan);
  }

  return 0;
}