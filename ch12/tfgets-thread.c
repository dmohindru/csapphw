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

}
void *sleep_thread(void *vargp);
{

}

char *tfgets(char *s, int size, FILE *stream)
{
    fgets(s, size, stream);
    return s;
}