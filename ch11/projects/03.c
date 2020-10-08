#include <stdio.h>

/* Ask the user to input a fraction, return the fraction to lowest terms
 * modified version of `../../ch06/projects/03.c`*/

/* After this function is called, `*reduced_numerator` is the GCD */
void reduce(int numerator
           ,int denominator
           ,int *const reduced_numerator
           ,int *const reduced_denominator) {
  int temp;

  for (*reduced_denominator = denominator
      ,*reduced_numerator = numerator
      ;*reduced_denominator != 0
      ;) {
    temp = *reduced_numerator % *reduced_denominator;
    *reduced_numerator = *reduced_denominator;
    *reduced_denominator = temp;

    /* to see visualisation of this process, uncomment the next line */
    // printf("first num = %d, second num = %d\n", *reduced_numerator, *b);
  }
}

int main() {
  int m, n;
  printf("Enter the fraction: ");
  scanf("%d/%d", &m, &n);

  int tmp_m, tmp_n;
  reduce(m, n, &tmp_m, &tmp_n);

  printf("In lowest terms: %d/%d\n", m / tmp_m, n / tmp_m);
  return 0;
}
