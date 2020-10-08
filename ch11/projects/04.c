#include "poker.h"

/* modified version of `../../ch10/projects/03-05.c` */

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
int main()
{
  int pairs, hand[5][2] = {};
  bool royal, straight, flush, four, three;

  for (;;) {
    read_cards(hand);
    analyse_hand(hand, &royal, &straight, &flush, &four, &three, &pairs);
    print_result(&royal, &straight, &flush, &four, &three, &pairs);
  }
}

//struct HandClassification
//{
//  bool royal_flush;
//  bool straight;
//  bool flush;
//  bool four;
//  bool three;
//  int  pairs;
//};


