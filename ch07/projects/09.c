#include <stdio.h>
#include <ctype.h>

/* Convert 12-hour format to 24-hour format */

int Time_input(int *const h_ptr, int *const m_ptr)
{
  int i;
  char cur;

  // printf("\nPointer address: %zu\n", &t);
  scanf("%d:%d", h_ptr, m_ptr);

  // strip space characters out of buffer
  for (;;)
  {
    cur = getchar();
    if (!isspace(cur))
      break;
  }

  switch (toupper(cur))
  {
  case 'P':
    *h_ptr += 12;
    return 0;
  case 'A':
    return 0;
  default:
    printf("INVALID!\n");
    return 1;
  }
}

int main()
{
  int h, m, program_status;

  printf("Enter a 12-hour time: ");
  program_status = Time_input(&h, &m);

  printf("Equivalent 24-hour time: %.2d:%.2d\n", h, m);
  return program_status;
}
