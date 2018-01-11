#include <stdio.h>

/*
* show-bytes.c
*/
typedef unsigned char* byte_pointer;
int is_little_endian(int test) {
  byte_pointer test_byte_ptr = (byte_pointer) &test;
  if(test_byte_ptr[0] == 0xDE)
    return 1;
  else
    return 0;
    
}
int main(int argc, char* argv[]) {
  int test_val = 0xFEDE;
  if(is_little_endian(test_val))
    printf("Its a little endian machine\n");
  else
    printf("Its a big endian machine\n");
}
