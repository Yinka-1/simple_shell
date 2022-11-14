#include <stdio.h>
#include <stdlib.h>
/**
* main - PID
*
* Return: Always 0.
*/
int main(__attribute__((unused))int ac, char **av)
{
	int index = 0;
	while(av[index])
	{
		printf("%s\n", av[index]);
		index++;
	}
	return (0);
}
