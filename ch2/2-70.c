#include <stdio.h>

int fits_bits(int x, int n)
{
  //get left most one in number x and generate its mask
  /* My Solution, which is partially correct :-(
  x |= x >> 1;
  x |= x >> 2;
  x |= x >> 4;
  x |= x >> 8;
  x |= x >> 16;
  int msb_mask = x & (~x >> 1);
  int w = sizeof(int) << 3;
  /* generate mask of all one for number of bits 
   * and perform bitwise and with msb_mask
   */
  //return !!(msb_mask & ((unsigned)-1 >> (w - n - 1) >> 1));
  /* Better solution 
   * and indeed a very eligant solution :-)
   */
  x >>= n - 2;
  return !(x >> 1) || !~(x >> 1);
}
int main(int argc, char *argv)
{
  printf("%d\n", fits_bits(-1, 8));
  printf("%d\n", fits_bits(128, 8));
  //printf("%d\n", fits_bits(10, 2));
  //printf("%d\n", fits_bits(10, 3));
  //printf("%d\n", fits_bits(10, 4));
  //printf("%d\n", fits_bits(255, 5));
  //printf("%d\n", 1 << 3);
  return 0;
}

