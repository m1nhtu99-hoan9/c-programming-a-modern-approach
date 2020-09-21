#ifndef READLINE_H
#define READLINE_H

/***********************************************************
 * Skips leading white-space characters, then reads the
 * remainder of the input line and store its in `str`.
 * Truncates the line if its length exceeds `n`.                                              
 * Return the number of characters stored.                             
 ***********************************************************/
int read_line(char str[], int n);

#endif