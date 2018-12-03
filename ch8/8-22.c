/* Homework Problem 8-22 */
//#include <stdio.h>
//#include <unistd.h>
#include "csapp.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>



int mysystem(char *command)
{
	pid_t pid;
	int status;
	
	//if ((pid = Fork()) == 0) /* For child process */
	if ((pid = fork()) == 0) /* For child process */
	{
		char *argv[4] = {"", "-c", command, NULL};
		execve("/bin/sh", argv, environ);
	}
	
	/* Print child process id so that we can kill it */
	printf("Child process pid: %d\n", pid);
	
	//if (Waitpid(pid, &status, 0) > 0) 
	if (waitpid(pid, &status, 0) > 0) 
	{
		/* Exited normally */
		if (WIFEXITED(status))
		{
			return WEXITSTATUS(status);
		}
		
		/* Exited by signal */
		if(WIFSIGNALED(status))
		{
			return WTERMSIG(status);
		}
	}
}
int main()
{
	return 0;
}
