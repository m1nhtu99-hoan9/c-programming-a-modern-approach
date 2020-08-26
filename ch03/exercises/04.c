#include <stdio.h>

/*
  After the `scanf` call, `x` will be 10, `i` will be 0.3 and `y` will be 5 
*/

int main()
{
  int i, j;
  float x;

  printf("Please input: ");
  scanf("%d%f%d", &i, &x, &j);
  printf("first one = %d; second one = %f; third one = %d\n", i, x, j);

  return 0;
}