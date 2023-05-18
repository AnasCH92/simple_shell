#include "shell.c"

/**
 * _strlen - returns the length of a string.
 *
 * @str: pointer to a string.
 *
 * Return: string length.
 */

int	_strlen(char	*str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

/**
 * _strcpy - copy string from source into destination string.
 *
 * @dest: pointer to destionation string.
 * @src: pointer to src string.
 *
 * @Return: destination string.
 */

char	*_strcpy(char	*dest, char	*src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strcat - appends src to dest.
 *
 * @dest: pointer to destination  string.
 * @src: pointer to src string.
 *
 * Return: destination string.
 */

char	*_strcat(char	*dest, char	*src)
{
	int i, j;

	i = _strlen(dest);
	j = 0;
	while (src[j] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

/**
 * _strcmp - compares two strings.
 *
 * @s1: pointer to string.
 * @s2: pointer to string.
 *
 * Return: 0 or s1[i] - s2[i].
 */

int	_strcmp(char	*s1, char	*s2)
{
	int i;

	for (i = 0; s1[i] != '\0' || s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
			i++;
	}
	return (0);
}
