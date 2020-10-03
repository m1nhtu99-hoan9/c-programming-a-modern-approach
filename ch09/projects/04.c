#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

/* Check If Two Strings Are Anagrams
 * modified version of `../../ch08/projects/16.c` */

/* Read user's input word, count number of occurrences of each alphabet character in the word
 * and store them in `counts` array */
void read_word (int counts[26]);
/* Check if two arrays are identical */
bool equal_array(int counts1[26], int counts2[26]);

int main() {
  int char_counts_1 [26] = {}, char_counts_2 [26] = {};

  /* Counting the number of occurrences of each alphabet character in the first input */
  printf("Enter first word: ");
  read_word(char_counts_1);

  /* Counting the number of occurrences of each alphabet character in the second input */
  printf("Enter second word: ");
  read_word(char_counts_2);

  printf("The words are %s.\n", equal_array(char_counts_1, char_counts_2) ? "anagrams" : "not anagrams");

  return 0;
}

/* implementation */

void read_word (int counts[26]) {
  char cur = '\0';

  for (; cur != '\n';) {
    cur = getchar();
    if (isalpha(cur)) {
      counts[(int) tolower(cur) - 'a']++;
    }
  }
}

bool equal_array(int counts1[26], int counts2[26]) {
  bool res = true;

  for (unsigned short int i = 0; i <= 25; i++) {
    if (counts1[i] != counts2[i]) {
      res = false;
      break;
    }
  }

  return res;
}