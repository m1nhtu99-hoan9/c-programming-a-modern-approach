#include <stdio.h>
#include <stdlib.h>

/* Selection Sort */

void selection_sort(int *const arr, int cur_id) {
  int max_i, tmp, i;

  if (!cur_id) {
    /* base case */
    // printf("<debug>base case</debug>\n");
    return;
  }
  else {
    /* recursive cases */

    // find the maximum value in the current sub-array
    for (max_i = 0, i = 1; i < cur_id; i++) {
      if (arr[i] > arr[max_i]) {
        max_i = i;
      }
    }

    // printf("<debug> current_id: %d, index of max value: %d, max value: %d </debug>\n", cur_id, max_i, arr[max_i]);
    // swap the largest element with the last element in the current sub-array
    tmp = arr[max_i];
    arr[max_i] = arr[cur_id - 1];
    arr[cur_id - 1] = tmp;

    selection_sort(arr, cur_id - 1);
  }
}

int main() {
  char chr_cur;
  int i, len;
  int *arr = (int *) calloc(100, sizeof(int));

  printf("Input array of integers\n");
  printf("(please start your input with a blank space, and then each number separated by a black space): \n");
  for (i = 0
      // consume blank space between input numbers
      ; i < 100 && (chr_cur = getchar() != '\n')
      ; i++) {
    scanf(" %d", arr + i);
  }
  len = i;

  // printf("<debug> Array address: %p </debug>\n", arr);
  printf("<debug> Input array: ");
  for (i = 0; i < len; i++) {
    printf("%d ", arr[i]);
  }
  printf("</debug>\n");

  selection_sort(arr, len);

  printf("Sorted array: ");
  for (i = 0; i < len; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  free(arr);

  return 0;
}