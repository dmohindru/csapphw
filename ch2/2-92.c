#include <stdio.h>
#include <math.h>
#include <limits.h>

typedef unsigned float_bits;

/* Compute -f. If f in NaN, then return f. */
float_bits float_negetive(float_bits f)
{
  unsigned exp = f >> 23 & 0xFF;
  unsigned frac = f & 0x7FFFFF;
  if (exp == 0xFF && frac != 0) //its a NaN
    return f;
  else
    return f ^ 0x80000000;
}
int main(int argc, char *argv[])
{
  int i = 0;
  float_bits f = 0;
  //printf("%X\n", UINT_MAX);
  //printf("%X\n", (unsigned)NAN);
  //printf("%X\n", (unsigned)INFINITY);
  //printf("%X\n", (unsigned)-INFINITY);
  //printf("%f\n", (float)0x00000000);
  //printf("%f\n", (float)0x8000000000000000);
  //printf("%f\n", (float)0x7F800001);
  //printf("%f\n", (float)0x7FFFFFFF);
  for (i = 0; i <= UINT_MAX; i++)
  {
    if ((i & 0x7FFFFFFF) >= 0x7F800001 || (i & 0x7FFFFFFF)  <= 0x7FFFFFFF) //its NAN
    {
    }
    else
    {
      if(-(float) i != float_negetive(i))
      {
        printf("test failed for value: %d\n", i);
        break;
      }
    }
  }
  //UINT_MAX
  //NAN;
  //INFINITY;
  return 0;
}
