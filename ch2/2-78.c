#include <stdio.h>
#include <limits.h>

int divide_power2(int x, int k)
{
  int is_neg = x & INT_MIN;
  (is_neg && (x = x + (1 << k) -1)); 
  return x >> k;
}
int main(int argc, char *argv[])
{
  printf("%d\n", divide_power2(100, 2));
  printf("%d\n", divide_power2(-100, 2));
  return 0;
}
