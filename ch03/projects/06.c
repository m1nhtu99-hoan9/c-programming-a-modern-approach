/* addfrac.c modified */
#include <stdio.h>

int main(void)
{
  int nums[2], denoms[2], result_num, result_denom;

  printf("Enter two fractions seperated by a plus sign: ");
  scanf("%d/%d+%d/%d", &nums[0], &denoms[0], &nums[1], &denoms[1]);

  result_num = nums[0] * denoms[1] + nums[1] * denoms[0];
  result_denom = denoms[0] * denoms[1];

  printf("The sum is %d/%d\n", result_num, result_denom);

  return 0;
}