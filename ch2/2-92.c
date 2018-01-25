#include <stdio.h>
#include <math.h>
#include <limits.h>

typedef unsigned float_bits;

/* Compute -f. If f in NaN, then return f. */
float_bits float_negetive(float_bits f)
{
  unsigned exp = f >> 23 & 0xFF;
  unsigned frac = f & 0x7FFFFF;
  unsigned u;
  if (exp == 0xFF && frac != 0) //its a NaN
    return f;
  else
    return f ^ 0x80000000;
}
int main(int argc, char *argv[])
{
  return 0;
}
