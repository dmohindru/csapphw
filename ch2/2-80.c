#include <stdio.h>
#include <limits.h>

int mul3div4(int x)
{
  int is_neg = x & INT_MIN;
  (is_neg && (x = x + (1 << 2) - 1));
  x >>= 2;
  return (x << 1) + x;
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
