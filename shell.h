#ifndef SHELL_H
#define SHELL_H

/********* LIBRARIES *******/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>


/********* PROTOTIPES *******/

void    prompt(char **argv, char **env);
int	_strlen(char	*str);
char	*_strcpy(char	*dest, char	*src);
char	*_strcat(char	*dest, char	*src);
int	_strcmp(char	*s1, char	*s2);
#endif
