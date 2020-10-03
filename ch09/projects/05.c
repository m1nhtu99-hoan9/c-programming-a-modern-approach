#include <stdio.h>
#include <stdlib.h>

/* De la Loubère's method for solving magic square
 * modified version of `../../ch08/projects/17.c` */

int i, j;

/* Implement De la Loubère's method to create magic square of size n*n */
void create_magic_square(int n, int magic_square[n][n]);

/* Print the matrix out */
void print_magic_square(int n, int magic_square[n][n]);

int main() {
  unsigned short int size;
  printf("This program creates a magic square of a specific size.\n");
  printf("The size must be an odd number between 1 and 99.\n");
  printf("Enter size of magic number: ");
  scanf("%hu", &size);

  /* validate number of size */
  if (size < 0 || size > 99) {
    printf("INVALID INPUT!\n");
    return 1;
  }

  if (size % 2 == 0)
    size++;

  int * board = (int *) malloc(size * sizeof(int));

  create_magic_square(size, board);
  print_magic_square(size, board);

  free(board);

  return 0;
}

/* implementation */

void create_magic_square(int n, int magic_square[n][n]) {
  int cur_x, cur_y, next_x, next_y;

  for (i = 1, cur_x = n / 2, cur_y = 0;
       i <= n * n;
       i++) {
    magic_square[cur_y][cur_x] = i;

    next_y = (n + cur_y - 1) % n;
    next_x = (cur_x + 1) % n;

    if (magic_square[next_y][next_x] == 0) {
      // move the cursor 1 row upward and 1 column to the rightward
      cur_y = next_y;
      cur_x = next_x;
    }
    else {
      // if the cell to move to is already populated, move the cursor 1 row downward
      next_y = (cur_y + 1) % n;
      cur_y = next_y;
    }

    // printf("Num: %d <current row: %d, current column: %d>\n", i, cur_y, cur_x);
  }
}

void print_magic_square(int n, int magic_square[n][n]) {
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf("%6d ", magic_square[i][j]);
    }
    printf("\n");
  }
}



