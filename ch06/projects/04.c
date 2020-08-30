#include <stdio.h>

const float RANGES[5] = {2500.00, 6250.00, 20000.00, 50000.00, 500000.00};
struct TradeConstant
{
  int base;
  float ratio;
};

const struct TradeConstant CONSTS[6] = {
    {
        .base = 30,
        .ratio = .017,
    },
    {
        .base = 56,
        .ratio = .0066,
    },
    {
        .base = 76,
        .ratio = .0034,
    },
    {
        .base = 100,
        .ratio = .0022,
    },
    {
        .base = 155,
        .ratio = .0011,
    },
    {
        .base = 255,
        .ratio = .0009,
    },
};

int main()
{
  int base;
  float ratio, commission, value = 1;

  while (value != 0)
  {
    printf("Enter the value of trade (0 to terminate): ");
    scanf("%f", &value);

    for (int i = 0; i < 5; i++)
    {
      // exclusively for the lower bound check case
      if (i == 0)
      {
        if (value < RANGES[0])
        {
          ratio = CONSTS[0].ratio;
          base = CONSTS[0].base;
        }
      }
      // for other check cases
      else
      {
        if (value >= RANGES[i - 1] && value < RANGES[i])
        {
          ratio = CONSTS[i].ratio;
          base = CONSTS[i].base;
        }
      }

      // for the upper bound, implement this extra check case
      if (i == 4)
      {
        if (value > RANGES[4])
        {
          ratio = CONSTS[5].ratio;
          base = CONSTS[5].base;
        }
      }
    }

    //printf("base = %d; ratio = %.4f\n", base, ratio);

    commission = base + ratio * value;
    if (commission < 39.00)
      commission = 39.00;

    printf("Commission: $%.2f\n", commission);
  }

  return 0;
}
