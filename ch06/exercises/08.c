#include <stdio.h>

int main()
{
  for (int i = 10; i >= 1; i /= 2)
    printf("%d", i++);

  return 0;
}

/* Output: Infinite loop
    1053211111111111111...
*/