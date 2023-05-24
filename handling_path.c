#include "main.h"

/**
 * _getenv - retrieves the value of an environment variable.
 * @name: string input
 * Return: value of an environment variable
 */

char *_getenv(char *name)
{
	int i = -1;
	size_t name_len;

	if (name == NULL || *name == '\0')
		return (NULL);
	if (environ == NULL)
		return (NULL);

	name_len = _strlen(name);

	while (environ[++i])
	{
		if (!_strncmp(environ[i], name, name_len) && environ[i][name_len] == '=')
		{
			return (environ[i] + name_len + 1);
		}
	}
	return (NULL);
}

/**
 * path_handling - locate the executable file associated with a given command.
 * @data: string input
 * Return: void
 */
int path_handling(input *data)
{
	char *token, *path,
		*paths = malloc(_strlen(_getenv("PATH") ? _getenv("PATH") : "") + 1);
	size_t token_len;
	int check = -1;

	if (!_getenv("PATH"))
		goto free;
	_strcpy(paths, _getenv("PATH"));
	if (paths == NULL)
		goto free;
	token = strtok(paths, ":");
	while (token)
	{
		token_len = _strlen(token) + _strlen(data->av[0]) + 2;
		path = malloc(token_len);
		if (path == NULL)
			return (check);
		_strcpy(path, token);
		_strcat(path, "/");
		_strcat(path,  data->av[0]);
		if (access(path, F_OK) == 0)
		{
			free(data->av[0]);
			data->av[0] = _strdup(path);
			free(path);
			check = 0;
			break;
		}
		free(path);
		token = strtok(NULL, ":");
	}
free:
	free(paths);
	return (check);
}
