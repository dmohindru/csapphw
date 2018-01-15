#include <stdio.h>
#include <string.h>
/* Return 1 when x contains an odd number of 1s; 0 otherwise.
   Assume w=32 */
/*
Bitwise algorithms
https://www.geeksforgeeks.org/bitwise-algorithms/
 */
int odd_ones(unsigned x)
{
  //At most 12 arthmatic, logical and bitwise operations
  x ^= x >> 16;
  //printf("value of x after xor: %X\n", x);
  x ^= x >> 8;
  //printf("value of x after xor: %X\n", x);
  x ^= x >> 4;
  //printf("value of x after xor: %X\n", x);
  x ^= x >> 2;
  //printf("value of x after xor: %X\n", x);
  x ^= x >> 1;
  //printf("value of x after xor: %X\n", x);
  x &= 0x1;
  return x;
  
  
}
int even_ones(unsigned x)
{
  //At most 12 arthmatic, logical and bitwise operations
  x ^= x >> 16;
  //printf("value of x after xor: %X\n", x);
  x ^= x >> 8;
  //printf("value of x after xor: %X\n", x);
  x ^= x >> 4;
  //printf("value of x after xor: %X\n", x);
  x ^= x >> 2;
  //printf("value of x after xor: %X\n", x);
  x ^= x >> 1;
  //printf("value of x after xor: %X\n", x);
  x &= 0x1;
  return !x;
  
  
}
int odd_ones_8bits(unsigned char x)
{
  x ^= x >> 4;
  //printf("value of x after xor: %X\n", x);
  x ^= x >> 2;
  //printf("value of x after xor: %X\n", x);
  x ^= x >> 1;
  //printf("value of x after xor: %X\n", x);
  printf("x: %X\n", x);
  x &= 0x1;
  return x;

}
/*void numToBinary(unsigned n, char *binary)
{
  char local_binary[10];
  if(binary == NULL)
    return;
  do{
    if (n % 2 == 0)
      *binary = '0';
    else
      *binary = '1';
    binary++;
    n = n / 2;
  } while (n > 0);
  *binary = '\0';
  binary = strrev(binary);
}*/

int main(int argc, char *argv[])
{
  /*printf("Odd check\n");
  printf("%d\n", odd_ones(0x01010101));
  printf("%d\n", odd_ones(0x01010100));
  printf("Even check\n");
  printf("%d\n", even_ones(0x01010101));
  printf("%d\n", even_ones(0x01010100));*/
  //char binary[10];
  //numToBinary(8, binary);
  //printf("%s\n", binary);
  odd_ones_8bits(0x01); //1 -1s
  odd_ones_8bits(0x11); //2 - 1s
  odd_ones_8bits(0x49); //3 - 1s
  odd_ones_8bits(0x4B); //4 - 1s
  odd_ones_8bits(0x6B); //5 - 1s
  odd_ones_8bits(0x7B); //6 - 1s
  odd_ones_8bits(0xFB); //7 - 1s
  odd_ones_8bits(0xFF); //8 - 1s
  //printf("%s\n", "dhruv");
  //printf("%s\n", strrev("dhruv"));
  return 0;
  
}
