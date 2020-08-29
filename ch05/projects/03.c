#include <stdio.h>

/* Calculate rival's commission and store its value to pointer `rival_ptr` */
void get_rival_commission(float *rival_ptr, int num_of_shares);

/* Calculate broker's commission and store its value to pointer `broker_ptr` */
void get_broker_commission(float *broker_ptr, int value);

int main()
{
  int shares, price_per_share, value;
  float broker_commission, rival_commission;

  printf("Enter number of shares: ");
  scanf("%d", &shares);

  printf("Enter price per share: ");
  scanf("%d", &price_per_share);

  value = shares * price_per_share;

  get_rival_commission(&rival_commission, shares);
  get_broker_commission(&broker_commission, value);

  printf("Rival\'s commission: $%.2f\n", rival_commission);
  printf("Broker\'s commission: $%.2f\n", broker_commission);
  return 0;
}

/* Implementation */

void get_rival_commission(float *rival_ptr, int num_of_shares)
{
  if (num_of_shares < 2000)
    *rival_ptr = 33 + (num_of_shares * 0.03);
  else
    *rival_ptr = 33 + (num_of_shares * 0.02);
}

void get_broker_commission(float *broker_ptr, int value)
{
  int base;
  float ratio;

  if (value < 2500)
  {
    base = 30;
    ratio = 0.017;
  }
  else if (value < 6250)
  {
    base = 56;
    ratio = 0.0066;
  }
  else if (value < 20000)
  {
    base = 76;
    ratio = 0.034;
  }
  else if (value < 50000)
  {
    base = 100;
    ratio = 0.0022;
  }
  else if (value < 500000)
  {
    base = 155;
    ratio = 0.0011;
  }
  else
  {
    base = 255;
    ratio = 0.0009;
  }

  *broker_ptr = base + ratio * value;

  if (*broker_ptr < 39)
    *broker_ptr = 39;
}