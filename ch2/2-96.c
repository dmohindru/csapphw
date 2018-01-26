#include <stdio.h>

typedef unsigned float_bits;
/*
 * Compute (int) f
 * If conversion causes overflow or f is NaN, return 0x80000000
 */
int float_f2i(float_bits f)
{
  unsigned sign = f >> 31;
  unsigned exp = f >> 23 & 0xFF;
  unsigned frac = f & 0x7FFFFF;
  int num = 0;
  unsigned bias = 127;
  unsigned M, E;
  if (exp >= 0 && exp < bias) // number is less than zero
  {
    num = 0;
  }
  else if(exp > 31 + bias) // its a overflow
  {
    num = 0x80000000;
  }
  else //number is with range
  {
    M = 0x800000 | frac; // generate Mantesa of form 1 fff ffff ffff ffff ffff ffff
    E = exp - bias;       //get E as per formula in book
    /* Since operatoin M = 0x800000 | fract will generate 24 bit number
     * So we need to shift it left if E > 23, mean append zero at the end
     * or if E <=23 we need to shift the whole 24 bit number to logical left
     */
    if (E > 23)         
      num = M << (E - 23);
    else
      num = M >> (23 - E);
  }
  return sign ? -num : num;
}

int main(int argc, char *argv[])
{
  return 0;
}
