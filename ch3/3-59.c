#include <stdint.h>
typedef __int128 int128_t;

void store_prod(int128_t *dest, int64_t x, int64_t y) {
  *dest = x * (int128_t) y;
}

/*
store_prod:
  # dest in %rdi, x in %rsi, y in %rdx
  movq	%rdx, %rax    ; %rax = y
	cqto                ; sign extend y into octoword %rdx:%rax
	movq	%rsi, %rcx    ; %rcx = x
	sarq	$63, %rcx     ; %rcx = x >> 63
	imulq	%rax, %rcx    ; 
	imulq	%rsi, %rdx
	addq	%rdx, %rcx
	mulq	%rsi
	addq	%rcx, %rdx
	movq	%rax, (%rdi)
	movq	%rdx, 8(%rdi)
	ret


*/
