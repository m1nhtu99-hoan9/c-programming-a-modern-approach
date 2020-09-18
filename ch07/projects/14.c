#include <stdio.h>
#include <math.h>

/* Newton's Method to Compute Square Root of a Positive Number */

double res;
/**
 *  After each guess, `lf_ptr2` points to x/y of last guess 
 *  and `lf_ptr1` point to the average of y and x/y from last turn.
 * 
 *  Return: original value of `lf_ptr1` 
 */
double exec_guess(double *lf_ptr1, double *lf_ptr2);

int main()
{
  double temp1 = 1., temp2;

  printf("Enter a positive number: ");
  /* no re-assignment of `res` is implemented after this initialisation */
  scanf("%lf", &res);

  if (res < 0)
  {
    printf("INVALID INPUT!");

    return 1;
  }
  else
  {
    /* iteratively carries out guesses until `temp` reaches the desired closeness */
    for (;;)
    {
      /* 
        This is possible because function call has the highest precedence among C operators. 
        `exec_guess` call below not only evaluates to the old value of `temp1` but also update
        new value for `temp1` which is used throughout the expression.
      */
      if (fabs(exec_guess(&temp1, &temp2) - temp1) < (temp1 * .00001))
        break;
    }

    printf("Square root: %lf\n", temp1);
    return 0;
  }
}

/* implementation */

double exec_guess(double *lf_ptr1, double *lf_ptr2)
{
  double old_lf1 = *lf_ptr1;

  *lf_ptr2 = res / *lf_ptr1;
  *lf_ptr1 = (*lf_ptr1 + *lf_ptr2) / 2;

  return old_lf1;
}
