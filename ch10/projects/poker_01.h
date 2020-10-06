/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King                                         *
 * Copyright (c) 2008, 1996 W. W. Norton & Company, Inc. *
 * All rights reserved.                                  *
 * This program may be freely distributed for class use, *
 * provided that this copyright notice is retained.      *
 *********************************************************/

#ifndef C_PROGRAMMING_A_MODERN_APPROACH_POKER_H

/* Reads the cards into `num_in_rank` and `num_in_suit`;
 * checks for bad cards and duplicate cards.
 */
void read_cards(int *const num_in_rank, int *const num_in_suit);

/* Determines whether the hand contains a straight, a flush, four-of-a-kind,
 * and/or three-of-a-kind; determines the number of pairs; stores the results into
 * the external variables straight, flush, four, three, and pairs.
 */
void analyse_hand(int *const num_in_rank, int *const num_in_suit);

/* Prints the classification of the hand, based on the values of the external
 * variables straight, flush, four, three, and pairs.
 */
void print_result();

#define C_PROGRAMMING_A_MODERN_APPROACH_POKER_H

#endif //C_PROGRAMMING_A_MODERN_APPROACH_POKER_H
