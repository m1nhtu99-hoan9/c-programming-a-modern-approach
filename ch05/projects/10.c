#include <stdio.h>

/* Given a numerical grade, print out a letter grade */

char get_grade(int n);

int main()
{
  int grade;

  printf("Enter numerical grade: ");
  scanf("%d", &grade);

  if (grade >= 0 && grade <= 100)
  {
    printf("Letter grade: %c\n", get_grade(grade));
    return 0;
  }
  else
  {
    printf("Invalid grade input!!!\n");
    return 1;
  }
}

char get_grade(int n)
{
  // get the ten's digit
  n = (n / 10);

  if (n >= 0 && n <= 5)
  {
    return 'F';
  }
  else
  {
    switch (n)
    {
    case 6:
      return 'D';
    case 7:
      return 'C';
    case 8:
      return 'B';
    case 9:
      return 'A';
    case 10:
      return 'A';
    }
  }
}