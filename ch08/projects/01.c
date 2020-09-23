#include <stdio.h>
#include <stdlib.h>

/* modified version of `repdigit.c` that show which digit(s) from user input are repeated */

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
      if (cur <= '9' && cur >= '0')
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

  printf("\nRepeated digit(s):");
  for (i = 0; i < 10; i++)
  {
    if (occurences[i] > 1)
    {
      printf("%2d", i);
    }
  }
  printf("\n");

  return 0;
}
