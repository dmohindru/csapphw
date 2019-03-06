#include "csapp.h"


char *tfgets(char *s, int size, FILE *stream)
{
    fd_set rfds;
    struct  timeval tv;
    int retval;
    FD_ZERO(&rfds);
    FD_SET(stream->_fileno, &rfds);
    /* Wait up to five seconds. */
    tv.tv_sec = 5;
    tv.tv_usec = 0;
    retval = select(1, &rfds, NULL, NULL, &tv);

    if (retval == -1)
        perror("select()");
    else if (FD_ISSET(stream->_fileno, &rfds))
    {
        fgets(s, size, stream);
        return s;
    }
    else
    {
        return NULL;
    }
}