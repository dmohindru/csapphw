long sum_col(long n, long A[NR(n)][NC(n)], long j) {
  long i;
  long result = 0;
  for (i = 0; i < NR(n); i++)
    result += A[i][j];
  return result;
}
/* Assembly annotation
n in %rdi, A in %rsi, j in %rdx
2.  %r8 = 4*n + 1 <-- NC
3.  %rax = 2*n + n = 3*n
4.  %rdi = 3*n or n = 3*n <-- NR
5.  test %rax for zero
6.  if <= jump to end of loop
7.  %r8 = (4*n + 1) << 3 = (4*n + 1) * 8
8.  %rcx = j*8 + A
9.  result = 0
10. j = 0
11. .L3
12. result = A[i][j]
13. j = j + 1
14. %rcx = %rcx + (4*n + 1) * 8
15. %rdx - %rdi
16. jump if not equal to zero

NR = 3*n
NC = 4*n + 1

*/
