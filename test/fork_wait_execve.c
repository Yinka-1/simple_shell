#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
* main - fork & wait execve
*
* Return: Always 0.
*/
int main(void)
{
	pid_t child_pid = 1;
	pid_t my_pid;
	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};
	int status, i = 0;

	my_pid = getpid();
	while (i < 5 && (child_pid != 0))
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
			return (1);
		}
		wait(&status);
		i++;
	}
	if (child_pid == 0)
	{
		printf("CHILD ID: %u\n PARENT ID: %u\n", getpid(), getppid());
	}
	else
	{
		printf("%u son is: %u\n", my_pid, child_pid);
	}
	if (execve(argv[0], argv, NULL) == -1)
	{
		perror("ERROR:");
	}
	return (0);
}
