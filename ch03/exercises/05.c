#include <stdio.h>

/*
  After the `scanf` call, `x` will be 12.3, `i` will be 45 and `y` will be 0.6
*/

int main()
{
  float x, y;
  int i;

  printf("Please input: ");
  scanf("%f%d%f", &x, &i, &y);
  printf("first one = %f; second one = %d; third one = %f\n", x, i, y);

  return 0;
}