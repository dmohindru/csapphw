#include <stdio.h>
#include <limits.h>

int tsub_ok(int x, int y)
{
  /*int result = x - y;
  int sign_mask = INT_MIN;
  
  return !((x & sign_mask) && (y & sign_mask) && !(result & sign_mask));
  //return (1) && (1) && !(1);*/
  if (y == INT_MIN)
    return 0;
  int neg_y = -y;
  int result = x + neg_y;
  int pos_overflow = x > 0 && neg_y > 0 && result < 0;
  int neg_overflow = x < 0 && neg_y < 0 && result >= 0;
  
  return !(pos_overflow || neg_overflow);
}
int main(int argc, char *argv[])
{
  printf("%d\n", tsub_ok(INT_MIN, -0x1234));
  printf("%d\n", tsub_ok(INT_MIN, 1));
  printf("%d\n", tsub_ok(2, 1));
  return 0;
}
