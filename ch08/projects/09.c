#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define UP    0
#define DOWN  1
#define LEFT  2
#define RIGHT 3

/** Returns either 0, 1, 2, 3 or -1 in case there are no movable directions */

int main() {
  char board[10][10] = {}, cur_elem;
  short int i, j;
  /* 0 means `up`, `1` means down, `2` means left, `3` means right */
  short int dir = 4;
  short int cur_x, cur_y;
  bool movable[4] = {true, true, true, true};
  short int possible_move_num, possible_dirs[4] = {-1, -1, -1, -1};

  /* prevent the generator from generating the same result 
     every time the program is executed */
  srand((unsigned) time(NULL));

  /* populate the board with `.` */
  for (i = 0; i < 10; i++) {
    for (j = 0; j < 10; j++) {
      board[j][i] = '.';
    }
  }

  for (cur_x = cur_y = 0, cur_elem = 'A'; cur_elem <= 'Z' && dir >= 0; cur_elem++) {
    board[cur_y][cur_x] = cur_elem;

    /* reset watcher array and counter for current cell */
    for (i = 0; i < 4; i++)
      movable[i] = false;
    possible_move_num = 0;

    /* look for movable cells from the current cell */
    if (cur_x > 0 && board[cur_y][cur_x - 1] == '.') {
      /* if the current cell is not on the left edge
         and the cell 1-step away from the left is not populated yet */
      movable[LEFT] = true;
      possible_move_num++;
    }
    if (cur_x < 9 && board[cur_y][cur_x + 1] == '.') {
      /* if the current cell is not on the right edge
         and the cell 1-step away from the right is not populated yet */
      movable[RIGHT] = true;
      possible_move_num++;
    }
    if (cur_y > 0 && board[cur_y - 1][cur_x] == '.') {
      /* if the current cell is not on the top edge
         and the cell 1-step away from the top is not populated yet */
      movable[UP] = true;
      possible_move_num++;
    }
    if (cur_y < 9 && board[cur_y + 1][cur_x] == '.') {
      /* if the current cell is not on the bottom edge
         and the cell 1-step away from the bottom is not populated yet */
      movable[DOWN] = true;
      possible_move_num++;
    }


    if (possible_move_num == 0) {
      dir = -1;
      break;
    } else {
      // finalise list of possibilities
      for (i = 0, j = 0; i < 4 && j <= possible_move_num; i++) {
        if (movable[i]) {
          possible_dirs[j++] = i;
        }
      }

      // randomly choose among the possibilities
      dir = possible_dirs[rand() % possible_move_num];
    }

    /* dispatch the direction code into action */
    switch (dir) {
      case 0:
        cur_y -= 1;
        break;
      case 1:
        cur_y += 1;
        break;
      case 2:
        cur_x -= 1;
        break;
      case 3:
        cur_x += 1;
        break;
    }
  }

  /* print the board out */
  for (i = 0; i < 10; i++) {
    for (j = 0; j < 10; j++) {
      printf("%c ", board[i][j]);
    }
    printf("\n");
  }

  return (dir < 0) ? 1 : 0;
}


