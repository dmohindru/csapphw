#include <stdio.h>

typedef unsigned float_bits;
/*
* round to even, we care about last 2 bits of frac
*
* 00 => 0 just >>1
* 01 => 0 (round to even) just >>1
* 10 => 1 just >>1
* 11 => 1 + 1 (round to even) just >>1 and plus 1
*/
float_bits float_half(float_bits f)
{
  unsigned sign = f >> 31;
  unsigned exp = f >> 23 & 0xFF;
  unsigned frac = f & 0x7FFFFF;
  unsigned rest = f & 0x7FFFFFFF;
  int addition = (frac & 0x3) == 0x3; //round to even stuff
  if (exp == 0xFF) //its a NaN or oo
    return f;
  else if (exp == 0) //its a denormalized number
  {
    frac >>= 1;
    frac += addition;
  }
  else if (exp == 1) //from normalized to denormalized number
  {
    rest >>= 1;
    rest += addition;
    exp = (rest >> 23) & 0xFF;
    frac = rest & 0x7FFFFF;
  }
  else //normal number
  {
    exp -= 1;
  }
  return (sign << 31 | exp << 23 | frac);
}
int main(int argc, char *argv[])
{
  return 0;
}
