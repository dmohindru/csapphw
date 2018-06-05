long A[R][S][T];

long store_ele(long i, long j, long k, long *dest)
{
  *dest = A[i][j][k];
  return sizeof(A);
}
/*
Annotation of assembly code
2. %rax = j*2 + j = 3*j
3. %rax = j + 12*j = 13*j
4. j = i
5. j = j << 6
6. i = i + j or i = i + (i << 6)
7. i = i + 13*j
8. k = k + i
9.
10. *dest = A[i][j][k];
11. return 3640;

eq 3.1 at pg 294
T D[R][C]
for D[i][j]
&D[i][j] = x_d + L(C.i + j)
*/
