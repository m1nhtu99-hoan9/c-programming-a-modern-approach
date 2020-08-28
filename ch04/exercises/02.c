#include <stdio.h>

int main()
{
  int i, j;

  printf("Input 2 positive integers: ");
  scanf("%d%d", &i, &j);

  printf("(-i)/j = %d\n", -i / j);
  printf("-(i/j) = %d\n", -(i / j));

  /* CONCLUSION: 
      These two result values are the same 
  */

  return 0;
}