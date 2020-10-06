#include <stdio.h>
#include <stdbool.h>

#define MAX_DIGITS 10

const bool SEGMENTS[10][7] = {
    // digit 0
    {true,  true,  true,  true,  true,  true,  false},
    // digit 1
    {false, true,  true,  false, false, false, false},
    // digit 2
    {true,  true,  false, true,  true,  false, true},
    // digit 3
    {true,  true,  true,  true,  false, false, true},
    // digit 4
    {false, true,  true,  false, false, true,  true},
    // digit 5
    {true,  false, true,  true,  false, true,  true},
    // digit 6
    {true,  false, true,  true,  true,  true,  true},
    // digit 7
    {true,  true,  true,  false, false, false, false},
    // digit 8
    {true,  true,  true,  true,  true,  true,  true},
    // digit 9
    {true,  true,  true,  true,  false, true,  true},
};

char board[3][1000] = {};

void process_digit(int digit, int pos);
void process_blank_space(int pos);

int main() {
  short int i, j, k, digits[MAX_DIGITS];
  char cur = '\0';

  printf("Enter a number: ");
  for (i = 0; i < MAX_DIGITS && cur != '\n';) {
    cur = getchar();

    if (cur >= '0' && cur <= '9') {
      digits[i++] = (short int) (cur - '0');
    }
  }

  for (j = k = 0; j < i; j++) {
    process_digit(digits[j], k);
    k+=3;
    process_blank_space(k++);
  }

  for (i = 0; i < 3; i++) {
    for (j = 0; j < k; j++) {
      printf("%c", board[i][j]);
    }
    printf("\n");
  }
}

void process_digit(int digit, int pos) {
  board[0][pos + 0] = ' ';
  // board[0][pos + 1] = ' ';
  board[0][pos + 1] = SEGMENTS[digit][0] ? '_' : ' ';
  // board[0][pos + 3] = ' ';
  board[0][pos + 2] = ' ';

  board[1][pos + 0] = SEGMENTS[digit][5] ? '|' : ' ';
  // board[1][pos + 1] = ' ';
  board[1][pos + 1] = SEGMENTS[digit][6] ? '_' : ' ';
  // board[1][pos + 3] = ' ';
  board[1][pos + 2] = SEGMENTS[digit][1] ? '|' : ' ';

  board[2][pos + 0] = SEGMENTS[digit][4] ? '|' : ' ';
  // board[2][pos + 1] = ' ';
  board[2][pos + 1] = SEGMENTS[digit][3] ? '_' : ' ';
  // board[2][pos + 3] = ' ';
  board[2][pos + 2] = SEGMENTS[digit][2] ? '|' : ' ';
}

void process_blank_space(int pos) {
  for (short int i = 0; i < 3; i++) {
    board[i][pos] = ' ';
  }
}

