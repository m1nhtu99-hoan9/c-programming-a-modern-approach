#include <stdio.h>
#define DAYS_PER_WEEK 7

int main()
{
  int days, starting_week_day, i;

  /* 
    A line need to display only `DAYS_PER_WEEK` piece of info, 
      which can be padding space (2 spaces) or a number.

    `cursor` helps to keep track of how many piece of info has been displayed in a line:
    When a piece of info is display, 
      update `cursor` respectively by substracting 1 from it.
    `cursor` equalling 0 signifies printing of new line 
      & resetting of `cursor` to its intial value (`DAYS_PER_WEEK`).
  */
  int cursor = DAYS_PER_WEEK;

  printf("Enter number of days in month: ");
  scanf("%d", &days);
  printf("Enter starting days of the week: ");
  scanf("%d", &starting_week_day);
  printf("\n");

  /* print 3 padding spaces for `starting_week_day - 1` times */
  for (i = starting_week_day - 2; i >= 0; i--)
  {
    cursor -= 1;
    printf("   ");
  }

  for (i = 1; i <= days; i++)
  {
    cursor -= 1;
    printf("%2d %c", i, cursor == 0 ? '\n' : '\0');
    if (cursor == 0)
      // reset the cursor
      cursor = DAYS_PER_WEEK;
  }
  printf("\n");

  return 0;
}
