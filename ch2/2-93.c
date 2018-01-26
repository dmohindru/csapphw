#include <stdio.h>

typedef unsigned float_bits;

float_bits float_absval(float_bits f)
{
  unsigned exp = f >> 23 & 0xFF;
  unsigned frac = f & 0x7FFFFF;
  unsigned u;
  if (exp == 0xFF && frac != 0) //its a NaN
    return f;
  else
    return f & 0x7FFFFFFF;
}
int main(int argc, char *argv[])
{
  return 0;
}
