#include <stdio.h>
#include <stdlib.h>
/**
 *main-prototype
 *Return: 0
 */
int main(void)
{
	char  *line = NULL;
	size_t len = 0;
	ssize_t nread;

	printf("$ ");
	nread = getline(&line, &len, stdin);
	printf("%s", line);
	printf("NUmber of characters: %ld\n", nread);

	free(line);

	return (0);
}
