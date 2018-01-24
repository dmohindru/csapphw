#include <stdio.h>

float fpwr2(int x)
{
  /* Result exponent and fraction */
  unsigned exp, frac;
  unsigned u;
  
  if (x < )//_________
  {
    /* Too small. Return 0.0 */
    exp = ;//_________
    frac = ;//_________
  } 
  else if (x < ) //_________
  {
    /* Denormalized result */
    exp = ;//____________
    frac = ;//___________
  }
  else if (x < ) //_____________
  {
    /* Normalized result */
    exp = ;//____________
    frac = ;//___________
  }
  else
  {
    /* Too big. Return +oo */
    exp = ;//____________
    frac = ;//___________
  }
  u  = exp << 23 | frac;
  /* Return as float */
  return u2f(u);
}
