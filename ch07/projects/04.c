#include <stdio.h>

/* Convert alphabetic phone number into numeric form */

/* Convert character to its respective digit */
void convert_char_to_digit(char *const chr_ptr, int id);

int main()
{
  char *const phone_number;
  printf("Enter phone number: ");
  scanf("%s", phone_number);

  for (int i = 0; phone_number != NULL; i++)
  {
    convert_char_to_digit(phone_number, i);
    printf("%c", phone_number[i]);
  }

  //printf("%s", *phone_number);

  return 0;
}

/* implementation */

void convert_char_to_digit(char *const chr_ptr, int id)
{
  if (chr_ptr[id] >= 'A' && chr_ptr[id] <= 'C')
  {
    chr_ptr[id] = '2';
  }
  else if (chr_ptr[id] >= 'D' && chr_ptr[id] <= 'F')
  {
    chr_ptr[id] = '3';
  }
  else if (chr_ptr[id] >= 'G' && chr_ptr[id] <= 'I')
  {
    chr_ptr[id] = '4';
  }
  else if (chr_ptr[id] >= 'J' && chr_ptr[id] <= 'L')
  {
    chr_ptr[id] = '5';
  }
  else if (chr_ptr[id] >= 'M' && chr_ptr[id] <= 'O')
  {
    chr_ptr[id] = '6';
  }
  else if (chr_ptr[id] >= 'P' && chr_ptr[id] <= 'S')
  {
    chr_ptr[id] = '7';
  }
  else if (chr_ptr[id] >= 'T' && chr_ptr[id] <= 'V')
  {
    chr_ptr[id] = '8';
  }
  else if (chr_ptr[id] >= 'W' && chr_ptr[id] <= 'Y')
  {
    chr_ptr[id] = '9';
  }
}
