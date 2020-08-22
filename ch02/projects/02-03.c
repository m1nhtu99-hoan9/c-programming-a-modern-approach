#include <stdio.h>
#include <math.h>

// directive for declaring global constant
#define PI acos(-1.0)

int main()
{
  float r, coefficient = 4.0f / 3.0f;

  printf("Enter the radius: ");
  scanf("%f", &r);

  float volOfSphere = coefficient * PI * pow(r, 3);
  printf("Result: %f\n", volOfSphere);

  return 0;
}

/* To compile this file on Ubuntu: 
    `gcc ./02-03.c -lm`
  `-lm` option helps to link with `libm.a`
*/