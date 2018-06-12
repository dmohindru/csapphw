typedef enum {NEG, ZERO, POS, OTHER} range_t;

//conditional jumps pg. 242 topic 3.6.3
range_t find_range(float x)
{
  __asm__(
      "vucomiss .L2(%rip), %xmm0  #compare x with zero constant\n\t"
      "jp       .L3       #NAN"
      "je       .L4       #equal to zero"
      "ja       .L5       #positive"
      "jb       .L6       #negtive"
      ".L2                #Zero constant\n\t"
      ".long 0            \n\t"
      ".L3:               #code for NAN\n\t"
      "movl $3, %eax      #move 3 as return value in %eax\n\t"
      "ret                #return\n\t"
      ".L4:               #code for zero\n\t"
      "movl $1, %eax      #move 1 as return value in %eax\n\t"
      "ret                #return\n\t"
      ".L5                #code for positive\n\t"
      "movl $2, %eax      #move 2 as return value in %eax\n\t"
      "ret                #return\n\t"
      ".L6                #code for negetive\n\t"
      "movl $0, %eax      #move 0 as return value in %eax\n\t"
      "ret                #return\n\t");
}
