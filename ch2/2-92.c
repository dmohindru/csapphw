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
  unsigned f = 0x4640E400;
  unsigned f_neg = float_negetive(f);
  //float f_num = u2f(f);
  //float test_num = -12345.00;
  float test_num = u2f(0xC640E400);
  unsigned test_f_neg = f2u(test_num);
  printf("%d\n", f_neg == test_f_neg);
  
  return 0;
}
