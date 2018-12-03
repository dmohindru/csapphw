/* Homework Problem 8-20 */
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[], char *envp[])
{
	if(execve("/bin/ls", argv, envp))
		//fprintf("execve error %s\n", strerror(errorno));
		printf("execve function error\n");
	return 0;
}
