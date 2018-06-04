/* Assembly code
long loop(long x, int n)
x in %rdi, n in %esi

1. loop:
2.   movl     %esi, %ecx
3.   movl     $1, %edx    ; mask = 1
4.   movl     $0, %eax    ; result = 0
5.   jmp      .L2
6. .L3
7.   movq     %rdi, %r8   ; r8 = x
8.   andq     %rdx, %r8   ; r8 = x & mask
9.   orq      %r8, %rax   ; result |= x & mask
10.  salq     %cl, %rdx   ; update of mask = mask << (char) n
11. .L2
12. testq     %rdx, %rdx
13. jne       .L3
14. rep; ret

*/
// Answer E
long loop(long x, long n)
{
  long result =  0  ;
  long mask;
  for (mask = 1; mask !=0; mask = mask << n) {
    result |= (x & mask)  ;
  }
  return result;
}

/*
Answer A
x       %rdi
n       %esi
result  %rax
mask    %rdx
*/

/*
Answer B
result = 0
mask   = 1

*/

/*
Answer C
mask != 0
*/

/*
Answer D
result |= (x & mask)  ;
*/

