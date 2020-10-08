#include "poker.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5

void read_cards(int hand[5][2])
{
  bool card_exists[NUM_RANKS][NUM_SUITS];
  char ch, rank_ch, suit_ch;
  int rank, suit;
  bool bad_card;

  for (short int i = 0; i < NUM_CARDS; ) {
    bad_card = false;

    printf("Enter a card: ");

    rank_ch = getchar();
    switch (rank_ch) {
      case '0':           exit(EXIT_SUCCESS);
      case '2':           rank = 0; break;
      case '3':           rank = 1; break;
      case '4':           rank = 2; break;
      case '5':           rank = 3; break;
      case '6':           rank = 4; break;
      case '7':           rank = 5; break;
      case '8':           rank = 6; break;
      case '9':           rank = 7; break;
      case 't': case 'T': rank = 8; break;
      case 'j': case 'J': rank = 9; break;
      case 'q': case 'Q': rank = 10; break;
      case 'k': case 'K': rank = 11; break;
      case 'a': case 'A': rank = 12; break;
      default:            bad_card = true;
    }

    suit_ch = getchar();
    switch (suit_ch) {
      case 'c': case 'C': suit = 0; break;
      case 'd': case 'D': suit = 1; break;
      case 'h': case 'H': suit = 2; break;
      case 's': case 'S': suit = 3; break;
      default:            bad_card = true;
    }

    while ((ch = getchar()) != '\n')
      if (ch != ' ') bad_card = true;

    /* persist user input */
    if (bad_card) {
      printf("Bad card; ignored.\n");
    }
    else if (card_exists[rank][suit]) {
      printf("Duplicate card; ignored.\n");
    }
    else {
      // the first element of the sub-array stores the rank, the second one stores the suit
      hand[i][0] = rank;
      hand[i][1] = suit;
      card_exists[rank][suit] = true;
      i++;
    }
  }
}


void analyse_hand(int hand[5][2], bool *royal, bool *straight, bool *flush, bool *four, bool *three, int *pairs)
{
  int num_consec = 0;
  int i, j;
  int num_in_rank[NUM_RANKS] = {};
  int num_in_suit[NUM_SUITS] = {};

  *royal = false;
  *straight = false;
  *flush = false;
  *four = false;
  *three = false;
  *pairs = 0;

  /* count number of occurrences for each i and j appeared in `hand`*/
  for (i = 0; i < 5; i++) {
    num_in_rank[hand[i][0]]++;
    num_in_suit[hand[i][1]]++;
  }

  /* check for flush */
  for (j = 0; j < NUM_SUITS && !(*flush); j++) {
    if (num_in_suit[j] == NUM_CARDS) {
      *flush = true;
    }
  }

  /* check for straight & royal flush */
  i = 0;
  while (num_in_rank[i] == 0) i++;
  // printf("<debug>Initial index of the loop checking for \"straight\": %d</debug>\n", i);
  for (; i < NUM_RANKS && num_in_rank[i] > 0;i++) {
    num_consec++;

    /* exclusively for the case of "ace-low straight" */
    if (i == 0 && num_in_rank[NUM_RANKS - 1] > 0) {
      num_consec++;
    }

    // printf("<debug>checking for \"straight\", index: %d</debug>\n", i);
  }
  if (num_consec == NUM_CARDS) {
    *straight = true;
    // printf("<debug>index value at the end of the loop checking for \"straight\": %d\n", i);
    if (i == NUM_RANKS && *straight && flush) {
      *royal = true;
      // printf("<debug>checking for \"royal flush\"!</debug>\n");
    }
    return;
  }

  /* check for 4-of-a-kind, 3-of-a-kind, and pairs */
  for (i = 0; i < NUM_RANKS; i++) {
    if (num_in_rank[i] == 4) *four = true;
    if (num_in_rank[i] == 3) *three = true;
    if (num_in_rank[i] == 2) *pairs++;
  }
}


void print_result(bool *royal, bool *straight, bool *flush, bool *four, bool *three, int *pairs)
{
  if (*royal)                       printf("Royal flush");
  else if (*straight && *flush)     printf("Straight flush");
  else if (*four)                   printf("Four of a kind");
  else if (*three && *pairs == 1)   printf("Full house");
  else if (*flush)                  printf("Flush");
  else if (*straight)               printf("Straight");
  else if (*three)                  printf("Three of a kind");
  else if (*pairs == 2)             printf("Two pairs");
  else if (*pairs == 1)             printf("Pair");
  else                              printf("High card");

  printf("\n\n");
}

