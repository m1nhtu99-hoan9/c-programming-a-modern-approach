#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/* B1FF ENCODING */

/* convert letter at index `i` to its B1FF counterpart */
void b1ff_filter(char *const chr, const int i);
/* `scanf` for sentence, and convert the whole string to uppercase */
void scanf_string(char *const chr);

int main()
{
  int final_len;
  char cur, mes[1000];

  printf("Enter message: ");
  /* read the sentence into `mes` and uppercase it */
  scanf_string(mes);

  /* implement the conversion */
  for (int i = 0; *(mes + i) != '\0'; i++)
  {
    b1ff_filter(mes, i);
  }

  /* print the string out & append 10 exclamation mark */
  printf("In B1FF-speak: ");
  for (int i = 0; *(mes + i) != '\0'; i++)
  {
    printf("%c", *(mes + i));
  }
  for (int i = 0; i < 10; i++)
  {
    printf("!");
  }
  printf("\n");

  return 0;
}

/* implementations */

void scanf_string(char *const chr)
{
  int i = 0;
  char cur;

  for (;;)
  {
    cur = getchar();
    if (cur != '\n')
    {
      // append the uppercased `cur` to given string
      *(chr + (i++)) = toupper(cur);
    }
    else
    {
      // signify the end of the string
      *(chr + i) = '\0';
      break;
    }
  }
}

void b1ff_filter(char *const chr, const int i)
{
  switch (*(chr + i))
  {
  case 'A':
    *(chr + i) = '4';
    break;
  case 'B':
    *(chr + i) = '8';
    break;
  case 'E':
    *(chr + i) = '3';
    break;
  case 'I':
    *(chr + i) = '1';
    break;
  case 'O':
    *(chr + i) = '0';
    break;
  case 'S':
    *(chr + i) = '5';
    break;
  }
}