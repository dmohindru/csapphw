typedef struct {
  long a[2]; //16 bytes
  long *p;   //8 bytes
} strA;      //Total: 24 bytes

typedef struct {
  long u[2];  //16 bytes
  long q;     //8 bytes
} strB;       //Total: 24 bytes

strB process(strA s) {
  strB r;
  r.u[0] = s.a[1];
  r.u[1] = s.a[0];
  r.q = *s.p;
  return r;
}

long eval(long x, long y, long z) {
  strA s;
  s.a[0] = x;
  s.a[1] = y;
  s.p = &z;
  strB r = process(s);
  return r.u[0] + r.u[1] + r.q;
}
/* Assembly code
strB process(strA s)
process:
	movq	%rdi, %rax      ; move &s to %rax
	movq	24(%rsp), %rdx  ;  
	movq	(%rdx), %rdx    ; 
	movq	16(%rsp), %rcx  ; 
	movq	%rcx, (%rdi)    ; r.u[0] = s.a[1]
	movq	8(%rsp), %rcx   ; r.u[1] = s.a[0]
	movq	%rcx, 8(%rdi)   ; r.u[1] = s.a[0]
	movq	%rdx, 16(%rdi)  ; r.q = *s.p
	ret

long eval(long x, long y, long z)
x in %rdi, y in %rsi, z in %rdx
eval:
	subq	$104, %rsp        ; allocate 104 bytes on stack
	movq	%rdx, 24(%rsp)    ; %rsp + 24 = z
	leaq	24(%rsp), %rax    ; comute &z and store in %rax
	movq	%rdi, (%rsp)      ; s.a[0] = x;
	movq	%rsi, 8(%rsp)     ; s.a[1] = y;
	movq	%rax, 16(%rsp)    ; s.p = &z;
	leaq	64(%rsp), %rdi    ; compute &(strB r)
	call	process           ; call process
	movq	72(%rsp), %rax    ; r.u[1]
	addq	64(%rsp), %rax    ; r.u[1] + r.u[0]
	addq	80(%rsp), %rax    ; r.u[1] + r.u[0] + r.q
	addq	$104, %rsp        ; deallocate 104 bytes from stack
	ret
*/
