#include <stdio.h>

int main()
{
  int a, b, c;
  float d, e;

  char formats[4][2][12] = {
      {"%d", " %d"},
      {"%d-%d-%d", "%d -%d -%d"},
      {"%f", "%f "},
      {"%f,%f", "%f, %f"}
  };

  /* Test case (a) */
  printf("\nInput x for scanning with the format `%%d`: ");
  scanf(formats[0][0], &a);
  printf("x = %d\n", a);

  printf("\nInput x for scanning with the format ` %%d`: ");
  scanf(formats[0][1], &a);
  printf("x = %d\n", a);

  /* Test case (b) */
  printf("\nInput x,y,z for scanning with the format `%%d-%%d-%%d`: ");
  scanf(formats[1][0], &a, &b, &c);
  printf("x = %d; y = %d; z = %d\n", a, b, c);

  printf("\nInput x,y,z for scanning with the format `%%d -%%d -%%d`: ");
  scanf(formats[1][1], &a, &b, &c);
  printf("x = %d; y = %d; z = %d\n", a, b, c);

  /* Test case (c) */
  printf("\nInput x for scanning with the format `%%f`: ");
  scanf(formats[2][0], &d);
  printf("x = %f\n", d);

  printf("\nInput x for scanning with the format `%%f `: ");
  // to escape backspace in this case, you should input float followed by an invalid character, i.e. '-' 
  scanf(formats[2][1], &d);
  printf("x = %f\n", d);

  /* Test case (d) */
  printf("\nInput x,y,z for scanning with the format `%%f,%%f`: ");
  scanf(formats[3][0], &d, &e);
  printf("x = %f; y = %f\n", d, e);

  printf("\nInput x,y,z for scanning with the format `%%f, %%f`: ");
  scanf(formats[3][1], &d, &e);
  printf("x = %f; y = %f\n", d, e);

  /* CONCLUSION: For case: 
    (a) these two format strings help `scanf` to behave the same 
    (b) the second format string can be used as alternative for the first one but not vice versa
    (c) these two format strings don't help `scanf` to behave the same
    (d) the second format string can be used as alternative for the first one but not vice versa
  */

  return 0;
}