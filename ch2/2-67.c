#include <stdio.h>

/*int bad_int_size_is_32()
{
  int set_msb = 1 << 31;
  int beyond_msb = 1 << 32;
  return set_msb && !beyond_msb;
}*/
/* As c standards state
 * If the value of the right operand is negative or is greater than or equal to the width of the promoted left
 * operand, the behavior it undefined.
 * Basic idea to follow is if shifting a value by number of places is
 * greater than supported data type than split that number of places value
 * into supported data type size
 * e.g. 32 shifts for 32 bit machine can be done as : 31 + 1
 * e.g. 32 shifts for 16 bit machine can be done as : 15 + 15 + 1
 * e.g. 32 shifts for 8 bit machine can be done as : 7 + 7 + 7 + 7 + 4  
 */
int int_size_is_32()
{
  int set_msb = 1 << 31;
  int beyond_msb = set_msb << 1;
  return set_msb && !beyond_msb;
}
int int_size_is_32_for_16bits()
{
  int set_msb = 1 << 15 << 15 << 1;
  int beyond_msb = set_msb << 1;
  return set_msb && !beyond_msb;
}
int main(int argc, char *argv[])
{
  printf("%d\n", int_size_is_32());
  return 0;
}
