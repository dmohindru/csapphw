#include <sys/mman.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
    char *bufp;
    int fd;
    struct stat stat;
    /* Open file for writing */
    //fd = fopen("hello.txt", "+r");
    fd = open("hello.txt", O_RDWR);
    if (fd < 0) {
        printf("Error in opening file\n");
        return;
    }
    /* Get file stats */
    fstat(fd, &stat);

    /* mmap a file */
    bufp = mmap(0, stat.st_size,PROT_WRITE,MAP_SHARED, fd, 0);
    if (bufp == MAP_FAILED) {
        printf("mmap function failed\n");
        return 0;
    }
    /* Access file as array of chars */
    bufp[0] = 'J';

    /* unmap a file */
    munmap(bufp, stat.st_size);
    return 0;
}
