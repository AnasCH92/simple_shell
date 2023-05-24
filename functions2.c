#include "main.h"

/**
 *  _white_spaces - remove ' ' and '\t' from command.
 *  @s: iput string.
 *  Return: void.
 */

void _white_spaces(char *s)
{
	int i = 0, j = 0;
	int len = _strlen(s);

	while (i < len && (s[i] == ' ' || s[i] == '\t'))
		i++;

	while (i < len)
	{
		s[j] = s[i];
		i++;
		j++;
	}
	s[j] = '\0';

	i = _strlen(s) - 1;
	while (i > 0 && (s[i] == ' ' || s[i] == '\t'))
	{
		s[i] = '\0';
		i--;
	}
}

