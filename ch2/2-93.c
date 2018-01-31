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
  unsigned num, num_abs, f_u, r;
  float f;
  int i;
  for (num = 0; num <= 100000; num++)
  {
    //printf("Testing for num: %u\n", num);
    r = rand() % UINT_MAX;
    num_abs = float_absval(r);
    f = u2f(r);
    if(isnan(f))
      f_u = f2u(f);
    else
      f_u = f2u(fabs(f));
    if (f_u != num_abs)
    {
      printf("float_abs failed for value of num: %u\n", num);
      break;
    }
  }
  return 0;
}
