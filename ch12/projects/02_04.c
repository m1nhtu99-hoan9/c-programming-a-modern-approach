#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* Check if a string is palindrome */

int main() {
  char *mes = malloc(1000 * sizeof(char));

  printf("Enter a message: ");

  char cur;
  unsigned short i;
  for (i = 0;; i++) {
    cur = getchar();
    if (cur == '\n') {
      break;
    }
    else {
      *(mes + i) = cur;
    }
  }

  char *i_ptr, *j_ptr, i_chr, j_chr;
  for (i_ptr = mes + 0, j_ptr = mes + i - 1; j_ptr >= i_ptr + 1; ) {
    if (!isalpha(*i_ptr)) {
      i_ptr++;
    }
    else if (!isalpha(*j_ptr)) {
      j_ptr--;
    }
    else {
      i_chr = tolower(*i_ptr);
      j_chr = tolower(*j_ptr);

      if (i_chr != j_chr) {
        /* prematurely terminate */
        // printf("<debug> compared %c with %c </debug>\n", i_chr, j_chr);
        printf("Not a palindrome!\n");

        free(mes);
        return 0;
      }
      else {
        // printf("<debug> compared %c with %c </debug>\n", i_chr, j_chr);
        i_ptr++;
        j_ptr--;
      }
    }
  }
  // if the program reaches here without being prematurely terminated, then
  printf("Palindrome!\n");

  free(mes);
  return 0;
}

// Test case: "He lived as a devil, eh?" -> True