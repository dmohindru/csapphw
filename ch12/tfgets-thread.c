#include "csapp.h"
int time_out = -1;
struct pack
{
    char *s;
    int size;
    FILE *stream;
};
void *read_thread(void *vargp)
{
    struct pack *args = (struct pack*)(vargp);
    fgets(args->s, args->size, args->stream);
    time_out = 0;
    return NULL;

}
void *sleep_thread(void *vargp)
{
    sleep(5);
    time_out = 1;
    return NULL;
}

char *tfgets(char *s, int size, FILE *stream)
{
    pthread_t readt, sleept;
    struct pack arg_pack;
    arg_pack.s = s;
    arg_pack.size = size;
    arg_pack.stream = stream;
    /* Create read threads */
    Pthread_create(&readt, NULL, read_thread,(void *)&arg_pack);
    /* Create sleep thread */
    Pthread_create(&sleept, NULL, sleep_thread, NULL);
    
    /* Wait for either thread to finish */
    while (time_out == -1);

    if (time_out == 0)  /* Got the input in time */
    {
        Pthread_cancel(sleept);
        return arg_pack.s;
    }
    else /* Time out happened */
    {
        Pthread_cancel(readt);
        return NULL;
    }
}