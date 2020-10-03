#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define UP    0
#define DOWN  1
#define LEFT  2
#define RIGHT 3

/* modified version of `../../ch08/projects/09.c` */

short int i, j;

void generate_random_walk(char walk[10][10]);
/* print the board out */
void print_array(char walk[10][10]);

int main() {
  char board[10][10] = {};

  /* prevent the generator from generating the same result
     every time the program is executed */
  srand((unsigned) time(NULL));

  for (unsigned short int k = 0; k < 4; k++) {
    /* populate the board with `.` */
    for (i = 0; i < 10; i++) {
      for (j = 0; j < 10; j++) {
        board[j][i] = '.';
      }
    }

    generate_random_walk(board);
    print_array(board);
  }

  return 0;
}

/* implementation */

void generate_random_walk(char walk[10][10]) {
  /* 0 means `up`, `1` means down, `2` means left, `3` means right */
  char cur_elem;
  short int dir = 4;
  short int cur_x, cur_y;
  bool movable[4] = {true, true, true, true};
  short int possible_move_num, possible_dirs[4] = {-1, -1, -1, -1};

  for (cur_x = cur_y = 0, cur_elem = 'A'; cur_elem <= 'Z' && dir >= 0; cur_elem++) {
    walk[cur_y][cur_x] = cur_elem;

    /* reset watcher array and counter for current cell */
    for (i = 0; i < 4; i++)
      movable[i] = false;
    possible_move_num = 0;

    /* look for movable cells from the current cell */
    if (cur_x > 0 && walk[cur_y][cur_x - 1] == '.') {
      /* if the current cell is not on the left edge
         and the cell 1-step away from the left is not populated yet */
      movable[LEFT] = true;
      possible_move_num++;
    }
    if (cur_x < 9 && walk[cur_y][cur_x + 1] == '.') {
      /* if the current cell is not on the right edge
         and the cell 1-step away from the right is not populated yet */
      movable[RIGHT] = true;
      possible_move_num++;
    }
    if (cur_y > 0 && walk[cur_y - 1][cur_x] == '.') {
      /* if the current cell is not on the top edge
         and the cell 1-step away from the top is not populated yet */
      movable[UP] = true;
      possible_move_num++;
    }
    if (cur_y < 9 && walk[cur_y + 1][cur_x] == '.') {
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
}

void print_array(char walk[10][10]) {
  for (i = 0; i < 10; i++) {
    for (j = 0; j < 10; j++) {
      printf("%c ", walk[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

