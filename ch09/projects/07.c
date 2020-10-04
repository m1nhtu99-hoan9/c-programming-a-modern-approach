#include <stdio.h>

/* `power` function */

double power(float x, int n) {
  if (n == 0) {
    return 1;
  }
  else if (n == 1) {
    return x;
  }
  else if (n == -1) {
    return 1.0 / x;
  }
  else {
    if (n % 2 == 1) {
      return x * power(x, n -1);
    }
    else {
      int half_n = n / 2;
      return power(x, half_n) * power(x, half_n);
    }
  }
}

int main () {
  float base_val;
  int power_val;

  printf("Calculate x^n.\n");
  printf("Input x: ");
  scanf("%f", &base_val);
  printf("Input n: ");
  scanf("%d", &power_val);

  printf("Result: %f\n", power(base_val, power_val));

  return 0;
}