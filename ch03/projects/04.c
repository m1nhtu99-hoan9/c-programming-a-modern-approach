#include <stdio.h>

int main()
{
  int prefix, body1, body2;

  printf("Enter phone number [(xxx) xxx-xxxx]: ");
  scanf("(%3d) %3d-%4d", &prefix, &body1, &body2);

  printf("You entered %3d.%3d.%4d\n", prefix, body1, body2);

  return 0;
}