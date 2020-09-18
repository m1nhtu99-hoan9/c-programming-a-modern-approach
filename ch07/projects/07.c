#include <stdio.h>
#include <stdbool.h>
#include "gcd.h"

/* Program to add, substract, multiply or divide 2 fractions 
   upgraded version of `../../ch03/projects/06.c`
*/

struct Fraction
{
  long numerator;
  long denominator;
};

bool Fraction_is_invalid(struct Fraction *f);
/* reduce a fraction to its simplest form */
void Fraction_simplify(struct Fraction *f);

/* safely assign data of the 2nd Fraction to the 1st Fraction */
void Fraction_assign(struct Fraction *f1, struct Fraction *f2);
void Fraction_scanf(struct Fraction *f);
void Fraction_printf(struct Fraction frac);

struct Fraction Fraction_add(struct Fraction *f1, struct Fraction *f2);
struct Fraction Fraction_subtract(struct Fraction *f1, struct Fraction *f2);
struct Fraction Fraction_multiply(struct Fraction *f1, struct Fraction *f2);
struct Fraction Fraction_divide(struct Fraction *f1, struct Fraction *f2);

int main()
{
  struct Fraction cur1, cur2;
  char operator;
  printf("Enter 2 fractions seperated by +, -, * or /: ");

  Fraction_scanf(&cur1);
  operator= getchar();
  Fraction_scanf(&cur2);

  if (Fraction_is_invalid(&cur1) || Fraction_is_invalid(&cur2))
  {
    printf("INVALID INPUT\n");

    return 1;
  }
  else
  {
    printf("Result: ");

    switch (operator)
    {
    case '+':
      Fraction_printf(Fraction_add(&cur1, &cur2));
      break;
    case '-':
      Fraction_printf(Fraction_subtract(&cur1, &cur2));
      break;

    case '*':
      Fraction_printf(Fraction_multiply(&cur1, &cur2));
      break;
    case '/':
      Fraction_printf(Fraction_divide(&cur1, &cur2));
    }

    printf("\n");
    return 0;
  }
}

/* implementations */

void Fraction_scanf(struct Fraction *f)
{
  scanf("%ld/%ld", &(f->numerator), &(f->denominator));
}

void Fraction_printf(struct Fraction frac)
{
  printf("%ld/%ld", frac.numerator, frac.denominator);
}

bool Fraction_is_invalid(struct Fraction *f)
{
  return (f->denominator == 0);
}

void Fraction_simplify(struct Fraction *f)
{
  long gcd = find_gcd(f->denominator, f->numerator);

  f->denominator /= gcd;
  f->numerator /= gcd;
}

void Fraction_assign(struct Fraction *f1, struct Fraction *f2)
{
  f1->numerator = f2->numerator;
  f1->denominator = f2->denominator;
}

struct Fraction Fraction_add(struct Fraction *f1, struct Fraction *f2)
{
  struct Fraction res;

  res.denominator = f1->denominator * f2->denominator;

  res.numerator = f1->numerator * f2->denominator;
  res.numerator += f2->numerator * f1->denominator;

  Fraction_simplify(&res);
  return res;
};

struct Fraction Fraction_subtract(struct Fraction *f1, struct Fraction *f2)
{
  struct Fraction res;

  res.denominator = f1->denominator * f2->denominator;

  res.numerator = f1->numerator * f2->denominator;
  res.numerator -= f2->numerator * f1->denominator;

  Fraction_simplify(&res);
  return res;
};

struct Fraction Fraction_multiply(struct Fraction *f1, struct Fraction *f2)
{
  struct Fraction res;

  res.denominator = f1->denominator * f2->denominator;
  res.numerator = f1->numerator * f2->numerator;

  Fraction_simplify(&res);
  return res;
}

struct Fraction Fraction_divide(struct Fraction *f1, struct Fraction *f2)
{
  struct Fraction res;

  // initiate `res` with inverse fraction of `*f2`
  res.denominator = f2->numerator;
  res.numerator = f2->denominator;

  Fraction_simplify(&res);
  return Fraction_multiply(f1, &res);
}
