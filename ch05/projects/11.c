#include <stdio.h>

const char *ones_to_eng(int n);
const char *tens_to_eng(int n);
const char *between_10_to_20_eng(int n);

int main()
{
  int tens_digit, ones_digit, n;

  printf("Enter a two-digit number: ");
  scanf("%1d%1d", &tens_digit, &ones_digit);
  n = tens_digit * 10 + ones_digit;
  printf("You entered the number: ");

  if (n >= 10 && n < 20)
  {
    printf("%s\n", between_10_to_20_eng(n));
  }
  else
  {
    printf("%s%s\n",
           tens_to_eng(tens_digit),
           ones_to_eng(ones_digit));
  }

  return 0;
}

const char *tens_to_eng(int n)
{
  switch (n)
  {
  case 2:
    return "twenty";
  case 3:
    return "thirty";
  case 4:
    return "forty";
  case 5:
    return "fifty";
  case 6:
    return "sixty";
  case 7:
    return "seventy";
  case 8:
    return "eighty";
  case 9:
    return "ninety";
  }
}

const char *ones_to_eng(int n)
{
  switch (n)
  {
  case 0:
    return "";
  case 1:
    return "-one";
  case 2:
    return "-two";
  case 3:
    return "-three";
  case 4:
    return "-four";
  case 5:
    return "-five";
  case 6:
    return "-six";
  case 7:
    return "-seven";
  case 8:
    return "-eight";
  case 9:
    return "-nine";
  }
}

const char *between_10_to_20_eng(int n)
{
  switch (n)
  {
  case 10:
    return "ten";
  case 11:
    return "eleven";
  case 12:
    return "twelve";
  case 13:
    return "thirteen";
  case 14:
    return "fourteen";
  case 15:
    return "fifteen";
  case 16:
    return "sixteen";
  case 17:
    return "seventeen";
  case 18:
    return "eighteen";
  case 19:
    return "nineteen";
  }
}
