#include <stdio.h>

int leftmost_one(unsigned x)
{
  x |= x >> 1;
  x |= x >> 2;
  x |= x >> 4;
  x |= x >> 8;
  x |= x >> 16;
  
  return x & (~x >> 1);
}

int main(int argc, char *argv[])
{
  printf("%X\n", leftmost_one(0x7F00));
  printf("%X\n", leftmost_one(0x6600));
  return 0;
}
