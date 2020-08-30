/** Euclid's Algorithm to Find the Greatest Common Divisor (GCD)
    @return when this procedure ends, *a hold the GCD value
 */
void process_find_gcd(int *const a, int *const b)
{
  int temp;

  while (*b != 0)
  {
    temp = *a % *b;
    *a = *b;
    *b = temp;

    /* to see visualisation of this process, uncomment the next line */
    // printf("first num = %d, second num = %d\n", *a, *b);
  }

  // at this point, *a is the GCD
}

/** Pure Function Implementing Euclid's Algorithm Recursively to 
 *    Find the Greatest Common Divisor (GCD)
 */
const int find_gcd (int a, int b) {
  int temp = a % b;
  if (temp == 0) return b;
  else           return find_gcd(b, a % b);
}
