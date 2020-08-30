#include <stdio.h>

int main()
{
  float max = 0, n;

  while (n) {
    printf("Enter a number: "); 
    scanf("%f", &n);

    if (n > max) max = n;
  }

  printf("The largest number entered was %.2f\n", max);
  return 0;
}
