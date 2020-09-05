#include <stdio.h>
#define INTERVAL 24

/* modified version of `./01.c` */

int main()
{
  short int i, n;
  long int odd, square;
  char chr;

  printf("This program prints a table of squares.\n");
  printf("Enter a number of entries in table: ");
  scanf("%hd", &n);
  // IMPORTANT: remove trailing newline character from the buffer
  getchar();

  for (odd = 3, square = 1, i = 1;
       i <= n;
       i++, square += odd, odd += 2)
  {
    // because (n+1)^2 = (n^2) + 2n + 1
    printf("%5hd%8ld\n", i, square);

    if (i % INTERVAL == 0)
    {
      printf("Press Enter to continue...");
      // iteratively read all characters to the buffer 
      // skip the loop only when getting '\n'
      while (getchar() != '\n')
        ;
    }
  }

  return 0;
}
