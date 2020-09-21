#include <ctype.h>
#include <stdio.h>
#include "readline.h"

int read_line(char str[], int n)
{
  int ch, i = 0;

  // skip all the leading white spaces
  for (;;)
  {
    if (!isspace(ch = getchar()))
      break;
  }

  while (ch != '\n' && ch != EOF)
  // read input and store them into `str`
  {
    if (i < n)
      str[i++] = ch;
    ch = getchar();
  }

  str[i] = '\0';
  return i;
}