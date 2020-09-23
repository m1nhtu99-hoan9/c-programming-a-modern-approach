#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* modified version of `repdigit.c` that show table of occurences */

int main()
{
  int i, occurences[10] = {};
  char cur;

  printf("Enter a number: ");
  for (;;)
  {
    cur = getchar();
    if (cur != '\n')
    {
      if (isspace(cur))
        continue;
      else if (cur <= '9' && cur >= '0')
        // accumulate the number of occurences
        occurences[cur - '0']++;
      else
      {
        printf("INVALID INPUT!\n");
        return 1;
      }
    }
    else
    {
      break;
    }
  }

  printf("\nDigit:\t\t");
  for (i = 0; i < 10; i++)
  {
    printf("%3d", i);
  }
  printf("\nOccurences:\t");
  for (i = 0; i < 10; i++)
  {
    printf("%3d", occurences[i]);
  }
  printf("\n");

  return 0;
}
