#include <stdio.h>

/* Calculate average word length of a sentence */

int main()
{
  char chr;
  int i, num_words, num_chars;
  float res;

  printf("Enter a sentence: ");

  for (i = 0, num_words = 0, num_chars = 0;
       (chr = getchar()) != '\n';)
  {
    // printf("This char: %c; ", chr);

    /* ' ' and '.' signify end of a word */
    if ((chr == ' ') || (chr == '.'))
    {
      // printf("i = %d; ", i);

      /* `i` holds the length of the traversed word */
      num_chars += i;
      // printf("res = %d; ", num_chars);

      /* `num_words` holds the number of words counted */
      num_words += 1;
      // printf("count = %d; ", num_words);

      /* reset `i` */
      i = 0;

      // printf("Encountered a word end.\n");
    }
    else
    {
      /* counting number of chars of a word */
      i += 1;

      // printf("Still counting.\n");
    }
  }
  printf("\n");

  printf("Total num of chars: %d; Total num of words: %d\n", num_chars, num_words);
  res = (float)num_chars;
  res /= (float)num_words;

  printf("Average word length: %.2f\n", res);

  return 0;
}
