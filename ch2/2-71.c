#include <stdio.h>

typedef unsigned packed_t;

/* Answer A: below code does not sign extent the extracted byte
int xbyte(packed_t word, int bytenum)
{
  return (word >> (bytenum << 3)) && 0xFF;
}
*/
/* Answer B: correct code with sign extention */
int xbyte(packed_t word, int bytenum)
{
  /* My Solution
  int w = sizeof(int) << 3;
  word <<= w - (bytenum  << 3) - 8;
  return (int) word >> (w - 8);
  */
  /* other solution as seem quite similar */
  int w = sizeof(unsigned);
  int left_shift = (w - 1 - bytenum) << 3;
  int right_shift = (w - 1) << 3;
  return (int) word << left_shift >> right_shift;
}
int main(int argc, char *argv[])
{
  printf("%X\n", xbyte(0x8F77F011, 3));
  printf("%X\n", xbyte(0x8F77F011, 2));
  printf("%X\n", xbyte(0x8F77F011, 1));
  printf("%X\n", xbyte(0x8F77F011, 0));
  return 0;
}
