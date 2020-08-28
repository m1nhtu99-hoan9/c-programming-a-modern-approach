#include <stdio.h>

/* Read an integer entered by the user and displays it in octal */
int main()
{
  /* Because the output has to be displayed using five digits,
     so use `res` array to store octal digits
   */
  int num, res[5] = {0, 0, 0, 0, 0}, i = 4;

  printf("Enter a number between 0 and 32767: ");
  scanf("%d", &num);

  while (num != 0)
  {
    // store the remainder in the respective octal digit place, then decrease `i` by 1
    res[i--] = num % 8;
    // divide the number by 8 now
    num /= 8;
  }

  printf("In octal, your number is: ");
  for (i = 0; i < 5; i++)
  {
    printf("%d", res[i]);
  }
  printf("\n");

  return 0;
}