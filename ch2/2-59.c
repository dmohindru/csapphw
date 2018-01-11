#include <stdio.h>

int main(int argc, char *argv[])
{
  int x = 0x89ABCDEF;
  int y = 0x76543210;
  //should yield 0x765432EF
  //int ans = (y & 0xFFFFFF00) | (x & 0x000000FF);
  int ans = (y & ~0xFF) | (x & 0xFF);
  printf("%X\n", ans);
}
