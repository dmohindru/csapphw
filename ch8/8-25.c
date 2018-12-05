/* Home work problem 8-25 */
#include <stdio.h>
#include <string.h>
//#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <setjmp.h>
#define BUFF_SIZE 20

sigjmp_buf buf;

void alarm_handler(int sig)
{
	siglongjmp(buf, 1);
}
char *tfgets(char *s, int size, FILE *stream)
{
	/* Install alarm handler */
	if (!sigsetjmp(buf, 1)) {
		if(signal(SIGALRM, alarm_handler) == SIG_ERR)
			printf("set alarm handler error\n");
		alarm(5);
		return fgets(s, BUFF_SIZE, stream);
	}
	else
	{
		return NULL;
	}
}

int main(int argc, char *argv[])
{
	char input_str[BUFF_SIZE];
	char *input;
	printf("Enter some text: ");
	input = tfgets(input_str, BUFF_SIZE, stdin);
	if(input != NULL)
	{
		printf("Entered string: %s", input);
	}
	else
	{
		printf("\nNothing entered\n");
	}
	
	return 0;
}
