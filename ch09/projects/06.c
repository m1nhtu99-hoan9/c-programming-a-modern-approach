#include <stdio.h>

double compute_polynomial(float x) {
  double res;
  int i;
  const int COEFFS[6] = {3, 2, -5, -1, 7, -6};

  for (i = 1
      , res = COEFFS[0] * x + COEFFS[1]
      ; i < 5
      ; i++) {
    res = res * x + COEFFS[i + 1];
  }

  return res;
}

int main() {
  float inp;

  printf("Calculate the value of 3*x^5 + 2*x^4 - 5*x^3 - x^2 + 7*x - 6.\n");
  printf("Input x: ");
  scanf("%f", &inp);

  printf("Result: %lf\n", compute_polynomial(inp));
  return 0;
}

