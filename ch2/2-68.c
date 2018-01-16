#include <stdio.h>


int lower_one_mask(int n)
{
  /* my solution
  int mask = 1 << (n -1);
  mask |= mask >> 1;
  mask |= mask >> 2;
  mask |= mask >> 4;
  mask |= mask >> 8;
  mask |= mask >> 16;
  */
  /* A better solution */
  int w = sizeof(int) << 3; //get number of bits
  return (unsigned) -1 >> (w - n); //move all ones (-1) w-n bits to logical right  
}
int main(int argc, char *argv[])
{
  printf("%X\n", lower_one_mask(6));
  printf("%X\n", lower_one_mask(17));
  printf("%X\n", lower_one_mask(32));
  printf("%X\n", lower_one_mask(2));
  return 0;
}
