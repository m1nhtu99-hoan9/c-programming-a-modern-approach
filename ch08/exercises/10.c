#include <stdio.h>
#include <ctype.h>

#define DIMENSION 8

int main()
{
  int i, j;

  /* intialise back line of upper side */
  char chess_board[DIMENSION][DIMENSION] = {
      [0][0] = 'r',
      [0][1] = 'n',
      [0][2] = 'b',
      [0][3] = 'q',
      [0][4] = 'k',
  };
  for (i = 0; i < 3; i++)
  {
    chess_board[0][DIMENSION - i - 1] = chess_board[0][i];
  }

  for (i = 0; i < DIMENSION; i++)
  {
    /* initialise both sides */
    chess_board[1][i] = 'p';
    chess_board[DIMENSION - 2][i] = 'P';
    chess_board[DIMENSION - 1][i] = toupper(chess_board[0][i]);

    /* intialise spaces in between */
    for (j = 2; j < DIMENSION - 2; j++)
    {
      chess_board[j][i] = ((i + j) % 2 == 0) ? ' ' : (!(i % 2)) ? '.' : '*';
    }
  }

  /* print the chessboard out */
  for (i = 0; i < DIMENSION; i++)
  {
    for (j = 0; j < DIMENSION; j++)
    {
      printf("%c ", chess_board[i][j]);
    }
    printf("\n");
  }

  return 0;
}