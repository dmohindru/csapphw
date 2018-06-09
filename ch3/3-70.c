union ele {
  struct {
    long *p;
    long y;
  } e1;
  struct {
    long x;
    union ele *next;
  } e2;
};
void proc (union ele *up) {
    up->e2.x   = *(*(up->e2.next).e1.p) - *(up->e2.next).e1.y ;
}
/*Answers A
 e1.p = 0
 e1.y = 8
 e2.x = 0
 e2.next = 8
 
 Answer B
 16 bytes


*/
void proc (union ele *up)
up in %rdi
proc:
  movq 8(%rdi), %rax ; up->e2.next
  movq (%rax), %rdx  ; *(up->e2.next)
  movq (%rdx), %rdx  ; *(*(up->e2.next).e1.p)
  subq 8(%rax), %rdx ; *(*(up->e2.next).e1.p) - *(up->e2.next).e1.y
  movq %rdx, (%rdi)  ; (%rdi) = up->e2.x
  ret
