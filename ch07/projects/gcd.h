/** Euclid's Algorithm to Find the Greatest Common Divisor (GCD)
    @return when this procedure ends, *a hold the GCD value
 */
void process_find_gcd(long *const a, long *const b)
{
  long temp;

  while (*b != 0)
  {
    temp = *a % *b;
    *a = *b;
    *b = temp;

    /* to see visualisation of this process, uncomment the next line */
    // printf("first num = %ld, second num = %ld\n", *a, *b);
  }

  // at this point, *a is the GCD
}

/** Pure Function Implementing Euclid's Algorithm Recursively to 
 *    Find the Greatest Common Divisor (GCD)
 */
const long find_gcd(long a, long b)
{
  long temp = a % b;
  return (temp == 0) ? b : find_gcd(b, temp);
}
