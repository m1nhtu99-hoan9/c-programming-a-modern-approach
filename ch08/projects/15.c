#include <stdio.h>

/* Caesar Cipher */

void encode(char *const chr_ptr, short int shift_amount);

int main() {
  char cur = '\0', message[100] = {};
  char *const message_pointer = (char *const) &message;
  short int i, n;

  printf("Enter message to be encrypted: ");
  for (i = 0; cur != '\n'; i++) {
    cur = getchar();
    message[i] = cur;
  }
  printf("Enter shift amount (1-25): ");
  scanf("%hd", &n);

  /* implement the encrypting */
  for (; i >= 0; i--) {
    // at the end of last loop, `i` holds the number of `char`s in message minus 1
    encode(message_pointer + i, n);
  }

  printf("Encrypted message: %s\n", message);

  return 0;
}

/* implementation */

void encode(char *const chr_ptr, short int shift_amount) {
  if (*chr_ptr >= 'a' && *chr_ptr <= 'z') {
    *chr_ptr = ((*chr_ptr - 'a') + shift_amount) % 26 + 'a';
  }
  else if (*chr_ptr >= 'A' && *chr_ptr <= 'Z') {
    *chr_ptr = ((*chr_ptr - 'A') + shift_amount) % 26 + 'A';
  }
}