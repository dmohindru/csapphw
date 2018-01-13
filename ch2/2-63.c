#include <stdio.h>
#include <assert.h>

unsigned srl(unsigned x, int k)
{
  /* Perform shift arithmetically */
  unsigned xsra = (int) x >> k;
  //need to clear upper order w-k bits
  int mask = -1; //all one
  int w = sizeof(int) << 3; //get number of bits in int
  mask = mask << (w - k); //shift mask to appropriate position
  return xsra & ~mask;
  
}
int sra(int x, int k)
{
  /* Perform shift logically */
  int xsrl = (unsigned) x >> k;
  int mask = -1; //all one
  int w = sizeof(int) << 3; //get number of bits in int
  mask = mask << (w - k);
  if(x < 0)
    return xsrl | mask;
  return xsrl;
}

int main(int argc, char *argv[])
{
  
  /*printf("%X\n", srl(0x7FFFFFFF, 2));
  printf("%X\n", sra(0x7FFFFFFF, 2));
  */
  unsigned test_unsigned = 0x12345678;
  int test_int = 0x12345678;
  assert(srl(test_unsigned, 4) == test_unsigned >> 4);
  assert(sra(test_int, 4) == test_int >> 4);
  return 0;
}
