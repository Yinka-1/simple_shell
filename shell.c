#include "shell.h"

/**
* main - simple shell
*
* Return: Always 0.
*/

int main(void)
{
	pid_t child_pid;
	int status, length;
	char **argv;
	char *line;

	line = NULL;
	while (1)
	{
		printf("#cisfun$ ");
		line = _getline(stdin);
		if (line == NULL)
			return (0);

		length = _strlen(line);
		line[length - 1] = '\0';
		argv = _strtok(line);
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error child");
			return (1);
		}
		if (child_pid == 0)
		{
			status = execve(argv[0], argv, NULL);
			if (status == -1)
			{
				perror("Error");
				return (1);
			}
		}
		else
		{
			wait(&status);
		}
	}
	free(argv);
	free(line);
	return (0);
}
