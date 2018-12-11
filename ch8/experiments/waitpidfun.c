/* A program to experiment with various option of waitpid
 * function and checking exit status of child process */
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#define MAX_SIZE 10
/* Test waitpid for following
 * 1. WNOHANG
 * 2. WUNTRACED
 * 3. WCONTINUED
 */

int main(int argc, char *argv)
{
	pid_t process_id, child_id;
	char input[MAX_SIZE];
	int option;
	
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
	printf("-1: to exit\n");
	while(1) {
		
		printf(">");
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
				printf("waitpid with WNOHANG option\n");
				break;
			case 2:
				printf("waitpid with WUNTRACED option\n");
				break;
			case 3:
				printf("waitpid with WCONTINUED option\n");
				break;
			case 4:
				printf("waitpid with no option\n");
				break;
			default:
				printf("Unknown option\n");
				break;
		};
	}
}
