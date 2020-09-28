#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

/* this is the same source code as `../../ch07/projects/11.c` */

int main()
{
  int i = 0;
  bool is_scanning_last = false;
  char cur, *first, *last;

  first = malloc(50 * sizeof(char));
  last = malloc(50 * sizeof(char));

  printf("Enter a first and last name: ");
  for (;;)
  {
    cur = getchar();
    if (cur != '\n')
    {
      if (isspace(cur))
      {
        i = 0;
        is_scanning_last = true;
      }
      else
      {
        if (is_scanning_last)
        {
          last[i++] = cur;
        }
        else
        {
          first[i++] = cur;
        }
      }
    }
    else
    {
      break;
    }
  }

  printf("%s, %c.\n", last, first[0]);
  return 0;
}
