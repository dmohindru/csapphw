/* Bubble sort: Pointer version */
/* gcc command line option to compile to 
 * unoptimized assembly code
 * gcc -Og -s file.c
 */

void bubble_p(long *data, long count) {
  long i, last;
  for (last = count-1; last > 0; last --) {
    for (i = 0; i < last; i++)
      if (*(data+i+1) < *(data+i)) {
        /* Swap adjacent elements */
        long t = *(data+i+1);
        *(data+i+1) = *(data+i);
        *(data+i) = t;
      }
  }
}
