#include <stdio.h>
#include <limits.h>

typedef unsigned float_bits;

/* Calculate bit length */
int bit_length(int i)
{
  int length = 0;
  if (i == INT_MIN)
    return 31;
  if (i < 0)
    i = -i; 
  
  while (i > 0)
  {
    length++;
    i = (unsigned)i >> 1;
  }
  return length;
}

/* generate frac bits mask */
unsigned frac_mask(int length)
{
  return (unsigned)-1 >> (32-length+1);
}
/* Computer (float) i */
float_bits float_i2f(int i)
{
/* 1. Get sign bit
 * 2. Calculate leftmost position E of 1 in a positive number
 *    and in negetive number left most except sign bit. Special case
 *    when i = INT_MIN, frac = 0;
 * 3. Calculate e = bais + E
 * 4. frac = Mantisa_mask & number
 * 5. assemble bits sign << 31 | e << 23 | frac
 */
 unsigned sign, e, E, frac, bias = 127;
 sign = i >> 31;
 if (i == INT_MIN)
 {
   E = 31;
   frac = 0;
 }
 else
 {
   
   
 }
 
}
int main(int argc, char *argv[])
{
  int len;
  unsigned frac_bit_mask;
  len = bit_length(INT_MAX);
  frac_bit_mask = frac_mask(len);
  printf("%d\n", len);
  printf("%X\n", frac_bit_mask);
  //printf("%d\n", bit_length(-125698));
  //printf("%d\n", bit_length(-9999));
  //printf("%d\n", bit_length(INT_MIN)); 0xFFFF0
  return 0;
}
