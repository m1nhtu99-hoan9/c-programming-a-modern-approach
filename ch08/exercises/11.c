#include <stdlib.h>
#include <stdio.h>

#define DIMENSION 8

int main()
{
  char checker_board[DIMENSION][DIMENSION] = {};

  for (int i = 0; i < DIMENSION; i++)
  {
    for (int j = 0; j < DIMENSION; j++)
    {
      checker_board[i][j] = ((i + j) % 2 == 0) ? 'B' : 'R';
      printf("%c ", checker_board[i][j]);
    }
    printf("\n");
  }

  return 0;
}