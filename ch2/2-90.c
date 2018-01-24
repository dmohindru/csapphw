#include <stdio.h>
#include <assert.h>
#include <math.h>

/* exponent range -126 to 127 */
float u2f(unsigned x) {
  return *(float*) &x;
}
float fpwr2(int x)
{
  /* Result exponent and fraction */
  unsigned exp, frac;
  unsigned u;
  
  if (x < (-126 - 23))//_________
  {
    /* Too small. Return 0.0 */
    exp = 0;//_________
    frac = 0;//_________
  } 
  else if (x < -126) //_________
  {
    /* Denormalized result */
    exp = 0;//____________
    frac = 1 << 149 + x;//___________
  }
  else if (x < 128) //_____________
  {
    /* Normalized result */
    exp = x + 127;//____________
    frac = 0;//___________
  }
  else
  {
    /* Too big. Return +oo */
    exp = 0xFF;//____________
    frac = 0;//___________
  }
  u  = exp << 23 | frac;
  /* Return as float */
  return u2f(u);
}
int main(int argc, char* argv[]) {
  assert(fpwr2(0) == powf(2,0));
  assert(fpwr2(100) == powf(2,100));
  assert(fpwr2(-100) == powf(2,-100));
  assert(fpwr2(10000) == powf(2,10000));
  assert(fpwr2(-10000) == powf(2,-10000));
  return 0;
}
