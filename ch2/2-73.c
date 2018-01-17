#include <stdio.h>
#include <limits.h>

int saturating_add(int x, int y)
{
  int result = x + y;
  int sign_mask = INT_MIN;
  int overflow_mask = !(x & sign_mask) && !(y & sign_mask) && (result & sign_mask);
  int underflow_mask =  (x & sign_mask) && (y & sign_mask) && !(result & sign_mask);
  
  (overflow_mask && (result = INT_MAX) || underflow_mask && (result = INT_MIN));
  return result;
}
int main(int argc, char *argv[])
{
  printf("%d\n", saturating_add(INT_MAX, 0x1234));
  printf("%d\n", saturating_add(INT_MIN, -0x1234));
  printf("%d\n", saturating_add(INT_MAX, -0x1234));
  printf("%d\n", saturating_add(INT_MIN, 0x1234));
  return 0;
}
