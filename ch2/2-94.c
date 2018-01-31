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
  unsigned num, num_twice, f_u, r;
  float f;
  int i;
  for (num = 0; num <= 100000; num++)
  {
    //printf("Testing for num: %u\n", num);
    r = rand() % UINT_MAX;
    num_twice = float_twice(r);
    f = u2f(r);
    if(isnan(f))
      f_u = f2u(f);
    else
      f_u = f2u(f * 2);
    if (f_u != num_twice)
    {
      printf("float_twice failed for value of num: %u\n", num);
      break;
    }
  }
  return 0;
}
