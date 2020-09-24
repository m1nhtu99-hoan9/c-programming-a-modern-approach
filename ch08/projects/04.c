#include <stdio.h>

/* modified version of `reverse.c` */

int main()
{
  int a[10], i;
  int len = (int)(sizeof(a) / sizeof(a[0]));

  printf("Enter %d numbers: ", len);
  for (i = 0; i < len; i++)
    scanf("%d", &a[i]);

  printf("In reverse order:");
  for (i = len - 1; i >= 0; i--)
    printf(" %d", a[i]);
  printf("\n");

  return 0;
}