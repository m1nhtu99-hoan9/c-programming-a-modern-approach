#include <stdio.h>

/* De la Loubère's method for solving magic square
 * @reference https://www.magic-squares.info/methods/odd.html
 * */

int board[99][99] = {};

int main() {
  short int cur_x, cur_y, next_x, next_y;
  unsigned short i, j, size;

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

  /* implement De la Loubère's method */
  for (i = 1, cur_x = size / 2, cur_y = 0;
       i <= size * size;
       i++)
  {
    board[cur_y][cur_x] = i;

    next_y = (size + cur_y - 1) % size;
    next_x = (cur_x + 1) % size;

    if (board[next_y][next_x] == 0) {
      // move the cursor 1 row upward and 1 column to the rightward
      cur_y = next_y;
      cur_x = next_x;
    }
    else {
      // if the cell to move to is already populated, move the cursor 1 row downward
      next_y = (cur_y + 1) % size;
      cur_y = next_y;
    }

    // printf("Num: %d <current row: %d, current column: %d>\n", i, cur_y, cur_x);
  }

  /* print the board out */
  for (i = 0; i < size; i++) {
    for (j = 0; j < size; j++) {
      printf("%6d ", board[i][j]);
    }
    printf("\n");
  }

  return 0;
}


