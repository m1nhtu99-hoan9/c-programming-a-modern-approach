#include <stdio.h>

int main()
{
  int gsi_prefix, group_id, publisher_code, item_num, check_degit;

  printf("Enter ISBN: ");
  scanf("%d-%d-%d-%d-%d", &gsi_prefix, &group_id, &publisher_code, &item_num, &check_degit);

  printf("\nGSI prefix: %d\n", gsi_prefix);
  printf("Group identifier: %d\n", group_id);
  printf("Publisher code: %d\n", publisher_code);
  printf("Item number: %d\n", item_num);
  printf("Check digit: %d\n", check_degit);

  return 0;
}