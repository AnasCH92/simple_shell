#ifndef MAIN_H
#define MAIN_h

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



void _printf(const char *str);
void command_line(input *d);
void init_data(input *data, const char *shell_name);
void command_spliter(input *data, const char *delim);
void free_array(char **array);
void child_process(input *data);
int exec_builtin(input *data);
void builtin_exit(input *data);
void builtin_env(input *data);
void _sigint(int signal);
char **_realloc(char **ptr, size_t size);
char	*_strdup(const char *s1);
void    command_path(input *data);
int	_strlen(char	*str);
char	*_strcpy(char	*dest, char	*src);
char	*_strcat(char	*dest, char	*src);
int	_strcmp(char	*s1, char	*s2);
char *get_env(char *env_var);


#endif