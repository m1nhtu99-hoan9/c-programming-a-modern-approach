#include <stdio.h>

int main()
{
  printf("`int` size: %zu\n", sizeof(int));
  printf("`short` size: %zu\n", sizeof(short));
  printf("`long` size: %zu\n", sizeof(long));
  printf("`float` size: %zu\n", sizeof(float));
  printf("`double` size: %zu\n", sizeof(double));
  printf("`long double` size: %zu\n", sizeof(long double));

  return 0;
}
