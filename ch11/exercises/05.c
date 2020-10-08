#include <stdio.h>
#include <stdlib.h>

void split_time(long total_sec, int *const hr, int *const min, int *const sec) {
  /* (*hr * 60^2) + (*min * 60) + *sec == total_sec */

  if (total_sec < 0) {
    printf("INVALID INPUT!\n");
    exit(EXIT_FAILURE);
  }
  else {
    *sec = total_sec % 60;
    total_sec /= 60;
    *min = total_sec % 60;
    *hr = total_sec / 60;
  }
}

int main() {
  long sec_num;
  int h, m, s;

  printf("Input the number of seconds since midnight: ");
  scanf("%ld", &sec_num);

  split_time(sec_num, &h, &m, &s);
  printf("Equivalent time: %.2d:%.2d:%.2d\n", h, m, s);

  return 0;
}

