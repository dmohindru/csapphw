#include "csapp.h"

/* Model this program close to program on pg. 821 fig.8.44 */

char *tfgets(char *s, int size, FILE *stream)
{
    fgets(s, size, stream);
    return s;
}