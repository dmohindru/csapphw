#include <stdio.h>
#include <assert.h>
int A(int x) {
  /* Explanation:
   * if any bit in x is 1 then !x with return 0
   * and !!x with return 1 hence our desired result
   */
  return !!x;
}
int B(int x) {
  /* Explanation:
   * if all bit in x is 1 (i.e. no zero) then ~x with return zero value
   * then !x with return 1 and !!x with return 0 hence our desired result
   * if any bit is zero (i.e. combo of 1 and zeros) then ~x with return non zeo value
   * then !x with return 0 and !!x with return 1 hence our desired result
   */
  return !!~x;
}
int C(int x) {
  /* mask of higher order bits and test with A function*/
  return A(x & 0xff);
}
int D(int x) {
  /* shift most siginificant byte to least significant byte
   * and test with function B
   */
  return B((x >> ((sizeof(int)-1) << 3)));
}
int main(int argc, char* argv[]) {
  int all_bit_one = ~0;
  int all_bit_zero = 0;
  printf("%d\n", D(all_bit_one));
  printf("%d\n", D(all_bit_zero));
  printf("%d\n", D(0x1234));
  printf("%d\n", D(0xFF123400));
  
  return 0;
}
