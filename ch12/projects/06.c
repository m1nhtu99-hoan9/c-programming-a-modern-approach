#include <stdio.h>

/* Sorts an array of integers using Quicksort algorithm
 * modified version of `qsort.c` (chapter 9, page 207)
 */

#define N 10

void quicksort(int* a_low, int* a_high);
int *split(int* a_low, int* a_high);

int main(void)
{
  int a[N], i;

  printf("Enter %d numbers to be sorted: ", N);
  for (i = 0; i < N; i++)
    scanf("%d", a+i);

  quicksort(a, a + N - 1);

  printf("In sorted order: ");
  for (i = 0; i < N; i++)
    printf("%d ", a[i]);
  printf("\n");

  return 0;
}

void quicksort(int *a_low, int *a_high)
{
  int *middle;

  if (a_low >= a_high) return;
  middle = split(a_low, a_high);
  quicksort(a_low, middle - 1);
  quicksort(middle + 1, a_high);
}

int *split(int *a_low, int *a_high) {
  int pivot = *a_low;

  /* At the end of this loop, `a_high` is the correct position to place `pivot` value in.
     All elements from the head of the array to the pivot position are smaller than or equal to `pivot`.
     All elements from the pivot position to the end of the array are larger than or equal to `pivot`
  */
  for (;;) {
    while (a_low < a_high && *a_high >= pivot) {
      // shift `a_high` pointer 1 cell leftward
      a_high--;
    }
    if (a_low >= a_high) {
      break;
    }
    /* `a_high` currently points to an element smaller than `pivot`;
        hence, this value is assigned to the first position in the sorted array */
    *(a_low++) = *a_high;

    while (a_low < a_high && *a_low <= pivot) {
      // shift `a_low` pointer 1 cell rightward
      a_low++;
    }
    if (a_low >= a_high) {
      break;
    }
    /* `a_low` currently points to an element larger than `pivot`;
        hence, this value is assigned to the last position in the sorted array */
    *(a_high--) = *a_low;
  }

  *a_high = pivot;
  return a_high;
}

