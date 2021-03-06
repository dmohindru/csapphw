#include <stdio.h>
#include <math.h>
#include <limits.h>
/* Reference to article about int to float conversion
 * https://locklessinc.com/articles/i2f/
 * https://github.com/wky/ICS-labs/blob/master/data/bits.c
 */
typedef unsigned float_bits;
/* Helper function*/
unsigned f2u(float f) {
  return *(unsigned*) &f;
}

float u2f(unsigned u) {
  return *(float*) &u;
}

/*
 * TODO: check for INT_MAX case
 * study round to zero , round to even case
 */
/* Calculate bit length */
/*int bit_length(int i)
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
}*/

/* generate frac bits mask */
/*unsigned frac_mask(int length)
{
  return (unsigned)-1 >> (32-length+1);
}
/* Computer (float) i */
/*float_bits float_i2f(int i)
{
/* 1. Get sign bit
 * 2. Calculate leftmost position E of 1 in a positive number
 *    and in negetive number left most except sign bit. Special case
 *    when i = INT_MIN, frac = 0;
 * 3. Calculate e = bais + E
 * 4. frac = Mantisa_mask & number
 * 5. assemble bits sign << 31 | e << 23 | frac
 */
 /*unsigned sign, e, E, frac, fmask, bias = 127;
 int num, len;
 sign = i >> 31;
 if (i == INT_MIN)
 {
   E = 31;
   e = E + bias; 
   frac = 0;
 }
 else
 {
   //num = sign ? -i : i;
   len = bit_length(i);
   fmask = frac_mask(len);
   E = len - 1;
   e = bias + E;
   num = sign ? -i : i;
   frac = num & fmask;
   if (E > 23)
   {
     //need to set condition for round to zero rule
     frac >>= (E - 23);
   }
   else
   {
     frac <<= (23 - E);
   }
 }
 return sign << 31 | e << 23 | frac;
}*/
float_bits float_i2f(int x) {
    int e = 158;
    int mask = 1<<31;
    int sign = x&mask;
    int frac;
    if (x == mask)
        return mask | (158<<23);
    if (!x)
        return 0;
    if (sign)
        x = ~x + 1;
    while (!(x&mask)) {
        x = x<<1;
        e = e -1;
    }
    frac = (x&(~mask)) >> 8;
    if (x&0x80 && ((x&0x7F) > 0 || frac&1)) //round off condition
        frac = frac + 1;
    return sign + (e<<23) + frac;
}
int main(int argc, char *argv[])
{
  unsigned num, r;
  float f, num_f;
  int i, f_i;
  for (num = 0; num <= 100000; num++)
  {
    //printf("Testing for num: %u\n", num);
    r = rand() % UINT_MAX;
    num_f = u2f(float_i2f((int)r));
    f = (float)(int)r;
    if (f != num_f)
    {
      printf("float_i2f failed for value of num: %u\n", num);
      break;
    }
  }
  
  return 0;
}
