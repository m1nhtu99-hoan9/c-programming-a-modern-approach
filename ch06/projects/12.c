#include <stdio.h>

/* Calculate the largest approximate value of algebraic constant e 
   which is smaller than user's input float 
*/

int main()
{
  unsigned long acc_factorial = 1;
  double res = 1, inp;
  int i = 0;

  printf("e = 1 + 1/1! + 1/2! + 1/3! + ... + 1/n!\n");
  printf("Find the largest e which is smaller than your input\n");
  printf("Your threshold input = ?: ");
  scanf("%lf", &inp);

  if (inp < 1)
  {
    printf("Invalid input!");
    return 1;
  }
  else
  {
    while (res < inp)
    {
      i += 1;
      acc_factorial *= i;
      res += 1.0 / acc_factorial;
    }
    /* when the above loop terminates, 
       `res` is larger than the desired result by `1 / acc_factorial` */
    printf("e = %lf\n", res - 1.0 / acc_factorial);

    return 0;
  }
}
