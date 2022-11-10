#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>


int hsh_launch(char **args);
void hsh_loop(void);
char *hsh_read_line(void);
char **hsh_split_line(char *line);
int hsh_launch(char **args);
int hsh_execute(char **args);

/**
* main - simple shell
*
* Return: Always 0.
*/

void hsh_loop(void)
{
	char *line;
	char **args;
	int status;

	do {
		printf("#cisfun$ ");
		line = hsh_read_line();
		args = hsh_split_line(line);
		status = hsh_execute(args);

		free(line);
		free(args);
	} while (status);
}

char *hsh_read_line(void)
{
	char *buffer = malloc(1024);
	size_t len = 1024;

	while (1)
	{
		getline(&buffer, &len, stdin);
	}

	return (buffer);
}

char **hsh_split_line(char *line)
{
	char **tokens = malloc(64 * sizeof(char *));
	char *token;
	int i = 0;

	token = strtok(line, " ");
	while (token)
	{
		tokens[i] = token;
		i++;
	}

	return (tokens);
}

int hsh_launch(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			perror("lsh");
		}
		exit(EXIT_FAILURE);
	}

	if (pid < 0)
	{
		perror("lsh");
	}

	do {
		waitpid(pid, &status, WUNTRACED);
	} while (!WIFEXITED(status) && !WIFSIGNALED(status));

	return (1);
}


int hsh_execute(char **args)
{

	if (args[0] == NULL)
	{
		return (1);
	}

	return (hsh_launch(args));
}


int main(int argc, char *argv[])
{
	hsh_loop();

	return (0);
}
