#include <stdio.h>

int main()
{
  int i, j;

  printf("Input two integers: ");
  scanf("%d %d", &i, &j);

  printf(
    "Result of the comparison of i to j: %d\n",
    (i < j) ? -1 : ((i == j) ? 0 : 1)
  );

  return 0;
}