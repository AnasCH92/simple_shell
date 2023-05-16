#include "shell.h"



void	prompt(char **argv, char **env)
{
	char *command = NULL;/*stores the adress of the buffer*/
	size_t n = 0;/*to store the allocated size in bytes*/
	int i, j, status;
	ssize_t number_of_chars;/*to store the number of chars read from getline*/
	char *buffer[] = {NULL, NULL};
	pid_t child_pid;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("cisfun$ ");

		number_of_chars = getline(&command, &n, stdin);
		if (number_of_chars == -1)
		{
			free(command);
			exit(EXIT_FAILURE);
		}
		i = 0;
		while (command[i])
		{
			if (command[i] == '\n')
				command[i] = 0;
			i++;
		}
		j = 0;
		buffer[j] = strtok(command, " \t\n");
		while (buffer[j])
			buffer[++j] = strtok(NULL, " \t\n");
		child_pid =fork();
		if (child_pid == -1)
		{
			free(command);
			exit(EXIT_FAILURE);
		}
		if (child_pid == 0)
		{
			if (execve(buffer[0], buffer, env) == -1)
				printf("%s: No such file or directory\n", argv[0]);
			exit(EXIT_FAILURE);
		}
		else
			wait(&status);
		free(command);
	}
}
