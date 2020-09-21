#include <stdio.h>
#include <stdint.h>

short fact_short(int *const n);
int fact_int(int *const n);
long fact_long(int *const n);
long long fact_long_long(int *const n);
float fact_float(int *const n);
double fact_double(int *const n);
long double fact_long_double(int const *n);

int main()
{
  int inp;

  printf("Enter a positive integer: ");
  scanf("%d", &inp);

  printf("Factorial of %d as ...\n", inp);
  printf("`short`:\t\t%hd\n", fact_short(&inp));
  printf("`int`:\t\t%d\n", fact_int(&inp));
  printf("`long`:\t\t%ld\n", fact_long(&inp));
  printf("`long long`:\t%lld\n", fact_long_long(&inp));
  printf("`float`:\t%f\n", fact_float(&inp));
  printf("`double`:\t%lf\n", fact_double(&inp));
  printf("`long double`:\t%Lf\n", fact_long_double(&inp));

  return 0;
}

short fact_short(int *const n)
{
  short res = 1;

  for (int i = 1; i <= *n; i++)
  {
    res *= i;
  }

  return res;
}
int fact_int(int *const n)
{
  int res = 1;

  for (int i = 1; i <= *n; i++)
  {
    res *= i;
  }

  return res;
}
long fact_long(int *const n)
{
  long res = 1;

  for (int i = 1; i <= *n; i++)
  {
    res *= i;
  }

  return res;
}
long long fact_long_long(int *const n)
{
  long long res = 1;

  for (int i = 1; i <= *n; i++)
  {
    res *= i;
  }

  return res;
}
float fact_float(int *const n)
{
  float res = 1.0;

  for (int i = 1; i <= *n; i++)
  {
    res *= i;
  }

  return res;
}

double fact_double(int *const n)
{
  double res = 1.0;

  for (int i = 1; i <= *n; i++)
  {
    res *= i;
  }

  return res;
}
long double fact_long_double(int const *n)
{
  long double res = 1.0;

  for (int i = 1; i <= *n; i++)
  {
    res *= i;
  }

  return res;
}
