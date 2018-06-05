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
6. i = i + j or i = i + (i << 6) or i = i + 64*i = 65*i
7. i = 65*i + 13*j
8. k = k + 65*i + 13*j or 13*5*i + 13*j + k
9.
10. *dest = A[i][j][k];
11. return 3640;

eq 3.1 at pg 294
T D[R][C]
for D[i][j]
&D[i][j] = x_d + L(C.i + j)
*/
/*
 Answer A:
 A[R][S][T]
 &A[i][j][k]
 x_a + L(S.T.i + T.j + k)
*/
/*
 long A[R][S][T]
 Answer B:
 Comparing equation
 65*i + 13*j or 13*5*i + 13*j + k
 x_a + L(S.T.i + T.j + k)
 R: 3640/(5*13*8) = 7
 S: 5
 T: 13
*/
