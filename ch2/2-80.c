#include <stdio.h>
#include <limits.h>

int mul3div4(int x)
{
  /*int is_neg = x & INT_MIN;
  (is_neg && (x = x + (1 << 2) - 1));
  x >>= 2;
  return (x << 1) + x;*/
  int is_neg = x & INT_MIN;
  int m = x & ~0x3;
  int l = x & 0x3;
  //calculation for m part
  int md4 = m >> 2;
  int md4m3 = (md4 << 1) + md4;
  //calcuation for l part
  int lm3 = (l << 1) + l;
  int bais = (1 << 2) - 1;
  (is_neg && (lm3 += bais));
  int lm3d4 =  lm3 >> 2;
  return (md4m3 + lm3d4);
}
int main(int argc, char *argv[])
{
  printf("%d\n", mul3div4(8));
  printf("%d\n", mul3div4(9));
  printf("%d\n", mul3div4(10));
  printf("%d\n", mul3div4(11));
  printf("%d\n", mul3div4(12));
  
  printf("%d\n", mul3div4(-8));
  printf("%d\n", mul3div4(-9));
  printf("%d\n", mul3div4(-10));
  printf("%d\n", mul3div4(-11));
  printf("%d\n", mul3div4(-12));
  return 0;
}
