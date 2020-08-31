#include <stdio.h>
#include <stdbool.h>

/* Given 2 dates, find out which date is earlier 
    modified version of `../../ch05/projects/09.c`
*/

struct Date
{
  int month;
  int date;
  int year;
};

int compare(int a, int b);
int compare_dates(struct Date *d1_ptr, struct Date *d2_ptr);
// safely assign data of the 2nd `struct Date` to the 1st `struct Date`
void assign_date(struct Date(*const d1_ptr), struct Date(*const d2_ptr));
void print_date(struct Date *const d);
void scan_date(struct Date *d);

int main()
{
  /*
    `d_min`   stores the earliest date
    `d_input` stores user's latest input
  */
  struct Date d_min, d_input;
  bool is_first_ask = true;

  for (;;)
  {
    printf("Enter a date (mm/dd/yyyy) {Enter 0/0/0 to terminate}: ");
    scan_date(&d_input);

    // check case for terminating the program
    if (!d_input.date || !d_input.month)
      break;

    if (compare_dates(&d_input, &d_min) <= 0 || is_first_ask)
    {
      // update the earliest date or initiate `d_min`
      assign_date(&d_min, &d_input);
      
      is_first_ask = false;
    }
  }

  print_date(&d_min);
  printf(" is the earliest date.\n");

  return 0;
}

/* implementation */

int compare(int a, int b)
{
  return (a > b) ? 1 : ((a == b) ? 0 : -1);
}

void print_date(struct Date *const d)
{
  printf("%d/%d/%.2d", d->month, d->date, (d->year) % 100);
}

void scan_date(struct Date *d)
{
  scanf("%d/%d/%d", &(d->month), &(d->date), &(d->year));
}

/** Safely assign fields of the 2nd struct Date to the 1st struct Date
*/
void assign_date(struct Date(*const d1_ptr), struct Date(*const d2_ptr))
{
  d1_ptr->date = d2_ptr->date;
  d1_ptr->month = d2_ptr->month;
  d1_ptr->year = d2_ptr->year;
}

/** Compare the 1st date to the 2nd date
 * @returns 
 *    (-1) if the first date is earlier;
 *     (1) if the second is earlier;
 *     (0) if these are the same date
 *          
*/
int compare_dates(struct Date *d1_ptr, struct Date *d2_ptr)
{
  int res;

  switch (compare(d1_ptr->year, d2_ptr->year))
  {
  case -1:
    res = -1;
    break;
  case 1:
    res = 1;
    break;
  case 0:
    switch (compare(d1_ptr->month, d2_ptr->month))
    {
    case -1:
      res = -1;
      break;
    case 1:
      res = 1;
      break;
    case 0:
      switch (compare(d1_ptr->date, d2_ptr->date))
      {
      case -1:
        res = -1;
        break;
      case 1:
        res = 1;
        break;
      case 0:
        res = 0;
        break;
      }
    }
  }

  return res;
}