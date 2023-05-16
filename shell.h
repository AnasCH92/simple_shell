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


#endif
