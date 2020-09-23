#include <stdio.h>
#include <stdlib.h>

int main()
{
  int i, j, cur, col_sums[5] = {}, row_sums[5] = {};

  for (i = 0; i < 5; i++)
  // traverse rows
  {
    printf("Enter row %d: ", i + 1);
    for (j = 0; j < 5; j++)
    // traverse columns
    {
      scanf("%d", &cur);

      // accumulated scanned value to respective running totals
      row_sums[i] += cur;
      col_sums[j] += cur;
    }
  }

  /* print out results */

  printf("\nRow totals:\t");
  for (int i = 0; i < 5; i++)
  {
    printf("%3d", row_sums[i]);
  }
  printf("\nColumn totals:\t");
  for (int i = 0; i < 5; i++)
  {
    printf("%3d", col_sums[i]);
  }
  printf("\n");

  return 0;
}