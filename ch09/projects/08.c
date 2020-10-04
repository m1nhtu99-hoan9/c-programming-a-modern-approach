#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

/* The Game of Craps */

unsigned short int dices[2] = {};

int roll_dice() {
  dices[0] = rand() % 6 + 1;
  dices[1] = rand() % 6 + 1;

  return dices[0] + dices[1];
}

bool play_game() {
  int res, point;

  printf("\nYou rolled: %d\n", res = roll_dice());
  if (res == 7 || res == 11) {
    printf("You win!\n");
    return true;
  }
  else if (res == 2 || res == 3 || res == 12) {
    printf("You lose!\n");
    return false;
  }
  else {
    printf("The point is %d\n", point = rand() % 11 + 1);

    for (res = roll_dice();; res = roll_dice()) {
      printf("You rolled: %d\n", res);
      if (res == 7) {
        if (point == 7) {
          printf("You win!\n");
          return true;
        }
        else {
          printf("You lose!\n");
          return false;
        }
      }
      else if (res == point) {
        printf("You win!\n");
        return true;
      }
      else {
        continue;
      }
    }
  }
}

int main() {
  unsigned int win_num = 0, lose_num = 0;

  /* prevent the generator from generating the same result
     every time the program is executed */
  srand((unsigned) time(NULL));

  for (;;) {
    if (play_game() == true)
      win_num++;
    else
      lose_num++;

    printf("Play again? ");

    if (getchar() == 'y') {
      // consume trailing '\n' character;
      getchar();

      continue;
    }
    else {
      break;
    }
  }

  printf("\nWins: %4d    Loses: %4d\n", win_num, lose_num);
  return 0;
}