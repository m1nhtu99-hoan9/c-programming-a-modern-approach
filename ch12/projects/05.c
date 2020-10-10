#include <ctype.h>
#include <stdio.h>

/* Reverse the words in a sentence
 * modified version of `../../ch08/projects/14.c`
 */

int main() {
  char cur = '\0', sentence[100][100] = {};
  short int i, j;

  printf("Enter a sentence: ");
  /* Iteratively scan input and store it as array of words.
   * At the end of this loop, number of words in the sentence equals `j` minus 1
   */
  for (i = 0, j = 0; cur != '\n';) {
    cur = getchar();
    if (isspace(cur)) {
      // signify the end of the word being reading
      sentence[j][i] = '\0';
      // reset counter for character index in the word being scanning
      i = 0;
      // increase counter for number of words
      j++;
    }
    else {
      sentence[j][i++] = cur;
    }
  }

  /* Print the sentence out in reverse */
  for (i = j; i >= 0; i--) {
    if (sentence[i][0] != '\0') {
      for (char *j_ptr = sentence[i]; *j_ptr != '\0' ;j_ptr++) {
        printf("%c", *j_ptr);
      }
//      for (j = 0; sentence[i][j] != '\0'; j++) {
//        printf("%c", sentence[i][j]);
//      }
      printf(" ");
    }
    else {
      continue;
    }
  }
  printf("\n");

  return 0;
}

// Test case: "you can cage a swallow can't you" -> "you can't swallow a cage can you"

