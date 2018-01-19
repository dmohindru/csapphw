#include <stdio.h>

int main(int argc, char *argv[])
{
  //A 1^(w-k)0^k
  int k = 16;
  int x = -1 << k;
  printf("%X\n", x);
  //B 0^(w-k-j)1^(k)0^(j)
  k = 8;
  int j = 8;
  x = (~(-1 << k)) << j;
  printf("%X\n", x);
  return 0;
}
