/* Homework problem 12-34
   implements parallel version of matrix multiplication
   and compares with sequential version
*/
#include "csapp.h"

#define M           2048
#define NTHREAD     4

int martix_a[M][M];             /* Matrix A for multipulication */
int martix_b[M][M];             /* Matrix B for multipulication */
int matrix_mul_seq[M][M];       /* Multiplicaiton result of sequential process */
int martix_mul_par[M][M];       /* Multiplicaiton result of parallel process */

void init_matrix();
void mult_seq();
void mult_parallel();
void display_matrix();
int compare_result();
void *mult_thread(void *vargp);

int main(int argc, char *argv[])
{
    struct timeval start, end;
    long sec, msec;
    init_matrix();
    /*if (compare_result())
        printf("Result: pass\n");
    else
        printf("Result: fail\n");
    */

    /*if (compare_result())
        printf("Result: pass\n");
    else
        printf("Result: fail\n");
    */

    //display_matrix();
    gettimeofday(&start, NULL);
    mult_seq();
    gettimeofday(&end, NULL);
    sec = (end.tv_sec - start.tv_sec);
    msec = ((sec * 1000000) + end.tv_usec) - start.tv_usec;
    printf("Time spent in sequential operation: %ld.%ld secs\n", sec, msec);
    gettimeofday(&start, NULL);
    mult_parallel();
    gettimeofday(&end, NULL);
    if (!compare_result())
        printf("Parallel multiplication failed\n");
    sec = (end.tv_sec - start.tv_sec);
    msec = ((sec * 1000000) + end.tv_usec) - start.tv_usec;
    printf("Time spent in parallel operation: %ld.%ld secs\n", sec, msec);

    return 0;
}

/* Function for initalizing matrix array */
void init_matrix()
{
    int i, j, max_num = 1000;

    /* Initalize matrix A */
    for (i = 0; i < M; i++) 
        for (j = 0; j < M; j++)
            martix_a[i][j] = rand() % max_num;
    
    /* Initalize matrix B */
    for (i = 0; i < M; i++) 
        for (j = 0; j < M; j++)
            martix_b[i][j] = rand() % max_num;
    
    /* Initalize matrix for sequential and parallel result */
    for (i = 0; i < M; i++) 
        for (j = 0; j < M; j++) {
            matrix_mul_seq[i][j] = 0;
            martix_mul_par[i][j] = 0;
        }
}

/* Function for sequential matrix multiplication */
void mult_seq()
{
    int i, j, k, sum = 0;
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < M; j++)
        {
            for (k = 0; k < M; k++) 
            {
                sum += martix_a[i][k] * martix_b[k][j];
            }
            matrix_mul_seq[i][j] = sum;
            sum = 0;
        }
    }
}

/* Function for parallel matrix multiplication */
void mult_parallel()
{
    pthread_t *tid;
    long i;
    tid = Malloc(NTHREAD * sizeof(pthread_t));

    /* Create thread for multiplication */
    for (i = 0; i < NTHREAD; i++)
        Pthread_create(tid+i, NULL, mult_thread, (void *)i);

    /* Wait for threads to finish */
    for (i = 0; i < NTHREAD; i++)
        Pthread_join(tid[i], NULL);

    Free(tid);
}

void *mult_thread(void *vargp)
{
    long row, index;
    int sum, i, j, k, start, end;
    index = (long)vargp;
    row = M / NTHREAD;
    sum = 0;
    start = index * row;
    end = (index * row) + row;

    //printf("I am thread with i=%ld\n", index);

    for (i = start; i < end ; i++)
    {
        for (j = 0; j < M; j++)
        {
            for (k = 0; k < M; k++) 
            {
                sum += martix_a[i][k] * martix_b[k][j];
            }
            martix_mul_par[i][j] = sum;
            sum = 0;
        }
    }
    return NULL;
}

/* Function to display matrix */
void display_matrix()
{
    int i, j;
    printf("\n\t\t----------Matrix A----------\n");
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < M; j++)
            printf("\t%d", martix_a[i][j]);
        printf("\n");
    }

    printf("\n\t\t----------Matrix B----------\n");
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < M; j++)
            printf("\t%d", martix_b[i][j]);
        printf("\n");
    }

    printf("\n\t\t----------Matrix sequential----------\n");
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < M; j++)
            printf("\t%d", matrix_mul_seq[i][j]);
        printf("\n");
    }

    printf("\n\t\t----------Matrix parallel----------\n");
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < M; j++)
            printf("\t%d", martix_mul_par[i][j]);
        printf("\n");
    }
}

/* Function to test matrix sequential and parallel result */
int compare_result()
{
    int i, j;
    for (i = 0; i < M; i++)
        for (j = 0; j < M; j++)
            if (matrix_mul_seq[i][j] != martix_mul_par[i][j])
                return 0;
    
    return 1;
}
