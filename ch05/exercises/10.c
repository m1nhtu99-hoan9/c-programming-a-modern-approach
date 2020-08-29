#include <stdio.h>

int main()
{
  int i;

  i = 1;
  switch (i % 3) {
    case 0: printf("zero");
    case 1: printf("one");
    case 2: printf("two");
  }
  printf("\n");

  return 0;
}

/* Output: "onetwo" */