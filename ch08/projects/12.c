#include <stdio.h>
#include <ctype.h>
#include <string.h>

/* this is the same source code as `../../ch07/projects/05.c` */

/**
 * Calculate Scrabble value of a character
*/
int point_of_char(char *const arr_ptr, size_t id);

int main()
{

  char *input;
  size_t str_len;
  unsigned int res = 0;

  printf("Enter a word: ");
  scanf("%s", input);

  str_len = strlen(input);
  for (int i = 0; i < str_len; i++)
  {
    // accumulate the result
    res += point_of_char(input, i);
  }

  printf("Scrabble value: %u\n", res);

  return 0;
}

/* implementation */

const int POINTS[7] = {1, 2, 3, 4, 5, 8, 10};
const char CHARS[7][12] = {"AEILNORSTU\0",
                           "DG\0",
                           "BCMP\0",
                           "FHVWY\0",
                           "K\0",
                           "JX\0",
                           "QZ\0"};

int point_of_char(char *const arr_ptr, size_t id)
{
  short int i, j;

  // traverse through list of strings in CHARS
  for (i = j = 0; i < 7; i++)
  {
    // traverse through each character of the string of CHARS[i]
    for (j = 0; CHARS[i][j] != '\0'; j++)
    {
      if (toupper(arr_ptr[id]) == CHARS[i][j])
      {
        return POINTS[i];
      }
    }
  }

  /* will never get here */
  return 0;
}
