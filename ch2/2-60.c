#include <stdio.h>
#include <assert.h>

unsigned replace_byte(unsigned x, int i, unsigned char b)
{
  unsigned mask = 0xFF;
  i = i * 8;
  mask = mask << i;
  x = x & ~mask;
  mask = b;
  mask = mask << i;
  x = x | mask;
  return x;
}

int main(int argc, char *argv[])
{
  unsigned val = replace_byte(0x12345678, 2, 0xAB);
  //printf("%X\n",replace_byte(0x12345678, 2, 0xAB));
  printf("%X\n",val);
  val = replace_byte(0x12345678, 0, 0xAB);
  //printf("%X\n",replace_byte(0x12345678, 0, 0xAB));
  printf("%X\n",val);
  //assert(val == 0x123456AC);
  return 0;
}
