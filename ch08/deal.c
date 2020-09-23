#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define NUM_SUITS 4
#define NUM_RANKS 13

const char RANK_CODES[] = {'2', '3', '4', '5', '6', '7', '8', '9', 't', 'j', 'q', 'k', 'a'};
const char SUIT_CODES[] = {'c', 'd', 'h', 's'};

int main()
{
  bool in_hand[NUM_SUITS][NUM_RANKS] = {false};
  int num_cards, rank, suit;

  // prevent the program from dealing the same cards every time it is executed
  srand((unsigned) time(NULL));

  printf("Enter number of cards in hand: ");
  scanf("%d", &num_cards);

  printf("Your hand: ");
  while (num_cards > 0)
  {
    // pick a random suit
    suit = rand() % NUM_SUITS;
    // pick a random rank
    rank = rand() % NUM_RANKS;

    if (!in_hand[suit][rank])
    {
      in_hand[suit][rank] = true;
      num_cards--;
      printf(" %c%c", RANK_CODES[rank], SUIT_CODES[suit]);
    }
  }
  printf("\n");

  return 0;
}
