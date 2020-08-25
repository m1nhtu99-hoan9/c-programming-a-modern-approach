#include <stdio.h>

int main() {
  int m, d, y;
  printf("Enter a date (mm/dd/yyyy): ");
  scanf("%d/%d/%d", &d, &m, &y);
  printf("You entered the date %4d%.2d%2d\n", y, m, d);

  return 0;
}