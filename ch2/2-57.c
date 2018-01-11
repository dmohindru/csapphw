#include <stdio.h>

/*
* show-bytes.c
*/
typedef unsigned char* byte_pointer;
void show_bytes(byte_pointer start, size_t len) {
  size_t i;
    for (i = 0; i < len; i++) {
    printf(" %.2x", start[i]);
  } 
  printf("\n");
}
void show_short(short x) {
  show_bytes((byte_pointer) &x, sizeof(short));
}
void show_long(long x) {
  show_bytes((byte_pointer) &x, sizeof(long));
}
void show_double(double x) {
  show_bytes((byte_pointer) &x, sizeof(double));
}
void show_float(float x) {
  show_bytes((byte_pointer) &x, sizeof(float));
}
void test_show_bytes(int val) {
  short sval = (short) val;
  long lval = (long) val;
  double dval = (double) val;
  float fval = (float) val;
  show_short(sval);
  show_long(lval);
  show_double(dval);
  show_float(fval);
}
int main(int argc, char* argv[]) {
  int test_num = 328;
  printf("print for %d\n", test_num);
  test_show_bytes(test_num);
  test_num = 1000;
  printf("print for %d\n", test_num);
  test_show_bytes(test_num);
  test_num = 0xFFEEDDCC;
  printf("print for %d\n", test_num);
  test_show_bytes(test_num);
  test_num = 0x7FEEDDCC;
  printf("print for %d\n", test_num);
  test_show_bytes(test_num);
  test_num = 0x11223344;
  printf("print for %d\n", test_num);
  test_show_bytes(test_num);
  return 0;
}
