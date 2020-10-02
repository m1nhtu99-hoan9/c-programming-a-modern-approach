#include <stdio.h>
#include <stdlib.h>

/* Selection Sort */

void swap(int *a_ptr, int *b_ptr) {
  *a_ptr = *a_ptr + *b_ptr;
  *b_ptr = *a_ptr - *b_ptr;
  *a_ptr = *a_ptr - *b_ptr;
}

void sort_iteration_step(int *const arr, int length) {
  int i, max_id, max;

  for (i = max_id = 0, max = *(arr + 0); i <= length - 1; i++) {
    if (*(arr + i) > max) {
      max = *(arr + i);
      max_id = i;
    }
  }

  swap(arr + length - 1, arr + max_id);
}

void selection_sort(int *const arr, int length) {
  if (length > 1) {
    sort_iteration_step(arr, length);
    selection_sort(arr, length - 1);
  }
}

int main() {
  int i, len;
  int *arr = (int *) calloc(10000, sizeof(int));

  printf("Input array of integers\n");
  printf("(each number separated by enter character; to signify end of the input, type 'q' and then enter): \n");
  for (i = 0; i < 100000; i++) {
    len = scanf("%d", arr + i);
    if (!len) {
      break;
    }
  }
  len = i;

  printf("Array address: %p\n", arr);
  selection_sort(arr, len);

  printf("Sorted array: ");
  for (i = 0; i < len; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  free(arr);

  return 0;
}