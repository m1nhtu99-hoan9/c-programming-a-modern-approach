#include <stdio.h>

int main(void)
{
  int item_number, date, month, year;
  float unit_price;

  printf("Enter item number: ");
  scanf("%d", &item_number);
  printf("Enter unit price: ");
  scanf("%f", &unit_price);
  printf("Enter purchase date (mm/dd/yyyy): ");
  scanf("%2d/%2d/%4d", &month, &date, &year);

  /* 
    Initially, I use '|' for to have make the output more visualisable;
    then, I deleted these '|' characters.  
  */
  printf("\nItem\t\tUnit\t\tPurchase\t\n");
  printf("\t\tPrice\t\tDate\t\t\n");
  printf("%d\t\t$%7.2f\t%2d/%2d/%2d\t\n", item_number, unit_price, month, date, year);
}