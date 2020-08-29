#include <stdio.h>

/* Calculate the number of digits of a input integer */

int main () {
  int n, i = 0;

  printf("Enter a nummber: ");
  scanf("%d", &n);
  // `printf` this line first before `n` is mutated
  printf("The number %d has ", n);

  while (n != 0) {
    ++i;
    n /= 10;
  }
  printf("%d digits\n", i);

  return 0;
}