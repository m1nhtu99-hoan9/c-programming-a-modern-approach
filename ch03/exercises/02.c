#include <stdio.h>

int main(void)
{
  double num;
  /*
    The first two conversion specifications are for exponential notation,
    the last two conversion specifications are for fixed decimal notation
  */
  const char formats[4][11] = {"|%-8.1e|\n\0", "|%10.6e|\n\0", "|%-8.3lf|\n\0", "|%6.0lf|\n\0"};

  printf("Give me a float: ");
  scanf("%lf", &num);

  printf("Output the number in specified formats:\n");
  for (int i = 0; i < 4; i++)
  {
    printf(formats[i], num);
  }
}
