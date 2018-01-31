#include <stdio.h>
#include <math.h>
#include <limits.h>

typedef unsigned float_bits;

/* Helper function*/
unsigned f2u(float f) {
  return *(unsigned*) &f;
}

float u2f(unsigned u) {
  return *(float*) &u;
}

/*
 * Compute (int) f
 * If conversion causes overflow or f is NaN, return 0x80000000
 */
/*int float_f2i(float_bits f)
{
  unsigned sign = f >> 31;
  unsigned exp = f >> 23 & 0xFF;
  unsigned frac = f & 0x7FFFFF;
  int num = 0;
  unsigned bias = 127;
  unsigned M, E;
  if (exp >= 0 && exp < bias) // number is less than zero
  {
    num = 0;
  }
  else if(exp > 31 + bias) // its a overflow
  {
    num = 0x80000000;
  }
  else //number is with range
  {
    M = 0x800000 | frac; // generate Mantesa of form 1 fff ffff ffff ffff ffff ffff
    E = exp - bias;       //get E as per formula in book
    /* Since operatoin M = 0x800000 | fract will generate 24 bit number
     * So we need to shift it left if E > 23, mean append zero at the end
     * or if E <=23 we need to shift the whole 24 bit number to logical left
     */
/*    if (E > 23)         
      num = M << (E - 23);
    else
      num = M >> (23 - E);
  }
  return sign ? -num : num;
}
*/
int float_f2i(float_bits f) {
  unsigned sig = f >> 31;
  unsigned exp = f >> 23 & 0xFF;
  unsigned frac = f & 0x7FFFFF;
  unsigned bias = 0x7F;

  int num;
  unsigned E;
  unsigned M;

  /*
   * consider positive numbers
   *
   * 0 00000000 00000000000000000000000
   *   ===>
   * 0 01111111 00000000000000000000000
   *   0 <= f < 1
   * get integer 0
   *
   * 0 01111111 00000000000000000000000
   *   ===>
   * 0 (01111111+31) 00000000000000000000000
   *   1 <= f < 2^31
   * integer round to 0
   *
   * 0 (01111111+31) 00000000000000000000000
   *   ===>
   * greater
   *   2^31 <= f < oo
   * return 0x80000000
   */
  if (exp >= 0 && exp < 0 + bias) {
    /* number less than 1 */
    num = 0;
  } else if (exp >= 31 + bias) {
    /* number overflow */
    /* or f < 0 and (int)f == INT_MIN */
    num = 0x80000000;
  } else {
    E = exp - bias;
    M = frac | 0x800000;
    if (E > 23) {
      num = M << (E - 23);
    } else {
      /* whether sig is 1 or 0, round to zero */
      num = M >> (23 - E);
    }
  }

  return sig ? -num : num;
}
int main(int argc, char *argv[])
{
  unsigned num, r;
  float f;
  int i, num_f2i, f_i;
  for (num = 0; num <= 100000; num++)
  {
    //printf("Testing for num: %u\n", num);
    r = rand() % UINT_MAX;
    num_f2i = float_f2i(r);
    f = u2f(r);
    f_i = (int) f;
    if (f_i != num_f2i)
    {
      printf("float_f2i failed for value of num: %u\n", num);
      break;
    }
  }
  return 0;
}
