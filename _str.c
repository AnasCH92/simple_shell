#include "main.h"

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

char *_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
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

	for (i = 0; s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]; i++)
	{
			i++;
	}
	return (s1[i] - s2[i]);
}

char	*_strdup(const char *s1)
{
	char	*dup;
	int		i;

	i = 0;
	while (s1[i])
		i++;
	dup = (char *)malloc(sizeof(char) * i + 1);
	i = 0;
	if (!dup)
		return (NULL);
	while (s1[i])
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}


char **_realloc(char **ptr, size_t size)
{
    int len;
    char    **save;

    len = 0;
    if (ptr == NULL)
    {
        save = malloc(sizeof(char *) * 2);
        save[0] = NULL;
        save[1] = NULL;
        return (save);
    }

    save = malloc(size);
    while(ptr[len])
    {
        save[len] = _strdup(ptr[len]);
        free(ptr[len]);
        len++;
    }
    free(ptr);
    save[len++] = NULL;
    save[len] = NULL;
    return (save);
}