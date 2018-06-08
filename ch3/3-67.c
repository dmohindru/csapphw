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
	movq	%rdi, %rax      ; move &r to %rax
	movq	24(%rsp), %rdx  ; %rdx = s.p
	movq	(%rdx), %rdx    ; %rdx = *s.p
	movq	16(%rsp), %rcx  ; %rcx = s.a[1]
	movq	%rcx, (%rdi)    ; r.u[0] = s.a[1]
	movq	8(%rsp), %rcx   ; %rcx = s.a[0]
	movq	%rcx, 8(%rdi)   ; r.u[1] = s.a[0]
	movq	%rdx, 16(%rdi)  ; r.q = *s.p
	ret

long eval(long x, long y, long z)
x in %rdi, y in %rsi, z in %rdx
eval:
	subq	$104, %rsp        ; allocate 104 bytes on stack
	movq	%rdx, 24(%rsp)    ; %rsp + 24 = z
	leaq	24(%rsp), %rax    ; comute &z and store in %rax
	movq	%rdi, (%rsp)      ; save x at %rsp or s.a[0] = x
	movq	%rsi, 8(%rsp)     ; save y at %rsp + 8 or s.a[1] = y
	movq	%rax, 16(%rsp)    ; save &x at %rsp + 16 or s.p = &z
	leaq	64(%rsp), %rdi    ; compute %rsp+64 address and pass as argument
	call	process           ; call process
	movq	72(%rsp), %rax    ; r.u[1]
	addq	64(%rsp), %rax    ; r.u[1] + r.u[0]
	addq	80(%rsp), %rax    ; r.u[1] + r.u[0] + r.q
	addq	$104, %rsp        ; deallocate 104 bytes from stack
	ret
*/
/*
Answer A:
Address     Content      Description
104-96
95-88
87-80        r.q
79-72        r.u[1]
71-64        r.u[0]         
63-56        
55-48        
47-40
39-32
31-24         z
23-16         &z           s.p
15-8          y            s.a[1]
7-0           x            %rsp ; s.a[0]

*/
/*
Answer B: Address of structure strB r which is %rsp + 64
*/
/*
Answer C:
s.a[0] as %rsp + 8
s.a[1] as %rsp + 16
s.p    as %rsp + 24
Address     Content      Description
104-96
95-88
87-80
79-72
71-64                     strB r
63-56
55-48
47-40
39-32
31-24         z
23-16         &z           s.p
15-8          y            s.a[1]
7-0           x            s.a[0]
-1-(-8)      ret adds      %rsp
-9-(-16)
*/
/*
Answer D:
r.u[0] as %rdi
r.u[0] as %rdi + 8
r.q as %rdi + 16
*/
/*
Answer E:
Address     Content      Description
104-96
95-88
87-80        r.q
79-72        r.u[1]
71-64        r.u[0]         
63-56        
55-48        
47-40
39-32
31-24         z
23-16         &z           s.p
15-8          y            s.a[1]
7-0           x            %rsp ; s.a[0]

*/
/*
Answer F: structure value are passed as pointer and returned as pointer in function calls
*/
