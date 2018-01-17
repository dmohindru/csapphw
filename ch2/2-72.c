#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* Answer A: below code is buggy because maxbytes is signed int
 * and sizeof operator returns size_t which is unsigned. So int 
 * is implicitly casted to unsigned quantity and hence passes all test.
 * Therefore maxbytes - sizeof(val) will be a unsigned val with is always
 * 0 or greater than zero.
 */

/*void copy_int(int val, void *buff, int maxbytes)
{
  if (maxbytes - sizeof(val) >= 0)
    memcpy(buff, (void *) &val, sizeof(val));
}*/
/* Answer B: correct implementation is as below */
void copy_int(int val, void *buff, int maxbytes)
{
  if (maxbytes - (int) sizeof(val) >= 0)
    memcpy(buff, (void *) &val, sizeof(val));
}
int main(int argc, char* argv[]) 
{
  int maxbytes = sizeof(int) * 10;
  void* buf = malloc(maxbytes);
  int val;
  val = 0x12345678;
  copy_int(val, buf, maxbytes);
  printf("%X\n", *(int*)buf);
  //assert(*(int*)buf == val);
  val = 0xAABBCCDD;
  copy_int(val, buf, 0);
  printf("%X\n", *(int*)buf);
  //assert(*(int*)buf != val);
  free(buf);
  return 0;
}
