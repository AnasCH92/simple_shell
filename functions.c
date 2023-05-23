#include "main.h"

/**
 * _putchar - Writes the character c to stdout
 *
 * @str: The character to print
 *
 * Return: On success 1.
*/

#include <unistd.h>

void _printf(const char *str)
{
	if (str == NULL)
	return;
	while (*str != '\0')
	{
	write(STDOUT_FILENO, str, 1);
	str++;
	}
}

/**
 * init_data - init data
 * @data: data struct input
 * @shell_name: string input
 * Return: void
 */

void init_data(input *data, const char *shell_name)
{
	data->command = NULL;
	data->av = NULL;
	data->shell_name = shell_name;
}

/**
 * start_process - start a new process
 * @data: data struct input
 * Return: void
 */

	void child_process(input *data, char **environ)
	{	
	pid_t child_pid = fork();
	int status = 0;
	
	if (child_pid == -1)
	goto free;
	if (child_pid == 0 && execve(data->av[0], data->av, environ) == -1)
		goto free;
	else if (wait(&status) == -1)
		goto free;
	return;
	free:
	perror(data->shell_name);
	free_array(data->av);
	free(data->command);
	exit(EXIT_FAILURE);
	}
/**
 * command_line - get the commend from the prompt and structure it into data struct
 * @data: data struct input
 * Return: void
 */

	void command_line(input *data)
	{
	size_t n = 0;
	ssize_t nb_of_chars;

	nb_of_chars = getline(&data->command, &n, stdin);

	if (nb_of_chars == -1)
	{
		free(data->command);
		exit(EXIT_FAILURE);
	}

	data->command[nb_of_chars - 1] = '\0';
	}

/**
 * handler_sigint - Signal handler function
 * @signal: int input
 * Return: void
 */

	void _sigint(int signal)
	{
		const char prompt[] = "\n#csisfun$ ";
		(void)signal;
		_printf(prompt);
	}

/**
 * split - split a given string by a delimiter
 * @data: data struct input
 * @delim: string input
 * Return: void
 */

	void command_spliter(input *data, const char *delim)
	{
	char *token;
		int ntoken = 0;

		data->av = malloc(2 * sizeof(char *));
		if (data->av == NULL)
		{
			free(data->command);
			perror(data->shell_name);
			exit(EXIT_FAILURE);
		}
		data->av[0] = NULL;
		data->av[1] = NULL;

		token = strtok(data->command, delim);
		while (token)
		{
			data->av = _realloc(data->av, (ntoken + 2) * sizeof(char *));
			if (data->av == NULL)
				goto free;
			data->av[ntoken] = _strdup(token);
			if (data->av[ntoken] == NULL)
				goto free;
			ntoken++;
			token = strtok(NULL, delim);
		}
		data->av[ntoken] = NULL;
		return;
		free:
		free_array(data->av);
		free(data->command);
		perror(data->shell_name);
		exit(EXIT_FAILURE);

	}
