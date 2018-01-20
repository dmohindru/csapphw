#include <stdio.h>

unsigned f2u(float x)
{
  return *(unsigned *)&x;
}
int float_le(float x, float y)
{
  unsigned ux = f2u(x);
  unsigned uy = f2u(y);
  /* Get sign bits */
  unsigned sx = ux >> 31;
  unsigned sy = uy >> 31;
  
  
  /* Give an expression using only ux, uy, sx and sy */
  return sx == sy ? (sx == 0 ? ux <= uy : ux >= uy) : sx > sy;
}
int main(int argc, char *argv[])
{
  printf("%d\n", float_le(+0, -0));
  printf("%d\n", float_le(0, 3));
  printf("%d\n", float_le(-4, -0));
  printf("%d\n", float_le(-4, -5));
  return 0;
}
