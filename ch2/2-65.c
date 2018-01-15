#include <stdio.h>

/* Return 1 when x contains an odd number of 1s; 0 otherwise.
   Assume w=32 */
/*
Bitwise algorithms
https://www.geeksforgeeks.org/bitwise-algorithms/
 */
int odd_ones(unsigned x)
{
  //At most 12 arthmatic, logical and bitwise operations
  x ^= x >> 16;
  //printf("value of x after xor: %X\n", x);
  x ^= x >> 8;
  //printf("value of x after xor: %X\n", x);
  x ^= x >> 4;
  //printf("value of x after xor: %X\n", x);
  x ^= x >> 2;
  //printf("value of x after xor: %X\n", x);
  x ^= x >> 1;
  //printf("value of x after xor: %X\n", x);
  x &= 0x1;
  return x;
  
  
}
int even_ones(unsigned x)
{
  //At most 12 arthmatic, logical and bitwise operations
  x ^= x >> 16;
  //printf("value of x after xor: %X\n", x);
  x ^= x >> 8;
  //printf("value of x after xor: %X\n", x);
  x ^= x >> 4;
  //printf("value of x after xor: %X\n", x);
  x ^= x >> 2;
  //printf("value of x after xor: %X\n", x);
  x ^= x >> 1;
  //printf("value of x after xor: %X\n", x);
  x &= 0x1;
  return !x;
  
  
}

int main(int argc, char *argv[])
{
  printf("Odd check\n");
  printf("%d\n", odd_ones(0x01010101));
  printf("%d\n", odd_ones(0x01010100));
  printf("Even check\n");
  printf("%d\n", even_ones(0x01010101));
  printf("%d\n", even_ones(0x01010100));
  return 0;
}
