#include <stdio.h>

/* Magic Square */

int main()
{
  int nums[16], sums[4];

  printf("Enter the numbers from 1 to 16 in any order: ");
  for (int i = 15; i >= 0; i--)
  {
    /* sample input: 
        16 3 2 13 5 10 11 8 9 6 7 12 4 15 14 1
    */
    scanf("%d", &nums[i]);
  }
  printf("\n");

  for (int i = 15; i >= 3; i -= 4)
  {
    printf("%3d%3d%3d%3d\n", nums[i], nums[i - 1], nums[i - 2], nums[i - 3]);

    // calculate row sums and store in `sums`
    sums[(15 - i) / 4] = nums[i] + nums[i - 1] + nums[i - 2] + nums[i - 3];
  }
  printf("\n");

  printf("Row sums: ");
  for (int i = 0; i <= 3; i++)
  {
    printf(" %d", sums[i]);

    // calculate sum of column 1 and store in sums[i]
    sums[i] = nums[i] + nums[i + 4] + nums[i + 8] + nums[i + 12];
  }
  printf("\n"); 

  printf("Colums sums: ");
  for (int i = 0; i <= 3; i++) {
    printf(" %d", sums[i]);
  } 
  printf("\n"); 

  // use sums[0] and sums[1] to store the two diagonal sums
  sums[0] = nums[0] + nums[5] + nums[10] + nums[15];
  sums[1] = nums[3] + nums[6] + nums[9] + nums[12];
  printf("Diagonal sums: %d %d\n", sums[0], sums[1]);

  return 0;
}