typedef struct {
  int first;   //4 bytes
  a_struct a[CNT]; //unknown
  int last; //4 bytes
} b_struct;
typedef struct {
  long idx
  long x[]
} a_struct;

void test(long i, b_struct *bp) {
  int n = bp->first + bp->last;
  a_struct *ap = &bp->a[i];
  ap->x[ap->idx] = n;
}

void test(long i, b_struct *bp)
i in %rdi, bp in %rsi

mov 0x120(%rsi), %ecx
%ecx = %rsi + 288 (alignment of 4 or 8) 
add (%rsi), %ecx
%ecx = *bp or %ecx = b_struct->first
lea (%rdi, %rdi, 4), %rax
%rdi = 4*i + i = 5*i
lea (%rsi, %rax, 8), %rax
%rax = bp + 40*i    (size of a_struct is 40 bytes)
ap = bp + 40*i
mov 0x8(%rax), %rdx
%rdx = ap + 8 or a_struct.idx
movslq %ecx, %rcx
int to long (%rcx = %ecx) or %rcx = (long) b_struct->first
mov %rcx,0x10(%rax,%rdx,8)
(ap + idx * 8) + 16 = %rcx 
retq

mov 0x120(%rsi), %ecx
%ecx = bp->last 
add (%rsi), %ecx
%ecx = bp->first + bp->last
lea (%rdi, %rdi, 4), %rax
%rdi = 4*i + i = 5*i
lea (%rsi, %rax, 8), %rax
%rax = bp + 40*i    (size of a_struct is 40 bytes)
ap = bp + 40*i
mov 0x8(%rax), %rdx
ap.idx/ap= bp + 40*i + 8 (alignment by 8)
movslq %ecx, %rcx
%rcx = (long)bp->first + bp->last
mov %rcx,0x10(%rax,%rdx,8)
ap 
(ap + idx * 8) + 16 = %rcx 


retq

memory alignment for b_struct
0-3     : first
4-7     : padding
8-287   : a_struct[CNT]
288-291 : last
288 = CNT * 40 + 4
solving for CNT
CNT = 284 / 40 = 
