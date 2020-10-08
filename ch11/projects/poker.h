/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King                                         *
 * Copyright (c) 2008, 1996 W. W. Norton & Company, Inc. *
 * All rights reserved.                                  *
 * This program may be freely distributed for class use, *
 * provided that this copyright notice is retained.      *
 *********************************************************/

#include <stdbool.h>

#ifndef C_PROGRAMMING_A_MODERN_APPROACH_POKER_CH11_H

/* Reads the cards into the external variables `num_in_rank` and `num_in_suit`;
 * checks for bad cards and duplicate cards.
 */
void read_cards(int hand[5][2]);

/* Determines whether the hand contains a straight, a flush, four-of-a-kind,
 * and/or three-of-a-kind; determines the number of pairs; stores the results into
 * the variables whose pointers passed into the function.
 */
void analyse_hand(int hand[5][2], bool *royal, bool *straight, bool *flush, bool *four, bool *three, int *pairs);

/* Prints the classification of the hand
 */
void print_result(bool *royal, bool *straight, bool *flush, bool *four, bool *three, int *pairs);


#define C_PROGRAMMING_A_MODERN_APPROACH_POKER_CH11_H

#endif //C_PROGRAMMING_A_MODERN_APPROACH_POKER_CH11_H
