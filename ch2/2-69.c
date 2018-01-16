#include <stdio.h>

unsigned rotate_left(unsigned x, int n)
{
  
  /* 1. Calculate number of bits w for int
   * 2. Extract w to w-n bits from a number
   * 3. Move those bits to low order n bits
   * 4. Left shift x by n places
   * 5. Or result of 3 and 4
   * 6. Return value
   */
  /* my solution
  int w = sizeof(int) << 3; //get number of bits
  int extract_mask = ~((unsigned) -1 >> n); // extract mask
  int rotate_val = x & extract_mask; // extract value to be rotated
  rotate_val >>= w - n - 1 ; //  rotate value right shift to approprate place
  x <<= n; // shift left x by n
  return (x | rotate_val); //or the result with x and return
  */
  /* A better solution */
  int w = sizeof(int) << 3;
  return x << n | x >> (w - n - 1) >> 1;
  
}
int main(int argc, char *argv[])
{
  printf("%X\n", rotate_left(0x12345678, 4));
  printf("%X\n", rotate_left(0x12345678, 20));
  printf("%X\n", rotate_left(0x12345678, 0));
  printf("%X\n", (unsigned) -1 >> 31);
  return 0;
}
