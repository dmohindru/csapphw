/* A program to experiment with various option of waitpid
 * function and checking exit status of child process */
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#define MAX_SIZE 10
/* Test waitpid for following
 * 1. WNOHANG
 * 2. WUNTRACED
 * 3. WCONTINUED
 */
void print_runstatus(pid_t pid)
{
	pid_t child_pid;
	int status;
	child_pid = waitpid(pid, &status, WUNTRACED|WNOHANG);
	if (child_pid == -1)
	{
		printf("Error in waitpid\n");
		if (errno == ECHILD)
			printf("No Child to wait for\n");
	}
	if (WIFSTOPPED(status))
		printf("Process: %d is stopped\n", pid);
	else
		printf("Process: %d is running\n", pid);
}

/* this function runs waitpid on all childrens of parent process */
void run_waitpid_all()
{
	pid_t child_pid;
	int status, i = 0;
	while (waitpid(-1, &status, WUNTRACED|WNOHANG)>-1)
	{
		i++;
		if (WIFSTOPPED(status))
			printf("Process: stopped\n");
		else
			printf("Process: running\n");
	}
	printf("While loop for run for %d times\n", i);
	
}

int main(int argc, char *argv)
{
	pid_t process_id, child_id, ret_value;
	char input[MAX_SIZE];
	int option, status;
	
	/* Get pid of process */
	process_id = getpid(); 
	/* Fork a child */
	child_id = fork();
	/* if failed to create child process then exit */
	if (child_id < 0) {
		printf("Unable to create child process exit....\n");
		exit(0);
	}
	/* if in a child process wait in loop */
	if (child_id == 0)
	{
		while(1);
		exit(1);
	}
	/* Print info about parent and child */
	printf("Prarent process id: %d\n", process_id);
	printf("Child process id: %d\n", child_id);
	
	/* Get inputs in loop to test for various waitpid options */
	printf(" 1: waitpid with WNOHANG option\n");
	printf(" 2: waitpid with WUNTRACED option\n");
	printf(" 3: waitpid with WCONTINUED option\n");
	printf(" 4: waitpid with no option\n");
	printf(" 5: waitpid with WUNTRACED|WNOHANG\n");
	printf(" 6: print run status\n");
	printf(" 7: run waitpid on all childrens\n");
	printf("-1: to exit\n");
	while(1) {
		
		printf("> ");
		fgets(input, MAX_SIZE, stdin);
		if(feof(stdin))
			exit(0);
		option = atoi(input);
		switch (option)
		{
			case -1:
				printf("Exiting.....\n");
				exit(0);
			case 1:
				//printf("waitpid with WNOHANG option\n");
				printf("Before call to waitpid WNOHANG option\n");
				ret_value = waitpid(child_id, &status, WNOHANG);
				printf("After call to waitpid WNOHANG option\n");
				break;
			case 2:
				//printf("waitpid with WUNTRACED option\n");
				printf("Before call to waitpid WUNTRACED option\n");
				ret_value = waitpid(child_id, &status, WUNTRACED);
				printf("After call to waitpid WUNTRACED option\n");
				break;
			case 3:
				//printf("waitpid with WCONTINUED option\n");
				printf("Before call to waitpid WCONTINUED option\n");
				ret_value = waitpid(child_id, &status, WCONTINUED);
				printf("After call to waitpid WCONTINUED option\n");
				break;
			case 4:
				//printf("waitpid with no option\n");
				printf("Before call to waitpid no option\n");
				ret_value = waitpid(child_id, &status, 0);
				printf("After call to waitpid no option\n");
				break;
			case 5:
				//printf("waitpid with no option\n");
				printf("Before call to waitpid WUNTRACED|WNOHANG option\n");
				ret_value = waitpid(child_id, &status, WUNTRACED|WNOHANG);
				printf("After call to waitpid WUNTRACED|WNOHANG option\n");
				break;
			case 6:
				print_runstatus(child_id);
				break;
			case 7:
				run_waitpid_all();
				break;
			default:
				printf("Unknown option\n");
				break;
		};
		/* Display various status info */
		if (option == 6 || option == 7)
			continue;
		printf("ret_value = %d\n", ret_value);
		if (WIFEXITED(status))
		{
			printf("Child process terminated with exited status: %d\n", WEXITSTATUS(status));
		}
		
		if (WIFSIGNALED(status))
		{
			printf("Child process exited by signal: %d\n", WTERMSIG(status));
		}
		
		if (WIFSTOPPED(status))
		{
			printf("Child process stopped by signal: %d\n", WSTOPSIG(status));
		}
		
		if (WIFCONTINUED(status))
		{
			printf("Child process started by SIGCONT signal\n");
		}
		
		/* Display some error messages
		 * Like ECHILD, EINTR */
		
	}
}
