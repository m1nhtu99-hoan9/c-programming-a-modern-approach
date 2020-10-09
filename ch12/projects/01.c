#include <stdio.h>
#include <stdlib.h>

int main() {
  unsigned int i;
  char cur;
  char *inp = malloc(1000 * sizeof(char));

  printf("Enter a message: ");
  for (i = 0;; i++) {
    if ((cur = getchar()) != '\n') {
      *(inp + i) = cur;
    }
    else {
      break;
    }
  }
  // at the end of the loop, *(inp + i) is '\n'

  printf("Reversal is: ");
  for (char *i_ptr = inp + i - 1; i_ptr >= inp; i_ptr--) {
    printf("%c", *i_ptr);
  }
  printf("\n");

  free(inp);
  return 0;
}