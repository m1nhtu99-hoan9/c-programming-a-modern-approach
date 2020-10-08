#include <stdio.h>
#include <stdlib.h>

int *find_largest(int a[], int n) {
  int id_max = 0;

  for (int i = 1; i < n; i++) {
    if (a[i] > a[id_max])
      id_max = i;
  }

  return a + id_max;
}

int main() {
  int len;
  printf("Array length? ");
  scanf("%d", &len);

  if (len <= 0) {
    printf("INVALID ARRAY LENGTH!\n");
    return 1;
  }
  else {
    int *arr = malloc(len * sizeof(int));

    printf("Input array: ");
    for (int i = 0; i < len; i++) {
      scanf(" %d", arr + i);
    }

    printf("The largest: %d\n", *find_largest(arr, len));

    free(arr);
    return 0;
  }
}