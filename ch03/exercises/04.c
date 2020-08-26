#include <stdio.h>

/*
  After the `scanf` call, `x` will be 12, `i` will be 0.3 and `y` will be 45.6
*/

int main() {
  int i, j;
  float x; 

  printf("Please input: ");
  scanf("%d%f%d", &i, &x, &j);
  printf("first one = %d; second one = %f; third one = %d\n", i, x, j);

  return 0;
}