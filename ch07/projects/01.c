#include <stdio.h>

/* modified version of `../../ch06/projects/07.c` */

int main()
{
  short int i, n; 
  long int odd, square;

  printf("This program prints a table of squares.\n");
  printf("Enter a number of entries in table: ");
  scanf("%hd", &n);

  for (odd = 3,
      square = 1,
      i = 1;
       i <= n; i++, square += odd, odd += 2)
    // because (n+1)^2 = (n^2) + 2n + 1
    printf("%5hd%8ld\n", i, square);
 
  return 0;
}

