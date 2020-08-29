#include <stdio.h>

const char *get_am_pm(const int h);
const int convert_hour(const int h);

int main()
{
  int hour, minute;

  printf("Enter a 24-hour time: ");
  scanf("%d:%d", &hour, &minute);

  // if the input is invalid, terminate the program
  if (hour >= 24 || hour < 0) {
    printf("Invalid hour input!!!\n");
    return 1;
  } 

  printf("Equivalent 12-hour time: %.2d:%.2d %s\n",
         convert_hour(hour),
         minute,
         get_am_pm(hour));

  return 0;
}

const char *get_am_pm(const int h)
{
  return (h < 12) ? "AM\0" : "PM\0";
}

const int convert_hour(const int h)
{
  return (h > 12) ? (h % 12) : h;
}