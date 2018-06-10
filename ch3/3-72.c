#include <alloca.h>

long aframe(long n, long idx, long *q) {
  long i;
  long **p = alloca(n * sizeof(long *));
  p[0] = &i;
  for (i = 1; i < n; i++)
    p[i] = q;
  return *p[idx];
}

//Assembly code
long aframe(long n, long idx, long *q)
n in %rdi, idx in %rsi, q in %rdx
1. aframe:
2.  pushq   %rbp
3.  movq    %rsp, %rbp
4.  subq    $16, %rsp           ;Allocate space for i (%rsp = s1)
5.  leaq    30(,%rdi,8), %rax
6.  andq    $-16, %rax
7.  subq    %rax, %rsp          ;Allocate space for array p (%rsp = s2)
8.  leaq    15(%rsp), %r8
9.  andq    $-16, %r8           ;Set %r8 to &p[0]

Answers A:
line 5: %rax = (n * 8) + 30
line 6: %rax = %rax & -16 (convert %rax into multiple of 16)
eg.
n = 0, %rax = 0 * 8 + 30 = 30
%rax = %rax & -16 = 16
%rsp = %rsp - 16 (Allocate 16 bytes on stack) 
n = 1, %rax = 1 * 8 + 30 = 38
%rax = %rax & -16 = 32    (18 + 24)
%rsp = %rsp - 32 (Allocate 32 bytes on stack)
n = 2, %rax = 2 * 8 + 30 = 46
%rax = %rax & -16 = 32 (16 + 16)
%rsp = %rsp - 48 (Allocate 48 bytes on stack)
n = 3, %rax = 3 * 8 + 30 = 54
%rax = %rax & -16 = 48 (24 + 24)
%rsp = %rsp - 48 (Allocate 48 bytes on stack)
n = 4, %rax = 4 * 8 + 30 = 62
%rax = %rax & - 16 = 48 (32 +16) 
%rsp = %rsp - 64 (Allocate 64 bytes on stack) 
