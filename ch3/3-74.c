#include <stdio.h>
#include <assert.h>

typedef enum {NEG, ZERO, POS, OTHER} range_t;

//conditional jumps pg. 242 topic 3.6.3
range_t find_range(float x)
{
  __asm__(
      "vxorps %xmm1, %xmm1, %xmm1 #generate zero in %xmm1\n\t"
      "movq $1, %rax \n\t#Return value for equal"
      "movq $0, %r8 \n\t#Return value for negetive"
      "movq $2, %r9 \n\t#Return value for positive"
      "movq $3, %r10 \n\t#Return value for NAN"
      "vucomiss %xmm1, %xmm0  #compare x with zero constant\n\t"
      "cmovbq %r8, %rax #Negetive\n\t"
      "cmovaq %r9, %rax #positive\n\t"
      "cmovpq %r10, %rax #NAN\n\t"
      );
}

int main(int argc, char* argv[]) {
  range_t n = NEG, z = ZERO, p = POS, o = OTHER;
  assert(o == find_range(0.0/0.0));
  assert(n == find_range(-2.3));
  assert(z == find_range(0.0));
  assert(p == find_range(3.33));
  return 0;
}

