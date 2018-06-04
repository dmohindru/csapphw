#include <stdint.h>
typedef __int128 int128_t;

void store_prod(int128_t *dest, int64_t x, int64_t y) {
  *dest = x * (int128_t) y;
}

/*
store_prod:
  # dest in %rdi, x in %rsi, y in %rdx
1   movq	%rdx, %rax    ; %rax = y
2	  cqto                ; sign extend y into octoword %rdx:%rax
3	  movq	%rsi, %rcx    ; %rcx = x
4	  sarq	$63, %rcx     ; %rcx = x >> 63
5	  imulq	%rax, %rcx    ; %rcx = y[63:0] * sign bit of x
6	  imulq	%rsi, %rdx    ; %rdx = y[127:64] * x
7	  addq	%rdx, %rcx    ; %rcx = %rdx + %rdx
8	  mulq	%rsi          ; %rax = %rax * %rsi
9	  addq	%rcx, %rdx    ; %rdx = %rdx + %rcx
10	movq	%rax, (%rdi)  ; store lower 64 bits in dest
11	movq	%rdx, 8(%rdi) ; store upper 64 bits in dest + 1
12	ret

pl = xl * yl
ph = (unsigned)xl * yl - (x_63*yl + y_63*xl) * 2^64

**********************
It was the touch one
**********************

Alogrithm work out

Line 1,2: Converts y from 64 bit to 128 bits by putting lower 
          64 bits in %rax and sign extended higher 64 bits in %rdx

Line 3,4: sets %rcx either to zero if x is +ve otherwise -1

Line 5  : multiplies y with %rcx (0 if x +ve) or (-1 if x -ve)

Line 6  : multiplies x with %rdx (0 if y +ve) or (-1 if y -ve)

Line 7  : adds the results of Line 5 and Line 6 to destination %rcx

Line 8  : unsigned multiply of x and y

Line 9  : adds the upper 8 bytes of unsigned multiply to result of line 7

Line 10 : stores lower 8 bytes to dest

Line 11 : stores upper 8 bytes to dest+1

Example using 8 bits numbers
x   = 127   (          0111 1111) (8  bits)
y   = 127   (          0111 1111) (8  bits)
x*y = 16129 (0011 1111 0000 0001) (16 bits)

line 1,2
y   = 127   (0000 0000 0111 1111) (16 bits)
%rdx = 0000 0000
%rax = 0111 1111

line 3,4
%rcx = 0000 0000

line 5
%rcx = %rcx * %rax
%rcx = 0 * 127
%rcx = 0000 0000

line 6
%rdx = %rdx * %rsi
%rdx = 0 * 127
%rdx = 0

line 7
%rcx = %rcx + %rdx
%rcx = 0 + 0
%rcx = 0

line 8
unsigned multiply
%rdx:%rax = %rsi * %rax
%rdx:%rax = 127 * 127
%rdx:%rax = 0011 1111 0000 0001
%rdx = 0011 1111
%rax = 0000 0001

line 9
%rdx = %rdx + %rcx
%rdx = 0011 1111 + 0000 0000
%rdx = 0011 1111

line 10,11
store the result

examples:
x = 127
y = -127
x_sign = 0
y_sign = -1
result1 = x * y_sign = 127 * -1 = -127
result2 = y * x_sign = -127 * 0 = 0
result3 = result1 + result2 = -127 + 0 = -127
unsigned_result = (unsigned)x * (unsigned)y = 127 * 129
unsigned_result = 16383
upper byte = 0011 1111 (63)
lower byte = 1111 1111 (255)
upper byte = 63 -127 = (1100 0000)
final result = (1100 0000 1111 1111)
127 * -127   = (1100 0000 1111 1111)
---------------------------------------------
x = 127, ux = 0*2^8 + 127 = 0 + 127 = 127
y = -127, uy = 1*2^8 - 127 = 256 - 127 = 129 
---------------------------------------------
ux*uy = 127 * 129 = 16383
---------------------------------------------
x*y = 127 * -127 = -16129
---------------------------------------------
x_7*y = 0 * -127 = 0
y_7*x = 1 * 127 = 127
2^8*(x_7*y+y_7*x) = 256*127 = 32512
---------------------------------------------
x*y +  2^8*(x_7*y+y_7*x) = -16129 + 32512 = 16383




*/
