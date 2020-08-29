#include <stdio.h>

/*
  Conclusion:
    For comparison operators, side effects are only performed on the left operands.
*/

int main()
{
  int i, j, k;

  /* question (a) */
  i = 3;
  j = 4;
  k = 5;
  printf("%d\n", i < j || ++j < k);
  printf("%d %d %d\n", i, j, k);
  printf("\n");

  /* question (b) */
  i = 7;
  j = 8;
  k = 9;
  printf("%d\n", i - 7 && j++ < k);
  printf("%d %d %d\n", i, j, k);
  printf("\n");

  /* question (c) */
  i = 7;
  j = 8;
  k = 9;
  printf("%d\n", (i = j) || (j = k));
  printf("%d %d %d\n", i, j, k);
  printf("\n");

  /* question (d) */
  i = 7;
  j = 8;
  k = 9;
  printf("%d\n", ++i || ++j && ++k);
  printf("%d %d %d\n", i, j, k);

  return 0;
}