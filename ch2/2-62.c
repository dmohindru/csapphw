#include <stdio.h>
int int_shifts_are_arithmetic()
{
  /*
   * logic behind this solution is
   * 1. first get size of int for a machine
   * 2. generate number with all 1s
   * 3. shift right most significant byte to least significant byte
   * 4. clear upper order bytes except least significant byte 
   * 5. test for all ones in least significant byte. 
   */
  /*
  int x = -1; //all ones
  return !!((x>>((sizeof(int)-1)<<3)) & 0xff);
  */
  //this solution seems simple
  int x = -1;
  return !(x ^ (x>>1)); 
}

int main(int argc, char * argv[])
{
  printf("%d\n", int_shifts_are_arithmetic());
  return 0;
}
