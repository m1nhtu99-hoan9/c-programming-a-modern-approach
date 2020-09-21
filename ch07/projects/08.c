#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

/* Find the earliest flight to the time user input 
     updated version of `../../ch05/projects/08.c`
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
const int minutes_difference(const struct Time t1, const struct Time t2);
const char *get_am_pm(const int h);
const int convert_hour(const int h);
void Time_print(const struct Time t);
void Time_input(struct Time *const t);

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
  int i, i_of_min, min;
  struct Time user_time;
  struct Time *user_time_ptr = &user_time;

  // printf("user pointer address: %zu\n", user_time_ptr);

  printf("Enter a time: ");
  Time_input(user_time_ptr);
  // scanf("%d:%d", &user_time.h, &user_time.m);

  for (min = minutes_difference(FLIGHTS[6].departure, user_time),
      i_of_min = 6,
      i = 5;
       i >= 0; i--)
  {
    int this_diff = minutes_difference(FLIGHTS[i].departure, user_time);
    if (this_diff <= min)
      // update the new smallest amount of minutes differences and its index
      i_of_min = i;
    min = this_diff;
  }

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

const int minutes_difference(const struct Time t1, const struct Time t2)
{
  return abs(minutes_since_midnight(t1) - minutes_since_midnight(t2));
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

void Time_input(struct Time *const t)
{
  int i;
  char cur;

  // printf("\nPointer address: %zu\n", &t);
  scanf("%2d:%2d", &t->h, &t->m);

  // strip space characters out of buffer
  for (;;)
  {
    cur = getchar();
    if (!isspace(cur))
      break;
  }

  switch (toupper(cur))
  {
  case 'P':
    t->h += 12;
    // printf("your input: hour <%d>, minute <%d>\n", t->h, t->m);
    break;
  case 'A':
    // printf("your input: hour <%d>, minute <%d>\n", t->h, t->m);
    break;
  default:
    printf("INVALID!\n");
    // printf("your input: hour <%d>, minute <%d>\n", t->h, t->m);
    break;
  }
}
