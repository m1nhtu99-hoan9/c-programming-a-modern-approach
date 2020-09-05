#include <stdio.h>

int main()
{
  double n, sum = 0.0; 

  printf("This program sums a series of doubles.\n");
  printf("Enter number [0 to terminate]: ");
  scanf("%lf", &n);

  while (n != 0.0) {
    sum += n;
    printf("Enter number [0 to terminate]: ");
    scanf("%lf", &n);
  }
  printf("\n");

  // "%f" can be used to `printf` both float and double
  printf("The sum is: %f\n", sum);
  return 0;
}
