#include <stdio.h>
#include <math.h>
#include <limits.h>

typedef unsigned float_bits;
/* Helper function*/
unsigned f2u(float f) {
  return *(unsigned*) &f;
}

float u2f(unsigned u) {
  return *(float*) &u;
}
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
  unsigned num, num_neg, f_u, r;
  float f;
  int i;
  for (num = 0; num <= 100000; num++)
  {
    //printf("Testing for num: %u\n", num);
    r = rand() % UINT_MAX;
    num_neg = float_negetive(r);
    f = u2f(r);
    if(isnan(f))
      f_u = f2u(f);
    else
      f_u = f2u(-f); 
    if (f_u != num_neg)
    {
      printf("float_negetive failed for value of num: %u\n", num);
      break;
    }
  }
  return 0;
}
