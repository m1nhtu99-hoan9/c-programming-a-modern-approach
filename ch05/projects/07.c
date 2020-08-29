#include <stdio.h>

/* Find the largest and smallest of four integers entered by user */

int main () {
  int nums[4], max, min, i;

  printf("Enter four integers: ");
  for (i = 0; i < 4; i++) {
    scanf("%d", &nums[i]);
  }

  max = min = nums[3]; // initiate `max` and `min`
  for (i = 2; i >= 0; i--) {
    if (nums[i] > max) max = nums[i];
    if (nums[i] < min) min = nums[i];
  }

  printf("Largest: %d\n", max);
  printf("Smallest: %d\n", min);
  
  return 0;
}