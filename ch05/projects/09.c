#include <stdio.h>
#include <stdbool.h>

/* Given 2 dates, find out which date is earlier */

int compare(int a, int b)
{
  return (a > b) ? 1 : ((a == b) ? 0 : -1);
}

void print_date(int m, int d, int y)
{
  printf("%d/%d/%2d", m, d, y % 100);
}

void scan_date(int *m_ptr, int *d_ptr, int *y_ptr)
{
  scanf("%d/%d/%d", m_ptr, d_ptr, y_ptr);
}

int main()
{
  int dates[2], months[2], years[2];
  bool is_1st_earlier;

  printf("Enter first date (mm/dd/yyyy): ");
  scan_date(&months[0], &dates[0], &years[0]);
  printf("Enter first date (mm/dd/yyyy): ");
  scan_date(&months[1], &dates[1], &years[1]);

  switch (compare(years[0], years[1]))
  {
  case -1:
    is_1st_earlier = true;
    break;
  case 1:
    is_1st_earlier = false;
    break;
  case 0:
    switch (compare(months[0], months[1]))
    {
    case -1:
      is_1st_earlier = true;
      break;
    case 1:
      is_1st_earlier = false;
      break;
    case 0:
      switch (compare(dates[0], dates[1]))
      {
      case -1:
        is_1st_earlier = true;
        break;
      case 1:
        is_1st_earlier = false;
        break;
      case 0:
        printf("These are the same dates.\n");
        return 0;
      }
    }
  }

  if (is_1st_earlier)
  {
    print_date(months[0], dates[0], years[0]);
    printf(" is earlier than ");
    print_date(months[1], dates[1], years[1]);
    printf(".\n");
  }
  else
  {
    print_date(months[1], dates[1], years[1]);
    printf(" is earlier than ");
    print_date(months[0], dates[0], years[0]);
    printf(".\n");
  }

  return 0;
}