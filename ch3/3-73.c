#include <stdio.h>
#include <assert.h>

typedef enum {NEG, ZERO, POS, OTHER} range_t;

//conditional jumps pg. 242 topic 3.6.3
range_t find_range(float x)
{
  __asm__(
      "vxorps %xmm1, %xmm1, %xmm1 #generate zero in %xmm1\n\t"
      "vucomiss %xmm1, %xmm0  #compare x with zero constant\n\t"
      "jp       .NAN       #NAN\n\t"
      "je       .ZERO       #equal to zero"
      "ja       .POS       #positive"
      "jb       .NEG       #negtive"
      ".NAN:               #code for NAN\n\t"
      "movl $3, %eax      #move 3 as return value in %eax\n\t"
      "jmp      .DONE     #return\n\t"
      ".ZERO:               #code for zero\n\t"
      "movl $1, %eax      #move 1 as return value in %eax\n\t"
      "jmp      .DONE     #return\n\t"
      ".POS:                #code for positive\n\t"
      "movl $2, %eax      #move 2 as return value in %eax\n\t"
      "jmp      .DONE     #return\n\t"
      ".NEG:               #code for negetive\n\t"
      "movl $0, %eax      #move 0 as return value in %eax\n\t"
      "jmp      .DONE     #return\n\t"
      ".DONE:              \n\t");
}

int main(int argc, char* argv[]) {
  range_t n = NEG, z = ZERO, p = POS, o = OTHER;
  assert(o == find_range(0.0/0.0));
  assert(n == find_range(-2.3));
  assert(z == find_range(0.0));
  assert(p == find_range(3.33));
  return 0;
}
