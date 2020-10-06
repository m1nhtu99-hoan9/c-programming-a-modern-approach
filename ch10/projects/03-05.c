#include "poker_02.h"

/* Refactored version of `poker.c` */

/* Ranks: 2 3 4 5 6 7 8 9 t j q k a
 * Suits: c d h s
 *
 * Royal flush:     ace, king, queen, jack, ten of the same suit
 * Straight flush:  both a straight and a flush
 * Four-of-a-kind:  four cards of the same rank
 * Full house:      a three of a kind and a pair
 * Flush:           five cards of the same suit
 * Straight:        five cards with consecutive ranks (ace-low straight included)
 * Three-of-a-kind: three cards of the sam rank
 * Two pairs
 * Pair:            two cards of the same rank
 * High card:       any other hand
 * */
int main(void)
{
  int hand[5][2] = {};

  for (;;) {
    read_cards(hand);
    analyse_hand(hand);
    print_result();
  }
}