#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

/* Check If Two Strings Are Anagrams */

int main() {
  bool res;
  int i, cur = '\0', char_indexes[(int) 'z' + 1] = {};

  /* Counting the number of occurrences of each alphabet character in the first input */
  printf("Enter first word: ");
  for (; cur != '\n';) {
    cur = getchar();
    if (isalpha(cur)) {
      char_indexes[(int) tolower(cur)]++;
    }
  }

  /* Using the same counter array, but decrement count value for alphabet characters encountered */
  printf("Enter second word: ");
  for (cur = '\0'; cur != '\n';) {
    cur = getchar();
    if (isalpha(cur)) {
      char_indexes[(int) tolower(cur)]--;
    }
  }

  /* If a letter's number of occurrences in first input
   * is different to that of its counterpart in second input,
   * then both string are not anagrams */
  for (i = (int) 'a', res = true; i <= 'z'; i++) {
    if (char_indexes[i] != 0) {
      // printf("anomaly: %c <count: %d>\n", i, char_indexes[i]);
      res = false;
      break;
    }
  }
  printf("The words are %s.\n", res ? "anagrams" : "not anagrams");

  return 0;
}