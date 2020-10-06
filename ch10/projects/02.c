#include "poker_01.h"

/* Refactored version of `poker.c`*/

#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5

/* Ranks: 2 3 4 5 6 7 8 9 t j q k a
 * Suits: c d h s
 *
 * Straight flush:  both a straight and a flush
 * Four-of-a-kind:  four cards of the same rank
 * Full house:      a three of a kind and a pair
 * Flush:           five cards of the same suit
 * Straight:        five cards with consecutive ranks
 * Three-of-a-kind: three cards of the sam rank
 * Two pairs
 * Pair:            two cards of the same rank
 * High card:       any other hand
 * */
int main(void)
{
  int num_in_rank[NUM_RANKS];
  int num_in_suit[NUM_SUITS];

  for (;;) {
    read_cards(num_in_rank, num_in_suit);
    analyse_hand(num_in_rank, num_in_suit);
    print_result();
  }
}