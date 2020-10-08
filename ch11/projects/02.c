#include <stdio.h>
#include <stdlib.h>

/* Find the earliest flight to the time user input
 * modified version of `../../ch05/projects/08.c`
 */

struct Time
{
  int h;
  int m;
};

struct Flight
{
  struct Time departure;
  struct Time arrival;
};

const int minutes_since_midnight(const struct Time t);
const char *get_am_pm(const int h);
const int convert_hour(const int h);
void Time_print(const struct Time t);

/* @params: `desired_time` is expressed in minutes since midnight;
 *          `*desired_flight_index` is index of the desired flight in the given constant array
 */
void find_closest_flight(int desired_time, int *desired_flight_index);

const struct Flight FLIGHTS[] = {
    {
        .departure = {.h = 8, .m = 0},
        .arrival = {.h = 10, .m = 16},
    },
    {
        .departure = {.h = 9, .m = 43},
        .arrival = {.h = 11, .m = 52},
    },
    {
        .departure = {.h = 11, .m = 19},
        .arrival = {.h = 13, .m = 31},
    },
    {
        .departure = {.h = 12, .m = 47},
        .arrival = {.h = 15, .m = 0},
    },
    {
        .departure = {.h = 14, .m = 0},
        .arrival = {.h = 16, .m = 8},
    },
    {
        .departure = {.h = 15, .m = 45},
        .arrival = {.h = 17, .m = 55},
    },
    {
        .departure = {.h = 19, .m = 0},
        .arrival = {.h = 21, .m = 20},
    },
    {
        .departure = {.h = 21, .m = 45},
        .arrival = {.h = 23, .m = 58},
    },
};

int main()
{
  int i_of_min;
  struct Time user_time;

  printf("Enter a 24-hour time: ");
  scanf("%d:%d", &user_time.h, &user_time.m);

  find_closest_flight(minutes_since_midnight(user_time), &i_of_min);

  printf("Closest departure time is ");
  Time_print(FLIGHTS[i_of_min].departure);
  printf(", arriving at ");
  Time_print(FLIGHTS[i_of_min].arrival);
  printf(".\n");

  return 0;
}

/* implementations */

const int minutes_since_midnight(const struct Time t)
{
  return t.h * 60 + t.m;
}


const char *get_am_pm(const int h)
{
  return (h < 12) ? "AM\0" : "PM\0";
}

const int convert_hour(const int h)
{
  return (h > 12) ? (h % 12) : h;
}

void Time_print(const struct Time t)
{
  printf("%.2d:%.2d %s", convert_hour(t.h), t.m, get_am_pm(t.h));
}

void find_closest_flight(int desired_time, int *desired_flight_index) {
  int i, i_of_min, min;

  for (min = abs(minutes_since_midnight(FLIGHTS[6].departure) - desired_time),
       i_of_min = 6,
       i = 5;
       i >= 0; i--)
  {
    int this_diff = minutes_since_midnight(FLIGHTS[i].departure) - desired_time;
    if (abs(this_diff) <= min) {
      // update the new smallest amount of minutes differences and its index
      i_of_min = i;
    }
    min = this_diff;
  }

  *desired_flight_index = i_of_min;
}
