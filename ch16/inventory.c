#include <stdio.h>
#include <ctype.h>
#include "readline.h"

/* Maintains a parts database (array version) */

#define NAME_LEN 25
#define MAX_PARTS 100

struct Part
{
  int number;
  char name[NAME_LEN + 1];
  int on_hand;
} inventory[MAX_PARTS];

/* number of parts currently stored */
int num_parts = 0;

/* Looks up a Part number in the inventory array.
   Returns the array index if the part number is found, otherwise returns -1.
*/
int Part_find(int number);

/* Prompts the user for information about a new path and then insert the part
   into the database, then returns 0.
   Prints an error message and return -1 prematurely if the part already exists or
   the database is full. 
*/
int insert(void);

/* Prompts the user to enter a part number, then looks up the part in the database. 
   If the part exists, prints the name and quantity on hands, then returns 0; 
   If not, prints an error message and return -1 */
int search(void);

/* Prompts the user to enter a part number.
   Print error message and return -1 if the part doesn't exist; 
   otherwise, prompts the user to enter change in quantity on hand,
   update the database, then return 0. */
int update(void);

/* Prints a listing of all parts in the database, showing the part number, 
   part name, and quantity on hand. Parts are in the order in which they
   were entered into the database.
*/
void print(void);

/*************************************************************************
 * Prompts the user to enter an operation code, then calls a function
 * to perform the requested action. Repeats until the user enters the 
 * command 'q'. Print an error message if user enters an illegal code.
 *************************************************************************/
int main()
{
  char code;

  for (;;)
  {
    printf("Enter operation code: ");
    scanf(" %c", &code);

    /* skip to end of line */
    for (;;)
    {
      if (getchar() == '\n')
        break;
    }

    switch (toupper(code))
    {
    case 'I':
      insert();
      break;
    case 'S':
      search();
      break;
    case 'U':
      update();
      break;
    case 'P':
      print();
      break;
    case 'Q':
      return 0;
    default:
      printf("ILLEGAL INPUT!!!");
      return 1;
    }

    printf("\n");
  }
}

/* implementation */

int Part_find(int number)
{
  int i;

  for (i = 0; i < num_parts; i++)
  {
    if (inventory[i].number == number)
    {
      return i;
    }
  }

  return -1;
}

int insert()
{
  int part_num;

  if (num_parts == MAX_PARTS)
  {
    printf("Database is full; can't add more parts.\n");
    return -1;
  }
  else
  {

    printf("Enter part number: ");
    scanf("%d", &part_num);

    if (Part_find(part_num) >= 0)
    {
      printf("Part already exists.\n");
      return -1;
    }
    else
    {
      inventory[num_parts].number = part_num;
      printf("Enter part name: ");
      read_line(inventory[num_parts].name, NAME_LEN);
      printf("Enter quantity on hand: ");
      scanf("%d", &inventory[num_parts].on_hand);
      num_parts++;

      return 0;
    }
  }
}

int search()
{
  int i_res, num;

  printf("Enter part number: ");
  scanf("%d", &num);

  i_res = Part_find(num);

  if (i_res >= 0)
  {
    printf("Part name: %s\n", inventory[i_res].name);
    printf("Quantity on hand: %d\n", inventory[i_res].on_hand);

    return i_res;
  }
  else
  {
    printf("Part not found!\n");

    return -1;
  }
}

int update()
{
  int i_res, num, change;

  printf("Enter part number: ");
  scanf("%d", &num);

  i_res = Part_find(num);

  if (i_res >= 0)
  {
    printf("Enter change in quantity on hand: ");
    scanf("%d", &change);

    inventory[i_res].on_hand += change;
    return i_res;
  }
  else
  {
    printf("Part not found,\n");
    return -1;
  }
}

void print()
{
  int i;

  printf("Part Number\tPart Name\t\t\tQuantity on Hand\n");

  for (i = 0; i < num_parts; i++)
  {
    printf("%11d\t%-20s\t%16d\n", inventory[i].number, inventory[i].name, inventory[i].on_hand);
  }
}
