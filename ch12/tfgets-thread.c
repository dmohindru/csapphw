#include "csapp.h"


char *tfgets(char *s, int size, FILE *stream)
{
    fgets(s, size, stream);
    return s;
}