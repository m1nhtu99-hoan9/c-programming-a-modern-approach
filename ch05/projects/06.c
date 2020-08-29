#include <stdio.h>

/* Given an UPC-A code, check if the given code is valid */

/* Compute UPC Check Digit */
int get_check_digit(int item_digit, const int (*m_digits_ptr)[5], const int (*p_digits_ptr)[5]);

int main()
{
  int item, manufacturer_digits[5], product_digits[5], check, i;

  printf("Enter a 12-digit UPC-A code: ");
  scanf("%1d", &item);
  for (i = 0; i < 5; i++)
  {
    scanf("%1d", &manufacturer_digits[i]);
  }
  for (i = 0; i < 5; i++)
  {
    scanf("%1d", &product_digits[i]);
  }
  scanf("%1d", &check);

  printf("Your input code is %s\n",
         (check == get_check_digit(item, &manufacturer_digits, &product_digits))
             ? "VALID"
             : "INVALID");

  return 0;
}

/* implementation */

int get_check_digit(int item_digit, const int (*m_digits_ptr)[5], const int (*p_digits_ptr)[5])
{
  /*
    UPC 1st  digit = item                  ; UPC 2nd  digit = manufacturer_digits[0];
    UPC 3rd  digit = manufacturer_digits[1]; UPC 4th  digit = manufacturer_digits[2];
    UPC 5th  digit = manufacturer_digits[3]; UPC 6th  digit = manufacturer_digits[4];
    UPC 7th  digit = product_digits[0]     ; UPC 8th  digit = product_digits[1]     ;
    UPC 9th  digit = product_digits[2]     ; UPC 10th digit = product_digits[3]     ;
    UPC 11th digit = product_digits[4]     ; 
  */

  int res, i;

  /* Procedure to compute check number */
  // get sum of digits in odd places
  res = item_digit + (*m_digits_ptr)[1] + (*m_digits_ptr)[3];
  for (i = 0; i <= 4; i += 2)
  {
    res += (*p_digits_ptr)[i];
  }
  // multiply this sum by 3
  res *= 3;
  // add it to the sum of digits in even places
  for (i = 0; i <= 4; i += 2)
  {
    res += (*m_digits_ptr)[i];
  }
  res += (*p_digits_ptr)[1] + (*p_digits_ptr)[3];
  // subtract 1 from the total
  res -= 1;
  // get the remainder when the adjusted total is divided by 10
  res /= 10;
  // subtract the remainder from 9
  res = 9 - res;
  /* END Procedure to compute check number */

  // printf("Valid check digit is: %d\n", res);
  return res;
}
