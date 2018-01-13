#include <stdio.h>

int any_odd_one(unsigned x)
{
  unsigned mask = 0xAAAAAAAA;
  return !!(x & mask);
}
int main (int argc, char *argv[])
{
  printf("%d\n", any_odd_one(0x55555555));
  printf("%d\n", any_odd_one(0x66666666));
}
