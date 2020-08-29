#include <stdio.h>

/* Display the corresponding description to the wind speed entered by user */

int main() {
  int n;

  printf("Enter wind speed (in knots): ");
  scanf("%d", &n);

  if (n < 1)                    printf("Calm\n");
  else if (n >= 1  && n <= 3)   printf("Light air\n");
  else if (n >= 4  && n <= 27)  printf("Breeze\n");
  else if (n >= 28 && n <= 47)  printf("Gale\n");
  else if (n >= 48 && n <= 63)  printf("Storm\n");
  else                          printf("Hurricane\n");

  return 0;
}