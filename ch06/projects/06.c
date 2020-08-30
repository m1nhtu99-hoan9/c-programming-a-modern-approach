#include <stdio.h>

/* Print all square numbers between 1 and a number input by user */

int main()
{
  long n;

  printf("Input an integer number: ");
  scanf("%ld", &n);

  if (n < 4)
  {
    printf("Your input number is too small!\n");
  }
  else
  {
    unsigned long squared;
    for (int i = 2;; i++)
    {
      squared = i * i;
      if (squared <= n)
        printf("%ld\n", squared);
      else
        break;
    }
  }

  return 0;
}
