#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>

extern char **environ;

typedef struct input
{
	char **av;
	char *command;
	const char *shell_name;
} input;

/**
 * struct builtin - holds the main data.
 * @cmd: built in cmd
 * @f: function of builtin cmd
 */
typedef struct builtin
{
	const char *command;
	void (*f)(input *data);
} builtin;


int	_putchar(char c);
void _printf(const char *str);
void init_data(input *data, const char *shell_name);
void command_line(input *d);
void command_spliter(input *data, const char *delim);
void child_process(input *data, char **environ);
int exec_builtin(input *data);
void builtin_exit(input *data);
void builtin_env(input *data);
void _sigint(int signal);
void free_array(char **array);
char **_realloc(char **ptr, size_t size);
void    command_path(input *data);
int	_strlen(char	*str);
char *get_env(char *env_var);
int _which(input *data);
char	*_strdup(const char *s1);
char	*_strcat(char	*dest, char	*src);
char	*_strcpy(char	*dest, char	*src);
int _atoi(char *s);
int	_strcmp(char	*s1, char	*s2);
int	_strncmp(char *s1, char *s2, unsigned int n);

#endif
