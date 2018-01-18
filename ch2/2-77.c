#include <stdio.h>

int main(int argc, char *argv[])
{
  /* A: 17 (0001 0001)
   * B: -7 (1111 1001)
   * C: 60 (0011 1100)
   * D: -112 (1001 0000)
   */
   int x = 10;
   int product;
   int a = 17, b = -7, c = 60, d = -112;
   //A: should be 10*17 = 170
   product = (x << 4) + x;
   printf("x * a: %d\n", x * a);
   printf("as shift opertion: %d\n", product);
   //B: should be 10*-7 = -70
   product = x - (x << 3);
   printf("x * b: %d\n", x * b);
   printf("as shift opertion: %d\n", product);
   //C: should be 10 * 60 = 600
   product = (x << 6) - (x << 2);
   printf("x * c: %d\n", x * c);
   printf("as shift opertion: %d\n", product);
   //D: should be 10 * -112 = -1120
   product = (x << 4) - (x << 7);
   printf("x * d: %d\n", x * d);
   printf("as shift opertion: %d\n", product);
   return 0;
}
