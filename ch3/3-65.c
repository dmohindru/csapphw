void transpost(long A[M][M]) {
  long i, j;
  for (i = 0; i < M; i++)
    for (j = 0; j < M; j++) {
      long t = A[i][j];
      A[i][j] = A[j][i];
      A[j][i] = t;
    }
}
/*
Ans A: %rdx (instuction 2)

Ans B: %rax (instruction 3)

Ans C: M = 120/8 = 15

*/
