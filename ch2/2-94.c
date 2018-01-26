#include <stdio.h>

typedef unsigned float_bits;

float_bits float_twice(float_bits f)
{
  unsigned sign = f >> 31;
  unsigned exp = f >> 23 & 0xFF;
  unsigned frac = f & 0x7FFFFF;
  if (exp == 0xFF) //its a NaN or oo
    return f;
  else if (exp == 0) //its a denormalized number
    frac <<= 1;
  else if(exp == 0xFF - 1)//max exponent
  {
    exp = 0xFF;
    frac = 0;
  }
  else //normal number
    exp += 1;
  return (sign << 31 | exp << 23 | frac);
}
int main(int argc, char *argv[])
{
  return 0;
}
