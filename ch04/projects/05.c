#include <stdio.h>

/* Compute UPC Check Digit */

int main()
{
  int item, manufacturer_digits[5], product_digits[5], i, res;
  /*
    UPC 1st  digit = item                  ; UPC 2nd  digit = manufacturer_digits[0];
    UPC 3rd  digit = manufacturer_digits[1]; UPC 4th  digit = manufacturer_digits[2];
    UPC 5th  digit = manufacturer_digits[3]; UPC 6th  digit = manufacturer_digits[4];
    UPC 7th  digit = product_digits[0]     ; UPC 8th  digit = product_digits[1]     ;
    UPC 9th  digit = product_digits[2]     ; UPC 10th digit = product_digits[3]     ;
    UPC 11th digit = product_digits[4]     ; 
  */

  printf("Enter the first 11 digits of a UPC: ");
  scanf("%1d", &item);
  for (i = 0; i < 5; i++)
  {
    scanf("%1d", &manufacturer_digits[i]);
  }
  for (i = 0; i < 5; i++)
  {
    scanf("%1d", &product_digits[i]);
  }

  /* Procedure to compute check number */
  // get sum of digits in odd places
  res = item + manufacturer_digits[1] + manufacturer_digits[3];
  for (i = 0; i <= 4; i += 2)
  {
    res += product_digits[i];
  }
  // multiply this sum by 3
  res *= 3;
  // add it to the sum of digits in even places
  for (i = 0; i <= 4; i += 2)
  {
    res += manufacturer_digits[i];
  }
  res += product_digits[1] + product_digits[3];
  // subtract 1 from the total
  res -= 1;
  // get the remainder when the adjusted total is divided by 10
  res /= 10;
  // subtract the remainder from 9
  res = 9 - res;
  /* END Procedure to compute check number */

  printf("Check digit: %d\n", res);

  return 0;
}