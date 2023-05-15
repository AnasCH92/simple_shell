#include "shell.h"



/**
 * main - Entry point.
 *
 * @argc: Argument counter.
 * @argv: Argument vector.
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE.
 */

int main(int argc, char **argv, char **env)
{
	if (argc == 1)
	{
		prompt(argv, env);
	}
	return (EXIT_SUCCESS);
}
