#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

unsigned short int board[99][99] = {};
bool is_used[99 * 99 + 1] = {false};

void populate_cell(const unsigned short int row, const unsigned short int col, unsigned short int value) {
  board[row][col] = value;
  is_used[value] = true;
}

int main() {
  unsigned short int i, j, size;
  srand((unsigned) time(NULL));

  printf("This program creates a magic square of a specific size.\n");
  printf("The size must be an odd number between 1 and 99.\n");
  printf("Enter size of magic number: ");
  scanf("%hu", &size);

  if (size < 0 || size > 99) {
    printf("INVALID INPUT!\n");
    return 1;
  }
  else {
    if (size % 2 == 0)
      size++;

    /* initiate variables */
    const unsigned short int LAST_NUM = size * size, HALF_SIZE = size / 2, MAGIC_SUM = (1 + LAST_NUM) * size / 2;

    /* populate the board */
    board[HALF_SIZE][HALF_SIZE] = (1 + LAST_NUM) / 2;
    i = rand() % 25 + 1;
    populate_cell(0, 0, i);
    i = (1 + LAST_NUM) - board[0][0];
    populate_cell(size - 1, size - 1, i);

    for (i = board[0][0]; i == board[0][0] || i == board[size - 1][size - 1];) {
      i = rand() % 25 + 1;
    }
    populate_cell(size - 1, 0, i);
    i = (1 + LAST_NUM) - board[size - 1][0];
    populate_cell(0, size - 1, i);

    i = MAGIC_SUM - 2 * (board[0][0] + board[0][size - 1]);
    populate_cell(0, HALF_SIZE, i);
    i = (1 + LAST_NUM) - board[0][HALF_SIZE];
    populate_cell(size - 1, HALF_SIZE, i);

    i = MAGIC_SUM - 2 * (board[0][0] + board[size - 1][0]);
    populate_cell(HALF_SIZE, 0, i);
    i = (1 + LAST_NUM) - board[(int) HALF_SIZE][0];
    populate_cell(HALF_SIZE, size - 1, i);

    /* print the board out */
    printf("Magic sum: %hu\n", MAGIC_SUM);
    for (i = 0; i < size; i++) {
      for (j = 0; j < size; j++) {
        printf("%2d ", board[i][j]);
      }
      printf("\n");
    }

    return 0;
  }
}


