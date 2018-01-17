#include <stdio.h>

/
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
  return (word >> (bytenum << 3)) && 0xFF;
}
int main(int argc, char *argv[])
{
  
  return 0;
}
