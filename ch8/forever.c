#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  int i, max;
  if (argc < 2)
  {
    printf("Usage forever num\n");
    return 0;
  }
  //printf("argv[1]: %s\n", argv[1]);
  max = atoi(argv[1]);
  for (i = 0; i < max; i++)
  {
    sleep(1);
    //printf("Hello ");
  }
  return 0;
}
