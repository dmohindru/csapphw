/* 
 * hello.c - Pthreads "hello, world" program 
 * home work solution for problem 12-16
 */
/* $begin hello */
#include "csapp.h"
void *thread(void *vargp);                    //line:conc:hello:prototype

int main(int argc, char *argv[])                                    //line:conc:hello:main
{
    int n, i;
    pthread_t *tid;
    if (argc != 2)
    {
        fprintf(stderr, "usage: %s <num_threads>\n", argv[0]);
        exit(0);
    }
    n = atoi(argv[1]);
    /* Allocate array of size n of type pthread_t */
    tid = Malloc(sizeof(pthread_t) * n);
    //printf("Creating num of threads: %d\n", n);

    /* Create peer threads */
    for (i = 0; i < n; i++)
        Pthread_create(tid+i, NULL, thread, NULL);    
                                //line:conc:hello:tid
    
    /* Wait for peer threads to finish */
    for (i = 0; i < n; i++)
        Pthread_join(tid[i], NULL);                  //line:conc:hello:join
    Free(tid);
    exit(0);                                  //line:conc:hello:exit
}

void *thread(void *vargp) /* thread routine */  //line:conc:hello:beginthread
{
    printf("Hello, world!\n");                 
    return NULL;                               //line:conc:hello:return
}                                              //line:conc:hello:endthread
/* $end hello */
