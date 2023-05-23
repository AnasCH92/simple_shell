#include "main.h"

/**
 * _atoi - converts string to int.
 *
 * @s: pointer to string.
 *
 * Return: the convert value.
 */

int _atoi(char *s)
{
	int i;
	int h, p;

	h = 0;
	p = -1;
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == '-')
			p *= -1;

		if (s[i] > 47 && s[i] < 58)
		{
			if (h < 0)
				h = (h * 10) - (s[i] - '0');
			else
				h = (s[i] - '0') * -1;

			if (s[i + 1] < 48 || s[i + 1] > 57)
				break;
		}
	}
	if (p < 0)
		h *= -1;

	return (h);
}

/**
 * _strncmp -  comares the first n chars of two strings.
 *
 * @s1: pointer to string.
 * @s2: pointer to string.
 * @n: number of chars.
 *
 * Return: returns an integer.
 */

int	_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int i = 0;

	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
			if (s1[i] != s2[i])
				return (s1[i] - s2[i]);
			i++;
	}
	return (0);
}
