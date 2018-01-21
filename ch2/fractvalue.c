/* Date: 21/01/218
 * Time: 09:26 AM
 * Author: Dhruv Mohindru
 * Description: This program calculates fraction value in decimal value
 * of form numerator/denominator with a bit patter string.
 * e.g for this pattern string 1110 0000, program would output 7/8.
 * Its a help program to analysis floating point values
 */
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
  if(argc != 2)
  {
    printf("usage: fractvalue bitpatterstring\n");
    return 1;
  }
  int i, lsb, length = strlen(argv[1]);
  int numerator, lsb_power2;
  //loop to find index of least significant 1 in bit string
  for(i = 0; i < length; i++)
  {
    if(argv[1][i] == '1')
    {
      lsb = i + 1;
    }
  }
  printf("You entered: %s\n", argv[1]);
  printf("lsb: %d\n", lsb);
  numerator = 0;
  lsb_power2 = 1 << lsb;
  for(i = 0; i < length; i++)
  {
    if(argv[1][i] == '1')
    {
      numerator +=  lsb_power2 / (1 << (i + 1)); //2^lsb / 2^(i+1)
    }
  }
  printf("fraction of form 0.ffff result: %d/%d\n", numerator, lsb_power2);
  printf("fraction of form 1.ffff result: %d/%d\n", numerator + lsb_power2, lsb_power2);
  return 0;
}
