#include <stdio.h>

/* Finds the largest and smallest elements in an array
 * modified version of `maxmin.c` (chapter 11, page 250)
 */

#define N 10

void max_min(int *a, int *max, int *min);

int main(void)
{
  int b[N], i, big, small;

  printf("Enter %d numbers: ", N);
  for (i = 0; i < N; i++)
    scanf("%d", b+i);

  max_min(b, &big, &small);

  printf("Largest: %d\n", big);
  printf("Smallest: %d\n", small);

  return 0;
}

void max_min(int *a, int *max, int *min)
{
  int* i_ptr;

  *max = *min = a[0];
  for (i_ptr = a; i_ptr <= a + N; i_ptr++) {
    if (*i_ptr > *max)
      *max = *i_ptr;
    else if (*i_ptr < *min)
      *min = *i_ptr;
  }
}