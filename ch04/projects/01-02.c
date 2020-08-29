#include <stdio.h>

/*
  Reverse any natural number
*/

int main()
{
  int num, reversed_num = 0;

  printf("Enter a natural number: "); 
  scanf("%d", &num);

  while (num != 0) {
    // pad a new ones column to `reversed_num`
    reversed_num *= 10; 
    // add the last digit of `num` to the recently created column
    reversed_num += num % 10;
    // strip out the last digit of `num`
    num /= 10;
  }

  printf("The reversed number is: %d\n", reversed_num);

  return 0;
}