/* $begin select */
#include "csapp.h"
void echo(int connfd);
int echo_line(int connfd);
void command(void);

int main(int argc, char **argv) 
{
    int listenfd, connfd, n;
    socklen_t clientlen;
    struct sockaddr_storage clientaddr;
    fd_set read_set, ready_set;

    if (argc != 2) {
	    fprintf(stderr, "usage: %s <port>\n", argv[0]);
	    exit(0);
    }
    listenfd = Open_listenfd(argv[1]);  //line:conc:select:openlistenfd
    printf("listenfd: %d\n", listenfd);
    FD_ZERO(&read_set);              /* Clear read set */ //line:conc:select:clearreadset
    FD_SET(STDIN_FILENO, &read_set); /* Add stdin to read set */ //line:conc:select:addstdin
    FD_SET(listenfd, &read_set);     /* Add listenfd to read set */ //line:conc:select:addlistenfd

    n = listenfd + 1; /* Max n for select */
    while (1) {
	    ready_set = read_set;
	    Select(n, &ready_set, NULL, NULL, NULL); //line:conc:select:select
	    if (FD_ISSET(STDIN_FILENO, &ready_set)) //line:conc:select:stdinready
	        command(); /* Read command line from stdin */
	    if (FD_ISSET(listenfd, &ready_set)) { //line:conc:select:listenfdready
            clientlen = sizeof(struct sockaddr_storage); 
	        connfd = Accept(listenfd, (SA *)&clientaddr, &clientlen);
            printf("connfd: %d\n", connfd);
            // listen to accepted io ports
            if (connfd+1 > FD_SETSIZE) {
                fprintf(stderr, "too many clients\n");
                Close(connfd);
            }
            n = n > connfd+1 ? n : connfd+1;
            FD_SET(connfd, &read_set);
        }
        int fd;
        for (fd = listenfd+1; fd < n; fd++)
            if (FD_ISSET(fd, &ready_set))
                
                if (echo_line(fd) == -1) {
                    printf("Terminated on connectfd: %d\n", fd);
                    Close(fd);
                    FD_CLR(fd, &read_set);
                }
    

	}
}

void command(void) {
    char buf[MAXLINE];
    if (!Fgets(buf, MAXLINE, stdin))
	exit(0); /* EOF */
    printf("%s", buf); /* Process the input command */
}
/* $end select */
void echo(int connfd) 
{
    int n; 
    char buf[MAXLINE]; 
    rio_t rio;

    Rio_readinitb(&rio, connfd);
    while((n = Rio_readlineb(&rio, buf, MAXLINE)) != 0) {
	printf("server received %d bytes\n", n);
	Rio_writen(connfd, buf, n);
    }
}
/* $end echo */

int echo_line(int connfd) 
{
    int n; 
    char buf[1]; 

    while ((n = Rio_readn(connfd, buf, 1)) > 0) {
        Rio_writen(connfd, buf, n);
        if (buf[0] = '\n')
            return 0;
    }
    return -1;
}
/* $end echo */
