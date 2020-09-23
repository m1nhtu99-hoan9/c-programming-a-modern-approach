#include <stdio.h>
#include <ctype.h>

/* Count the number of vowels in a sentence */

char *const VOWELS = "AEOUIaeoui";

int main()
{
  char cur, *inp;
  // declares an array and fills its values with zeroes
  int res = 0, index_array[128] = {};

  /* count number of occurances for each character in user's input */
  printf("Enter a sentence: ");
  for (;;)
  {
    cur = getchar();

    if (cur != '\n')
    {
      index_array[cur]++;
    }
    else
    {
      break;
    }
  }

  /* calculate the sum of occurances of vowel characters */
  for (int i = 0; i < 10; i++)
  {
    res += index_array[VOWELS[i]];
  }

  printf("Your sentence contains %d vowels.\n", res);
  return 0;
}
