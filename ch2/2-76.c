#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

void* another_calloc(size_t nmemb, size_t size)
{
  void* mem_ptr;
  if(nmemb == 0 || size == 0)
    return NULL;
  
  size_t num_bytes = nmemb * size; // chances of overflow
  if(nmemb == num_bytes/size)
  {
    mem_ptr = malloc(num_bytes);
    memset(mem_ptr, 0, num_bytes);
    return mem_ptr;
  }
  return NULL;
}
int main(int argc, char *argv[])
{
  void *ptr = another_calloc(10, 4);
  if(ptr)
  {
    printf("another_calloc(10,4) - succedded\n");
  }
  else
  {
    printf("another_calloc(10,4) - failed\n");
  }
  ptr = another_calloc(SIZE_MAX, 4);
  if(ptr)
  {
    printf("another_calloc(SIZE_MAX,4) - succedded\n");
  }
  else
  {
    printf("another_calloc(SIZE_MAX,4) - failed\n");
  }
  return 0;
}
