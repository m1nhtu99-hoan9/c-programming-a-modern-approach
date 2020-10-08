#include <stdio.h>
#include <stdlib.h>

void find_two_largest(int n, int a[n], int *const largest, int *const second_largest) {
  *largest = *second_largest = a[0];
  for (int i = 1; i < n; i++) {
    // if the current element is larger than the current largest
    if (*largest < a[i]) {
      *second_largest = *largest;
      *largest = a[i];
    }
    // if the current element is in between the current second largest and the current largest
    else {
      if (*second_largest < a[i]) {
        *second_largest = a[i];
      }
    }
  }
}

int main() {
  int len, max, max1;

  printf("The length of the array? ");
  scanf("%d", &len);

  if (len <= 0) {
    printf("INVALID INPUT!");
    return 1;
  }
  else {
    int *arr = (int *) malloc(len * sizeof(int));

    printf("Enter array (each element separated by a blank space): ");
    for (int i = 0; i < len; i++) {
      scanf(" %d", arr+i);
    }

    find_two_largest(len, arr, &max, &max1);

    printf("The largest element: %d; The second largest element: %d\n", max, max1);

    free(arr);
    return 0;
  }
}