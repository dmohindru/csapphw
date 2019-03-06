#include "csapp.h"

/* Model this program close to program on pg. 821 fig.8.44 */
sigjmp_buf buf;

void handler(int sig)
{
    siglongjmp(buf, 1);
}
char *tfgets(char *s, int size, FILE *stream)
{
    if (Fork() == 0)
    {
        sleep(5);
        exit(0);
    }
    if (!sigsetjmp(buf, 1))
    {
        Signal(SIGCHLD, handler);
        fgets(s, size, stream);
        return s;
    }
    else
    {
        return NULL;
    }
}