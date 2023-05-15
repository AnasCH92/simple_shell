#include "shell.h"



void	prompt(char **argv, char **env)
{
	char *command = NULL;/*stores the adress of the buffer*/
	size_t n = 0;/*to store the allocated size in bytes*/
	int i, status;
	ssize_t number_of_chars;/*to store the number of chars read from getline*/
	char *av[] = {NULL, NULL};
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
		av[0] = command;
		child_pid =fork();
		if (child_pid == -1)
		{
			free(command);
			exit(EXIT_FAILURE);
		}
		if (child_pid == 0)
		{
			if (execve(av[0], av, env) == -1)
				printf("%s: No such file or directory\n", argv[0]);
			exit(EXIT_FAILURE);
		}
		else
			wait(&status);
	}
}
