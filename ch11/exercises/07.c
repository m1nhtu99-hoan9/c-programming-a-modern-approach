#include <stdio.h>
#include <stdlib.h>

int is_leap_year(int *const year) {
  if (*year < 0) {
    printf("INVALID YEAR INPUT!\n");
    exit(EXIT_FAILURE);
  }
  else {
    return !(*year % 4);
  }
}

int num_days_in_month(int month, int leap_indicator) {
  if (month < 1 || month > 12) {
    printf("INVALID MONTH NUMBER!\n");
    exit(EXIT_FAILURE);
  }
  else {
    if (month == 2) {
      return 28 + leap_indicator;
    }
    else {
      // return 30 + ((month < 8) ? (month % 2) : !(month % 2));
      return 30 + (!(month < 8) || (month % 2));
    }
  }
}

void split_date(int day_of_year, int year, int *const month, int *const day) {
  const int leap_indicator = is_leap_year(&year);

  if (day_of_year < 1 || day_of_year > 365 + leap_indicator) {
    printf("INVALID INPUT!\n");
    exit(EXIT_FAILURE);
  }
  else {
    int NUM_DAYS[13];

    NUM_DAYS[0] = 0;
    for (int _month = 1; _month <= 12; _month++) {
      // calculate the number of days since the 01/01 to this month
      NUM_DAYS[_month] = NUM_DAYS[_month - 1] + num_days_in_month(_month, leap_indicator);
    }

    for (int _month = 1; _month <= 12; _month++) {
      if (day_of_year > NUM_DAYS[_month - 1] && day_of_year <= NUM_DAYS[_month]) {
        *month = _month;
        *day = day_of_year - NUM_DAYS[_month - 1];
        break;
      }
    }
  }

}

int main () {
  int days, y, m, d;
  printf("What year? ");
  scanf("%d", &y);
  int leap_indicator = is_leap_year(&y);

  printf("Input an integer between 1 and %d, specifying a particular day within the year of %d: "
         , (365 + leap_indicator), y);
  scanf("%d", &days);

  split_date(days, y, &m, &d);
  printf("Result: %.2d/%.2d\n", d, m);

  return 0;
}