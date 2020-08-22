#include <stdio.h>

int main()
{
  /* Simple Interest */
  float loan, interestRate, monthlyPayment;
  char ordinals[3][7] = {"first\0", "second\0", "third\0"};

  printf("Enter amount of loan: ");
  scanf("%f", &loan);
  printf("Enter interest rate: ");
  scanf("%f", &interestRate);
  printf("Enter monthly payment: ");
  scanf("%f", &monthlyPayment);

  // convert `interestRate` to its percentage
  interestRate = interestRate / 100;
  // calculate monthly flat interest rate
  float monthlyRate = interestRate / 12;

  for (int i = 0; i < 3; i++)
  {
    /* every month, the balance is increased by 
       the balance times the monthly interest rate 
       and decreased by the amount of payment
    */
    loan *= (1 + monthlyRate);
    loan -= monthlyPayment;

    printf("Balance remaining after %s payment: %.2f\n", ordinals[i], loan);
  }

  return 0;
}