#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER 1024

char *_getline(FILE *file);
char **_strtok(char *str);
int _strlen(char *s);

#endif
